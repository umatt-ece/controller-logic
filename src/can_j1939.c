/******************************************************************************/
/*!
    \file
        can_j1939.c

    \defgroup
        can CAN

    \brief
        File to perform CAN messaging\n
        CAN modules including CAN in and out functions, and message layouts.

    \ingroup
        can

    \copyright
        Copyright (C) 2023  MacDon Inustries Ltd.  All Rights Reserved.
        License   use only under terms of contract / confidential\n

    History:

    Date (YYYY/MM/DD) |   Author      |   Changes
    ------------------|---------------|----------------
    2023/03/30        | Ivan Ciric    | File Created
*/
/******************************************************************************/
/*
- Important for RX message objects and gateway objects:
The order of the message object initialization defines the arbitration order of incoming message filtering of a CAN bus.
When a CAN bus receives a message it checks the filter of all RX message objects in the order of their initialization.
The message object whose filter fits the incoming message ID first will get the message,
the following RX objects won't get the message even if a RX filter fits.
- Hardware buffers are dedicated memory for use with CAN objects. They cannot be used for anything else and so should be used first.
I believe they are also the faster option since they are dedicated, however I have never seen a measurable difference between the two.
- Software buffers are just allocated RAM from the system RAM.
*/

/*******************************************************************************
  INCLUDE
*******************************************************************************/
#include <string.h>


// include platform configuration
#include "platform_config.h"

#include "can_j1939.h"
#include "can_j1939_user.h"
#include "general.h"

#if defined( CONTROLLER_3CS )
    #include "can_j1939_3CS.h"
#endif // defined

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

/*******************************************************************************
  FUNCTIONS
*******************************************************************************/

/******************************************************************************/
/*!
   \fn       int16_t initialize_CAN( void )
   \brief    All CAN BUS are initialized (250kbps).\n
             All Tx and Rx CAN messages are initialized used for sending data as well as receiving message\n
   \param    None.
   \ingroup  initCAN
   \return   error code from x_can_bus_init

    @{
*/
/******************************************************************************/
int16_t initialize_CAN( void )
{
    int16_t s16_error = C_UNKNOWN_ERR; // Assume there is some unknown error

    #if defined( CONTROLLER_3CS )
        // This device is a 3CS controller, so call the hardware-specific
        // implementation.
        s16_error = initialize_CAN_3CS( );
    #endif // defined

    // Initialize the user application's CAN variables
    s16_error |= initialize_CAN_user( );

    return( s16_error );
}
/*! @} */

/******************************************************************************/
/*!
   \fn       int16_t J1939_lock_message( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address, j1939_message_t type, boolean lock )
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
int16_t J1939_lock_message( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address, j1939_message_t type, boolean lock )
{
    int16_t s16_error = C_UNKNOWN_ERR; // Assume there is some unknown error

    #if defined( CONTROLLER_3CS )
        // This device is a 3CS controller, so call the hardware-specific
        // implementation.
        s16_error = J1939_lock_message_3CS( j1939_stack, PGN, destination_address, source_address, type, lock );
    #endif // defined

    return( s16_error );
}
/*! @} */

/******************************************************************************/
/*!
   \fn       int16_t J1939_lock_all_messages( J1939_stack_t j1939_stack, j1939_message_t type, boolean lock )
   \brief    Locks or unlocks all messages in the table that matches the supplied PGN,\n
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
int16_t J1939_lock_all_messages( J1939_stack_t j1939_stack, j1939_message_t type, boolean lock )
{
    int16_t s16_error = C_UNKNOWN_ERR; // Assume there is some unknown error

    #if defined( CONTROLLER_3CS )
        // This device is a 3CS controller, so call the hardware-specific
        // implementation.
        s16_error = J1939_lock_all_messages_3CS( j1939_stack, type, lock );
    #endif // defined

    return( s16_error );
}
/*! @} */

/******************************************************************************/
/*!
   \fn       int16_t J1939_filter_message( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address, j1939_message_t type, uint32_t mask )
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
int16_t J1939_filter_message( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address, j1939_message_t type, uint32_t mask )
{
    int16_t s16_error = C_UNKNOWN_ERR; // Assume there is some unknown error

    #if defined( CONTROLLER_3CS )
        // This device is a 3CS controller, so call the hardware-specific
        // implementation.
        s16_error = J1939_filter_message_3CS( j1939_stack, PGN, destination_address, source_address, type, mask );
    #endif // defined

    return( s16_error );
}
/*! @} */

