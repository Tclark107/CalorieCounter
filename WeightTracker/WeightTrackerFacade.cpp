#include "WeightTrackerFacade.h"
#include "WeightTrackerService.h"
#include "UserInterface.h"

#include <string>

WeightTrackerFacade::WeightTrackerFacade(bool devMode, UserInterface* ui) :
devMode(devMode),
ui(ui)
{
    weightTrackerService = new WeightTrackerService(devMode);
}

void WeightTrackerFacade::recordWeight()
{
    std::string prompt = "What weight would you like to record: ";
    ui->displayMessage(prompt);
    std::string input = ui->getUserInput();
    weightTrackerService->addEntry(input);
    displayProgress();
}

void WeightTrackerFacade::displayProgress()
{
    std::string weightHistory = "";
    weightHistory = weightTrackerService->getHistory();
    ui->displayMessage(weightHistory);
}
