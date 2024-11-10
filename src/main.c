/******************************************************************************/
/*!
    \file
        main.c

   \brief
        Main function to initialize application, tasks and control functions.

    \ingroup
        rtos

    \copyright
        Copyright (C) 2023  MacDon Inustries Ltd.  All Rights Reserved.
        License     use only under terms of contract / confidential\n

    History:

    Date (YYYY/MM/DD) |   Author      |   Changes
    ------------------|---------------|----------------
    2023/03/29        | Ivan Ciric    | File branched from project 278 (ETDK) to create ISOBUS template project.
*/
/******************************************************************************/

/*******************************************************************************
  INCLUDE
*******************************************************************************/
// include STW libraries
#include "stwtypes.h"
#include "x_lib.h"
#include "x_os.h"
#include "x_ssv.h"

// include project headers
#include "can_j1939.h"
#include "main.h"
#include "NVStorage.h"

/*******************************************************************************
  DEFINES
*******************************************************************************/
#define EXT_SENSOR_SUPPLY_12V   12000u  //!<External sensor power supply 12V
#define EXT_SENSOR_SUPPLY_5V    5000u   //!<External sensor power supply  5V

#define MAIN_SHUTDOWN_DELAY     20000   // in microseconds

/*******************************************************************************
  MACROS
*******************************************************************************/

/*******************************************************************************
  ENUMS
*******************************************************************************/

/*******************************************************************************
  STRUCTS
*******************************************************************************/

/*******************************************************************************
  CONSTANTS
*******************************************************************************/
/*!
    \brief
    This struct with the Application information is not used within the
    Software. It will be placed in a special memory region (defined by
    X_MEM_APPLICATION_INFO).\n
    The information contained in this struct can be read by STW flash tools
    (like e.g. Winflash) to determine the type of software that has been
    flashed to the ECU.\n
    Note:\n
    There can only be one application information block defined.
*/
const T_x_lib_info gt_AppInfo X_MEM_APPLICATION_INFO =
{
  X_LIB_INFO_APPL_MAGIC,        //Magic key (signaling a valid Application Info Block) (do not edit!)
  X_LIB_INFO_STRUCT_VERSION,    //Version information of the info struct               (do not edit!)
  X_LIB_INFO_DEVICE_ID,         //ECU device ID  ; masked by X_LIB_INFO_CONTAINS_DEVICE_ID
  __DATE__,                     //current date   ; masked by X_LIB_INFO_CONTAINS_DATE_TIME
  __TIME__,                     //current time   ; masked by X_LIB_INFO_CONTAINS_DATE_TIME
  APP_SOFTWARE_NAME,            //project name   ; masked by X_LIB_INFO_CONTAINS_PROJECT_NAME
  APP_SOFTWARE_VERSION,         //project version; masked by X_LIB_INFO_CONTAINS_PROJECT_VERSION
  X_LIB_INFO_ADDITIONAL_MAX,    //size of additional Info (max. 0xFF); masked by X_LIB_INFO_CONTAINS_ADDITIONAL_INFO
  "UMATT"       //Additional Info (max. 255 chars)   ; masked by X_LIB_INFO_CONTAINS_ADDITIONAL_INFO
};

/*!
    \brief Watchdog Structure for STW shutdown and startup.

    Watchdog parameters:\n
        Minimum trigger time window = 100ms\n
        Maximum trigger time window = 400ms\n
        Minimum supply Votlage UEmin = 8.0V\n
        Maximum supply Voltage UEmax = 32.0V\n
        reset ECU when a watchdog error occurs or
        any ECU internal voltage is out of range or
        or supply voltage UE is below minimum.
*/
const T_x_ssv_config t_SSVConfig =
{
       100,                // watchdog minimum trigger time window is 100 milliseconds
       400,                // watchdog maximum trigger time window is 400 milliseconds
       32,                 // minimum supply voltage UEmin = 8.0 V
       128,                // maximum supply voltage UEmax = 32.0 V
       X_SSV_ERR_UEMAX,    // switch power off when UE > UEmax
       X_SSV_ERR_WD_USER | // reset ECU when a watchdog error occurs
       X_SSV_ERR_USYSMAX | // or any ECU internal voltage is out of range
       X_SSV_ERR_USYSMIN |
       X_SSV_ERR_UEMIN     // or supply voltage UE is below minimum
};

