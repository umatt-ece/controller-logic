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
#include <sys/types.h>

#define MAX_JOYSTICK_POSITION 256
#define MIN_JOYSTICK_POSITION 0
#define JOYSTICK_CENTER_POSITION 128
#define JOYSTICK_BUTTONS \
  16  // This is an arbitrary number, adjust as needed (Also power of 2 :P)

typedef struct JOYSTICK {
  uint8_t current_position;
  uint8_t previous_position;
  bool deadman_switch;
} joystick_t;

/******************************************************************************/
/*!
  \brief This function checks if the joystick is in the dead zone
  \param joystick A pointer to a joystick_t type that contains the joystick
  \param dead_zone The dead zone value to check against
*/
/*******************************************************************************/
bool joystick_in_dead_zone(joystick_t *joystick, uint16_t dead_zone);

/******************************************************************************/
/*!
  \brief This function reads the joystick position and updates the
  joystick_position_t
  \param joystick A pointer to a joystick_t structure that contains the
  joystick information
*/
/*******************************************************************************/
typedef void read_joystick(joystick_t *joystick);

#endif  // JOYSTICK_H
