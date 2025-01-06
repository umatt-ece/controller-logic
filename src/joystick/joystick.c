/*******************************************************************************/
/*!
    \file joystick.c
    \brief Provides a basic

    Project     Controller Logic\n
    Copyright   UMATT 2025\n
    License     Use only under the terms of the contract / confidential\n

    Date (YYYY/MM/DD) |   Author       |   Changes
    ------------------|----------------|----------------
    2025/01/4        |   Bruce Niemi  | File created

 */
/*******************************************************************************/

#include "joystick.h"

#include <stdio.h>

/*******************************************************************************/
/*!
    \brief Initialize the joystick to default values

    \param joystick The joystick to initialize
  */
/*******************************************************************************/
void initialize_joystick(Joystick *joystick) {
  if (joystick == NULL) {
    return;
  }

  joystick->speed = MEDIUM;
  joystick->deadman_switch = false;
  joystick->current_position = 0;
  joystick->previous_position = 0;
}