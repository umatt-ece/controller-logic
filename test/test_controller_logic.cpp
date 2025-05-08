#include <gtest/gtest.h>

extern "C" {
#include "controller_logic.h"
#include "controller_logic_context.h"
#include "joystick.h"
}

// Sample button mapping functions for testing
static uint16_t identity_mapping(uint16_t raw) { return raw; }

static uint16_t plus_one_mapping(uint16_t raw) { return raw + 1; }

// Test fixture for controller_logic_context_init
TEST(ControllerLogicContextTest, InitDefaultValues) {
  controller_logic_context_t context;
  controller_logic_context_init(&context);

  // Default context values
  EXPECT_FALSE(context.seat_pressed);
  EXPECT_EQ(context.left_joystick.current_position, JOYSTICK_CENTER_POSITION);
  EXPECT_EQ(context.left_joystick.previous_position, JOYSTICK_CENTER_POSITION);
  EXPECT_FALSE(context.left_joystick.deadman_switch);
  EXPECT_EQ(context.left_joystick.current_buttons, 0u);
  EXPECT_EQ(context.left_joystick.previous_buttons, 0u);

  EXPECT_EQ(context.right_joystick.current_position, JOYSTICK_CENTER_POSITION);
  EXPECT_EQ(context.right_joystick.previous_position, JOYSTICK_CENTER_POSITION);
  EXPECT_FALSE(context.right_joystick.deadman_switch);
  EXPECT_EQ(context.right_joystick.current_buttons, 0u);
  EXPECT_EQ(context.right_joystick.previous_buttons, 0u);
}

// Verify that passing a null settings pointer returns an error
TEST(ControllerLogicInitTest, NullSettingsReturnsError) {
  controller_logic_context_t context;
  controller_logic_context_init(&context);
  controller_logic_error_t result = controller_logic_init(nullptr, &context);
  EXPECT_EQ(result, CONTROLLER_LOGIC_INVALID_SETTINGS);
}

// Verify that valid settings yield a successful initialization
TEST(ControllerLogicInitTest, ValidSettingsReturnsOk) {
  controller_logic_context_t context;
  controller_logic_context_init(&context);

  controller_logic_settings_t settings;
  settings.dead_zone = 10;
  settings.sensitivity = 5;
  settings.button_mapping = identity_mapping;

  controller_logic_error_t result = controller_logic_init(&settings, &context);
  EXPECT_EQ(result, CONTROLLER_LOGIC_OK);
}

// Unit test for a custom button mapping function
TEST(ButtonMappingFunctionTest, PlusOneMapping) {
  EXPECT_EQ(plus_one_mapping(0), 1);
  EXPECT_EQ(plus_one_mapping(5), 6);
  // Note: overflow behavior depends on uint16_t wrap-around
  EXPECT_EQ(plus_one_mapping(65535), 0);
}