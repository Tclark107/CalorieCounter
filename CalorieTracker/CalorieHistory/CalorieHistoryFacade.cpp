#include "CalorieHistoryFacade.h"
#include "UserInterface.h"
#include "Utility.h"
#include "CalorieHistoryService.h"

#include <iostream>
#include <limits>

CalorieHistoryFacade::CalorieHistoryFacade(bool devMode, UserInterface* ui) :
cHS(nullptr),
ui(ui)
{
    cHS = new CalorieHistoryService(devMode);
}

void CalorieHistoryFacade::displayHistory()
{
    cHS->displayHistory();
}

void CalorieHistoryFacade::trackItem()
{
   std::string date = Utility::getDate();
   std::string foodItem = getUserItem();
   std::cout << "fooditem = " << foodItem << std::endl;
   //if(LF->inLibrary())
   //{
   //   
   //}
   //else
   //{
   //   FL->addItemToLibrary
   //}
   cHS->trackItem();
}

void CalorieHistoryFacade::saveHistory()
{
    cHS->writeToDatabase();
}

void CalorieHistoryFacade::addItemToHistory()
{
}

std::string CalorieHistoryFacade::getUserItem()
{
   std::string name;
   std::string prompt = "What is the name of the item you would like to add? ";
   ui->displayMessage(prompt);
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   std::getline(std::cin, name);

   return name;
}

/*
FoodItem AppManager::createUserItem(std::string name)
{

    int calories = 0;
    double proteins = 0;
    double fats = 0;
    double carbs = 0;

    prompt = "How many calories are in " + name + "?";
    ui->displayMessage(prompt);
    std::cin >> placeHolder;
    calories = std::stoi(placeHolder);

    prompt = "How many proteins are in " + name + "?";
    ui->displayMessage(prompt);
    std::cin >> placeHolder;
    proteins = std::stod(placeHolder);

    prompt = "How many fats are in " + name + "?";
    ui->displayMessage(prompt);
    std::cin >> placeHolder;
    fats = std::stod(placeHolder);

    prompt = "How many carbs are in " + name + "?";
    ui->displayMessage(prompt);
    std::cin >> placeHolder;
    carbs = std::stod(placeHolder);

    FoodLibrary& fl = FoodLibrary::GetInstance();
    FoodItem food(name, calories, proteins, fats, carbs);
    return food;
}
*/

