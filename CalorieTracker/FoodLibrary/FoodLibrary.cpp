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