/******************************************************************************/
/*!
   \fn       CAN_STATUS_t receive_J1939_messages( void )
   \brief    Receives the corresponding J1939 message and passes it to the application.
   \param    None.
   \ingroup  receiveCAN
   \return   The CAN status, as defined in enum CAN_STATUS_t.
   \retval   CAN_STATUS_t

    @{
*/
/******************************************************************************/
CAN_STATUS_t receive_J1939_messages( void )
{
    CAN_STATUS_t status = UNKNOWN_ERROR; // Assume there is some unknown error

    #if defined( CONTROLLER_3CS )
        // This device is a 3CS controller, so call the hardware-specific
        // implementation.
        status = receive_J1939_messages_3CS( );
    #endif // defined

    return( status );
}
/*! @} */

/******************************************************************************/
/*!
   \fn       CAN_STATUS_t send_J1939_messages( void )
   \brief    Sends the J1939 corresponding to the supplied Tx message index.
   \param    None.
   \ingroup  sendCAN
   \return   The CAN status, as defined in enum CAN_STATUS_t.
   \retval   CAN_STATUS_t

    @{
*/
/******************************************************************************/
CAN_STATUS_t send_J1939_messages( void )
{
    CAN_STATUS_t status = UNKNOWN_ERROR; // Assume there is some unknown error

    #if defined( CONTROLLER_3CS )
        // This device is a 3CS controller, so call the hardware-specific
        // implementation.
        status = send_J1939_messages_3CS( );
    #endif // defined

    return( status );
}
/*! @} */

/******************************************************************************/
/*!
   \fn       CAN_STATUS_t send_j1939_message( J1939_stack_t j1939_stack, J1939_tx_message_t * message )
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
CAN_STATUS_t send_j1939_message( J1939_stack_t j1939_stack, J1939_tx_message_t * message )
{
    CAN_STATUS_t status = UNKNOWN_ERROR; // Assume there is some unknown error

    #if defined( CONTROLLER_3CS )
        // This device is a 3CS controller, so call the hardware-specific
        // implementation.
        status = send_j1939_message_3CS( j1939_stack, message );
    #endif // defined

    return( status );
}
/*! @} */

/******************************************************************************/
/*!
   \fn       boolean update_j1939_tx_request_message_state( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address, boolean data_obtained )
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
boolean update_j1939_tx_request_message_state( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address, boolean data_obtained )
{
    boolean message_found = FALSE; // Assume this entry could not be found

    #if defined( CONTROLLER_3CS )
        // This device is a 3CS controller, so call the hardware-specific
        // implementation.
        message_found = update_j1939_tx_request_message_state_3CS( j1939_stack, PGN, destination_address, source_address, data_obtained );
    #endif // defined

    return( message_found );
}
/*! @} */

/******************************************************************************/
/*!
   \fn       boolean get_j1939_tx_request_message_state( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address )
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
boolean get_j1939_tx_request_message_state( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address )
{
    boolean data_obtained = FALSE; // Assume this entry could not be found

    #if defined( CONTROLLER_3CS )
        // This device is a 3CS controller, so call the hardware-specific
        // implementation.
        data_obtained = get_j1939_tx_request_message_state_3CS( j1939_stack, PGN, destination_address, source_address );
    #endif // defined

    return( data_obtained );
}
/*! @} */

/******************************************************************************/
/*!
   \fn       CAN_STATUS_t search_and_send_j1939_message( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address )
   \brief    This function searches through the J1939 table, and if a match is found\n
             sends the J1939 Tx message immediately. This is how any on demand\n
             messages are sent. Usually the period in the J1939 tables will be\n
             set to 0 when this function is used, but it is not required.
   \param    J1939_stack_t j1939_stack: The J1939 stack that the J1939 Tx message is on.
   \param    uint32_t PGN: The PGN of the message to find.
   \param    uint32_t destination_address: The destination address of the message to find.
   \param    uint32_t source_address: The source address of the message to find.
   \ingroup  sendCAN
   \return   The CAN status, as defined in enum CAN_STATUS_t.
   \retval   CAN_STATUS_t

    @{
*/
/******************************************************************************/
CAN_STATUS_t search_and_send_j1939_message( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address )
{
    CAN_STATUS_t status = UNKNOWN_ERROR; // Assume there is some unknown error

    #if defined( CONTROLLER_3CS )
        // This device is a 3CS controller, so call the hardware-specific
        // implementation.
        status = search_and_send_j1939_message_3CS( j1939_stack, PGN, destination_address, source_address );
    #endif // defined

    return( status );
}
/*! @} */

/******************************************************************************/
/*!
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
   \retval   J1939_tx_message_t *

    @{
*/
/******************************************************************************/
J1939_tx_message_t * get_j1939_tx_message( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address )
{
    J1939_tx_message_t * message = NULL; // Assume message could not be found

    #if defined( CONTROLLER_3CS )
        // This device is a 3CS controller, so call the hardware-specific
        // implementation.
        message = get_j1939_tx_message_3CS( j1939_stack, PGN, destination_address, source_address );
    #endif // defined

    return( message );
}

