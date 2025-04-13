#include "WeightTrackerFacade.h"
#include "WeightTrackerService.h"
#include "UserInterface.h"

#include <string>
#include <sstream>

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
    weightTrackerService->saveEntryToDataBase(input);
    displayProgress();
}

void WeightTrackerFacade::displayProgress()
{
    std::string weightHistory = "";
    weightHistory = weightTrackerService->getHistory();
    ui->displayMessage(weightHistory);
}

void WeightTrackerFacade::getAverageWeight()
{
    float averageWeight = 0;
    averageWeight = weightTrackerService->calculateWeeklyAverage();
    std::stringstream ss;
    ss << "Your average weight over the last week is: " << averageWeight;
    std::string message = ss.str();
    ui->displayMessage(message);
}
