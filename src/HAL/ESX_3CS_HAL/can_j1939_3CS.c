/******************************************************************************/
/*!
    \file
        can_j1939_3CS.c

    \defgroup
        can CAN

    \brief
        Hardware-specific file to perform CAN messaging\n
        CAN modules including CAN in and out functions, and message layouts.

    \ingroup
        can

    \copyright
        Copyright (C) 2023  MacDon Inustries Ltd.  All Rights Reserved.
        License   use only under terms of contract / confidential\n

    History:

    Date (YYYY/MM/DD) |   Author      |   Changes
    ------------------|---------------|----------------
    2023/04/12        | Ivan Ciric    | File Created
*/
/******************************************************************************/

#if defined( CONTROLLER_3CS )

/*******************************************************************************
  INCLUDE
*******************************************************************************/
#include <string.h>

// include platform configuration
#include "platform_config.h"

#include "can_j1939_3CS.h"

#include "can_j1939.h"
#include "can_j1939_user.h"
#include "global_data.h"
#include "main.h"

/*******************************************************************************
  DEFINES
*******************************************************************************/

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
  VARIABLES
*******************************************************************************/
static J1939_stack_message_handler_obj_t J1939_stack_1_tx_message_obj[ NUM_J1939_STACK_1_TX_MESSAGES ];
static J1939_stack_message_handler_obj_t J1939_stack_2_tx_message_obj[ NUM_J1939_STACK_2_TX_MESSAGES ];

static J1939_stack_message_handler_obj_t J1939_stack_1_rx_message_obj[ NUM_J1939_STACK_1_RX_MESSAGES ];
static J1939_stack_message_handler_obj_t J1939_stack_2_rx_message_obj[ NUM_J1939_STACK_2_RX_MESSAGES ];

static uint32_t J1939_stack_1_tx_time_ms[ NUM_J1939_STACK_1_TX_MESSAGES ];
static uint32_t J1939_stack_2_tx_time_ms[ NUM_J1939_STACK_2_TX_MESSAGES ];

static j1939_transmit_request_table_t J1939_stack_1_transmit_request_msg_table[ NUM_J1939_STACK_1_TX_MESSAGES ];
static uint32_t J1939_stack_1_transmit_request_index = 0;

static j1939_transmit_request_table_t J1939_stack_2_transmit_request_msg_table[ NUM_J1939_STACK_2_TX_MESSAGES ];
static uint32_t J1939_stack_2_transmit_request_index = 0;

/*******************************************************************************
  EXTERNS
*******************************************************************************/

/*******************************************************************************
  PROTOTYPES
*******************************************************************************/
static uint32_t find_next_transmit_request_message( J1939_stack_t j1939_stack, uint32_t current_index );
static void update_EA00_tx_request_msg( J1939_stack_t j1939_stack, J1939_tx_message_t * message );

/*******************************************************************************
  FUNCTIONS
*******************************************************************************/

