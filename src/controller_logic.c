/*******************************************************************************/
/*!
    \file controller_logic.c
    \brief Implementation of the controller_logic.c

    Project     Controller Logic\n
    Copyright   UMATT 2025\n
    License     Use only under the terms of the contract / confidential\n

    Date (YYYY/MM/DD) |   Author       |   Changes
    ------------------|----------------|----------------
    2025/04/19       |   Bruce Niemi  | File created
 */
/*******************************************************************************/

#include "controller_logic.h"

#include <stdio.h>
#include <stdlib.h>

#include "controller_logic_context.h"
#include "motor.h"

static const controller_logic_settings_t *controller_settings = NULL;
static controller_logic_context_t *controller_context = NULL;

void handle_joystick_input(joystick_t *joystick, motor_t *motor,
                           motor_set_speed_function_t motor_set_speed);

controller_logic_error_t controller_logic_init(
    const controller_logic_settings_t *settings,
    controller_logic_context_t *context) {
  if (settings == NULL) {
    return CONTROLLER_LOGIC_INVALID_SETTINGS;
  }

  if (context == NULL) {
    return CONTROLLER_LOGIC_INVALID_SETTINGS;
  }

  controller_settings = settings;
  controller_context = context;

  if (settings->dead_zone > 256) {
    return CONTROLLER_LOGIC_INVALID_SETTINGS;
  }

  if (settings->sensitivity > 256) {
    return CONTROLLER_LOGIC_INVALID_SETTINGS;
  }

  return CONTROLLER_LOGIC_OK;
}

void controller_logic_run(void) {
  if (controller_settings == NULL || controller_context == NULL) {
    return;
  }

  controller_settings->seat_pressed(&controller_context->seat_pressed);

  controller_settings->read_right_joystick(&controller_context->right_joystick);
  controller_settings->read_left_joystick(&controller_context->left_joystick);

  // Before any of the joystick logic, check if the deadman switch is pressed
  // and if not, do not run any of the joystick logic
  if (controller_logic_deadman_switch_pressed(controller_context) &&
      controller_context->seat_pressed) {
    handle_joystick_input(&controller_context->right_joystick,
                          &controller_context->right_motor,
                          controller_settings->right_motor_set_speed);

    handle_joystick_input(&controller_context->left_joystick,
                          &controller_context->left_motor,
                          controller_settings->left_motor_set_speed);
  } else {
    // If the deadman switch and the seat is not pressed, we need to kill ALL
    // the motion on the tractor
    printf("Deadman switch not pressed or seat not pressed\n");
    controller_context->right_motor.speed = MOTOR_SPEED_STOP;

    controller_settings->right_motor_set_speed(
        &controller_context->right_motor);

    controller_context->left_motor.speed = MOTOR_SPEED_STOP;

    controller_settings->left_motor_set_speed(&controller_context->left_motor);
  }
}

void handle_joystick_input(joystick_t *joystick, motor_t *motor,
                           motor_set_speed_function_t motor_set_speed) {
  // Check if the joystick has moved a bit
  int delta = joystick->current_position - joystick->previous_position;

  if (abs(delta) > controller_settings->sensitivity) {
    printf("Joystick moved: %d\n", delta);

    if (!joystick_in_dead_zone(&controller_context->right_joystick,
                               controller_settings->dead_zone)) {
      printf("Joystick is not in dead zone\n");
      if (joystick->current_position > joystick->previous_position) {
        printf("Joystick moved forward\n");
        motor->direction = MOTOR_DIRECTION_FORWARD;
        controller_context->right_motor.speed =
            controller_settings
                ->speed;  // This should be dynamic but for now eh

        motor_set_speed(motor);
      } else {
        printf("Joystick moved backward\n");
        motor->direction = MOTOR_DIRECTION_BACKWARD;
        controller_context->right_motor.speed =
            controller_settings
                ->speed;  // This should be dynamic but for now eh

        motor_set_speed(motor);
      }
    } else {
      printf("Joystick is in dead zone\n");
      controller_context->right_motor.speed = MOTOR_SPEED_STOP;
      motor_set_speed(motor);
    }
  }
}
