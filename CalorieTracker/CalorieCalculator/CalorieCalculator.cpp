#include "CalorieCalculator.h"

namespace CalorieCalculator
{
    double calculateCalories(double amount, int calories)
    {
        double result;
        result  = amount * calories;
        return result;
    }
     
}