/******************************************************************************/
/*
   \fn       int16_t initialize_CAN_3CS( void )
   \brief    Initializes all CAN buses on the STW 3CS controller\n
             All Tx and Rx CAN messages are initialized used for sending data as well as receiving message\n
   \param    None.
   \ingroup  initCAN
   \return   error code from x_can_bus_init

    @{
*/
/******************************************************************************/
int16_t initialize_CAN_3CS( void )
{
    T_x_osf_can osf_canParameters;
    T_x_osf_oscs t_OsyParameters;
    int16_t s16_error;
    uint16_t u16_canChannel;
    uint32_t u32_bitrate;
    uint16_t u16_samplePoint;

    T_x_can_obj_config t_canConfig_initCAN;
    uint32_t u32_i;

    // Initialize the variable responsible for keeping track of which
    // Tx messages need to be sent on CAN 1
    for( u32_i = 0; u32_i < NUM_J1939_STACK_1_TX_MESSAGES; u32_i++ )
    {
        J1939_stack_1_tx_time_ms[ u32_i ] = 0;
    }

    // Initialize the variable responsible for keeping track of which
    // Tx messages need to be sent on CAN 2
    for( u32_i = 0; u32_i < NUM_J1939_STACK_2_TX_MESSAGES; u32_i++ )
    {
        J1939_stack_2_tx_time_ms[ u32_i ] = 0;
    }

    // initialize all CAN channels
    for( u16_canChannel = X_CAN_BUS_01; u16_canChannel < X_CAN_CH_MAX; u16_canChannel++ )
    {
      // try to get configuration parameter for the openSYDE buses from EEPROM
      s16_error = x_osf_can_get_param( u16_canChannel, &osf_canParameters );
      if( C_NO_ERR == s16_error )
      {
         u32_bitrate = osf_canParameters.u32_Bitrate;
         u16_samplePoint = osf_canParameters.u16_SamplePoint;
      }
      else
      {
         // no valid EEPROM content: use default bitrate and auto sample point
         u32_bitrate = J1939_DEFAULT_BITRATE;
         u16_samplePoint = 0;
      }

      if( u16_samplePoint != 0 )
      {
         // use configured sample point
         s16_error |= x_can_bus_init_ext( u16_canChannel, u32_bitrate, u16_samplePoint, NULL );
      }
      else
      {
         // sample point is determined automatically
         s16_error |= x_can_bus_init( u16_canChannel, u32_bitrate );
      }
    }

    if (s16_error == C_NO_ERR)
      {
         // The device configuration in the openSYDE tool does not change the activation flags, so
         // the application must configure the active communication channels by itself
         // For the example application, we want to use all CAN buses
         const uint8 au8_DefaultActivation[X_CAN_CH_MAX] = {1, 1};

         (void)x_osf_can_get_oscs(u16_canChannel, &t_OsyParameters);
         t_OsyParameters.u8_Active = au8_DefaultActivation[u16_canChannel];
         (void)x_osf_can_set_oscs(u16_canChannel, &t_OsyParameters);
      }

    // Initialize the user application's CAN parameters, passing any error
    // that may have occurred, and then obtaining any error that may occur
    // during user initialization
    if( C_NO_ERR == s16_error )
    {
        /*-----------------------------------------------------------*/
        // Initialize user application's Rx messages on CAN 1
        /*-----------------------------------------------------------*/
        for( u32_i = 0; u32_i < NUM_J1939_STACK_1_RX_MESSAGES; u32_i++ )
        {
            // Populate the t_canConfig_initCAN variable
            //   u32_Id: Rx Identifier (11-bit or 29-bit)
            //   u8_Xtd: TRUE if using 29-bit identifier, FALSE if using 11-bit
            //   u8_MsgType: X_CAN_OBJ_TYPE_RX for Rx object, X_CAN_OBJ_TYPE_TX for Tx object
            //   u16_Pause: Tx pause function (use 0 if not used)
            //   u16_SoftBuffer: The number of soft buffers in use
            //   u16_HardBuffer: The number of hard buffers in use
            //   u32_CallbackParameter: The callback parameter (use 0 if not used)
            //   pr_Callback: Function pointer callback (use NULL if not used)
            t_canConfig_initCAN.t_Id.u32_Id = J1939_MSG_ID(
                J1939_stack_1_rx_msg_table[ u32_i ].message_id.priority,
                J1939_stack_1_rx_msg_table[ u32_i ].message_id.data_page,
                J1939_stack_1_rx_msg_table[ u32_i ].message_id.PGN,
                J1939_stack_1_rx_msg_table[ u32_i ].message_id.destination_address,
                J1939_stack_1_rx_msg_table[ u32_i ].message_id.source_address
            );
            t_canConfig_initCAN.t_Id.u8_Xtd = TRUE;
            t_canConfig_initCAN.u8_MsgType = X_CAN_OBJ_TYPE_RX;
            t_canConfig_initCAN.u16_Pause = 10;
            t_canConfig_initCAN.u16_SoftBuffer = 10;
            t_canConfig_initCAN.u16_HardBuffer = 0;
            t_canConfig_initCAN.u32_CallbackParameter = 0;
            t_canConfig_initCAN.pr_Callback = NULL;

            // Initialize the CAN with this message
            s16_error |= x_can_obj_init( X_CAN_BUS_01, &t_canConfig_initCAN, &J1939_stack_1_rx_message_obj[ u32_i ].pv_can_handle );
        }

        /*-----------------------------------------------------------*/
        // Initialize user application's Rx messages on CAN 2
        /*-----------------------------------------------------------*/
        for( u32_i = 0; u32_i < NUM_J1939_STACK_2_RX_MESSAGES; u32_i++ )
        {
            // Populate the t_canConfig_initCAN variable
            //   u32_Id: Rx Identifier (11-bit or 29-bit)
            //   u8_Xtd: TRUE if using 29-bit identifier, FALSE if using 11-bit
            //   u8_MsgType: X_CAN_OBJ_TYPE_RX for Rx object, X_CAN_OBJ_TYPE_TX for Tx object
            //   u16_Pause: Tx pause function (use 0 if not used)
            //   u16_SoftBuffer: The number of soft buffers in use
            //   u16_HardBuffer: The number of hard buffers in use
            //   u32_CallbackParameter: The callback parameter (use 0 if not used)
            //   pr_Callback: Function pointer callback (use NULL if not used)
            t_canConfig_initCAN.t_Id.u32_Id = J1939_MSG_ID(
                J1939_stack_2_rx_msg_table[ u32_i ].message_id.priority,
                J1939_stack_2_rx_msg_table[ u32_i ].message_id.data_page,
                J1939_stack_2_rx_msg_table[ u32_i ].message_id.PGN,
                J1939_stack_2_rx_msg_table[ u32_i ].message_id.destination_address,
                J1939_stack_2_rx_msg_table[ u32_i ].message_id.source_address
            );
            t_canConfig_initCAN.t_Id.u8_Xtd = TRUE;
            t_canConfig_initCAN.u8_MsgType = X_CAN_OBJ_TYPE_RX;
            t_canConfig_initCAN.u16_Pause = 10;
            t_canConfig_initCAN.u16_SoftBuffer = 10;
            t_canConfig_initCAN.u16_HardBuffer = 0;
            t_canConfig_initCAN.u32_CallbackParameter = 0;
            t_canConfig_initCAN.pr_Callback = NULL;

            // Initialize the CAN with this message
            s16_error |= x_can_obj_init( X_CAN_BUS_02, &t_canConfig_initCAN, &J1939_stack_2_rx_message_obj[ u32_i ].pv_can_handle );
        }

        /*-----------------------------------------------------------*/
        // Initialize user application's Tx messages on CAN 1
        /*-----------------------------------------------------------*/
        for( u32_i = 0; u32_i < NUM_J1939_STACK_1_TX_MESSAGES; u32_i++ )
        {
            // Populate the t_canConfig_initCAN variable
            //   u32_Id: Rx Identifier (11-bit or 29-bit)
            //   u8_Xtd: TRUE if using 29-bit identifier, FALSE if using 11-bit
            //   u8_MsgType: X_CAN_OBJ_TYPE_RX for Rx object, X_CAN_OBJ_TYPE_TX for Tx object
            //   u16_Pause: Tx pause function (use 0 if not used)
            //   u16_SoftBuffer: The number of soft buffers in use
            //   u16_HardBuffer: The number of hard buffers in use
            //   u32_CallbackParameter: The callback parameter (use 0 if not used)
            //   pr_Callback: Function pointer callback (use NULL if not used)
            t_canConfig_initCAN.t_Id.u32_Id = J1939_MSG_ID(
                J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.priority,
                J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.data_page,
                J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.PGN,
                J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.destination_address,
                J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.source_address
            );
            t_canConfig_initCAN.t_Id.u8_Xtd = TRUE;
            t_canConfig_initCAN.u8_MsgType = X_CAN_OBJ_TYPE_TX;
            t_canConfig_initCAN.u16_Pause = 10;
            t_canConfig_initCAN.u16_SoftBuffer = 10;
            t_canConfig_initCAN.u16_HardBuffer = 0;
            t_canConfig_initCAN.u32_CallbackParameter = 0;
            t_canConfig_initCAN.pr_Callback = NULL;

            // Check to see if this Tx message is a Transmit Request message
            // PGN 0xEA00-0xEAFF
            if( (J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.PGN >= 0xEA00) &&
                (J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.PGN <= 0xEAFF) )
            {
                // Add this transmit request message to the transmit request message table
                J1939_stack_1_transmit_request_msg_table[ u32_i ].data_obtained = TRUE;
                J1939_stack_1_transmit_request_msg_table[ u32_i ].tx_update_handler = update_EA00_tx_request_msg;
            }
            else
            {
                // This is not a transmit request message.
                // Copy the PGN, but set data_obtained to TRUE and tx_update_handler to NULL
                J1939_stack_1_transmit_request_msg_table[ u32_i ].data_obtained = TRUE;
                J1939_stack_1_transmit_request_msg_table[ u32_i ].tx_update_handler = NULL;
            }

            // Initialize the CAN with this message
            s16_error |= x_can_obj_init( X_CAN_BUS_01, &t_canConfig_initCAN, &J1939_stack_1_tx_message_obj[ u32_i ].pv_can_handle );
        }

        /*-----------------------------------------------------------*/
        // Initialize user application's Tx messages on CAN 2
        /*-----------------------------------------------------------*/
        for( u32_i = 0; u32_i < NUM_J1939_STACK_2_TX_MESSAGES; u32_i++ )
        {
            // Populate the t_canConfig_initCAN variable
            //   u32_Id: Rx Identifier (11-bit or 29-bit)
            //   u8_Xtd: TRUE if using 29-bit identifier, FALSE if using 11-bit
            //   u8_MsgType: X_CAN_OBJ_TYPE_RX for Rx object, X_CAN_OBJ_TYPE_TX for Tx object
            //   u16_Pause: Tx pause function (use 0 if not used)
            //   u16_SoftBuffer: The number of soft buffers in use
            //   u16_HardBuffer: The number of hard buffers in use
            //   u32_CallbackParameter: The callback parameter (use 0 if not used)
            //   pr_Callback: Function pointer callback (use NULL if not used)
            t_canConfig_initCAN.t_Id.u32_Id = J1939_MSG_ID(
                J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.priority,
                J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.data_page,
                J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.PGN,
                J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.destination_address,
                J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.source_address
            );
            t_canConfig_initCAN.t_Id.u8_Xtd = TRUE;
            t_canConfig_initCAN.u8_MsgType = X_CAN_OBJ_TYPE_TX;
            t_canConfig_initCAN.u16_Pause = 10;
            t_canConfig_initCAN.u16_SoftBuffer = 10;
            t_canConfig_initCAN.u16_HardBuffer = 0;
            t_canConfig_initCAN.u32_CallbackParameter = 0;
            t_canConfig_initCAN.pr_Callback = NULL;

            // Check to see if this Tx message is a Transmit Request message
            // PGN 0xEA00-0xEAFF
            if( (J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.PGN >= 0xEA00) &&
                (J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.PGN <= 0xEAFF) )
            {
                // Add this transmit request message to the transmit request message table
                J1939_stack_2_transmit_request_msg_table[ u32_i ].data_obtained = TRUE;
                J1939_stack_2_transmit_request_msg_table[ u32_i ].tx_update_handler = update_EA00_tx_request_msg;
            }
            else
            {
                // This is not a transmit request message.
                // Copy the PGN, but set data_obtained to TRUE and tx_update_handler to NULL
                J1939_stack_2_transmit_request_msg_table[ u32_i ].data_obtained = TRUE;
                J1939_stack_2_transmit_request_msg_table[ u32_i ].tx_update_handler = NULL;
            }

            // Initialize the CAN with this message
            s16_error |= x_can_obj_init( X_CAN_BUS_02, &t_canConfig_initCAN, &J1939_stack_2_tx_message_obj[ u32_i ].pv_can_handle );
        }
    }

    return( s16_error );
}
/* @} */

