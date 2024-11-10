/******************************************************************************/
/*!
    \file
        can_j1939.h

    \brief
        File to perform CAN messaging\n
        CAN modules including CAN in and out functions, and message layouts.

    \copyright
        Copyright (C) 2023  MacDon Inustries Ltd.  All Rights Reserved.
        License     use only under terms of contract / confidential\n

   \ingroup   can

    History:

    Date (YYYY/MM/DD) |   Author      |   Changes
    ------------------|---------------|----------------
    2023/03/31        | Ivan Ciric    | File branched from project 278 (ETDK) to create ISOBUS template project.
*/
/******************************************************************************/

#ifndef __CAN_J1939_H__
#define __CAN_J1939_H__

/*******************************************************************************
  INCLUDE
*******************************************************************************/
// include platform configuration
#include "platform_config.h"
#include "can_j1939.h"

/*******************************************************************************
  DEFINES
*******************************************************************************/
//define each message ID and DLC
//put every parameter in hex format 0xHH
//pri->priority, mostly 0x6
//dp->data page, mostly is 0x0, then PGN range 0x0000~0xEF00. Rarely is 0x1 in which if more than 0xFFFF number of message required.
//destAddr->destination address, only PGN 0x0000~0xEF00 need destination address
//srAddr->source address, every PGN has a source address

/*!
    \brief      CAN message structure definition
    \ingroup    can
    \defgroup   canStruc CAN message structure
    @{
*/
#define DP0                           (0x0)   //there are two data page DP=0 or DP=1. DP0 is mostly used.
#define DP1                           (0x1)
#define J1939_MSG_NORMAL_PRIORITY     (0x6)
#define J1939_MSG_2ND_PRIORITY        (0x2)
#define J1939_MSG_NORMAL_PG_SIZE      (0x8)

#define J1939_DEFAULT_BITRATE         (250 * 1000U)

#define J1939_NULL_ADDRESS            (0xFE)         // J1939 null address
#define J1939_BROADCAST_ADDRESS       (0xFF)         // J1939 broadcast address

#define J1939_RX_MSG_DATA_SIZE        (8)            // J1939 Rx message data size, in bytes
#define J1939_TX_MSG_DATA_SIZE        (8)            // J1939 Tx message data size, in bytes

/*! @} */

/*******************************************************************************
  MACROS
*******************************************************************************/
// for universal ID macro J1939_MSG_ID(priority, data page, PGN, destination address, source address)
// every PGN should has a source address. If the message is broadcasting, make
// destination address=0x00, but be aware of that 0x00 is not a destination
// address in broadcasting.
#define J1939_MSG_ID( pri, dp, pgn, destAddr, srAddr )    ( \
    ( (pri) << 26 ) | ( (dp) << 24 ) | (( (pgn) | (( (pgn) < 0xF000 )? (destAddr) : 0x00)) << 8) | (srAddr) \
)

/*******************************************************************************
  ENUMS
*******************************************************************************/
/*!
    \brief      This is the CAN status enumerate.\n
                This defines the different status options from receive_J1939_messages() and\n
                send_J1939_messages().\n
                The values of these errors will depend on the hardware configuration.
    \ingroup    can
    @{
 */
typedef enum
{
    CAN_OK = 0,

#if defined( CONTROLLER_3CS )
    // The following is a list of errors tied to the STW 3CS
    UNKNOWN_ERROR,
    WARNING,
    DEFAULT,
    BUSY,
    RANGE,
    OVERFLOW,
    READ_WRITE,
    NO_ACTION_REQUIRED,
    COMMUNICATION,
    CONFIGURATION,
    CHECKSUM,
    TIMEOUT,
    IN_PROGRESS,
#else
    CAN_ERROR,
#endif // defined

    NUM_CAN_STATUS
} CAN_STATUS_t;
/*! @} */

/*!
    \brief      This is the J1939 Stack enumerate.\n
                This lists all of the J1939 Stacks available. Each stack corresponds to\n
                a particular CAN bus (ex. stack 1 corresponds to CAN 1, etc.).
                The amount of J1939 stacks available depends on the hardware configuration.
    \ingroup    can
    @{
 */
typedef enum
{
    J1939_STACK_1 = 0,

    #if( X_CAN_CH_MAX > 1 )
        J1939_STACK_2,
    #endif

    #if( X_CAN_CH_MAX > 2 )
        J1939_STACK_3,
    #endif

    #if( X_CAN_CH_MAX > 3 )
        J1939_STACK_4,
    #endif

    NUM_J1939_STACKS
} J1939_stack_t;
/*! @} */

/*!
    \brief      This is the J1939 Message Type enumerate.\n
                This lists all of the options available to lock a specific type of\n
                J1939 Message. Available options are:\n
                  - Rx Messages\n
                  - Tx Messages\n
                  - Rx and Tx Messages\n
    \ingroup    can
    @{
 */
typedef enum
{
    RX_MESSAGES = 0,
    TX_MESSAGES,
    RX_AND_TX_MESSAGES,

    NUM_LOCK_MESSAGES
} j1939_message_t;
/*! @} */

/*******************************************************************************
  STRUCTS
*******************************************************************************/
/*!
    \brief      This is J1939 Message ID structure.\n
                This structure is used to define each J1939 Message ID with the following parameters:\n
                    - PGN: The PGN of the message.\n
                    - destination_address: The destination address of the message.\n
                    - source_address: The source address of the message.\n
                    - priority: The J1939 priority of the message.
    \ingroup    can
    @{
 */
