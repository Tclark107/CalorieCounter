#include "CalorieTrackerManager.h"
#include "FoodLibraryFacade.h"
#include "CalorieHistoryFacade.h"
#include "UserInterface.h"
#include "Utility.h"
#include "CalorieCalculator.h"

#include <iostream>
#include <sstream>

CalorieTrackerManager::CalorieTrackerManager () {}

CalorieTrackerManager::CalorieTrackerManager(bool devMode, UserInterface* ui) :
fl(nullptr),
ch(nullptr),
ui(ui)
{
    try
    {
        fl = new FoodLibraryFacade(devMode, ui);
        ch = new CalorieHistoryFacade(devMode, ui);
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Memory allocation failed during start u: " 
            << e.what() 
            << std::endl;
    }

}

CalorieTrackerManager::~CalorieTrackerManager () 
{
    delete fl;
    delete ch;
}

void CalorieTrackerManager::showLibrary()
{
    fl->displayLibrary();
}

void CalorieTrackerManager::addItemToLibrary()
{
    fl->addItemToLibrary();
}

void CalorieTrackerManager::showHistory()
{
    ch->displayHistory();
}

void CalorieTrackerManager::trackItemToday()
{
    std::string date = Utility::getDate();

    std::string userItem = fl->getUserItemName();
    if(!fl->inLibrary(userItem))
    {
        fl->addItemToLibrary(userItem);
    }

    std::string prompt = "How many ounces of " + userItem + " did you have?\n";
    std::cout << prompt;
    std::string amount = ""; 
    std::cin >> amount;

    double dbAmount = 0;
    dbAmount = Utility::convertStringToDouble(amount);

    std::string item = fl->getItemFromLibrary(userItem);
    std::cout << "item = " << item << std::endl;

    double calories = CalorieCalculator::calculateCalories(dbAmount, fl->getItemCaloriesPerGram(userItem));
    std::cout << "calories after calc is " << calories << std::endl;
    double proteins = CalorieCalculator::calculateProteins(dbAmount, fl->getItemProteinsPerGram(userItem));
    std::cout << "proteins after calc is " << proteins << std::endl;
    double fats = CalorieCalculator::calculateFats(dbAmount, fl->getItemFatsPerGram(userItem));
    std::cout << "fats after calc is " << fats << std::endl;
    double carbs = CalorieCalculator::calculateCarbs(dbAmount, fl->getItemCarbsPerGram(userItem));
    std::cout << "carbs after calc is " << carbs << std::endl;
    //calorieHistor->buildItem();
    std::stringstream ss;
    ss << userItem << "-"
       << calories << "-"
       << proteins << "-"
       << fats << "-"
       << carbs;

    //std::string newItemToTrack = fl->getItemFromLibrary(userItem);
    std::string newItemToTrack = ss.str(); 
    std::cout << "newitem = " << newItemToTrack << std::endl;
    ch->trackItem(date, newItemToTrack);
}

void CalorieTrackerManager::saveHistory()
{
    ch->saveHistory();
}

void CalorieTrackerManager::displayTodaysMacros()
{
    std::vector<std::string> todaysFood = ch->getTodaysFoodItems();
    double calories = 0; 
    double proteins = 0; 
    double fats = 0; 
    double carbs = 0; 
    for(int i = 0; i < todaysFood.size(); i++)
    {
        calories += fl->getItemCaloriesPerGram(todaysFood[i]);
        proteins += fl->getItemProteinsPerGram(todaysFood[i]);
        fats += fl->getItemFatsPerGram(todaysFood[i]);
        carbs += fl->getItemCarbsPerGram(todaysFood[i]);
    }
    
    std::stringstream ss;
    ss << "Today you have had " << calories << " calories: ";
    ss << proteins << " proteins, "
       << fats << " fats and "  
       << carbs << " carbs.\n";
    std::string prompt = ss.str();
    ui->displayMessage(prompt);

}


