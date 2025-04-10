#include "WeightTracker.h"
#include "CalorieHistory.h"

WeightTracker::WeightTracker() {}

void WeightTracker::trackWeight(const std::string& date, const int& weight)
{
    weightHistory[date] = weight;
}

int WeightTracker::getWeight(const std::string& date)
{
    return weightHistory[date];
}

std::map<std::string,int> WeightTracker::getWeightHistory()
{
    return weightHistory;
}
