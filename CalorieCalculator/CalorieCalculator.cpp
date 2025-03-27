#include "CalorieCalculator.h"

CalorieCalculator::CalorieCalculator() {}

double CalorieCalculator::calculateCalories(FoodItem food, int amount)
{
    double protein = food.getProteins() * amount;
    return protein;
}
     
