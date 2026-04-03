#include "distance.h"
#include <iomanip>
#include <iostream>
#include <unordered_map>

namespace /* private */ {
  std::string getDistanceUnitSign(DistanceUnit unit)
  {
    std::unordered_map<DistanceUnit, std::string> unitSigns = {
      {DistanceUnit::Meters, "m"},
      {DistanceUnit::Feet, "ft"},
      {DistanceUnit::Yards, "yd"}
    };

    return unitSigns.at(unit);
  }
} // namespace private

namespace DistanceConversion
{
  void startFlow()
  {
    double sourceValue = getSourceValue();
    DistanceUnit from = getDistanceUnit("source");
    DistanceUnit to = getDistanceUnit("target");

    double targetValue = convertDistance(sourceValue, from, to);

    std::cout << std::fixed << std::setprecision(2)
              << sourceValue << getDistanceUnitSign(from)
              << " is "
              << targetValue << getDistanceUnitSign(to)
              << '\n';
  }

  double getSourceValue()
  {
    double value;
    std::cout << "Enter the value to be converted: ";
    std::cin >> value;
    return value;
  }

  DistanceUnit getDistanceUnit(const std::string_view &sourceOrTarget)
  {
    int choice;
    std::cout << "Select " << std::string(sourceOrTarget) << " distance unit:\n";
    std::cout << "[1] Meters\n";
    std::cout << "[2] Feet\n";
    std::cout << "[3] Yards\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
      return DistanceUnit::Meters;
    case 2:
      return DistanceUnit::Feet;
    case 3:
      return DistanceUnit::Yards;
    default:
      return DistanceUnit::Meters; // Default to Meters
    }
  }

  double convertDistance(double value, DistanceUnit from, DistanceUnit to)
  {
    // Todo implement the actual conversion logic
    if (from == to)
    {
      return value;
    }

    // Convert everything to meters first
    if (from == DistanceUnit::Feet)
    {
      value *= 0.3048;
    }

    else if (from == DistanceUnit::Yards)
    {
      value *= 0.9144;
    }

    // Then convert to target unit
    if (to == DistanceUnit::Feet)
    {
      value *= 3.28084;
    }

    else if (to == DistanceUnit::Yards)
    {
      value *= 1.09361;
    }

    return value;
  }
}
