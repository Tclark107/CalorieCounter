#include <iostream>

#include "FoodItem.h"

int main()
{
    std::cout << "hello " << std::endl;
    std::string name = "Chicken";
    int calories = 45;
    double proteins = 8;
    double fats = 1;
    double carbs = 0;

    FoodItem chicken(name, calories, proteins, fats, carbs);
    std::cout << "chicken calories " << chicken.getCalories() << std::endl;


}
