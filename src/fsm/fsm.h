/*******************************************************************************/
/*!
    \file fsm.h
    \brief Defines the behavior of individual components of the system
           using the concept of a finite-state machine (FSM).

    Project     Controller Logic\n
    Copyright   UMATT 2025\n
    License     Use only under the terms of the contract / confidential\n

    Date (YYYY/MM/DD) |   Author       |   Changes
    ------------------|----------------|----------------
    2024/12/26        |   Bruce Niemi  | File created

 */
/*******************************************************************************/
#ifndef FSM_H
#define FSM_H

/******************************************************************************/
/*!
   \brief    StateHandler is a function pointer type

   \details  Used within the state machine to call the appropriate state
             handler function.
*/
/******************************************************************************/
typedef void (*StateHandler)(void);



#endif // FSM_H