#include "WeightTrackerFacade.h"
#include "WeightTrackerDBInterface.h"
#include "WeightTrackerService.h"
#include "UserInterface.h"

#include <string>

WeightTrackerFacade::WeightTrackerFacade(bool devMode, UserInterface* ui) :
devMode(devMode),
ui(ui)
{
    weightTrackerService = new WeightTrackerService;
}

void WeightTrackerFacade::recordWeight()
{
    std::string prompt = "What weight would you like to record: ";
    ui->displayMessage(prompt);
    std::string input = ui->getUserInput();
    weightTrackerService->addEntry(input);
}

void WeightTrackerFacade::displayProgress()
{
}
