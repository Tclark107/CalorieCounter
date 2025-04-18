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

void CalorieHistoryFacade::addItemToHistory()
{
}
