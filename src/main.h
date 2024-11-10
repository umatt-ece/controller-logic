/******************************************************************************/
/*!
    \file
        main.h

    \brief
        File to declare variables above all application header.

    \copyright
        Copyright (C) 2023  MacDon Inustries Ltd.  All Rights Reserved.
        License     use only under terms of contract / confidential\n

    History:

    Date (YYYY/MM/DD) |   Author      |   Changes
    ------------------|---------------|----------------
    2024/03/13        |Brent Fletcher | Initial build of triple mower software for 2024
*/
/******************************************************************************/

#ifndef __MAIN_H__
#define __MAIN_H__

/*******************************************************************************
  INCLUDE
*******************************************************************************/
// include standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdtypes.h>

// include STW libraries
#include "x_sys.h"

// Include ISObus libaries


/*
Here is a list of some (if not all) the STW libraries that can be included:
*/
#include "stwtypes.h"
#include "x_can.h"
#include "x_eep.h"
#include "x_esx3cs.h"
#include "x_in.h"
#include "x_lib.h"
#include "x_os.h"
#include "x_out.h"
#include "x_out_relay.h"
#include "x_ser.h"
#include "x_ssv.h"
#include "x_sys.h"
#include "x_tim.h"
#include "x_uti.h"

// include openSYDE headers
#include "osy_app_setup.h"
#include "osy_init.h"
#include "diagnostics_data_pool.h"

// include DisTek libraries
#include "TaskScheduler.h"

// include project files
#include "IOMapping.h"
#include "NVStorage.h"



/******************************************************************************/
/*!
    \defgroup rtos RTOS Information
    \brief Application tasking and interrupt

    Below is a list of application tasking and interrupt

    Task Name               | Priority      |    Task
    ------------------------|---------------|-----------------------------------------
    vLhPulseCallback        | +++           |    Left speed sensor interrupt
    vRhPulseCallback        | +++           |    Right speed sensor interrupt
    osy_app_task            | ++            |    openSYDE task for flashloading
    m_main_task             | +             |    main control loop

*/
/******************************************************************************/

/*******************************************************************************
  DEFINES
*******************************************************************************/

/*!
    \brief      Tasking parameters.
    \ingroup    rtos
    \defgroup   tasking Tasking Parameters
@{
*/
// Main control loop
#define MAIN_CONTROLLOOP_TIME_INTERVAL (10u)      //!<main control loop time interval 10 ms.
#define MAIN_CONTROLLOOP_TIME_DELAY    (100u)     //!<main control loop time delay before the task start 100ms.
#define MAIN_CONTROLLOOP_PRIORITY      (1u)       //!<main control loop priority. Larger number, higher priority.

//2017-03-03 & 2018-02-23 bzhou  check stack size 268. So 1000 should be good for a while. Plus later add ETDK in, stack size set higher
//2018-05-22 bzhou: use 8K for a long time it worked fine. When integrating openSYDE, the example code use 32k
#define MAIN_CONTROLLOOP_STACK_SIZE    (8u*1024u) //!<main control loop stack size 8K.

//openSYDE
#define OPENSYDE_APP_TIME_INTERVAL     (10u)      //!<openSYDE time interval 10ms.
#define OPENSYDE_APP_TIME_DELAY        (50u)      //!<openSYDE loop time delay before the task start 50ms.
#define OPENSYDE_APP_PRIORITY          (10u)      //!<openSYDE loop priority. Larger number, higher priority.
#define OPENSYDE_APP_STACK_SIZE        (8u*1024u) //!<openSYDE loop stack size 8K.
/*! @} */

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

/*******************************************************************************
  EXTERNS
*******************************************************************************/
extern T_x_sys_system_information  tSys;

//---------------------storage.c-----------------------------------------------
extern EE_section_0_t gu_ee_section_0;
extern EE_section_1_t gu_ee_section_1;
extern EE_section_2_t gu_ee_section_2;
extern EE_section_3_t gu_ee_section_3;
extern EE_section_4_t gu_ee_section_4;
extern EE_section_5_t gu_ee_section_5;
extern EE_section_6_t gu_ee_section_6;
extern EE_section_7_t gu_ee_section_7;
extern EE_section_8_t gu_ee_section_8;


/*******************************************************************************
  PROTOTYPES
*******************************************************************************/
/*!
    \brief    Main control loop
    \ingroup  mainTask
    \defgroup mainLoop Main Control Loop
    @{
*/
//init main control loop cyclic period 10ms
void mainControlCycle( void );
/*! @} */

/*!
    \brief      Every time pulses are read at right hand this function will be called
    \ingroup    rtos
    \defgroup   init Initialization
    @{
*/
sint16 init_SSV_config( void );
/*! @} */

/******************************************************************************/
/*
   Copyright (C) 2023 MacDon Industries Ltd.  All Rights Reserved.

   Developed by:
      MacDon Industries Ltd.
      680 Moray St.
      Winnipeg, MB, R3J 3S3
      Tel: 204-885-5590
*/
/******************************************************************************/

#endif  //__MAIN_H__






