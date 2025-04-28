#include "CalorieCalculator.h"

namespace CalorieCalculator
{
    double calculateCalories(double amount, double calories)
    {
        double result;
        result  = amount * calories;
        result = gramToOunce(result);
        return result;
    }

    double calculateFats(double amount, double fats)
    {
        double result;
        result  = amount * fats;
        result = gramToOunce(result);
        return result;
    }

    double calculateProteins(double amount, double proteins)
    {
        double result;
        result  = amount * proteins;
        result = gramToOunce(result);
        return result;
    }

    double calculateCarbs(double amount, double carbs)
    {
        double result;
        result  = amount * carbs;
        result = gramToOunce(result);
        return result;
    }
  
    double gramToOunce(double gram)
    {
        double result = 0;
        result = gram * GRAM_TO_OUNCE_CONVERSION;
        return result;
    }
}
