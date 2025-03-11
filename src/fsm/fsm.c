#include "fsm.h"
#include <stddef.h>

void initalize_fsm(StateMachine *statemachine,
                   uint32_t initialState,
                   StateTransition *stateTransitions,
                   uint32_t numTransitions)
{
    statemachine->currentState = initialState;
    statemachine->stateTransitions = stateTransitions;
    statemachine->numTransitions = numTransitions;
}

void process_event(StateMachine *statemachine, uint32_t event, void *data)
{
    for (uint32_t i = 0; i < statemachine->numTransitions; i++)
    {
        StateTransition *transition = &statemachine->stateTransitions[i];
        if (transition->currentState == statemachine->currentState &&
            transition->event == event)
        {
            if (transition->stateHandler != NULL)
            {
                transition->stateHandler(data);
            }

            statemachine->currentState = transition->nextState;
            break;
        }
    }
}