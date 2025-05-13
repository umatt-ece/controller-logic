/*******************************************************************************/
/*!
    \file controller_logic_context.c
    \brief Implementation of the controller_logic_context.c

    Project     Controller Logic\n
    Copyright   UMATT 2025\n
    License     Use only under the terms of the contract / confidential\n

    Date (YYYY/MM/DD) |   Author       |   Changes
    ------------------|----------------|----------------
    2025/04/22       |   Bruce Niemi  | File created
 */
/*******************************************************************************/

#include "controller_logic_context.h"

#include <stdlib.h>

#include "motor.h"


void controller_logic_context_init(controller_logic_context_t *context) {
  if (context == NULL) {
    return;
  }

  context->left_joystick.current_position = JOYSTICK_CENTER_POSITION;
  context->left_joystick.previous_position = JOYSTICK_CENTER_POSITION;
  context->left_joystick.deadman_switch = false;

  context->right_joystick.current_position = JOYSTICK_CENTER_POSITION;
  context->right_joystick.previous_position = JOYSTICK_CENTER_POSITION;
  context->right_joystick.deadman_switch = false;

  context->left_motor.speed = MOTOR_SPEED_STOP;
  context->left_motor.direction = MOTOR_DIRECTION_FORWARD;

  context->right_motor.speed = MOTOR_SPEED_STOP;
  context->right_motor.direction = MOTOR_DIRECTION_FORWARD;

  context->seat_pressed = false;
}

bool controller_logic_deadman_switch_pressed(
    const controller_logic_context_t *context) {
  if (context == NULL) {
    return false;
  }

  return context->left_joystick.deadman_switch &&
         context->right_joystick.deadman_switch;
}
