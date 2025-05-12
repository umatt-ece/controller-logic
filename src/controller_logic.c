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

static const controller_logic_settings_t *controller_settings = NULL;
static controller_logic_context_t *controller_context = NULL;

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
  if (controller_settings == NULL) {
    return;
  }

  controller_settings->read_right_joystick(&controller_context->right_joystick);
  controller_settings->read_left_joystick(&controller_context->left_joystick);

  // Before any of the joystick logic, check if the deadman switch is pressed
  // and if not, do not run any of the joystick logic
  if (controller_logic_deadman_switch_pressed(controller_context) &&
      controller_context->seat_pressed) {
    // Check if the joystick has moved a bit
    int delta = controller_context->right_joystick.current_position -
                controller_context->right_joystick.previous_position;

    if (abs(delta) > controller_settings->sensitivity) {
      if (!joystick_in_dead_zone(&controller_context->right_joystick,
                                 controller_settings->dead_zone)) {
        
        if(controller_context->right_joystick.current_position >
            controller_context->right_joystick.previous_position) {
          // Move the tractor forward
        } else {
          // Move the tractor backward
        }
      }
    } else {
      // If the deadman switch and the seat is not pressed, we need to kill ALL
      // the motion on the tractor
    }
  }

}