/*******************************************************************************
  VARIABLES
*******************************************************************************/
uint32 board_serial_number;     //!<This is programmatic access to the module's serial number. It can be extracted any time you need to identify the specific module.

/* This variable contains all the system information of the controller.
 * See structure T_x_sys_system_information in header file x_sys.h for more
 * information.
 */
T_x_sys_system_information  tSys;
//---------------------------------------------------------
//---------------------------------------------------------
//error code detection
//---------------------------------------------------
//gt_error will track all IO error, system error and other behaviour errors.
static T_Error gt_error;

/*******************************************************************************
  EXTERNS
*******************************************************************************/

/*******************************************************************************
  PROTOTYPES
*******************************************************************************/
static void m_main_task( void * const opv_TaskParameter );
boolean compareToSSVConfigInEE( const T_x_ssv_config * const ot_ssv_config, const EE_section_2_t * const ou_ee_section );
sint16 init_SSV_config( void );
uint8 init_system( void );

/*******************************************************************************
  FUNCTIONS
*******************************************************************************/

/******************************************************************************/
/*!
   \fn       static void m_main_task( void * const opv_TaskParameter )
   \brief    Initialize main control task
   \param    void * const opv_TaskParameter: The task parameter.
   \ingroup  rtos
   \defgroup mainTask Main Control Task
   \return   None.

    @{
*/
/******************************************************************************/
static void m_main_task( void * const opv_TaskParameter )
{
   (void)opv_TaskParameter;
    while( TRUE )
    {
        mainControlCycle( );

        x_os_wait_for_events( );
    }//while
}
/*! @} */

/******************************************************************************/
/*
   \fn       boolean compareToSSVConfigInEE( const T_x_ssv_config * const ot_ssv_config, const EE_section_2_t * const ou_ee_section )
   \brief    Compares data to configuration in EEPROM.
   \param    const T_x_ssv_config * const ot_ssv_config: The SSV configuration.
   \param    const EE_section_2_t * const ou_ee_section: The section in EEPROM.
   \return   None.
*/
/******************************************************************************/
boolean compareToSSVConfigInEE( const T_x_ssv_config * const ot_ssv_config, const EE_section_2_t * const ou_ee_section )
{
    boolean q_ssv_config_required;
    if(
        (ot_ssv_config->u16_WDmin != ou_ee_section->t_ee_data.u16_SSVConfig_WDmin) ||
        (ot_ssv_config->u16_WDmax != ou_ee_section->t_ee_data.u16_SSVConfig_WDmax) ||
        (ot_ssv_config->u8_UEmin != ou_ee_section->t_ee_data.u8_SSVConfig_UEmin) ||
        (ot_ssv_config->u8_UEmax != ou_ee_section->t_ee_data.u8_SSVConfig_UEmax) ||
        (ot_ssv_config->u8_RelOff != ou_ee_section->t_ee_data.u8_SSVConfig_RelOff) ||
        (ot_ssv_config->u8_Reset != ou_ee_section->t_ee_data.u8_SSVConfig_Reset)
       )
    {
        q_ssv_config_required = TRUE;
    }
    else
    {
        q_ssv_config_required = FALSE;
    }

    return( q_ssv_config_required );
}

