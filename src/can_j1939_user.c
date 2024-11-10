/******************************************************************************/
/*!
    \file
        can_j1939_user.c

    \defgroup
        can CAN

    \brief
        Application-specific file to define each Rx and Tx CAN message.

    \ingroup
        can

    \copyright
        Copyright (C) 2023  MacDon Inustries Ltd.  All Rights Reserved.
        License   use only under terms of contract / confidential\n

    History:

    Date (YYYY/MM/DD) |   Author      |   Changes
    ------------------|---------------|----------------
    2023/03/31        | Ivan Ciric    | File Created
*/
/******************************************************************************/

/*******************************************************************************
  INCLUDE
*******************************************************************************/
// include platform configuration
#include "platform_config.h"

#include "can_j1939.h"
#include "can_j1939_user.h"
#include "j1939_pgn_CCVS.h"
#include "general.h"
#include "j1939_user_parameters.h"
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

/*******************************************************************************
  EXTERNS
*******************************************************************************/

/*******************************************************************************
  PROTOTYPES
*******************************************************************************/
static void f001_tx_msg_update_handler( J1939_stack_t j1939_stack, J1939_tx_message_t * message );
static void f002_rx_msg_handler( J1939_stack_t j1939_stack, J1939_rx_message_t * message );

/*******************************************************************************
  J1939 TABLES
*******************************************************************************/
/*!
    \brief      The J1939 Stack 1 Transmit message table.\n
                The user can declare each J1939 Tx message that is used on CAN 1 by adding\n
                each entry into the J1939_stack_1_tx_msg_table.
    \ingroup    can
    @{
 */
J1939_tx_msg_table_t J1939_stack_1_tx_msg_table[ ] =
{
    /*{ { PGN,     destination_address,      source_address, priority, data_page },  { data_buffer,     }, length, period }, tx_update_handler           },*/

};

static_assert(
    ( sizeof(J1939_stack_1_tx_msg_table) / sizeof(J1939_tx_msg_table_t) ) == NUM_J1939_STACK_1_TX_MESSAGES,
    "Size of J1939_stack_1_tx_msg_table[] does not match NUM_J1939_STACK_1_TX_MESSAGES. \
     Update this define in can_j1939_user.h"
);
/*! @} */

/*!
    \brief      The J1939 Stack 2 Transmit message table.\n
                The user can declare each J1939 Tx message that is used on CAN 2 by adding\n
                each entry into the J1939_stack_2_tx_msg_table.
    \ingroup    can
    @{
 */
J1939_tx_msg_table_t J1939_stack_2_tx_msg_table[ ] =
{
    /*{ { PGN,     destination_address,      source_address, priority, data_page },  { data_buffer,                                   }, length, period }, tx_update_handler           },*/
    { { { 0xF001,  J1939_BROADCAST_ADDRESS,  0xFF,           6,        DP0       },  { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }, 8,      100    }, f001_tx_msg_update_handler  },

};

static_assert(
    ( sizeof(J1939_stack_2_tx_msg_table) / sizeof(J1939_tx_msg_table_t) ) == NUM_J1939_STACK_2_TX_MESSAGES,
    "Size of J1939_stack_2_tx_msg_table[] does not match NUM_J1939_STACK_2_TX_MESSAGES. \
     Update this define in can_j1939_user.h"
);
/*! @} */

/*!
    \brief      The J1939 Stack 1 Receive message table.\n
                The user can declare each J1939 Rx function that is received on CAN 1.\n
                This table filters each received message by its PGN, and the first\n
                match it will call the declared function.
    \ingroup    can
    @{
 */
J1939_rx_msg_table_t J1939_stack_1_rx_msg_table[ ] =
{
  /*{ { PGN,     destination_address,      source_address, priority, data_page },  rx_callback          },*/
    { { 0xF002,  J1939_BROADCAST_ADDRESS,  0xFF,           6,        DP0       },  f002_rx_msg_handler  },
};

static_assert(
    ( sizeof(J1939_stack_1_rx_msg_table) / sizeof(J1939_rx_msg_table_t) ) == NUM_J1939_STACK_1_RX_MESSAGES,
    "Size of J1939_stack_1_rx_msg_table[] does not match NUM_J1939_STACK_1_RX_MESSAGES. \
     Update this define in can_j1939_user.h"
);
/*! @} */

