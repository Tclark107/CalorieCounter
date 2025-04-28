#include "FoodLibraryFacade.h"
#include "FoodLibraryService.h"
#include "UserInterface.h"
#include "Utility.h"

#include <iostream>
#include <limits>

FoodLibraryFacade::FoodLibraryFacade(bool devMode, UserInterface* ui) :
foodLibraryService(nullptr),
ui(ui)
{
    foodLibraryService = new FoodLibraryService(devMode);
}

void FoodLibraryFacade::displayLibrary()
{
    foodLibraryService->displayLibrary();
}

void FoodLibraryFacade::addItemToLibrary()
{
    std::string name = getUserItemName();
    addItemToLibrary(name);
}

void FoodLibraryFacade::addItemToLibrary(const std::string name)
{
    double calories = getUserItemCalories(name);
    double proteins = getUserItemProteins(name);
    double fats = getUserItemFats(name);
    double carbs = getUserItemCarbs(name);

    //have to add entry before saveing to database
    foodLibraryService->addItem(name, calories, proteins, fats, carbs);

    foodLibraryService->saveEntryToDataBase(name);
}

std::string FoodLibraryFacade::getItemFromLibrary(const std::string item)
{
    return foodLibraryService->getStringItem(item);
}

bool FoodLibraryFacade::inLibrary(const std::string item)
{
    return foodLibraryService->inLibrary(item);
}

std::string FoodLibraryFacade::getUserItemName()
{
    std::string name;
    std::string prompt = "What is the name of the item you would like to add";
    ui->displayMessage(prompt);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);

    return name;
}

double FoodLibraryFacade::getUserItemCalories(const std::string name)
{
    std::string prompt = "";
    std::string placeHolder = "";
    double calories = 0;

    prompt = "How many calories are in 100g of " + name + "?";
    ui->displayMessage(prompt);
    std::cin >> placeHolder;
    calories = Utility::convertStringToDouble(placeHolder);
    return calories;

}

double FoodLibraryFacade::getUserItemProteins(const std::string name)
{
    std::string prompt = "";
    std::string placeHolder = "";
    double proteins = 0;

    prompt = "How many proteins are in 100g of " + name + "?";
    ui->displayMessage(prompt);
    std::cin >> placeHolder;
    proteins = Utility::convertStringToDouble(placeHolder);
    
    return proteins;
}

double FoodLibraryFacade::getUserItemFats(const std::string name)
{
    std::string prompt = "";
    std::string placeHolder = "";
    double fats = 0;

    prompt = "How many fats are in 100g of " + name + "?";
    ui->displayMessage(prompt);
    std::cin >> placeHolder;
    fats = Utility::convertStringToDouble(placeHolder);
    
    return fats;
}

double FoodLibraryFacade::getUserItemCarbs(const std::string name)
{
    std::string prompt = "";
    std::string placeHolder = "";
    double carbs = 0;

    prompt = "How many carbs are in 100g of " + name + "?";
    ui->displayMessage(prompt);
    std::cin >> placeHolder;
    carbs = Utility::convertStringToDouble(placeHolder);
    
    return carbs;
}

double FoodLibraryFacade::getItemCaloriesPerGram(const std::string name)
{
    return foodLibraryService->getItemCaloriesPerGram(name);
}

double FoodLibraryFacade::getItemProteinsPerGram(const std::string name)
{
    return foodLibraryService->getItemProteinsPerGram(name);
}

double FoodLibraryFacade::getItemFatsPerGram(const std::string name)
{
    return foodLibraryService->getItemFatsPerGram(name);
}

double FoodLibraryFacade::getItemCarbsPerGram(const std::string name)
{
    return foodLibraryService->getItemCarbsPerGram(name);
}
