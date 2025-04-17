#include "CalorieHistoryFacade.h"
#include "UserInterface.h"
#include "Utility.h"

#include <iostream>
#include <limits>

CalorieHistoryFacade::CalorieHistoryFacade(bool devMode, UserInterface* ui) :
CalorieHistoryService(nullptr),
ui(ui)
{
    CalorieHistoryService = new CalorieHistoryService(devMode);
}

void CalorieHistoryFacade::displayHistory()
{
    CalorieHistoryService->displayHistory();
}

void CalorieHistoryFacade::addItemToHistory()
{
}
