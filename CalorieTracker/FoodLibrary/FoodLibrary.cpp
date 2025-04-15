#include "FoodLibrary.h"

#include <iostream>
#include <sstream>
#include <iomanip>

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

FoodItem FoodLibrary::getItem(std::string food)
{
    return foodLibrary[food];
}

FoodItem FoodLibrary::createItem(std::string name,
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

bool FoodLibrary::inLibrary(std::string item)
{
    if(foodLibrary.find(item) != foodLibrary.end())
    {
        return true;
    }
    return false;
}

//bool FoodLibrary::editItem(std::string item)
//
//   if(!inLibrary(item))
//   {
//       std::cout << "Item not in Library so we will add the Item instead.\n";
//       return false;
//   }
//
//   return true;
//}

std::string FoodLibrary::toString(FoodItem item)
{
    std::stringstream ss;
    ss << item.getName() << " "
       << item.getCalories() << " "
       << item.getProteins() << " "
       << item.getFats() << " "
       << item.getCarbohydrates();

    std::string result = ss.str();
    return result;
}