/******************************************************************************/
/*
   \fn       int16_t J1939_lock_message_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address, j1939_message_t type, boolean lock )
   \brief    Locks or unlocks the first entry in the table that matches the supplied PGN,\n
             destination address, and source address.
   \param    J1939_stack_t j1939_stack: The J1939 stack that the J1939 Tx message is on.
   \param    uint32_t PGN: The PGN of the message to find.
   \param    uint32_t destination_address: The destination address of the message to find.
   \param    uint32_t source_address: The source address of the message to find.
   \param    j1939_message_t type: The type of message to lock. See enum\n
             j1939_message_t for options.
   \param    boolean lock: TRUE if message should be locked, FALSE otherwise.
   \ingroup  sendCAN
   \return   error code from x_can_obj_lock

    @{
*/
/******************************************************************************/
int16_t J1939_lock_message_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address, j1939_message_t type, boolean lock )
{
    int16_t s16_error = C_NO_ERR; // Assume there are no errors
    boolean message_found = FALSE;
    uint8 ou8_OnOff = ((TRUE == lock) ? X_ON : X_OFF );
    uint32_t u32_i;

    switch( j1939_stack )
    {
        case J1939_STACK_1:
            if( (TX_MESSAGES == type) || (RX_AND_TX_MESSAGES == type) )
            {
                // Loop through the table to search for the message
                for( u32_i = 0; (u32_i < NUM_J1939_STACK_1_TX_MESSAGES) && !message_found; u32_i++ )
                {
                    if( (PGN == J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.PGN) &&
                        (destination_address == J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.destination_address) &&
                        (source_address == J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.source_address) )
                    {
                        // We found a match
                        message_found = TRUE;

                        // Lock/unlock this message
                        s16_error |= x_can_obj_lock( J1939_stack_1_tx_message_obj[ u32_i ].pv_can_handle, ou8_OnOff );
                    }
                }
            }

            if( (RX_MESSAGES == type) || (RX_AND_TX_MESSAGES == type) )
            {
                // Loop through the table to search for the message
                for( u32_i = 0; (u32_i < NUM_J1939_STACK_1_RX_MESSAGES) && !message_found; u32_i++ )
                {
                    if( (PGN == J1939_stack_1_rx_msg_table[ u32_i ].message_id.PGN) &&
                        (destination_address == J1939_stack_1_rx_msg_table[ u32_i ].message_id.destination_address) &&
                        (source_address == J1939_stack_1_rx_msg_table[ u32_i ].message_id.source_address) )
                    {
                        // We found a match
                        message_found = TRUE;

                        // Lock/unlock this message
                        s16_error |= x_can_obj_lock( J1939_stack_1_rx_message_obj[ u32_i ].pv_can_handle, ou8_OnOff );
                    }
                }
            }
            break;

        case J1939_STACK_2:
            if( (TX_MESSAGES == type) || (RX_AND_TX_MESSAGES == type) )
            {
                // Loop through the table to search for the message
                for( u32_i = 0; (u32_i < NUM_J1939_STACK_2_TX_MESSAGES) && !message_found; u32_i++ )
                {
                    if( (PGN == J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.PGN) &&
                        (destination_address == J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.destination_address) &&
                        (source_address == J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.source_address) )
                    {
                        // We found a match
                        message_found = TRUE;

                        // Lock/unlock this message
                        s16_error |= x_can_obj_lock( J1939_stack_2_tx_message_obj[ u32_i ].pv_can_handle, ou8_OnOff );
                    }
                }
            }

            if( (RX_MESSAGES == type) || (RX_AND_TX_MESSAGES == type) )
            {
                // Loop through the table to search for the message
                for( u32_i = 0; (u32_i < NUM_J1939_STACK_2_RX_MESSAGES) && !message_found; u32_i++ )
                {
                    if( (PGN == J1939_stack_2_rx_msg_table[ u32_i ].message_id.PGN) &&
                        (destination_address == J1939_stack_2_rx_msg_table[ u32_i ].message_id.destination_address) &&
                        (source_address == J1939_stack_2_rx_msg_table[ u32_i ].message_id.source_address) )
                    {
                        // We found a match
                        message_found = TRUE;

                        // Lock/unlock this message
                        s16_error |= x_can_obj_lock( J1939_stack_2_tx_message_obj[ u32_i ].pv_can_handle, ou8_OnOff );
                    }
                }
            }
            break;

        default:
            // Return a range error
            s16_error = C_RANGE;
            break;
    }

    return( s16_error );
}
/* @} */

/******************************************************************************/
/*
   \fn       int16_t J1939_lock_all_messages_3CS( J1939_stack_t j1939_stack, j1939_message_t type, boolean lock )
   \brief    Locks or unlocks the first entry in the table that matches the supplied PGN,\n
             destination address, and source address.
   \param    J1939_stack_t j1939_stack: The J1939 stack that the J1939 Tx message is on.
   \param    j1939_message_t type: The type of message to lock. See enum\n
             j1939_message_t for options.
   \param    boolean lock: TRUE if message should be locked, FALSE otherwise.
   \ingroup  sendCAN
   \return   error code from x_can_obj_lock

    @{
*/
/******************************************************************************/
int16_t J1939_lock_all_messages_3CS( J1939_stack_t j1939_stack, j1939_message_t type, boolean lock )
{
    int16_t s16_error = C_NO_ERR; // Assume there are no errors
    uint8 ou8_OnOff = ((TRUE == lock) ? X_ON : X_OFF );
    uint32_t u32_i;

    switch( j1939_stack )
    {
        case J1939_STACK_1:
            if( (TX_MESSAGES == type) || (RX_AND_TX_MESSAGES == type) )
            {
                // Loop through the table to search for the message
                for( u32_i = 0; u32_i < NUM_J1939_STACK_1_TX_MESSAGES; u32_i++ )
                {
                    // Lock/unlock this message
                    s16_error |= x_can_obj_lock( J1939_stack_1_tx_message_obj[ u32_i ].pv_can_handle, ou8_OnOff );
                }
            }

            if( (RX_MESSAGES == type) || (RX_AND_TX_MESSAGES == type) )
            {
                // Loop through the table to search for the message
                for( u32_i = 0; u32_i < NUM_J1939_STACK_1_RX_MESSAGES; u32_i++ )
                {
                    // Lock/unlock this message
                    s16_error |= x_can_obj_lock( J1939_stack_1_rx_message_obj[ u32_i ].pv_can_handle, ou8_OnOff );
                }
            }
            break;

        case J1939_STACK_2:
            if( (TX_MESSAGES == type) || (RX_AND_TX_MESSAGES == type) )
            {
                // Loop through the table to search for the message
                for( u32_i = 0; u32_i < NUM_J1939_STACK_2_TX_MESSAGES; u32_i++ )
                {
                    // Lock/unlock this message
                    s16_error |= x_can_obj_lock( J1939_stack_2_tx_message_obj[ u32_i ].pv_can_handle, ou8_OnOff );
                }
            }

            if( (RX_MESSAGES == type) || (RX_AND_TX_MESSAGES == type) )
            {
                // Loop through the table to search for the message
                for( u32_i = 0; u32_i < NUM_J1939_STACK_2_RX_MESSAGES; u32_i++ )
                {
                    // Lock/unlock this message
                    s16_error |= x_can_obj_lock( J1939_stack_2_rx_message_obj[ u32_i ].pv_can_handle, ou8_OnOff );
                }
            }
            break;

        default:
            // Return a range error
            s16_error = C_RANGE;
            break;
    }

    return( s16_error );
}
/* @} */