/******************************************************************************/
/*
   \fn       sint16 init_SSV_config( void )
   \brief    Initializes the SSV configuration.
   \param    None.
   \return   None.
*/
/******************************************************************************/
sint16 init_SSV_config( void )
{
    sint16 s16_Error = C_NO_ERR;

    gu_ee_section_2.t_ee_data.u16_SSVConfig_WDmin = t_SSVConfig.u16_WDmin;
    gu_ee_section_2.t_ee_data.u16_SSVConfig_WDmax = t_SSVConfig.u16_WDmax;
    gu_ee_section_2.t_ee_data.u8_SSVConfig_UEmin = t_SSVConfig.u8_UEmin;
    gu_ee_section_2.t_ee_data.u8_SSVConfig_UEmax = t_SSVConfig.u8_UEmax;
    gu_ee_section_2.t_ee_data.u8_SSVConfig_RelOff = t_SSVConfig.u8_RelOff;
    gu_ee_section_2.t_ee_data.u8_SSVConfig_Reset = t_SSVConfig.u8_Reset;
    if( !GetEEDataInit(EE_SECTION_2_BASE_ADDR, gu_ee_section_2.au8_sectionData, TRUE) )
    {
        gt_error.u32_systemErr |= ERR_SYS_EEP_CRC_ERR;
    }

    if( compareToSSVConfigInEE(&t_SSVConfig, &gu_ee_section_2) )
    {
        s16_Error = x_ssv_init(&t_SSVConfig);
        gu_ee_section_2.t_ee_data.u16_SSVConfig_WDmin = t_SSVConfig.u16_WDmin;
        gu_ee_section_2.t_ee_data.u16_SSVConfig_WDmax = t_SSVConfig.u16_WDmax;
        gu_ee_section_2.t_ee_data.u8_SSVConfig_UEmin = t_SSVConfig.u8_UEmin;
        gu_ee_section_2.t_ee_data.u8_SSVConfig_UEmax = t_SSVConfig.u8_UEmax;
        gu_ee_section_2.t_ee_data.u8_SSVConfig_RelOff = t_SSVConfig.u8_RelOff;
        gu_ee_section_2.t_ee_data.u8_SSVConfig_Reset = t_SSVConfig.u8_Reset;
        putEEdata(EE_SECTION_2_BASE_ADDR, gu_ee_section_2.au8_sectionData, TRUE);
    }

    return( s16_Error );
}

/******************************************************************************/
/*
   \fn       uint8 init_system( void )
   \brief    Initializes all parameters associated with the application.
   \param    None.
   \return   uint8
   \retval   Main While Loop state (TRUE or FALSE).
*/
/******************************************************************************/
uint8 init_system( void )
{
    sint16 s16_Error;
    uint8  u8_mainWhileLoop;

    /*--- init ESX-3CS hardware, this function call is mandatory. ---*/
    // no wakeup process required.
    s16_Error = x_sys_init( &tSys );
    // switches the system self-holding on. Keep running when the ECU wake up
    // signals (like ignition KL15) are disconnected.
    s16_Error |= x_sys_stay_alive( X_ON );

    /*--- system supervisor to watch voltages ---*/
    s16_Error |= init_SSV_config( );

    board_serial_number =((tSys.t_LogisticData.au8_SerialNumber[1] & 0xF0) >> 4) * 100000 +
                         ((tSys.t_LogisticData.au8_SerialNumber[1] & 0x0F) >> 0) *  10000 +
                         ((tSys.t_LogisticData.au8_SerialNumber[2] & 0xF0) >> 4) *   1000 +
                         ((tSys.t_LogisticData.au8_SerialNumber[2] & 0x0F) >> 0) *    100 +
                         ((tSys.t_LogisticData.au8_SerialNumber[3] & 0xF0) >> 4) *     10 +
                         ((tSys.t_LogisticData.au8_SerialNumber[3] & 0x0F) >> 0) *      1;

    /*--- turn 3CM sensor supply 1, 2, 3 on ---*/
    #if defined( CONTROLLER_3CS )
        x_sys_set_sensor_supply( X_SYS_SENSOR_SUPPLY_01, EXT_SENSOR_SUPPLY_12V );
        x_sys_set_sensor_supply( X_SYS_SENSOR_SUPPLY_02, EXT_SENSOR_SUPPLY_5V );

        // turn on main switches of UB1
        x_out_relay_set( X_OUT_RELAY_01, X_ON );
    #endif // CONTROLLER_3CS

    /*--- I/O init and variables for every control ---*/
    if( C_NO_ERR == s16_Error )
    {
        //initError( );

        // load some variables with values from EEPROM
        // but some values might be changed later when the function is initialized
        //loadErrorCodeFrEE( );

        //----------------init CAN --------------------------
        // CANbus setup and messages setup
        s16_Error |= initialize_CAN( );

        s16_Error |= s16_Init_testSensors();



    }

    /*--- basic initialization passed, continue with higher layer initialization ---*/
    if( C_NO_ERR == s16_Error )
    {
        /*--- Initialize openSYDE Server ---*/
        const T_osy_dpd_application_information t_ApplicationInformation =
        {
            APP_SOFTWARE_NAME,
            APP_SOFTWARE_VERSION
        };
        s16_Error += osy_app_init( &t_ApplicationInformation );

        /*--- init real time operating system kernel ---*/
        // This function must be called only once before any task will be installed with
        // x_os_install_task in the main initialization sequence.
        //
        // Use big external memory. Locate task data into external heap memory
        s16_Error |= x_os_init( X_OS_HEAP_DEFAULT );

        /*--- install main control loop. cycle 1ms ---*/
        //2017-03-03 bzhou:  check stack size 268.
        s16_Error |= x_os_install_task( MAIN_CONTROLLOOP_PRIORITY,
                                        MAIN_CONTROLLOOP_TIME_INTERVAL,
                                        MAIN_CONTROLLOOP_TIME_DELAY,
                                        &m_main_task,
                                        MAIN_CONTROLLOOP_STACK_SIZE );

        /*--- install 10ms cyclic high-prio task with 32k stack for openSYDE adn 50ms startup delay ---*/
        s16_Error += x_os_install_task( OPENSYDE_APP_PRIORITY,
                                        OPENSYDE_APP_TIME_INTERVAL,
                                        OPENSYDE_APP_TIME_DELAY,
                                        &osy_app_task,
                                        OPENSYDE_APP_STACK_SIZE );

        if( C_NO_ERR == s16_Error )
        {
            // start task scheduler, OS timer tick = 1000 microseconds
            s16_Error += x_os_start( 1000 );//every tick 1ms
        }

        /*--- set main while loop return value to TRUE to allow it to run ---*/
        u8_mainWhileLoop = TRUE;

        /*--- Initialize ISOBUS ---*/
        #if ISO_VT_RUNNING
            TaskScheduler_Init();
        #endif // ISO_VT_RUNNING
    }

    if( s16_Error != C_NO_ERR )
    {
        /*--- One or more initialization sections failed. Switch LED to red ---*/
        (void)x_sys_set_led( X_SYS_LED_01, X_ON, X_SYS_LED_COLOR_RED );
    }

    return( u8_mainWhileLoop );
}

