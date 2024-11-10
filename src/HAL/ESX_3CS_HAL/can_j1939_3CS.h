/******************************************************************************/
/*!
    \file
        can_j1939_3CS.h

    \brief
        Hardware-specific file to perform CAN messaging\n
        CAN modules including CAN in and out functions, and message layouts.

    \copyright
        Copyright (C) 2023  MacDon Inustries Ltd.  All Rights Reserved.
        License     use only under terms of contract / confidential\n

   \ingroup   can

    History:

    Date (YYYY/MM/DD) |   Author      |   Changes
    ------------------|---------------|----------------
    2023/04/12        | Ivan Ciric    | File branched from project 278 (ETDK) to create ISOBUS template project.
*/
/******************************************************************************/

#ifndef __CAN_J1939_3CS_H__
#define __CAN_J1939_3CS_H__

#if defined( CONTROLLER_3CS )

/*******************************************************************************
  INCLUDE
*******************************************************************************/
#include "can_j1939.h"

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
  CONSTANTS
*******************************************************************************/

/*******************************************************************************
  STRUCTS
*******************************************************************************/
/*
 * This is J1939 Message Handler object.\n
 * This structure is used to interface with the CAN hardware on the 3CS.
 */
typedef struct
{
    void * pv_can_handle;
} J1939_stack_message_handler_obj_t;

/*
    \brief      J1939 Transmit Request Table structure
    \ingroup    can
    \defgroup   initCAN CAN initialization
    @{
*/
typedef struct
{
    uint32_t               PGN;
    boolean                data_obtained;
    J1939_tx_callback_ptr  tx_update_handler;
} j1939_transmit_request_table_t;

/*******************************************************************************
  EXTERNS
*******************************************************************************/

/*******************************************************************************
  PROTOTYPES
*******************************************************************************/
/*
    \brief      Initialize CAN BUS and messages on the 3CS
    \ingroup    can
    \defgroup   initCAN CAN initialization
    @{
*/
int16_t initialize_CAN_3CS( void );
/* @} */

/*
    \brief      Locks or unlocks the CAN messages, in order to prevent them
                from being transmitted or received.
    \ingroup    can
    \defgroup   lockCAN CAN Lock
    @{
*/
int16_t J1939_lock_message_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address, j1939_message_t type, boolean lock );
int16_t J1939_lock_all_messages_3CS( J1939_stack_t j1939_stack, j1939_message_t type, boolean lock );
/* @} */

/*
    \brief      Receiving or sending CAN messages on the 3CS
    \ingroup    can
    \defgroup   transceiver CAN receiving / sending
    @{
*/
CAN_STATUS_t receive_J1939_messages_3CS( void );
CAN_STATUS_t send_J1939_messages_3CS( void );
CAN_STATUS_t send_j1939_message_3CS( J1939_stack_t j1939_stack, J1939_tx_message_t * message );
CAN_STATUS_t search_and_send_j1939_message_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address );
/* @} */

/*
    \brief      Sets/Gets the J1939 Tx Request Message's data obtained flag on the 3CS
    \ingroup    can
    \defgroup   CAN J1939 Messages
    @{
*/
boolean get_j1939_tx_request_message_state_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address );
boolean update_j1939_tx_request_message_state_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address, boolean data_obtained );
/* @} */

/*
    \brief      Retrieving a specific J1939 Tx message on the 3CS
    \ingroup    can
    \defgroup   CAN J1939 Messages
    @{
*/
J1939_tx_message_t * get_j1939_tx_message_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address );
/* @} */

/*
    \brief      Sets a filter of one or more J1939 message on the 3CS
    \ingroup    can
    \defgroup   CAN J1939 Messages
    @{
*/
int16_t J1939_filter_message_3CS( J1939_stack_t j1939_stack, uint32_t PGN, uint8_t destination_address, uint8_t source_address, j1939_message_t type, uint32_t mask );
/* @} */

#endif  //defined( CONTROLLER_3CS )

#endif  //__CAN_J1939_3CS_H__