/******************************************************************************/
/*
   \fn       int16_t J1939_filter_message_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address, j1939_message_t type, uint32_t mask )
   \brief    Filters the J1939 message that matches the PGN, destination address\n
             and source address provided by using the provided mask.
   \param    J1939_stack_t j1939_stack: The J1939 stack that the J1939 message is on.
   \param    uint32_t PGN: The PGN of the message to find.
   \param    uint32_t destination_address: The destination address of the message to find.
   \param    uint32_t source_address: The source address of the message to find.
   \param    j1939_message_t type: The type of message to filter. See enum\n
             j1939_message_t for options.
   \param    uint32_t mask: The mask to apply to the 29-bit CAN ID. When a bit\n
             is set, that will be compared to the CAN ID to determine if the\n
             message should be passed to the appropriate handler.
   \ingroup  CAN
   \return   error code from x_can_obj_set_filter

    @{
*/
/******************************************************************************/
int16_t J1939_filter_message_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address, j1939_message_t type, uint32_t mask )
{
    int16_t s16_error = C_NO_ERR; // Assume there are no errors
    boolean message_found = FALSE;
    T_x_can_id t_CompareId;
    T_x_can_id t_Mask;
    uint32_t u32_i;

    switch( j1939_stack )
    {
        case J1939_STACK_1:
            if( (TX_MESSAGES == type) || (RX_AND_TX_MESSAGES == type) )
            {
                // Loop through the table to search for the message
                for( u32_i = 0; (u32_i < NUM_J1939_STACK_1_TX_MESSAGES) && !message_found; u32_i++ )
                {
                    if( (PGN == J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.PGN) &&
                        (destination_address == J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.destination_address) &&
                        (source_address == J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.source_address) )
                    {
                        // We found a match
                        message_found = TRUE;

                        // Generate the 29-bit CAN ID from the table
                        t_CompareId.u32_Id = J1939_MSG_ID(
                            J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.priority,
                            J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.data_page,
                            J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.PGN,
                            J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.destination_address,
                            J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.source_address
                        );
                        t_CompareId.u8_Xtd = TRUE;

                        // Generate the 29-bit CAN ID mask for this message
                        t_Mask.u32_Id = mask;
                        t_Mask.u8_Xtd = TRUE;

                        // Filter this message
                        s16_error |= x_can_obj_set_filter( J1939_stack_1_tx_message_obj[ u32_i ].pv_can_handle, &t_CompareId, &t_Mask );
                    }
                }
            }

            if( (RX_MESSAGES == type) || (RX_AND_TX_MESSAGES == type) )
            {
                // Loop through the table to search for the message
                for( u32_i = 0; (u32_i < NUM_J1939_STACK_1_RX_MESSAGES) && !message_found; u32_i++ )
                {
                    if( (PGN == J1939_stack_1_rx_msg_table[ u32_i ].message_id.PGN) &&
                        (destination_address == J1939_stack_1_rx_msg_table[ u32_i ].message_id.destination_address) &&
                        (source_address == J1939_stack_1_rx_msg_table[ u32_i ].message_id.source_address) )
                    {
                        // We found a match
                        message_found = TRUE;

                        // Generate the 29-bit CAN ID from the table
                        t_CompareId.u32_Id = J1939_MSG_ID(
                            J1939_stack_1_rx_msg_table[ u32_i ].message_id.priority,
                            J1939_stack_1_rx_msg_table[ u32_i ].message_id.data_page,
                            J1939_stack_1_rx_msg_table[ u32_i ].message_id.PGN,
                            J1939_stack_1_rx_msg_table[ u32_i ].message_id.destination_address,
                            J1939_stack_1_rx_msg_table[ u32_i ].message_id.source_address
                        );
                        t_CompareId.u8_Xtd = TRUE;

                        // Generate the 29-bit CAN ID mask for this message
                        t_Mask.u32_Id = mask;
                        t_Mask.u8_Xtd = TRUE;

                        // Filter this message
                        s16_error |= x_can_obj_set_filter( J1939_stack_1_rx_message_obj[ u32_i ].pv_can_handle, &t_CompareId, &t_Mask );
                    }
                }
            }
            break;

        case J1939_STACK_2:
            if( (TX_MESSAGES == type) || (RX_AND_TX_MESSAGES == type) )
            {
                // Loop through the table to search for the message
                for( u32_i = 0; (u32_i < NUM_J1939_STACK_2_TX_MESSAGES) && !message_found; u32_i++ )
                {
                    if( (PGN == J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.PGN) &&
                        (destination_address == J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.destination_address) &&
                        (source_address == J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.source_address) )
                    {
                        // We found a match
                        message_found = TRUE;

                        // Generate the 29-bit CAN ID from the table
                        t_CompareId.u32_Id = J1939_MSG_ID(
                            J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.priority,
                            J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.data_page,
                            J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.PGN,
                            J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.destination_address,
                            J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.source_address
                        );
                        t_CompareId.u8_Xtd = TRUE;

                        // Generate the 29-bit CAN ID mask for this message
                        t_Mask.u32_Id = mask;
                        t_Mask.u8_Xtd = TRUE;

                        // Filter this message
                        s16_error |= x_can_obj_set_filter( J1939_stack_2_tx_message_obj[ u32_i ].pv_can_handle, &t_CompareId, &t_Mask );
                    }
                }
            }

            if( (RX_MESSAGES == type) || (RX_AND_TX_MESSAGES == type) )
            {
                // Loop through the table to search for the message
                for( u32_i = 0; (u32_i < NUM_J1939_STACK_2_RX_MESSAGES) && !message_found; u32_i++ )
                {
                    if( (PGN == J1939_stack_2_rx_msg_table[ u32_i ].message_id.PGN) &&
                        (destination_address == J1939_stack_2_rx_msg_table[ u32_i ].message_id.destination_address) &&
                        (source_address == J1939_stack_2_rx_msg_table[ u32_i ].message_id.source_address) )
                    {
                        // We found a match
                        message_found = TRUE;

                        // Generate the 29-bit CAN ID from the table
                        t_CompareId.u32_Id = J1939_MSG_ID(
                            J1939_stack_2_rx_msg_table[ u32_i ].message_id.priority,
                            J1939_stack_2_rx_msg_table[ u32_i ].message_id.data_page,
                            J1939_stack_2_rx_msg_table[ u32_i ].message_id.PGN,
                            J1939_stack_2_rx_msg_table[ u32_i ].message_id.destination_address,
                            J1939_stack_2_rx_msg_table[ u32_i ].message_id.source_address
                        );
                        t_CompareId.u8_Xtd = TRUE;

                        // Generate the 29-bit CAN ID mask for this message
                        t_Mask.u32_Id = mask;
                        t_Mask.u8_Xtd = TRUE;

                        // Filter this message
                        s16_error |= x_can_obj_set_filter( J1939_stack_2_rx_message_obj[ u32_i ].pv_can_handle, &t_CompareId, &t_Mask );
                    }
                }
            }
            break;

        default:
            // Return a range error
            s16_error = C_RANGE;
            break;
    }

    return( s16_error );
}
/* @} */

/******************************************************************************/
/*
   \fn       CAN_STATUS_t receive_J1939_messages_3CS( void )
   \brief    Receives the corresponding J1939 message and passes it to the application.
   \param    None.
   \ingroup  receiveCAN
   \return   The CAN status, as defined in enumerate CAN_STATUS_t.

    @{
*/
/******************************************************************************/
CAN_STATUS_t receive_J1939_messages_3CS( void )
{
    CAN_STATUS_t status = CAN_OK; // Assume no errors occurred
    J1939_rx_message_t rx_msg;
    T_x_can_msg opt_can_msg;
    uint8_t u8_destination_address;
    uint16_t u16_can_buffer_count;
    uint16_t u16_PGN;
    uint32_t u32_i;
    int16_t s16_error;

    // Loop through the whole message list on J1939 stack 1
    for( u32_i = 0; u32_i < NUM_J1939_STACK_1_RX_MESSAGES; u32_i++ )
    {
        // Get CAN buffer count
        u16_can_buffer_count = 0;
        x_can_obj_get_buf_count( J1939_stack_1_rx_message_obj[ u32_i ].pv_can_handle, &u16_can_buffer_count );

        if( u16_can_buffer_count > 0 ) // Get message only if there are messages in the buffer to get
        {
            // Get the message and make sure there are no errors present
            s16_error = x_can_obj_get_msg( J1939_stack_1_rx_message_obj[ u32_i ].pv_can_handle, &opt_can_msg );
            if( C_NO_ERR == s16_error )
            {
                if( TRUE == opt_can_msg.t_Id.u8_Xtd ) // This is a J1939 message
                {
                    // Extract the PGN and Destination Address (if applicable)
                    u16_PGN = (uint16_t)((opt_can_msg.t_Id.u32_Id >> 8) & 0xFFFF);
                    if( u16_PGN < 0xF000 )
                    {
                        u16_PGN = (uint16_t)(u16_PGN & 0xFF00);
                        u8_destination_address = (uint8_t)(u16_PGN & 0x00FF);
                    }
                    else
                    {
                        u8_destination_address = 0x00;
                    }

                    if( u16_PGN == J1939_stack_1_rx_msg_table[ u32_i ].message_id.PGN ) // PGN matches
                    {
                        // Populate the rx_msg with the PGN
                        rx_msg.message_id.PGN = u16_PGN;

                        // Populate the rx_msg with the destination address
                        rx_msg.message_id.destination_address = u8_destination_address;

                        // Populate the source address
                        rx_msg.message_id.source_address = (uint8_t)(opt_can_msg.t_Id.u32_Id & 0xFF);

                        // Populate the CAN data
                        for( rx_msg.length = 0; rx_msg.length < sizeof(opt_can_msg.au8_Data); rx_msg.length++ )
                        {
                            rx_msg.data_buffer[ rx_msg.length ] = opt_can_msg.au8_Data[ rx_msg.length ];
                        }

                        // Call the Rx Callback to pass the data to the application, if it exists
                        if( J1939_stack_1_rx_msg_table[ u32_i ].rx_callback != NULL )
                        {
                            J1939_stack_1_rx_msg_table[ u32_i ].rx_callback( J1939_STACK_1, &rx_msg );
                        }
                    }
                }
            }
            else // An error occurred
            {
                // Check to see if any failures already happened.
                // We will return only the first kind of failure to the calling function.
                if( status != CAN_OK )
                {
                    // Return a value to indicate an error occured
                    status = (CAN_STATUS_t)(C_NO_ERR - s16_error);
                }
            }
        }
    }

    // Loop through the whole message list on J1939 stack 2
    for( u32_i = 0; u32_i < NUM_J1939_STACK_2_RX_MESSAGES; u32_i++ )
    {
        // Get CAN buffer count
        u16_can_buffer_count = 0;
        x_can_obj_get_buf_count( J1939_stack_2_rx_message_obj[ u32_i ].pv_can_handle, &u16_can_buffer_count );

        if( u16_can_buffer_count > 0 ) // Get message only if there are messages in the buffer to get
        {
            // Get the message and make sure there are no errors present
            s16_error = x_can_obj_get_msg( J1939_stack_2_rx_message_obj[ u32_i ].pv_can_handle, &opt_can_msg );
            if( C_NO_ERR == s16_error )
            {
                if( TRUE == opt_can_msg.t_Id.u8_Xtd ) // This is a J1939 message
                {
                    // Extract the PGN and Destination Address (if applicable)
                    u16_PGN = (uint16_t)((opt_can_msg.t_Id.u32_Id >> 8) & 0xFFFF);
                    if( u16_PGN < 0xF000 )
                    {
                        u16_PGN = (uint16_t)(u16_PGN & 0xFF00);
                        u8_destination_address = (uint8_t)(u16_PGN & 0x00FF);
                    }
                    else
                    {
                        u8_destination_address = 0x00;
                    }

                    if( u16_PGN == J1939_stack_2_rx_msg_table[ u32_i ].message_id.PGN ) // PGN matches
                    {
                        // Populate the rx_msg with the PGN
                        rx_msg.message_id.PGN = u16_PGN;

                        // Populate the rx_msg with the destination address
                        rx_msg.message_id.destination_address = u8_destination_address;

                        // Populate the source address
                        rx_msg.message_id.source_address = (uint8_t)(opt_can_msg.t_Id.u32_Id & 0xFF);

                        // Populate the CAN data
                        for( rx_msg.length = 0; rx_msg.length < sizeof(opt_can_msg.au8_Data); rx_msg.length++ )
                        {
                            rx_msg.data_buffer[ rx_msg.length ] = opt_can_msg.au8_Data[ rx_msg.length ];
                        }

                        // Call the Rx Callback to pass the data to the application, if it exists
                        if( J1939_stack_2_rx_msg_table[ u32_i ].rx_callback != NULL )
                        {
                            J1939_stack_2_rx_msg_table[ u32_i ].rx_callback( J1939_STACK_2, &rx_msg );
                        }
                    }
                }
            }
            else // An error occurred
            {
                // Check to see if any failures already happened.
                // We will return only the first kind of failure to the calling function.
                if( status != CAN_OK )
                {
                    // Return a value to indicate an error occured
                    status = (CAN_STATUS_t)(C_NO_ERR - s16_error);
                }
            }
        }
    }

    return( status );
}
/* @} */

