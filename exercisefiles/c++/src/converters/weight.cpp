#include "weight.h"
#include <iomanip>
#include <iostream>
#include <unordered_map>

namespace /* private */
{
	std::string getWeightUnitSign(WeightUnit unit)
	{
		std::unordered_map<WeightUnit, std::string> unitSigns = {
			{WeightUnit::Kilograms, "kg"},
			{WeightUnit::Pounds, "lb"}
		};

		return unitSigns.at(unit);
	}
} // namespace private

namespace WeightConversion
{
	void startFlow()
	{
		double sourceValue = getSourceValue();
		WeightUnit from = getWeightUnit("source");
		WeightUnit to = getWeightUnit("target");

		double targetValue = convertWeight(sourceValue, from, to);

		std::cout << std::fixed << std::setprecision(2)
							<< sourceValue << getWeightUnitSign(from)
							<< " is "
							<< targetValue << getWeightUnitSign(to)
							<< '\n';
	}

	double getSourceValue()
	{
		double value;
		std::cout << "Enter the value to be converted: ";
		std::cin >> value;
		return value;
	}

	WeightUnit getWeightUnit(const std::string_view &sourceOrTarget)
	{
		int choice;
		std::cout << "Select " << std::string(sourceOrTarget) << " weight unit:\n";
		std::cout << "[1] Kilograms\n";
		std::cout << "[2] Pounds\n";
		std::cout << "Enter choice: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			return WeightUnit::Kilograms;
		case 2:
			return WeightUnit::Pounds;
		default:
			return WeightUnit::Kilograms;
		}
	}

	double convertWeight(double value, WeightUnit from, WeightUnit to)
	{
		if (from == to)
		{
			return value;
		}

		if (from == WeightUnit::Pounds)
		{
			value *= 0.45359237;
		}

		if (to == WeightUnit::Pounds)
		{
			value *= 2.2046226218487757;
		}

		return value;
	}
}
