#ifndef CALORIECALCULATOR_H
#define CALORIECALCULATOR_H

#include <string>

class CalorieCalculator {
    public:
        CalorieCalculator();
        double calculateCalories(std::string unit, int amount);
};

#endif

