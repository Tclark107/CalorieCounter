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
    int calories = getUserItemCalories(name);
    double proteins = getUserItemProteins(name);
    double fats = getUserItemFats(name);
    double carbs = getUserItemCarbs(name);

    foodLibraryService->addEntry(name, calories, proteins, fats, carbs);

    //have to add entry before saveing to database
    foodLibraryService->saveEntryToDataBase(name);
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

int FoodLibraryFacade::getUserItemCalories(const std::string name)
{
    std::string prompt = "";
    std::string placeHolder = "";
    int calories = 0;

    prompt = "How many calories are in " + name + "?";
    ui->displayMessage(prompt);
    std::cin >> placeHolder;
    calories = Utility::convertStringToInt(placeHolder);
    return calories;

}

double FoodLibraryFacade::getUserItemProteins(const std::string name)
{
    std::string prompt = "";
    std::string placeHolder = "";
    float proteins = 0;

    prompt = "How many proteins are in " + name + "?";
    ui->displayMessage(prompt);
    std::cin >> placeHolder;
    proteins = Utility::convertStringToDouble(placeHolder);
    
    return proteins;
}

double FoodLibraryFacade::getUserItemFats(const std::string name)
{
    std::string prompt = "";
    std::string placeHolder = "";
    float fats = 0;

    prompt = "How many fats are in " + name + "?";
    ui->displayMessage(prompt);
    std::cin >> placeHolder;
    fats = Utility::convertStringToDouble(placeHolder);
    
    return fats;
}

double FoodLibraryFacade::getUserItemCarbs(const std::string name)
{
    std::string prompt = "";
    std::string placeHolder = "";
    float carbs = 0;

    prompt = "How many carbs are in " + name + "?";
    ui->displayMessage(prompt);
    std::cin >> placeHolder;
    carbs = Utility::convertStringToDouble(placeHolder);
    
    return carbs;
}
