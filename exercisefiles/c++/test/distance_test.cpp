#include "distance.h"
#include <gtest/gtest.h>

TEST(DistanceConverterTest, MetersToFeet) {
    double result = DistanceConversion::convertDistance(10, DistanceUnit::Meters, DistanceUnit::Feet);
    ASSERT_DOUBLE_EQ(result, 32.8084);
}

TEST(DistanceConverterTest, MetersToYards) {
    double result = DistanceConversion::convertDistance(10, DistanceUnit::Meters, DistanceUnit::Yards);
    ASSERT_NEAR(result, 10.9361, 1e-3);
}

TEST(DistanceConverterTest, FeetToMeters) {
    double result = DistanceConversion::convertDistance(10, DistanceUnit::Feet, DistanceUnit::Meters);
    ASSERT_DOUBLE_EQ(result, 3.048);
}

TEST(DistanceConverterTest, FeetToYards) {
    double result = DistanceConversion::convertDistance(10, DistanceUnit::Feet, DistanceUnit::Yards);
    ASSERT_NEAR(result, 3.3333, 1e-3);
}

TEST(DistanceConverterTest, YardsToMeters) {
    double result = DistanceConversion::convertDistance(10, DistanceUnit::Yards, DistanceUnit::Meters);
    ASSERT_DOUBLE_EQ(result, 9.144);
}

TEST(DistanceConverterTest, YardsToFeet) {
    double result = DistanceConversion::convertDistance(10, DistanceUnit::Yards, DistanceUnit::Feet);
    ASSERT_NEAR(result, 30, 1e-3);
}
