/*******************************************************************************/
/*!
    \file joystick.h
    \brief Header file for the joystick module.

    Project     Controller Logic\n
    Copyright   UMATT 2025\n
    License     Use only under the terms of the contract / confidential\n

    Date (YYYY/MM/DD) |   Author       |   Changes
    ------------------|----------------|----------------
    2025/04/21      |   Bruce Niemi  | File created
 */
/*******************************************************************************/

#ifndef JOYSTICK_H
#define JOYSTICK_H

typedef struct JOYSTICK {
  float current_x;   // Current X axis value
  float current_y;   // Current Y axis value
  float previous_x;  // Previous X axis value
  float previous_y;  // Previous Y axis value

} joystick_t;

#endif  // JOYSTICK_H
