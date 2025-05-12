#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "joystick.h"

extern "C" {
#include "controller_logic.h"
#include "controller_logic_context.h"
}

void read_joystick_right(joystick_t *joystick) {
  joystick->previous_position = joystick->current_position;
  joystick->current_position = 128;
}

void read_joystick_left(joystick_t *joystick) {
  joystick->previous_position = joystick->current_position;
  joystick->current_position = 200;
}

TEST(ControllerLogicTest, Initialization) {
  controller_logic_settings_t settings = {
      .dead_zone = 7,    // Area were we don't care about the joystick position
      .sensitivity = 5,  // How sensitive the joystick is
      .read_right_joystick = read_joystick_right,
      .read_left_joystick = read_joystick_left,
  };

  controller_logic_context_t context;
  controller_logic_context_init(&context);

  controller_logic_error_t result = controller_logic_init(&settings, &context);

  EXPECT_EQ(result, CONTROLLER_LOGIC_OK);

  controller_logic_run();  // Run the controller logic I'm assuming that this is
                           // a 'loop' function
}