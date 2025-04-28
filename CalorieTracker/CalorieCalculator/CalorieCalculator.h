#ifndef CALORIECALCULATOR_H
#define CALORIECALCULATOR_H

#include <string>

enum MACRONUTRIENT
{
    PROTEIN = 4,
    CARB = 4,
    FAT = 9
};

inline constexpr double GRAM_TO_OUNCE_CONVERSION = 28.35;

namespace CalorieCalculator 
{
    double calculateCalories(double, double);
    double calculateProteins(double, double);
    double calculateFats(double, double);
    double calculateCarbs(double, double);
    double gramToOunce(double);
};

#endif

