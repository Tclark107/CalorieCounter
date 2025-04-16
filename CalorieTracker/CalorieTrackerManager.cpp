#include "CalorieTrackerManager.h"
#include "FoodLibraryFacade.h"
#include "UserInterface.h"

#include <iostream>

CalorieTrackerManager::CalorieTrackerManager () {}

CalorieTrackerManager::CalorieTrackerManager(bool devMode, UserInterface ui)
{
    try
    {
        fl = new FoodLibraryFacade(devMode, ui);
        //ch = new CalorieHistoryFacade(devMode, ui);
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
    //delete ch;
}


