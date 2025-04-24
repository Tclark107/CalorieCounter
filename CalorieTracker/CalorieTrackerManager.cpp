#include "CalorieTrackerManager.h"
#include "FoodLibraryFacade.h"
#include "CalorieHistoryFacade.h"
#include "UserInterface.h"
#include "Utility.h"

#include <iostream>

CalorieTrackerManager::CalorieTrackerManager () {}

CalorieTrackerManager::CalorieTrackerManager(bool devMode, UserInterface* ui)
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

    std::string newItemToTrack = fl->getItemFromLibrary(userItem);
    ch->trackItem(date, newItemToTrack);
}

void CalorieTrackerManager::saveHistory()
{
    ch->saveHistory();
}

/*
void AppManager::displayTodaysMacros()
{
    CalorieHistory& ch = CalorieHistory::GetInstance();
    Date today = ch.getCurrentDate();
    int calories = ch.getTotalCalories(today);
    int proteins = ch.getTotalProteins(today);
    int fats = ch.getTotalFats(today);
    int carbs = ch.getTotalCarbohydrates(today);

    std::cout << std::endl;
    std::cout << "Today you have had " << calories << " calories, "
        << proteins << " grams of protien, " 
        << fats << " grams of fat, and " 
        << carbs << " grams of carbohydrates.\n";
    std::cout << std::endl;
}

*/
