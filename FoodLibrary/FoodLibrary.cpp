#include "FoodLibrary.h"

#include <iostream>

void FoodLibrary::showFoodLibrary()
{
    std::cout << std::endl;
    std::cout << "FoodLibrary::showFoodLibrary()\n";
    for(auto& pair : foodLibrary)
    {
    	std::cout << pair.first << " "; 
    	std::cout << pair.second << std::endl;
    }
    std::cout << std::endl;
}

void FoodLibrary::addItem(FoodItem food)
{
    foodLibrary[food.getName()] = food;
}

FoodItem createItem(std::string name,
                    int calories,
                    double proteins,
                    double fats,
                    double carbs)
{
    FoodItem food;
    food.setName(name);
    food.setCalories(calories);
    food.setProteins(proteins);
    food.setFats(fats);
    food.setCarbohydrates(carbs);
    return food;
}

