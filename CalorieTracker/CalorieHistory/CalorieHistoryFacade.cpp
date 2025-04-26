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

void CalorieHistoryFacade::trackItem(const std::string date, const std::string item)
{
   cHS->trackItem(date, item);
}

void CalorieHistoryFacade::saveHistory()
{
    cHS->writeToDatabase();
}

std::vector<std::string> CalorieHistoryFacade::getTodaysFoodItems()
{
    std::vector<std::string> result = cHS->getTodaysFoodItems();
    return result;
}
