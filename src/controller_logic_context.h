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
#include "motor.h"

typedef struct CONTROLLER_LOGIC_CONTEXT_T {
  bool seat_pressed;
  joystick_t left_joystick;
  joystick_t right_joystick;
  motor_t left_motor;
  motor_t right_motor;
} controller_logic_context_t;

typedef void (*read_seat_pressed)(bool *seat_pressed);

/*******************************************************************************/
/*!
    \brief Initialize the controller logic context.

    \param context Pointer to the controller logic context to initialize

    \return None
*/
/*******************************************************************************/
void controller_logic_context_init(controller_logic_context_t *context);

bool controller_logic_deadman_switch_pressed(
    const controller_logic_context_t *context);

#endif  // CONTROLLER_LOGIC_CONTEXT_H
