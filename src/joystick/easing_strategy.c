/*******************************************************************************/
/*!
    \file easing_strategy.c
    \brief Provides a basic interface for working with easing functions. For
   more information on easing functions, see https://easings.net/

    Project     Controller Logic\n
    Copyright   UMATT 2025\n
    License     Use only under the terms of the contract / confidential\n

    Date (YYYY/MM/DD) |   Author       |   Changes
    ------------------|----------------|----------------
    2025/01/2        |   Bruce Niemi  | File created

 */
/*******************************************************************************/

#include "easing_strategy.h"

#include <assert.h>
#include <math.h>

/*******************************************************************************/
/*!
    \brief Normalize the time value to be within the range [0, 1]

    \param time The current time
    \param duration The total duration of the easing function

    \return The current progress of the easing function in the range [0, 1]
*/
/*******************************************************************************/
double normalize_time(int time, int duration) {
  assert(duration > 0);
  assert(time > 0);

  if (duration == 0) {
    return 1;
  }

  // Ensure that we fit within the range [0, 1]
  return max(0, min(1, (double)time / duration));
}