/******************************************************************************/
/*
   \fn       static uint32_t find_next_transmit_request_message( J1939_stack_t j1939_stack, uint32_t current_index )
   \brief    This is the 0xEA00 J1939 Request transmit message handler.\n
             It will allow the application to update the request message data\n
             before the J1939 message is sent.
   \param    J1939_stack_t j1939_stack: The J1939 stack that this message will\n
             be transmitted on.
   \param    uint32_t current_index: The current index of the table to start looking.
   \ingroup  CAN
   \return   The next entry in the request table, and if there are none, returns the\n
             current entry.
   \retval   uint32_t

    @{
*/
/******************************************************************************/
static uint32_t find_next_transmit_request_message( J1939_stack_t j1939_stack, uint32_t current_index )
{
    uint32_t u32_next_entry;

    // Search through the table to find the next transmit request message
    u32_next_entry = current_index;

    switch( j1939_stack )
    {
        case J1939_STACK_1:
            do
            {
                // Incremenet to the next element in the table,
                // wrapping back to the first entry if we exceed the maximum
                u32_next_entry++;
                u32_next_entry %= NUM_J1939_STACK_1_TX_MESSAGES;

                if( !J1939_stack_1_transmit_request_msg_table[ u32_next_entry ].data_obtained )
                {
                    // We found the next entry.
                    // Set the index to this entry
                    current_index = u32_next_entry;
                }
            } while( current_index != u32_next_entry );
            break;

        case J1939_STACK_2:
            do
            {
                // Incremenet to the next element in the table,
                // wrapping back to the first entry if we exceed the maximum
                u32_next_entry++;
                u32_next_entry %= NUM_J1939_STACK_2_TX_MESSAGES;

                if( !J1939_stack_2_transmit_request_msg_table[ u32_next_entry ].data_obtained )
                {
                    // We found the next entry.
                    // Set the index to this entry
                    current_index = u32_next_entry;
                }
            } while( current_index != u32_next_entry );
            break;

        default:
            // Do nothing
            break;
    }

    return( u32_next_entry );
}
/* @} */

/******************************************************************************/
/*
   \fn       static void update_EA00_tx_request_msg( J1939_stack_t j1939_stack, J1939_tx_message_t * message )
   \brief    This updates the 0xEA00 J1939 Transmit Request message for the specified\n
             message.
   \param    J1939_stack_t j1939_stack: The J1939 stack that this message will\n
             be transmitted on.
   \param    J1939_tx_message_t * message: A pointer to the message that will\n
             be transmitted.
   \ingroup  CAN
   \return   None.

    @{
*/
/******************************************************************************/
static void update_EA00_tx_request_msg( J1939_stack_t j1939_stack, J1939_tx_message_t * message )
{
    uint32_t u32_next_entry;

    switch( j1939_stack )
    {
        case J1939_STACK_1:
            if( !J1939_stack_1_transmit_request_msg_table[ J1939_stack_1_transmit_request_index ].data_obtained )
            {
                // This message has not received a response.
                // Send out this PGN as a transmit request message
                message->data_buffer[0] = (uint8_t)(J1939_stack_1_tx_msg_table[ J1939_stack_1_transmit_request_index ].tx_message.message_id.PGN);
                message->data_buffer[1] = (uint8_t)(J1939_stack_1_tx_msg_table[ J1939_stack_1_transmit_request_index ].tx_message.message_id.PGN >> 8);
                message->data_buffer[2] = (uint8_t)(J1939_stack_1_tx_msg_table[ J1939_stack_1_transmit_request_index ].tx_message.message_id.PGN >> 16);
                message->length = 3;

                // Find the next entry for the next request message
                J1939_stack_1_transmit_request_index = find_next_transmit_request_message( j1939_stack, J1939_stack_1_transmit_request_index );
            }
            else
            {
                // This entry is no longer valid.
                // Find the next transmit request message
                u32_next_entry = find_next_transmit_request_message( j1939_stack, J1939_stack_1_transmit_request_index );

                // Check to see if this entry is different
                // If it is, then send out this request message
                // Otherwise, we are done
                if( u32_next_entry != J1939_stack_1_transmit_request_index )
                {
                    // Update the data buffer with this PGN transmit request
                    message->data_buffer[0] = (uint8_t)(J1939_stack_1_tx_msg_table[ u32_next_entry ].tx_message.message_id.PGN);
                    message->data_buffer[1] = (uint8_t)(J1939_stack_1_tx_msg_table[ u32_next_entry ].tx_message.message_id.PGN >> 8);
                    message->data_buffer[2] = (uint8_t)(J1939_stack_1_tx_msg_table[ u32_next_entry ].tx_message.message_id.PGN >> 16);
                    message->length = 3;

                    // Set the current entry to the next entry
                    J1939_stack_1_transmit_request_index = u32_next_entry;
                }
                else // The indices are the same
                {
                    // This must mean that we searched all the way through the table,
                    // and ended up at the same staring point.
                    // We can stop transmiting request messages.

                    // Transmit out a request of [ 0xFF 0xFF 0xFF ]
                    message->data_buffer[0] = 0xFF;
                    message->data_buffer[1] = 0xFF;
                    message->data_buffer[2] = 0xFF;
                    message->length = 3;

                    // Update the request message period to 0
                    // message->period = 0;
                }
            }
            break;

        case J1939_STACK_2:
            if( !J1939_stack_2_transmit_request_msg_table[ J1939_stack_2_transmit_request_index ].data_obtained )
            {
                // This message has not received a response.
                // Send out this PGN as a transmit request message
                message->data_buffer[0] = (uint8_t)(J1939_stack_2_tx_msg_table[ J1939_stack_2_transmit_request_index ].tx_message.message_id.PGN);
                message->data_buffer[1] = (uint8_t)(J1939_stack_2_tx_msg_table[ J1939_stack_2_transmit_request_index ].tx_message.message_id.PGN >> 8);
                message->data_buffer[2] = (uint8_t)(J1939_stack_2_tx_msg_table[ J1939_stack_2_transmit_request_index ].tx_message.message_id.PGN >> 16);
                message->length = 3;

                // Find the next entry for the next request message
                J1939_stack_2_transmit_request_index = find_next_transmit_request_message( j1939_stack, J1939_stack_2_transmit_request_index );
            }
            else
            {
                // This entry is no longer valid.
                // Find the next transmit request message
                u32_next_entry = find_next_transmit_request_message( j1939_stack, J1939_stack_2_transmit_request_index );

                // Check to see if this entry is different
                // If it is, then send out this request message
                // Otherwise, we are done
                if( u32_next_entry != J1939_stack_2_transmit_request_index )
                {
                    // Update the data buffer with this PGN transmit request
                    message->data_buffer[0] = (uint8_t)(J1939_stack_2_tx_msg_table[ u32_next_entry ].tx_message.message_id.PGN);
                    message->data_buffer[1] = (uint8_t)(J1939_stack_2_tx_msg_table[ u32_next_entry ].tx_message.message_id.PGN >> 8);
                    message->data_buffer[2] = (uint8_t)(J1939_stack_2_tx_msg_table[ u32_next_entry ].tx_message.message_id.PGN >> 16);
                    message->length = 3;

                    // Set the current entry to the next entry
                    J1939_stack_2_transmit_request_index = u32_next_entry;
                }
                else // The indices are the same
                {
                    // This must mean that we searched all the way through the table,
                    // and ended up at the same staring point.
                    // We can stop transmiting request messages.

                    // Transmit out a request of [ 0xFF 0xFF 0xFF ]
                    message->data_buffer[0] = 0xFF;
                    message->data_buffer[1] = 0xFF;
                    message->data_buffer[2] = 0xFF;
                    message->length = 3;

                    // Update the request message period to 0
                    message->period = 0;
                }
            }
            break;

        default:
            // Do nothing
            break;
    }
}
/* @} */

