#include "weight.h"
#include <gtest/gtest.h>

TEST(WeightConverterTest, KilogramsToPounds) {
    double result = WeightConversion::convertWeight(80, WeightUnit::Kilograms, WeightUnit::Pounds);
    ASSERT_NEAR(result, 176.37, 1e-2);
}

TEST(WeightConverterTest, PoundsToKilograms) {
    double result = WeightConversion::convertWeight(225, WeightUnit::Pounds, WeightUnit::Kilograms);
    ASSERT_NEAR(result, 102.06, 1e-2);
}