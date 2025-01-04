/*******************************************************************************/
/*!
    \file easing_strategy.h
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

#ifndef EASING_STRATEGY_H
#define EASING_STRATEGY_H

/*******************************************************************************/
/*!
    \brief EasingStrategy is a function pointer that takes in an integer time
   and duration and returns a double. The time and duration are used to
   calculate the current progress of the easing function. The return value
    should be in the range [0, 1] where 0 is the start of the easing function
   and 1 is the end of the easing function.

    \param time The current time
    \param duration The total duration of the easing function

    \return The current progress of the easing function in the range [0, 1]
*/
/*******************************************************************************/
typedef double (*EasingStrategy)(int time, int duration);

/*******************************************************************************/
/*!
    \brief Normalize the time value to be within the range [0, 1]

    \param time The current time
    \param duration The total duration of the easing function

    \return The current progress of the easing function in the range [0, 1]
*/
/*******************************************************************************/
double normalize_time(int time, int duration);

#endif  // EASING_STRATEGY_H
