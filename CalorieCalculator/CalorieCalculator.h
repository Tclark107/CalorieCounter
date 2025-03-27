#ifndef CALORIECALCULATOR_H
#define CALORIECALCULATOR_H

#include "FoodItem.h"

class CalorieCalculator {
    public:
        CalorieCalculator();
        double calculateCalories(const FoodItem item, int amount);
};

#endif

