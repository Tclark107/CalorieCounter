#include "WeightTrackerService.h"
#include "Utility.h"

#include <iostream>

WeightTrackerService::WeightTrackerService() : 
entries()
{}

void WeightTrackerService::addEntry(const std::string& userInput)
{
    float weight = 0;
    weight = Utility::convertStringToFloat(userInput);

    std::string date = "";
    date = Utility::getDate();
    std::cout << "date = " << date << std::endl;
    std::cout << "weight = " << weight << std::endl;

    WeightEntry entry(date, weight);
    entries.push_back(entry);
}

std::vector<WeightEntry> getAllEntries()
{
    std::vector<WeightEntry> entries;
    return entries;
}

float WeightTrackerService::calculateWeeklyAverage() const
{
    float weeklyAverage = 0;
    int vecSize = entries.size();
    int count = 0;
    for(int i = vecSize - 1; i >= 0; i--)
    {
        if(count > 6) break;
        weeklyAverage += entries[i].getWeight();
        count++;
    }
    weeklyAverage = weeklyAverage/count;

    return weeklyAverage;
}