/******************************************************************************/
/*
   \fn       CAN_STATUS_t send_J1939_messages_3CS( void )
   \brief    Sends the J1939 corresponding to the supplied Tx message index.
   \param    void.
   \ingroup  sendCAN
   \return   The CAN status, as defined in enumerate CAN_STATUS_t.

    @{
*/
/******************************************************************************/
CAN_STATUS_t send_J1939_messages_3CS( void )
{
    CAN_STATUS_t status = CAN_OK; // Assume no errors occurred
    T_x_can_msg tx_msg;
    uint8_t u8_i;
    uint8_t u8_length;
    int16_t s16_error;
    uint32_t u32_i;

    // Loop through the whole message list on J1939 stack 1
    for( u32_i = 0; u32_i < NUM_J1939_STACK_1_TX_MESSAGES; u32_i++ )
    {
        // Only transmit messages that are periodic.
        // Messages that have a period of 0 are skipped.
        if( J1939_stack_1_tx_msg_table[ u32_i ].tx_message.period != 0 )
        {
            // Increment the amount of time that has passed
            J1939_stack_1_tx_time_ms[ u32_i ] += MAIN_CONTROLLOOP_TIME_INTERVAL;

            // Check to see if it's time to transmit this message
            if( J1939_stack_1_tx_time_ms[ u32_i ] >= J1939_stack_1_tx_msg_table[ u32_i ].tx_message.period )
            {
                // Reset Tx time to zero
                J1939_stack_1_tx_time_ms[ u32_i ] = 0;

                // Check to see if this table entry is a J1939 Transmit Request message.
                // If the tx_update_handler of this object is not NULL, then this is a transmit
                // request message.
                if( J1939_stack_1_transmit_request_msg_table[ u32_i ].tx_update_handler != NULL )
                {
                    // Update the data for the J1939 Transmit Request message
                    J1939_stack_1_transmit_request_msg_table[ u32_i ].tx_update_handler( J1939_STACK_1, &J1939_stack_1_tx_msg_table[ u32_i ].tx_message );
                }

                // Call the J1939 Tx message update handler, if it exists, so the user application
                // can update the data buffer
                if( J1939_stack_1_tx_msg_table[ u32_i ].tx_update_handler != NULL )
                {
                    J1939_stack_1_tx_msg_table[ u32_i ].tx_update_handler( J1939_STACK_1, &J1939_stack_1_tx_msg_table[ u32_i ].tx_message );
                }

                // Check to make sure that the J1939 Tx message length does not exceed
                // the maximum buffer length
                if( J1939_stack_1_tx_msg_table[ u32_i ].tx_message.length > sizeof(tx_msg.au8_Data) )
                {
                    u8_length = sizeof(tx_msg.au8_Data);
                }
                else
                {
                    u8_length = J1939_stack_1_tx_msg_table[ u32_i ].tx_message.length;
                }

                // Populate the information in the Tx message list
                tx_msg.t_Id.u32_Id = J1939_MSG_ID(
                    J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.priority,
                    J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.data_page,
                    J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.PGN,
                    J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.destination_address,
                    J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.source_address
                );
                tx_msg.t_Id.u8_Xtd = TRUE;
                tx_msg.u8_Dlc = u8_length;
                for( u8_i = 0; u8_i < u8_length; u8_i++ )
                {
                    tx_msg.au8_Data[ u8_i ] = J1939_stack_1_tx_msg_table[ u32_i ].tx_message.data_buffer[ u8_i ];
                }
                tx_msg.u32_Time = x_sys_get_time_ms( );

                // Send the Tx message
                s16_error = x_can_obj_send_msg( J1939_stack_1_tx_message_obj[ u32_i ].pv_can_handle, &tx_msg );
                if( s16_error != C_NO_ERR )
                {
                    status = (CAN_STATUS_t)(C_NO_ERR - s16_error);
                }
            }
        }
    }

    // Loop through the whole message list on J1939 stack 2
    for( u32_i = 0; u32_i < NUM_J1939_STACK_2_TX_MESSAGES; u32_i++ )
    {
        // Only transmit messages that are periodic.
        // Messages that have a period of 0 are skipped.
        if( J1939_stack_2_tx_msg_table[ u32_i ].tx_message.period != 0 )
        {
            // Increment the amount of time that has passed
            J1939_stack_2_tx_time_ms[ u32_i ] += MAIN_CONTROLLOOP_TIME_INTERVAL;

            // Check to see if it's time to transmit this message
            if( J1939_stack_2_tx_time_ms[ u32_i ] >= J1939_stack_2_tx_msg_table[ u32_i ].tx_message.period )
            {
                // Reset Tx time to zero
                J1939_stack_2_tx_time_ms[ u32_i ] = 0;

                // Check to see if this table entry is a J1939 Transmit Request message.
                // If the tx_update_handler of this object is not NULL, then this is a transmit
                // request message.
                if( J1939_stack_2_transmit_request_msg_table[ u32_i ].tx_update_handler != NULL )
                {
                    // Update the data for the J1939 Transmit Request message
                    J1939_stack_2_transmit_request_msg_table[ u32_i ].tx_update_handler( J1939_STACK_2, &J1939_stack_2_tx_msg_table[ u32_i ].tx_message );
                }

                // Call the J1939 Tx message update handler, if it exists, so the user application
                // can update the data buffer
                if( J1939_stack_2_tx_msg_table[ u32_i ].tx_update_handler != NULL )
                {
                    J1939_stack_2_tx_msg_table[ u32_i ].tx_update_handler( J1939_STACK_2, &J1939_stack_2_tx_msg_table[ u32_i ].tx_message );
                }

                // Check to make sure that the J1939 Tx message length does not exceed
                // the maximum buffer length
                if( J1939_stack_2_tx_msg_table[ u32_i ].tx_message.length > sizeof(tx_msg.au8_Data) )
                {
                    u8_length = sizeof(tx_msg.au8_Data);
                }
                else
                {
                    u8_length = J1939_stack_2_tx_msg_table[ u32_i ].tx_message.length;
                }

                // Populate the information in the Tx message list
                tx_msg.t_Id.u32_Id = J1939_MSG_ID(
                    J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.priority,
                    J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.data_page,
                    J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.PGN,
                    J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.destination_address,
                    J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.source_address
                );
                tx_msg.t_Id.u8_Xtd = TRUE;
                tx_msg.u8_Dlc = u8_length;
                for( u8_i = 0; u8_i < u8_length; u8_i++ )
                {
                    tx_msg.au8_Data[ u8_i ] = J1939_stack_2_tx_msg_table[ u32_i ].tx_message.data_buffer[ u8_i ];
                }
                tx_msg.u32_Time = x_sys_get_time_ms( );

                // Send the Tx message
                s16_error = x_can_obj_send_msg( J1939_stack_2_tx_message_obj[ u32_i ].pv_can_handle, &tx_msg );
                if( s16_error != C_NO_ERR )
                {
                    status = (CAN_STATUS_t)(C_NO_ERR - s16_error);
                }
            }
        }
    }

    return( status );
}
/* @} */

