#include "CalorieTrackerManager.h"

CalorieTrackerManager::CalorieTrackerManager() {}

CalorieTrackerManager::CalorieTrackerManager(bool devMode) :
devMode(devMode)
{}

void CalorieTrackerManager::startUp()
{
    DBInterface dbInterface(devMode);
    dbInterface.updateCalorieHistory();
    dbInterface.updateFoodLibrary();

    UserInterface UI;
    UI.UserInterfaceStart();
}
