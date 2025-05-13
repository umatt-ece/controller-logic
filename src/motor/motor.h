/*******************************************************************************/
/*!
    \file controller_logic.h
    \brief Header file for the controller logic module.

    Project     Controller Logic\n
    Copyright   UMATT 2025\n
    License     Use only under the terms of the contract / confidential\n

    Date (YYYY/MM/DD) |   Author       |   Changes
    ------------------|----------------|----------------
    2025/05/12       |   Bruce Niemi  | File created
 */
/*******************************************************************************/

#ifndef MOTOR_H
#define MOTOR_H

typedef enum MOTOR_SPEED {
  MOTOR_SPEED_STOP = 0,
  MOTOR_SPEED_SLOW = 1,
  MOTOR_SPEED_MEDIUM = 2,
  MOTOR_SPEED_FAST = 3,
} motor_speed_t;

typedef enum MOTOR_DIRECTION {
  MOTOR_DIRECTION_FORWARD = 0,
  MOTOR_DIRECTION_BACKWARD = 1,
} motor_direction_t;

typedef struct MOTOR {
  motor_speed_t speed;
  motor_direction_t direction;
} motor_t;

/******************************************************************************/
/*!
  \brief This function reads sets the speed of the motor based on the joystick
  \param motor A pointer to a motor_t structure that contains the motor
*/
/*******************************************************************************/
typedef void (*motor_set_speed_function_t)(motor_t *motor);

#endif  // MOTOR_H