/******************************************************************************/
/*!
   \fn       boolean populate_J1939_tx_message( J1939_tx_message_t * message,\n
                 const uint8_t u8_start_bit,\n
                 const uint8_t u8_bit_length,\n
                 const uint64_t u64_data )
   \brief    Populates the data into the supplied J1939 Tx message.
   \param    const J1939_tx_message_t * message: The J1939 Tx message.
   \param    const uint8_t u8_start_bit: The bit to start populating at.
   \param    const uint8_t u8_bit_length: The bit length of the data.
   \param    const uint64_t u64_data: The data to populate into the Tx message.
   \ingroup  populateCAN
   \return   TRUE if the data was successfully inserted into the J1939 Tx buffer,\n
             FALSE otherwise.

    @{
*/
/******************************************************************************/
boolean populate_J1939_tx_message( J1939_tx_message_t * message,
    const uint8_t u8_start_bit,
    const uint8_t u8_bit_length,
    const uint64_t u64_data )
{
    boolean success = FALSE; // Assume could not populate data
    uint64_t u64_message_data = 0;
    errno_t error = 0;
    uint8_t u8_i;

    // Check the validity of the J1939 message
    if( message != NULL )
    {
        // Check to ensure that we do not exceed the maximum size of the buffer.
        // There are 8 bits per byte, and sizeof(message->data_buffer) is the
        // number of bytes in the buffer
        if( (u8_start_bit + u8_bit_length) <= (8 * sizeof(message->data_buffer)) )
        {
            // Convert buffer data to a 64-bit value
            error = memcpy_s( &u64_message_data, sizeof(uint64_t), message->data_buffer, sizeof(message->data_buffer) );
            if( 0 == error ) // No Errors occurred during copy
            {
                // Clear/Set the appropriate bits
                for( u8_i = 0; u8_i < u8_bit_length; u8_i++ )
                {
                    if( u64_data & (1ULL << u8_i) )
                    {
                        u64_message_data |= ( 1ULL << (u8_i + u8_start_bit) );
                    }
                    else
                    {
                        u64_message_data &= ~( 1ULL << (u8_i + u8_start_bit) );
                    }
                }

                // Copy the data back to the buffer
                error = memcpy_s( message->data_buffer, sizeof(message->data_buffer), &u64_message_data, sizeof(uint64_t) );
                if( 0 == error ) // No Errors occurred during copy
                {
                    // Data was successfully populated
                    success = TRUE;
                }
            }
        }
    }

    return( success );
}
/*! @} */

/******************************************************************************/
/*!
   \fn       boolean extract_J1939_rx_message( const J1939_rx_message_t * message,\n
                 const uint8_t u8_start_bit,\n
                 const uint8_t u8_bit_length,\n
                 uint64_t * u64_data )
   \brief    Extracts the data from the supplied J1939 Rx message.
   \param    const J1939_rx_message_t * message: The J1939 Rx message.
   \param    const uint8_t u8_start_bit: The bit to start populating at.
   \param    const uint8_t u8_bit_length: The bit length of the data.
   \param    uint64_t * u64_data: Pointer to where to store the extracted data.
   \ingroup  extractCAN
   \return   True if data was successfully extracted, False otherwise.
   \retval   boolean

    @{
*/
/******************************************************************************/
boolean extract_J1939_rx_message( const J1939_rx_message_t * message,
    const uint8_t u8_start_bit,
    const uint8_t u8_bit_length,
    uint64_t * u64_data )
{
    boolean success = FALSE; // Assume could not extract data
    uint64_t u64_message_data = 0;
    uint64_t u64_mask = 0;
    errno_t error = 0;

    // Check the validity of the J1939 message
    if( message != NULL )
    {
        // Check to ensure that we do not exceed the maximum size of the buffer.
        // There are 8 bits per byte, and sizeof(message->data_buffer) is the
        // number of bytes in the buffer
        if( (u8_start_bit + u8_bit_length) <= (8 * sizeof(message->data_buffer)) )
        {
            // Convert buffer data to a 64-bit value
            error = memcpy_s( &u64_message_data, sizeof(uint64_t), message->data_buffer, sizeof(message->data_buffer) );
            if( 0 == error ) // No Errors occurred during copy
            {
                // Extract the message data
                u64_mask = ~(0xFFFFFFFFFFFFFFFFULL << u8_bit_length);
                *u64_data = (u64_message_data >> u8_start_bit) & u64_mask;

                // Return TRUE to indicate data extracted successfully
                success = TRUE;
            }
        }
    }

    return( success );
}
/*! @} */
