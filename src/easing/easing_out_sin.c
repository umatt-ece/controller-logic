/*******************************************************************************/
/*!
    \file easing_out_sin.c
    \brief Provides an implementation of the ease_out_sine easing function. For
   more information on https://easings.net/#easeOutSine.

    Project     Controller Logic\n
    Copyright   UMATT 2025\n
    License     Use only under the terms of the contract / confidential\n

    Date (YYYY/MM/DD) |   Author       |   Changes
    ------------------|----------------|----------------
    2025/01/2        |   Bruce Niemi  | File created
 */
/*******************************************************************************/

#include "easing_out_sin.h"

#include <math.h>

#include "easing_strategy.h"

#define M_PI 3.14159265358979323846

/*******************************************************************************/
/*!
    \brief Easing function that starts slow and speeds up a visualization of the
   function can be found at https://easings.net/#easeOutSine.

    \param time The current time
    \param duration The total duration of the easing function

    \return The current progress of the easing function in the range [0, 1]
*/
/*******************************************************************************/
double ease_out_sine(int time, int duration) {
  double normalized_time = normalize_time(time, duration);
  return sin((normalized_time * M_PI) / 2);
}
