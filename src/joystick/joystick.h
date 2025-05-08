/*******************************************************************************/
/*!
    \file controller_logic.h
    \brief Header file for the controller logic module.

    Project     Controller Logic\n
    Copyright   UMATT 2025\n
    License     Use only under the terms of the contract / confidential\n

    Date (YYYY/MM/DD) |   Author       |   Changes
    ------------------|----------------|----------------
    2025/05/07       |   Bruce Niemi  | File created
 */
/*******************************************************************************/

#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <stdbool.h>
#include <stdint.h>

#define MAX_JOYSTICK_POSITION 256
#define MIN_JOYSTICK_POSITION 0
#define JOYSTICK_CENTER_POSITION 128
#define JOYSTICK_BUTTONS \
  16  // This is an arbitrary number, adjust as needed (Also power of 2 :P)

typedef struct JOYSTICK {
  uint8_t current_position;
  uint8_t previous_position;
  bool deadman_switch;
  uint16_t current_buttons;
  uint16_t previous_buttons;
} joystick_t;

typedef void (*joystick_button_handler_t)(uint16_t button_idx, bool pressed);

#endif  // JOYSTICK_H
