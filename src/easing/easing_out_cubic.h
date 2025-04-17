/*******************************************************************************/
/*!
    \file easing_out_cubic.h
    \brief Provides a declaration of the ease_out_cubic easing function. For
   more information on https://easings.net/#easeOutCubic.

    Project     Controller Logic\n
    Copyright   UMATT 2025\n
    License     Use only under the terms of the contract / confidential\n

    Date (YYYY/MM/DD) |   Author       |   Changes
    ------------------|----------------|----------------
    2025/01/2        |   Bruce Niemi  | File created
    2025/04/17       |   Bruce Niemi  | Converted to header
 */
/*******************************************************************************/

#ifndef EASING_OUT_CUBIC_H
#define EASING_OUT_CUBIC_H

/*******************************************************************************/
/*!
    \brief Easing function that starts slow and speeds up a visualization of the
   function can be found at https://easings.net/#easeOutCubic.

    \param time The current time
    \param duration The total duration of the easing function

    \return The current progress of the easing function in the range [0, 1]
*/
/*******************************************************************************/
double ease_out_cubic(int time, int duration);

#endif /* EASING_OUT_CUBIC_H */
