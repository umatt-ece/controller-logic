/******************************************************************************/
/*!
    \file
        can_j1939_user.h

    \brief
        Application-specific file to define each Rx and Tx CAN message.

    \copyright
        Copyright (C) 2025  University of Manitoba Association of Tiny Tractors.  All Rights Reserved.
        License     use only under terms of contract / confidential\n

    History:

    Date (YYYY/MM/DD) |   Author        |   Changes
    ------------------|-----------------|----------------
    2025/01/29        |Zachary DeGraeve | File created
*/
/******************************************************************************/

#ifndef __CAN_J1939_USER_H__
#define __CAN_J1939_USER_H__

/*******************************************************************************
  INCLUDE
*******************************************************************************/
#include "can_j1939.h"

/*******************************************************************************
  DEFINES
*******************************************************************************/
/*!
    \brief      These are the J1939 stack sizes. They must match the number\n
                of entries in the J1939 Tx and J1939 Rx tables.
    \ingroup    can
    @{
 */
#define NUM_J1939_STACK_1_TX_MESSAGES        ( 0 )
#define NUM_J1939_STACK_2_TX_MESSAGES        ( 1 )

#define NUM_J1939_STACK_1_RX_MESSAGES        ( 1 )
#define NUM_J1939_STACK_2_RX_MESSAGES        ( 1 )
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
/*!
    \brief      These are the J1939 stack tables.\n
                These tables are used to transmit and receive messages on each CAN bus.\n
                    - CAN 1 is mapped to J1939 Stack 1.\n
                    - CAN 2 is mapped to J1939 Stack 2.\n
                    etc.
    \ingroup    can
    @{
 */
extern J1939_tx_msg_table_t J1939_stack_1_tx_msg_table[ ];
extern J1939_tx_msg_table_t J1939_stack_2_tx_msg_table[ ];

extern J1939_rx_msg_table_t J1939_stack_1_rx_msg_table[ ];
extern J1939_rx_msg_table_t J1939_stack_2_rx_msg_table[ ];
/*! @} */

/*******************************************************************************
  PROTOTYPES
*******************************************************************************/
/*!
    \brief      Application-specific CAN initialization.
    \ingroup    can
    \defgroup   initCAN CAN initialization
    @{
*/
sint16 initialize_CAN_user( void );
/*! @} */

#endif  //__CAN_J1939_USER_H__


