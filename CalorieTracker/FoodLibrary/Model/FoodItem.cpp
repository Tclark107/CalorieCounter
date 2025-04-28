#include "FoodItem.h"

FoodItem::FoodItem() :
    name (),
    caloriesPerGram (0),
    proteinsPerGram (0),
    fatsPerGram (0),
    carbsPerGram(0)
{}


FoodItem::FoodItem(std::string name,
                   double caloriesPerGram, 
                   double proteinsPerGram, 
                   double fatsPerGram, 
                   double carbsPerGram) :
    name (name),
    caloriesPerGram (caloriesPerGram),
    proteinsPerGram (proteinsPerGram),
    fatsPerGram (fatsPerGram),
    carbsPerGram (carbsPerGram)
{}

std::string FoodItem::getName()
{
    return name;
}

double FoodItem::getCaloriesPerGram()
{ 
    return caloriesPerGram;
}

double FoodItem::getProteinsPerGram()
{
    return proteinsPerGram;
}

double FoodItem::getFatsPerGram()
{
    return fatsPerGram;
}

double FoodItem::getCarbsPerGram()
{
    return carbsPerGram;
} 

void FoodItem::setName(std::string name)
{
	this->name = name;
}

void FoodItem::setCaloriesPerGram(double caloriesPerGram)
{
	this->caloriesPerGram = caloriesPerGram;
}

void FoodItem::setProteinsPerGram(double proteinsPerGram)
{
	this->proteinsPerGram = proteinsPerGram;
}

void FoodItem::setFatsPerGram(double fatsPerGram)
{
	this->fatsPerGram = fatsPerGram;
}

void FoodItem::setCarbsPerGram( double carbsPerGram)
{
	this->carbsPerGram = carbsPerGram;
}

//std::ostream& operator<<(std::ostream& os, const FoodItem& food) {
std::ostream& operator<<(std::ostream& os, FoodItem& food) {
        os << food.getName() << "-"
           << food.getCaloriesPerGram() << "-"
           << food.getProteinsPerGram() << "-"
           << food.getFatsPerGram() << "-"
           << food.getCarbsPerGram();
        return os;
}
