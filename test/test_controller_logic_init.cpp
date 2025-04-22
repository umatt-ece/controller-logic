#include <gmock/gmock.h>
#include <gtest/gtest.h>

extern "C" {
#include "controller_logic.h"
}

class ControllerLogicInitTest : public ::testing::Test {
 protected:
  void SetUp() override {
    controller_logic_context_init(&context);
    settings.dummy_value = 42;
  }

  controller_logic_settings_t settings;
  controller_logic_context_t context;
};

// Test initialization with valid parameters
TEST_F(ControllerLogicInitTest, InitWithValidParameters) {
  controller_logic_error_t result = controller_logic_init(&settings, &context);
  EXPECT_EQ(result, CONTROLLER_LOGIC_OK);
}

// Test initialization with NULL settings
TEST_F(ControllerLogicInitTest, InitWithNullSettings) {
  controller_logic_error_t result = controller_logic_init(NULL, &context);
  EXPECT_EQ(result, CONTROLLER_LOGIC_INVALID_SETTINGS);
}

// Test initialization with NULL context
TEST_F(ControllerLogicInitTest, InitWithNullContext) {
  controller_logic_error_t result = controller_logic_init(&settings, NULL);
  EXPECT_EQ(result, CONTROLLER_LOGIC_INVALID_SETTINGS);
}

// Test that controller_logic_run doesn't crash when not initialized
TEST_F(ControllerLogicInitTest, RunWithoutInit) {
  // This should not crash
  controller_logic_run();
  // No assertions needed as we're just testing that it doesn't crash
}

// Test that controller_logic_run works after initialization
TEST_F(ControllerLogicInitTest, RunAfterInit) {
  controller_logic_init(&settings, &context);
  controller_logic_run();
  // No assertions needed as we're just testing that it doesn't crash
}

// Test context initialization
TEST_F(ControllerLogicInitTest, ContextInitialization) {
  EXPECT_FALSE(context.seat_pressed);
}