/*!
    \brief      The J1939 Stack 2 Receive message table.\n
                The user can declare each J1939 Rx function that is received on CAN 2.\n
                This table filters each received message by its PGN, and the first\n
                match it will call the declared function.
    \ingroup    can
    @{
 */
J1939_rx_msg_table_t J1939_stack_2_rx_msg_table[ ] =
{
  /*{ { PGN,     destination_address,      source_address, priority, data_page },  rx_callback          },*/
    { { 0xF002,  J1939_BROADCAST_ADDRESS,  0xFF,           6,        DP0       },  f002_rx_msg_handler  },
};

static_assert(
    ( sizeof(J1939_stack_2_rx_msg_table) / sizeof(J1939_rx_msg_table_t) ) == NUM_J1939_STACK_2_RX_MESSAGES,
    "Size of J1939_stack_2_rx_msg_table[] does not match NUM_J1939_STACK_2_RX_MESSAGES. \
     Update this define in can_j1939_user.h"
);
/*! @} */

/*******************************************************************************
  FUNCTIONS
*******************************************************************************/

/******************************************************************************/
/*!
   \fn       int16_t initialize_CAN_user( void )
   \brief    Application-specific CAN initialization implementation.
   \param    None.
   \ingroup  initCAN
   \return   error code from stwerrors.h
   \retval   int16_t

    @{
*/
/******************************************************************************/
int16_t initialize_CAN_user( void )
{
    int16_t s16_error = C_NO_ERR;

    //--- Add application specific initialization here ---
    //--- Return C_NO_ERR if no errors, or error code from stwerrors.h ---

    return( s16_error );
}

/******************************************************************************/
/*!
   \fn       static void f001_tx_msg_update_handler( J1939_stack_t j1939_stack, J1939_tx_message_t * message )
   \brief    This is the 0xF001 transmit message handler. It will allow the\n
             application to update the data before the J1939 message is sent.
   \param    J1939_stack_t j1939_stack: The J1939 stack that this message will\n
             be transmitted on.
   \param    J1939_tx_message_t * message: A pointer to the message that will\n
             be transmitted.
   \ingroup  CAN
   \return   None.

    @{
*/
/******************************************************************************/
static void f001_tx_msg_update_handler( J1939_stack_t j1939_stack, J1939_tx_message_t * message )
{
    boolean success;
    uint32_t spn_u32_sample_tx_param = get_spn_u32_sample_tx_parameter( );

    switch( j1939_stack )
    {

        case J1939_STACK_2:
            // Populate the SPN into the Tx buffer
            success = populate_J1939_tx_message( message, 0, 32, spn_u32_sample_tx_param );
            if( !success )
            {
                // Handle any errors populating the message here
            }
            break;

        default:
            // Do nothing
            break;
    }
}
/*! @} */

/******************************************************************************/
/*!
   \fn       static void f002_rx_msg_handler( J1939_stack_t j1939_stack, J1939_rx_message_t * message )
   \brief    This is the 0xF002 receive message handler. It will process the\n
             received message.
   \param    J1939_stack_t j1939_stack: The J1939 stack that this message was received on.
   \param    J1939_rx_message_t * message: A pointer to the received message.
   \ingroup  CAN
   \return   None.

    @{
*/
/******************************************************************************/
static void f002_rx_msg_handler( J1939_stack_t j1939_stack, J1939_rx_message_t * message )
{
    uint64_t u64_data = 0;
    boolean success;

    switch( j1939_stack )
    {
        case J1939_STACK_1:
                // Filter received message by PGN
                switch( message->message_id.PGN )
                {
                    default:
                        // Extract the data
                        success = extract_J1939_rx_message( message, 0, 16, &u64_data );
                        if( success )
                        {
                            // Store the received parameter
                            set_spn_u32_sample_rx_parameter( (uint32_t)u64_data );
                        }
                        else
                        {
                            // Handle any errors populating the message here
                        }
                        break;
                }
                break;
        case J1939_STACK_2:
            // Filter received message by PGN
            switch( message->message_id.PGN )
            {
                default:
                    // Extract the data
                    success = extract_J1939_rx_message( message, 0, 32, &u64_data );
                    if( success )
                    {
                        // Store the received parameter
                        set_spn_u32_sample_rx_parameter( (uint32_t)u64_data );
                    }
                    else
                    {
                        // Handle any errors populating the message here
                    }
                    break;
            }
            break;

        default:
            // Do nothing
            break;
    }
}
