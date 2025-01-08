/*******************************************************************************/
/*!
    \file timer.c
    \brief Provides the joystick a basic timer for handling the joystick
   input delays.

    Project     Controller Logic\n
    Copyright   UMATT 2025\n
    License     Use only under the terms of the contract / confidential\n

    Date (YYYY/MM/DD) |   Author       |   Changes
    ------------------|----------------|----------------
    2025/01/4        |   Bruce Niemi  | File created

 */
/*******************************************************************************/

#include "timer.h"

/*******************************************************************************/
/*!
    \brief Initialize the timer to default values
    \param timer The timer to initialize
    \param duration The duration of the timer in seconds
  */
/*******************************************************************************/
void initialize_timer(Timer *timer, int duration) {
  if (timer == NULL) {
    return;
  }

  timer->start_time = time(NULL);
  timer->duration = duration;
}

/*******************************************************************************/
/*!
    \brief Check if the timer has reached its duration

    \param timer The timer to check
    \return True if the timer is done, false otherwise
  */
/*******************************************************************************/
bool has_elapsed(const Timer *timer) {
  if (timer == NULL) {
    return false;
  }

  return difftime(time(NULL), timer->start_time) >= timer->duration;
}