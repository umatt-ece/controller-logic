#include <cmath>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

extern "C" {
#include "easing_out_cubic.h"
#include "easing_out_sin.h"
#include "easing_strategy.h"
}

class EasingStrategyTest : public ::testing::Test {
protected:
  const double EPSILON = 1e-6; // Tolerance for floating point comparisons
};

TEST_F(EasingStrategyTest, NormalizeTimeReturnsCorrectValues) {
  EXPECT_DOUBLE_EQ(0.0, normalize_time(0, 100));
  EXPECT_DOUBLE_EQ(1.0, normalize_time(100, 100));

  EXPECT_DOUBLE_EQ(0.5, normalize_time(50, 100));
  EXPECT_DOUBLE_EQ(0.25, normalize_time(25, 100));
  EXPECT_DOUBLE_EQ(0.75, normalize_time(75, 100));

  EXPECT_DOUBLE_EQ(0.0, normalize_time(-10, 100));
  EXPECT_DOUBLE_EQ(1.0, normalize_time(110, 100));
}

TEST_F(EasingStrategyTest, EaseOutSineProducesCorrectValues) {
  EXPECT_NEAR(0.0, ease_out_sine(0, 100), EPSILON);
  EXPECT_NEAR(1.0, ease_out_sine(100, 100), EPSILON);

  // At t=50, sine easing should be around sin(π/2 * 0.5) = 0.7071
  EXPECT_NEAR(0.7071, ease_out_sine(50, 100), 0.01);

  double prev = ease_out_sine(0, 100);
  for (int i = 10; i <= 100; i += 10) {
    double current = ease_out_sine(i, 100);
    EXPECT_GT(current, prev) << "Failed at time " << i;
    prev = current;
  }

  for (int i = 0; i <= 100; i += 5) {
    double value = ease_out_sine(i, 100);
    EXPECT_GE(value, 0.0) << "Output below 0 at time " << i;
    EXPECT_LE(value, 1.0) << "Output above 1 at time " << i;
  }
}

TEST_F(EasingStrategyTest, EaseOutCubicProducesCorrectValues) {
  EXPECT_NEAR(0.0, ease_out_cubic(0, 100), EPSILON);
  EXPECT_NEAR(1.0, ease_out_cubic(100, 100), EPSILON);

  // At t=50, cubic easing should be 1 - pow(1 - 0.5, 3) = 0.875
  EXPECT_NEAR(0.875, ease_out_cubic(50, 100), EPSILON);

  double prev = ease_out_cubic(0, 100);
  for (int i = 10; i <= 100; i += 10) {
    double current = ease_out_cubic(i, 100);
    EXPECT_GT(current, prev) << "Failed at time " << i;
    prev = current;
  }

  for (int i = 0; i <= 100; i += 5) {
    double value = ease_out_cubic(i, 100);
    EXPECT_GE(value, 0.0) << "Output below 0 at time " << i;
    EXPECT_LE(value, 1.0) << "Output above 1 at time " << i;
  }
}

TEST_F(EasingStrategyTest, EasingStrategyFunctionPointer) {
  EasingStrategy sine_strategy = ease_out_sine;
  EasingStrategy cubic_strategy = ease_out_cubic;

  EXPECT_NEAR(0.0, sine_strategy(0, 100), EPSILON);
  EXPECT_NEAR(1.0, sine_strategy(100, 100), EPSILON);

  EXPECT_NEAR(0.0, cubic_strategy(0, 100), EPSILON);
  EXPECT_NEAR(1.0, cubic_strategy(100, 100), EPSILON);

  EXPECT_NE(sine_strategy(50, 100), cubic_strategy(50, 100));
}