/******************************************************************************/
/*
   \fn       boolean update_j1939_tx_request_message_state_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address, boolean data_obtained )
   \brief    This function searches the J1939 Tx Request message table until it\n
             finds the first transmit request message that matches the PGN,\n
             destination address, and source address, and marks that message as\n
             received or not received.
   \param    J1939_stack_t j1939_stack: The J1939 stack that the J1939 Tx message is on.
   \param    uint32_t PGN: The PGN of the message to find.
   \param    uint32_t destination_address: The destination address of the message to find.
   \param    uint32_t source_address: The source address of the message to find.
   \param    boolean data_obtained: TRUE if data has been obtained, FALSE otherwise
   \ingroup  CAN
   \return   TRUE if successful, FALSE otherwise.
   \retval   boolean

    @{
*/
/******************************************************************************/
boolean update_j1939_tx_request_message_state_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address, boolean data_obtained )
{
    boolean message_found = FALSE;
    static boolean first_transmit_request_message_set[ NUM_J1939_STACKS ] = { FALSE, FALSE };
    uint32_t u32_i;

    switch( j1939_stack )
    {
        case J1939_STACK_1:
            // Search through the entire table to find the PGN that matches this rx handler
            for( u32_i = 0; (u32_i < NUM_J1939_STACK_1_TX_MESSAGES) && !message_found; u32_i++ )
            {
                if( (PGN == J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.PGN) &&
                    (destination_address == J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.destination_address) &&
                    (source_address == J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.source_address) )
                {
                    // We found a match
                    message_found = TRUE;

                    // Update the data_obtained flag
                    J1939_stack_1_transmit_request_msg_table[ u32_i ].data_obtained = data_obtained;

                    // If the first transmit request message has not yet been found,
                    // then mark the index of this message
                    if( !first_transmit_request_message_set[ j1939_stack ] )
                    {
                        J1939_stack_1_transmit_request_index = u32_i;
                        first_transmit_request_message_set[ j1939_stack ] = TRUE;
                    }
                }
            }
            break;

        case J1939_STACK_2:
            // Search through the entire table to find the PGN that matches this rx handler
            for( u32_i = 0; (u32_i < NUM_J1939_STACK_2_TX_MESSAGES) && !message_found; u32_i++ )
            {
                if( (PGN == J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.PGN) &&
                    (destination_address == J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.destination_address) &&
                    (source_address == J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.source_address) )
                {
                    // We found a match
                    message_found = TRUE;

                    // Update the data_obtained flag
                    J1939_stack_2_transmit_request_msg_table[ u32_i ].data_obtained = data_obtained;

                    // If the first transmit request message has not yet been found,
                    // then mark the index of this message
                    if( !first_transmit_request_message_set[ j1939_stack ] )
                    {
                        J1939_stack_1_transmit_request_index = u32_i;
                        first_transmit_request_message_set[ j1939_stack ] = TRUE;
                    }
                }
            }
            break;

        default:
            // Do nothing
            break;
    }

    return( message_found );
}
/* @} */

/******************************************************************************/
/*
   \fn       boolean get_j1939_tx_request_message_state_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address )
   \brief    This function searches the J1939 Tx Request message table until it\n
             finds the first transmit request message that matches the PGN,\n
             destination address, and source address, and returns whether the\n
             data has been obtained.
   \param    J1939_stack_t j1939_stack: The J1939 stack that the J1939 Tx message is on.
   \param    uint32_t PGN: The PGN of the message to find.
   \param    uint32_t destination_address: The destination address of the message to find.
   \param    uint32_t source_address: The source address of the message to find.
   \ingroup  CAN
   \return   TRUE if successful, FALSE otherwise.
   \retval   boolean

    @{
*/
/******************************************************************************/
boolean get_j1939_tx_request_message_state_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address )
{
    boolean message_found = FALSE;
    boolean data_obtained = FALSE;
    uint32_t u32_i;

    switch( j1939_stack )
    {
        case J1939_STACK_1:
            // Search through the entire table to find the PGN that matches this rx handler
            for( u32_i = 0; (u32_i < NUM_J1939_STACK_1_TX_MESSAGES) && !message_found; u32_i++ )
            {
                if( (PGN == J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.PGN) &&
                    (destination_address == J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.destination_address) &&
                    (source_address == J1939_stack_1_tx_msg_table[ u32_i ].tx_message.message_id.source_address) )
                {
                    // We found a match
                    message_found = TRUE;

                    // Get the data_obtained flag
                    data_obtained = J1939_stack_1_transmit_request_msg_table[ u32_i ].data_obtained;
                }
            }
            break;

        case J1939_STACK_2:
            // Search through the entire table to find the PGN that matches this rx handler
            for( u32_i = 0; (u32_i < NUM_J1939_STACK_2_TX_MESSAGES) && !message_found; u32_i++ )
            {
                if( (PGN == J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.PGN) &&
                    (destination_address == J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.destination_address) &&
                    (source_address == J1939_stack_2_tx_msg_table[ u32_i ].tx_message.message_id.source_address) )
                {
                    // We found a match
                    message_found = TRUE;

                    // Get the data_obtained flag
                    data_obtained = J1939_stack_2_transmit_request_msg_table[ u32_i ].data_obtained;
                }
            }
            break;

        default:
            // Do nothing
            break;
    }

    return( data_obtained );
}
/* @} */

/******************************************************************************/
/*
   \fn       J1939_tx_message_t * get_j1939_tx_message_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address )
   \brief    This function searches the J1939 Tx table until it finds the first\n
             message that matches the PGN, destination address, and source address\n
             and returns that message. If the message cannot be found, this function\n
             will instead return NULL.
   \param    J1939_stack_t j1939_stack: The J1939 stack that the J1939 Tx message is on.
   \param    uint32_t PGN: The PGN of the message to find.
   \param    uint32_t destination_address: The destination address of the message to find.
   \param    uint32_t source_address: The source address of the message to find.
   \ingroup  CAN
   \return   A pointer to the message in the table, or NULL if the message is not found.

    @{
*/
/******************************************************************************/
J1939_tx_message_t * get_j1939_tx_message_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address )
{
    J1939_tx_message_t * message = NULL; // Assume message could not be found
    boolean message_found = FALSE;
    uint32_t u32_i;

    switch( j1939_stack )
    {
        case J1939_STACK_1:
            // Loop through the table to search for the message
            for( u32_i = 0; (u32_i < NUM_J1939_STACK_1_TX_MESSAGES) && !message_found; u32_i++ )
            {
                message = &J1939_stack_1_tx_msg_table[ u32_i ].tx_message;
                if( (PGN == message->message_id.PGN) &&
                    (destination_address == message->message_id.destination_address) &&
                    (source_address == message->message_id.source_address) )
                {
                    // We found a match
                    message_found = TRUE;
                }
            }
            break;

        case J1939_STACK_2:
            // Loop through the table to search for the message
            for( u32_i = 0; (u32_i < NUM_J1939_STACK_2_TX_MESSAGES) && !message_found; u32_i++ )
            {
                message = &J1939_stack_2_tx_msg_table[ u32_i ].tx_message;
                if( (PGN == message->message_id.PGN) &&
                    (destination_address == message->message_id.destination_address) &&
                    (source_address == message->message_id.source_address) )
                {
                    // We found a match
                    message_found = TRUE;
                }
            }
            break;

        default:
            // Do nothing
            break;
    }

    if( !message_found )
    {
        // Message was not found; return NULL
        message = NULL;
    }

    return( message );
}
/* @} */

/******************************************************************************/
/*
   \fn       J1939_tx_msg_table_t * get_j1939_tx_message_table_entry_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address )
   \brief    This function searches the J1939 Tx table until it finds the first\n
             message that matches the PGN, destination address, and source address\n
             and returns that message table entry. If the message cannot be found,\n
             this function will instead return NULL.
   \param    J1939_stack_t j1939_stack: The J1939 stack that the J1939 Tx message is on.
   \param    uint32_t PGN: The PGN of the message to find.
   \param    uint32_t destination_address: The destination address of the message to find.
   \param    uint32_t source_address: The source address of the message to find.
   \ingroup  CAN
   \return   A pointer to the message table, or NULL if the message is not found.

    @{
*/
/******************************************************************************/
static J1939_tx_msg_table_t * get_j1939_tx_message_table_entry_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address )
{
    J1939_tx_msg_table_t * message = NULL; // Assume message could not be found
    boolean message_found = FALSE;
    uint32_t u32_i;

    switch( j1939_stack )
    {
        case J1939_STACK_1:
            // Loop through the table to search for the message
            for( u32_i = 0; (u32_i < NUM_J1939_STACK_1_TX_MESSAGES) && !message_found; u32_i++ )
            {
                message = &J1939_stack_1_tx_msg_table[ u32_i ];
                if( (PGN == message->tx_message.message_id.PGN) &&
                    (destination_address == message->tx_message.message_id.destination_address) &&
                    (source_address == message->tx_message.message_id.source_address) )
                {
                    // We found a match
                    message_found = TRUE;
                }
            }
            break;

        case J1939_STACK_2:
            // Loop through the table to search for the message
            for( u32_i = 0; (u32_i < NUM_J1939_STACK_2_TX_MESSAGES) && !message_found; u32_i++ )
            {
                message = &J1939_stack_2_tx_msg_table[ u32_i ];
                if( (PGN == message->tx_message.message_id.PGN) &&
                    (destination_address == message->tx_message.message_id.destination_address) &&
                    (source_address == message->tx_message.message_id.source_address) )
                {
                    // We found a match
                    message_found = TRUE;
                }
            }
            break;

        default:
            // Do nothing
            break;
    }

    if( !message_found )
    {
        // Message was not found; return NULL
        message = NULL;
    }

    return( message );
}
/* @} */

