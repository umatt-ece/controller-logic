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

#include <stdint.h>

/******************************************************************************/
/*!
   \brief    StateHandler is a function pointer type

   \details  Used within the state machine to call the appropriate state
             handler function.
*/
/******************************************************************************/
typedef void (*StateHandler)(void *); // I should be put down for the use of void*. :)

/******************************************************************************/

typedef struct
{
   uint32_t currentState;
   uint32_t event;
   uint32_t nextState;
   StateHandler stateHandler;
} StateTransition;

typedef struct
{
   uint32_t currentState;
   StateTransition *stateTransitions;
   uint32_t numTransitions;
} StateMachine;

void initalize_fsm(StateMachine *statemachine,
                   uint32_t initialState,
                   StateTransition *stateTransitions,
                   uint32_t numTransitions);

void process_event(StateMachine *statemachine, uint32_t event, void *data);

#endif // FSM_H