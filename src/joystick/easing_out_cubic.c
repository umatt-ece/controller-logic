/*******************************************************************************/
/*!
    \file easing_out_cubic.c
    \brief Provides an implementation of the ease_out_sine easing function. For
   more information on https://easings.net/#easeOutCubic.

    Project     Controller Logic\n
    Copyright   UMATT 2025\n
    License     Use only under the terms of the contract / confidential\n

    Date (YYYY/MM/DD) |   Author       |   Changes
    ------------------|----------------|----------------
    2025/01/2        |   Bruce Niemi  | File created
 */
/*******************************************************************************/

#include "easing_strategy.h"

/*******************************************************************************/
/*!
    \brief Easing function that starts slow and speeds up a visualization of the
   function can be found at https://easings.net/#easeOutCubic.

    \param time The current time
    \param duration The total duration of the easing function

    \return The current progress of the easing function in the range [0, 1]
*/
/*******************************************************************************/
double ease_out_cubic(int time, int duration) {
  double normalized_time = normalize_time(time, duration);
  return 1 - pow(1 - normalized_time, 3);
}
