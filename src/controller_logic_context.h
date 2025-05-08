/*******************************************************************************/
/*!
    \file controller_logic_context.h
    \brief Header file for the controller logic context.

    Project     Controller Logic\n
    Copyright   UMATT 2025\n
    License     Use only under the terms of the contract / confidential\n

    Date (YYYY/MM/DD) |   Author       |   Changes
    ------------------|----------------|----------------
    2025/04/22       |   Bruce Niemi  | File created
 */
/*******************************************************************************/

#ifndef CONTROLLER_LOGIC_CONTEXT_H
#define CONTROLLER_LOGIC_CONTEXT_H

#include <stdbool.h>

#include "joystick.h"

typedef struct CONTROLLER_LOGIC_CONTEXT_T {
  bool seat_pressed;
  joystick_t left_joystick;
  joystick_t right_joystick;
} controller_logic_context_t;

/*******************************************************************************/
/*!
    \brief Initialize the controller logic context.

    \param context Pointer to the controller logic context to initialize

    \return None
*/
/*******************************************************************************/
void controller_logic_context_init(controller_logic_context_t *context);

#endif  // CONTROLLER_LOGIC_CONTEXT_H
