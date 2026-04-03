#ifndef WEIGHT_H
#define WEIGHT_H

#include <string>

enum class WeightUnit
{
    Kilograms,
    Pounds
};

namespace WeightConversion
{
    void startFlow();
    double getSourceValue();
    WeightUnit getWeightUnit(const std::string_view &sourceOrTarget);
    double convertWeight(double value, WeightUnit from, WeightUnit to);
}

#endif