/*******************************************************************************/
/*!
    \file joystick.h
    \brief Provides the joystick struct and functions to interact with the
   control of the rest.

    Project     Controller Logic\n
    Copyright   UMATT 2025\n
    License     Use only under the terms of the contract / confidential\n

    Date (YYYY/MM/DD) |   Author       |   Changes
    ------------------|----------------|----------------
    2025/01/4        |   Bruce Niemi  | File created

 */
/*******************************************************************************/

#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <stdbool.h>
#include "easing_strategy.h"

enum JoystickSpeed { SLOW = 0, MEDIUM = 1, FAST = 2, SPEED_COUNT = 3 };

const int JOYSTICK_SPEED_DELAY[SPEED_COUNT] = {10, 5, 2};  // in seconds

typedef struct {
  enum JoystickSpeed speed;
  bool deadman_switch;
  EasingStrategy easing_strategy;
  int current_position;
  int previous_position;
} Joystick;

/*******************************************************************************/
/*!
    \brief Initialize the joystick to default values

    \param joystick The joystick to initialize
  */
/*******************************************************************************/
void initialize_joystick(Joystick *joystick);

#endif  // JOYSTICK_H