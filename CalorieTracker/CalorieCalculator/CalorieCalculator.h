#ifndef CALORIECALCULATOR_H
#define CALORIECALCULATOR_H

#include <string>

enum MACRONUTRIENT
{
    PROTEIN = 4,
    CARB = 4,
    FAT = 9
};

namespace CalorieCalculator 
{
    double calculateCalories(double amount, int calories);
};

#endif