typedef struct
{
    uint32_t               PGN;
    uint8_t                destination_address;
    uint8_t                source_address;
    uint8_t                priority;
    uint8_t                data_page;
} J1939_message_id_t;
/*! @} */

/*!
    \brief      This is J1939 Tx Message structure.\n
                This structure is used to define each J1939 Tx Message with the following parameters:\n
                    - data_buffer[]: This buffer stores the data that needs to be transmitted.\n
                    - message_id: The J1939_message_id_t message ID.\n
                    - length: The length of the data.
                    - period: The period that this message is transmitted, in ms.
    \ingroup    can
    @{
 */
typedef struct
{
    J1939_message_id_t     message_id;
    uint8_t                data_buffer[ J1939_TX_MSG_DATA_SIZE ];
    uint8_t                length;
    uint32_t               period;
} J1939_tx_message_t;
/*! @} */

/*!
    \brief      This is J1939 Tx Message Table structure.\n
                This structure is used to define each message in the J1939 Tx Message table with the following parameters:\n
                    - tx_message: The Tx message object. See structure J1939_tx_message_t.
                    - tx_callback: The function to call before sending the J1939 data This allows the application to update the buffer.
    \ingroup    can
    @{
 */
typedef void (* J1939_tx_callback_ptr) ( J1939_stack_t j1939_stack, J1939_tx_message_t * );
typedef struct
{
    J1939_tx_message_t     tx_message;
    J1939_tx_callback_ptr  tx_update_handler;
} J1939_tx_msg_table_t;
/*! @} */

/*!
    \brief      This is J1939 Rx Message structure.\n
                This structure is used to define each J1939 Rx Message with the following parameters:\n
                    - data_buffer[]: This buffer stores the data that is received.\n
                    - message_id: The J1939_message_id_t message ID.\n
                    - length: The length of the data.
    \ingroup    can
    @{
 */
typedef struct
{
    J1939_message_id_t     message_id;
    uint8_t                data_buffer[ J1939_RX_MSG_DATA_SIZE ];
    uint8_t                length;
} J1939_rx_message_t;
/*! @} */

/*!
    \brief      This is J1939 Rx Message Table structure.\n
                This structure is used to define each message in the J1939 Rx Message table with the following parameters:\n
                    - message_id: The J1939 message ID of the received message. See structure J1939_message_id_t.\n
                    - rx_callback: The function to call to send the data to the application.
    \ingroup    can
    @{
 */
typedef void (* J1939_rx_callback_ptr) ( J1939_stack_t j1939_stack, J1939_rx_message_t * );
typedef struct
{
    J1939_message_id_t     message_id;
    J1939_rx_callback_ptr  rx_callback;
} J1939_rx_msg_table_t;
/*! @} */

/*******************************************************************************
  CONSTANTS
*******************************************************************************/

/*******************************************************************************
  EXTERNS
*******************************************************************************/

/*******************************************************************************
  PROTOTYPES
*******************************************************************************/
/*!
    \brief      Initialize CAN BUS and messages
    \ingroup    can
    \defgroup   initCAN CAN initialization
    @{
*/
int16_t initialize_CAN( void );
/*! @} */

/*!
    \brief      Locks or unlocks the CAN messages, in order to prevent them
                from being transmitted or received.
    \ingroup    can
    \defgroup   lockCAN CAN Lock
    @{
*/
int16_t J1939_lock_message( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address, j1939_message_t type, boolean lock );
int16_t J1939_lock_all_messages( J1939_stack_t j1939_stack, j1939_message_t type, boolean lock );
/*! @} */

/*!
    \brief      Receiving or sending CAN messages
    \ingroup    can
    \defgroup   transceiver CAN receiving / sending
    @{
*/
CAN_STATUS_t receive_J1939_messages( void );
CAN_STATUS_t send_J1939_messages( void );
CAN_STATUS_t send_j1939_message( J1939_stack_t j1939_stack, J1939_tx_message_t * message );
CAN_STATUS_t search_and_send_j1939_message( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address );
/*! @} */

/*!
    \brief      Retrieving a specific J1939 Tx message
    \ingroup    can
    \defgroup   CAN J1939 Messages
    @{
*/
J1939_tx_message_t * get_j1939_tx_message( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address );
/*! @} */

/*!
    \brief      Populating CAN message before sending
    \ingroup    can
    \defgroup   populate Populating CAN message
    @{
*/
boolean populate_J1939_tx_message( J1939_tx_message_t * message, const uint8_t u8_start_bit, const uint8_t u8_bit_length, const uint64_t u64_data );
/*! @} */

/*!
    \brief      Extracting CAN message after receiving
    \ingroup    can
    \defgroup   extract Extracting CAN message
    @{
*/
boolean extract_J1939_rx_message( const J1939_rx_message_t * message, const uint8_t u8_start_bit, const uint8_t u8_bit_length, uint64_t * u64_data );
/*! @} */

/*!
    \brief      Gets/Sets the J1939 Tx Request Message's data obtained flag on the 3CS
    \ingroup    can
    \defgroup   CAN J1939 Messages
    @{
*/
boolean get_j1939_tx_request_message_state( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address );
boolean update_j1939_tx_request_message_state( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address, boolean data_obtained );
/*! @} */

/*!
    \brief      Sets a filter of one or more J1939 message
    \ingroup    can
    \defgroup   CAN J1939 Messages
    @{
*/
int16_t J1939_filter_message( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address, j1939_message_t type, uint32_t mask );
/*! @} */

#endif  //__CAN_J1939_H__