/******************************************************************************/
/*
   \fn       static J1939_stack_message_handler_obj_t * get_j1939_stack_tx_message_object_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address )
   \brief    This function searches the J1939 Tx message object table until it\n
             finds the first message that matches the PGN, destination address,\n
             and source address, and returns that message's CAN object handle.\n
             If the message cannot be found, this function will instead return NULL.
   \param    J1939_stack_t j1939_stack: The J1939 stack that the J1939 Tx message is on.
   \param    uint32_t PGN: The PGN of the message to find.
   \param    uint32_t destination_address: The destination address of the message to find.
   \param    uint32_t source_address: The source address of the message to find.
   \ingroup  CAN
   \return   A pointer to the message handle object, or NULL if the message is not found.

    @{
*/
/******************************************************************************/
static J1939_stack_message_handler_obj_t * get_j1939_stack_tx_message_object_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address )
{
    J1939_stack_message_handler_obj_t * message_handle_obj = NULL; // Assume message handle could not be found
    J1939_tx_message_t * message = NULL;
    boolean message_found = FALSE;
    uint32_t u32_i;

    switch( j1939_stack )
    {
        case J1939_STACK_1:
            // Loop through the table to search for the message
            for( u32_i = 0; (u32_i < NUM_J1939_STACK_1_TX_MESSAGES) && !message_found; u32_i++ )
            {
                message = &J1939_stack_1_tx_msg_table[ u32_i ].tx_message;
                if( (PGN == message->message_id.PGN) &&
                    (destination_address == message->message_id.destination_address) &&
                    (source_address == message->message_id.source_address) )
                {
                    // We found a match
                    message_handle_obj = &J1939_stack_1_tx_message_obj[ u32_i ];
                    message_found = TRUE;
                }
            }
            break;

        case J1939_STACK_2:
            // Loop through the table to search for the message
            for( u32_i = 0; (u32_i < NUM_J1939_STACK_2_TX_MESSAGES) && !message_found; u32_i++ )
            {
                message = &J1939_stack_2_tx_msg_table[ u32_i ].tx_message;
                if( (PGN == message->message_id.PGN) &&
                    (destination_address == message->message_id.destination_address) &&
                    (source_address == message->message_id.source_address) )
                {
                    // We found a match
                    message_handle_obj = &J1939_stack_2_tx_message_obj[ u32_i ];
                    message_found = TRUE;
                }
            }
            break;

        default:
            // Do nothing
            break;
    }

    return( message_handle_obj );
}
/* @} */

/******************************************************************************/
/*
   \fn       CAN_STATUS_t send_j1939_message_3CS( J1939_stack_t j1939_stack, J1939_tx_message_t * message )
   \brief    This function sends the J1939 Tx message immediately. This is how\n
             any on demand messages are sent. Usually the period in the J1939\n
             tables will be set to 0 when this function is used, but it is not required.
   \param    J1939_stack_t j1939_stack: The J1939 stack that the J1939 Tx message is on.
   \param    J1939_tx_message_t * message: The J1939 Tx message to send.
   \ingroup  CAN
   \return   The CAN status, as defined in enumerate CAN_STATUS_t.

    @{
*/
/******************************************************************************/
CAN_STATUS_t send_j1939_message_3CS( J1939_stack_t j1939_stack, J1939_tx_message_t * message )
{
    CAN_STATUS_t status = CAN_OK; // Assume no errors occurred
    J1939_stack_message_handler_obj_t * message_handle_obj = NULL; // Assume message handle could not be obtained
    T_x_can_msg tx_msg;
    uint8_t u8_i;
    uint8_t u8_length;
    int16_t s16_error;

    // Verify that the message was found
    if( message != NULL ) // Message found
    {
        // Get the J1939 Tx message handle object for this message
        message_handle_obj = get_j1939_stack_tx_message_object_3CS( j1939_stack,
            message->message_id.PGN,
            message->message_id.destination_address,
            message->message_id.source_address
        );

        // Ensure that we have a valid message handle object
        if( message_handle_obj != NULL ) // Message object found
        {
            // Check to make sure that the J1939 Tx message length does not exceed
            // the maximum buffer length
            if( message->length > sizeof(tx_msg.au8_Data) )
            {
                u8_length = sizeof(tx_msg.au8_Data);
            }
            else
            {
                u8_length = message->length;
            }

            // Populate the information in the Tx message list
            tx_msg.t_Id.u32_Id = J1939_MSG_ID(
                message->message_id.priority,
                message->message_id.data_page,
                message->message_id.PGN,
                message->message_id.destination_address,
                message->message_id.source_address
            );
            tx_msg.t_Id.u8_Xtd = TRUE;
            tx_msg.u8_Dlc = u8_length;
            for( u8_i = 0; u8_i < u8_length; u8_i++ )
            {
                tx_msg.au8_Data[ u8_i ] = message->data_buffer[ u8_i ];
            }
            tx_msg.u32_Time = x_sys_get_time_ms( );

            // Send the Tx message
            s16_error = x_can_obj_send_msg( message_handle_obj->pv_can_handle, &tx_msg );
            if( s16_error != C_NO_ERR )
            {
                status = (CAN_STATUS_t)(C_NO_ERR - s16_error);
            }
        }
        else // Message handle object not found
        {
            // Return a configuration error, as either the table is not correct
            // or the supplied parameters are not correct.
            status = CONFIGURATION;
        }
    }
    else // Message not found
    {
        // Return a configuration error, as either the table is not correct
        // or the supplied parameters are not correct.
        status = CONFIGURATION;
    }

    return( status );
}
/* @} */

/******************************************************************************/
/*
   \fn       CAN_STATUS_t search_and_send_j1939_message_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address )
   \brief    This function searches through the J1939 table, and if a match is found\n
             sends the J1939 Tx message immediately. This is how any on demand\n
             messages are sent. Usually the period in the J1939 tables will be\n
             set to 0 when this function is used, but it is not required.
   \param    J1939_stack_t j1939_stack: The J1939 stack that the J1939 Tx message is on.
   \param    uint32_t PGN: The PGN of the message to find.
   \param    uint32_t destination_address: The destination address of the message to find.
   \param    uint32_t source_address: The source address of the message to find.
   \ingroup  CAN
   \return   The CAN status, as defined in enumerate CAN_STATUS_t.

    @{
*/
/******************************************************************************/
CAN_STATUS_t search_and_send_j1939_message_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address )
{
    CAN_STATUS_t status = CAN_OK; // Assume no errors occurred
    J1939_stack_message_handler_obj_t * message_handle_obj;
    J1939_tx_msg_table_t * message_table_entry;
    T_x_can_msg tx_msg;
    uint8_t u8_i;
    uint8_t u8_length;
    int16_t s16_error;

    // Get the J1939 Tx message handle object for this PGN/Destination Address/Source Address
    message_handle_obj = get_j1939_stack_tx_message_object_3CS( j1939_stack, PGN, destination_address, source_address );

    // Get the table entry matching this PGN/Destination Address/Source Address
    message_table_entry = get_j1939_tx_message_table_entry_3CS( j1939_stack, PGN, destination_address, source_address );

    // Ensure that we have a valid message handle object & table entry
    if( (message_handle_obj != NULL) && (message_table_entry != NULL) ) // Handle object & table entry both valid
    {
        // Call the J1939 Tx message update handler, if it exists, so the user application
        // can update the data buffer
        if( message_table_entry->tx_update_handler != NULL )
        {
            message_table_entry->tx_update_handler( j1939_stack, &message_table_entry->tx_message );
        }

        // Check to make sure that the J1939 Tx message length does not exceed
        // the maximum buffer length
        if( message_table_entry->tx_message.length > sizeof(tx_msg.au8_Data) )
        {
            u8_length = sizeof(tx_msg.au8_Data);
        }
        else
        {
            u8_length = message_table_entry->tx_message.length;
        }

        // Populate the information in the Tx message list
        tx_msg.t_Id.u32_Id = J1939_MSG_ID(
            message_table_entry->tx_message.message_id.priority,
            message_table_entry->tx_message.message_id.data_page,
            message_table_entry->tx_message.message_id.PGN,
            message_table_entry->tx_message.message_id.destination_address,
            message_table_entry->tx_message.message_id.source_address
        );
        tx_msg.t_Id.u8_Xtd = TRUE;
        tx_msg.u8_Dlc = u8_length;
        for( u8_i = 0; u8_i < u8_length; u8_i++ )
        {
            tx_msg.au8_Data[ u8_i ] = message_table_entry->tx_message.data_buffer[ u8_i ];
        }
        tx_msg.u32_Time = x_sys_get_time_ms( );

        // Send the Tx message
        s16_error = x_can_obj_send_msg( message_handle_obj->pv_can_handle, &tx_msg );
        if( s16_error != C_NO_ERR )
        {
            status = (CAN_STATUS_t)(C_NO_ERR - s16_error);
        }
    }
    else // Message handle object or table entry not found
    {
        // Return a configuration error, as either the table is not correct
        // or the supplied parameters are not correct.
        status = CONFIGURATION;
    }

    return( status );
}
/* @} */

#endif // defined( CONTROLLER_3CS )
