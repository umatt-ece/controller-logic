#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "joystick.h"
#include "motor.h"

extern "C" {
#include "controller_logic.h"
#include "controller_logic_context.h"
}

void print_motor_status(const motor_t *motor) {
  // Convert speed enum to string
  const char *speed_str;
  switch (motor->speed) {
    case MOTOR_SPEED_STOP:
      speed_str = "STOP";
      break;
    case MOTOR_SPEED_SLOW:
      speed_str = "SLOW";
      break;
    case MOTOR_SPEED_MEDIUM:
      speed_str = "MEDIUM";
      break;
    case MOTOR_SPEED_FAST:
      speed_str = "FAST";
      break;
    default:
      speed_str = "UNKNOWN";
      break;
  }

  // Convert direction enum to string
  const char *direction_str;
  switch (motor->direction) {
    case MOTOR_DIRECTION_FORWARD:
      direction_str = "FORWARD";
      break;
    case MOTOR_DIRECTION_BACKWARD:
      direction_str = "BACKWARD";
      break;
    default:
      direction_str = "UNKNOWN";
      break;
  }

  printf("Motor settings: Speed = %s, Direction = %s\n", speed_str,
         direction_str);
}

void read_joystick_right(joystick_t *joystick) {
  joystick->previous_position = joystick->current_position;
  joystick->current_position = 230;
}

void read_joystick_left(joystick_t *joystick) {
  joystick->previous_position = joystick->current_position;
  joystick->current_position = 50;
}

void set_right_motor_speed(motor_t *motor) { print_motor_status(motor); }

void set_left_motor_speed(motor_t *motor) { print_motor_status(motor); }

void seat_switch_pressed(bool *seat_pressed) { *seat_pressed = true; }

TEST(ControllerLogicTest, Initialization) {
  controller_logic_settings_t settings = {
      .dead_zone = 7,    // Area were we don't care about the joystick position
      .sensitivity = 5,  // How sensitive the joystick is
      .speed = MOTOR_SPEED_MEDIUM,  // Speed of the motor
      .seat_pressed = seat_switch_pressed,
      .read_right_joystick = read_joystick_right,
      .read_left_joystick = read_joystick_left,
      .right_motor_set_speed = set_right_motor_speed,
      .left_motor_set_speed = set_left_motor_speed,
  };

  controller_logic_context_t context;
  controller_logic_context_init(&context);

  context.seat_pressed = true;  // Simulate that the seat is pressed
  context.left_joystick.deadman_switch = true;   // Simulate that the deadman
                                                 // switch is pressed
  context.right_joystick.deadman_switch = true;  // Simulate that the deadman
                                                 // switch is pressed

  controller_logic_error_t result = controller_logic_init(&settings, &context);

  EXPECT_EQ(result, CONTROLLER_LOGIC_OK);

  controller_logic_run();  // Run the controller logic I'm assuming that this is
  // a 'loop' function
}
