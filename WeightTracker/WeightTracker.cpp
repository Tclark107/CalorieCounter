#include "WeightTracker.h"
#include "WeightTrackerDBInterface.h"
#include "WeightTrackerService.h"
#include "UserInterface.h"

WeightTracker::WeightTracker(bool devMode, UserInterface* ui) :
devMode(devMode),
ui(ui)
{}

void WeightTracker::recordWeight()
{
}

void WeightTracker::displayProgress()
{
}
