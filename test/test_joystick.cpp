#include <gmock/gmock.h>
#include <gtest/gtest.h>

extern "C" {
#include "joystick.h"
}

class JoystickDeadZoneTest : public ::testing::Test {
 protected:
  joystick_t joystick;
  const uint16_t dead_zone = 10;

  void SetUp() override {
    // Initialize joystick to a known state
    joystick.previous_position = JOYSTICK_CENTER_POSITION;
    joystick.deadman_switch = false;
  }
};

TEST_F(JoystickDeadZoneTest, NullPointerReturnsFalse) {
  EXPECT_FALSE(joystick_in_dead_zone(nullptr, dead_zone));
}

TEST_F(JoystickDeadZoneTest, AtCenterIsInsideDeadZone) {
  joystick.current_position = JOYSTICK_CENTER_POSITION;
  EXPECT_TRUE(joystick_in_dead_zone(&joystick, dead_zone));
}

TEST_F(JoystickDeadZoneTest, AtPositiveBoundaryIsInsideDeadZone) {
  joystick.current_position = JOYSTICK_CENTER_POSITION + dead_zone;
  EXPECT_TRUE(joystick_in_dead_zone(&joystick, dead_zone));
}

TEST_F(JoystickDeadZoneTest, AtNegativeBoundaryIsInsideDeadZone) {
  joystick.current_position = JOYSTICK_CENTER_POSITION - dead_zone;
  EXPECT_TRUE(joystick_in_dead_zone(&joystick, dead_zone));
}

TEST_F(JoystickDeadZoneTest, JustOutsidePositiveBoundaryIsOutsideDeadZone) {
  joystick.current_position = JOYSTICK_CENTER_POSITION + dead_zone + 1;
  EXPECT_FALSE(joystick_in_dead_zone(&joystick, dead_zone));
}

TEST_F(JoystickDeadZoneTest, JustOutsideNegativeBoundaryIsOutsideDeadZone) {
  joystick.current_position = JOYSTICK_CENTER_POSITION - dead_zone - 1;
  EXPECT_FALSE(joystick_in_dead_zone(&joystick, dead_zone));
}