/******************************************************************************/
/*!
   \fn       int main( void )

   \brief    Startup Function

   \details  This is the first function in the program to run

   \return   int

   \retval   0         Clean exit
   \retval   non-zero  failure
*/
/******************************************************************************/
int main( void )
{
    uint8 u8_mainWhileLoop;
    uint8 u8_Ignition_main;

    /*--- Initialize the system ---*/
    u8_mainWhileLoop = init_system( );

    /*--- Start the main while-loop ---*/
    // one of the jobs for the main while: check for shut down
    while( u8_mainWhileLoop )
    {
        /*--- ISOBUS ---*/
        //2017-03-15 bzhou: test proved that TaskScheduler_Run() must put in here
        // in order to run the total software
        //if put into main control loop, it will die.
        #if ISO_VT_RUNNING
            TaskScheduler_Run( );
        #endif // ISO_VT_RUNNING

        /*--- Read ignition (D+ signal), and if it's off, shut down ---*/
        x_sys_get_ignition( &u8_Ignition_main );
        if( X_OFF == u8_Ignition_main )
        {
            u8_mainWhileLoop = FALSE;
        }
    }

    #if ISO_VT_RUNNING
        //ISO BUS task scheduler
        TaskScheduler_Exit( );
    #endif // ISO_VT_RUNNING

    /*--- Delay and then shut down application ---*/
    x_sys_delay_us( MAIN_SHUTDOWN_DELAY );
    x_sys_close( );

    return 0u;
}   //end of main()

/******************************************************************************/
/*!
   \fn       void mainControlCycle( void )

   \brief    The main control loop.

   \details  This function periodically updates the states of various functions
             within the main loop. These include:
             - Send/Receive J1939 messages
             - Detect any errors (I/O, system, software)

   \return   None.
*/
/******************************************************************************/
void mainControlCycle( void )
{
    CAN_STATUS_t status;

    /*--- Manage CAN/J1939 Rx ---*/
    status = receive_J1939_messages( );
    if( status != CAN_OK )
    {
        /*--- Process CAN Rx errors here ---*/
    }

    /*--- Add main application code here ---*/

    /*--- manage CAN/J1939 Tx ---*/
    status = send_J1939_messages( );
    if( status != CAN_OK )
    {
        /*--- Process CAN Tx errors here ---*/
    }
}

/******************************************************************************/
/*! \mainpage Introduction





*/
/******************************************************************************/

/******************************************************************************/
/*
   Copyright (C) 2016  MacDon Industries Ltd.  All Rights Reserved.
*/
/******************************************************************************/
