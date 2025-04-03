#include "FoodItem.h"

FoodItem::FoodItem() :
    name (),
    calories (0),
    proteins (0),
    fats (0),
    carbohydrates(0)
{}


FoodItem::FoodItem(std::string name,
                   int calories, 
                   double proteins, 
                   double fats, 
                   double carbohydrates) :
    name (name),
    calories (calories),
    proteins (proteins),
    fats (fats),
    carbohydrates (carbohydrates)
{}

std::string FoodItem::getName()
{
    return name;
}

int FoodItem::getCalories()
{
    return calories;
}

double FoodItem::getProteins()
{
    return proteins;
}

double FoodItem::getFats()
{
    return fats;
}

double FoodItem::getCarbohydrates()
{
    return carbohydrates;
}

std::ostream& operator<<(std::ostream& os, const FoodItem& food) {
        os << food.getName() << " ";
           << food.getCalories() << " ";
           << food.getProteins() << " ";
           << food.getFats() << " ";
           << food.getCarbohydrates() << "\n";
        return os;
}
