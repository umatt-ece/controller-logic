/*******************************************************************************/
/*!
    \file joystick_events.h
    \brief Header file for the joystick events.

    Project     Controller Logic\n
    Copyright   UMATT 2025\n
    License     Use only under the terms of the contract / confidential\n

    Date (YYYY/MM/DD) |   Author       |   Changes
    ------------------|----------------|----------------
    2025/04/21      |   Bruce Niemi  | File created
 */
/*******************************************************************************/

#ifndef JOYSTICK_EVENTS_H
#define JOYSTICK_EVENTS_H

typedef enum JOYSTICK_EVENTS_TYPES {
  JOYSTICK_EVENT_NONE = 0,
  JOYSTICK_EVENT_AXIS_MOVED,
} joystick_events_types_t;

typedef enum JOYSTICK_AXIS {
  JOYSTICK_AXIS_X = 0,  // X axis
  JOYSTICK_AXIS_Y,      // Y axis
} joystick_axis_t;

typedef struct JOYSTICK_EVENT_AXIS_MOVED {
  joystick_axis_t axis;  // Axis that was moved
  float value;  // Value of the axis movement, typically between -1.0 and 1.0
} joystick_event_axis_moved_t;

typedef struct JOYSTICK_EVENT {
  joystick_events_types_t type;
  union {
    joystick_event_axis_moved_t axis_moved;
  } data;
} joystick_event_t;

#endif  // JOYSTICK_EVENTS_H
