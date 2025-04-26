#include "CalorieTrackerManager.h"
#include "FoodLibraryFacade.h"
#include "CalorieHistoryFacade.h"
#include "UserInterface.h"
#include "Utility.h"

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

    std::string newItemToTrack = fl->getItemFromLibrary(userItem);
    ch->trackItem(date, newItemToTrack);
}

void CalorieTrackerManager::saveHistory()
{
    ch->saveHistory();
}

void CalorieTrackerManager::displayTodaysMacros()
{
    std::vector<std::string> todaysFood = ch->getTodaysFoodItems();
    int calories = 0; 
    double proteins = 0; 
    double fats = 0; 
    double carbs = 0; 
    for(int i = 0; i < todaysFood.size(); i++)
    {
        calories += fl->getItemCalories(todaysFood[i]);
        proteins += fl->getItemProteins(todaysFood[i]);
        fats += fl->getItemFats(todaysFood[i]);
        carbs += fl->getItemCarbs(todaysFood[i]);
    }
    
    std::stringstream ss;
    ss << "Today you have had " << calories << " calories: ";
    ss << proteins << " proteins, "
       << fats << " fats and "  
       << carbs << " carbs.\n";
    std::string prompt = ss.str();
    ui->displayMessage(prompt);

}


