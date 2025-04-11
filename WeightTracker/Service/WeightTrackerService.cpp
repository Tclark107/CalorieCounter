#include "WeightTrackerService.h"
#include "Utility.h"

WeightTrackerService::WeightTrackerService(WeightTrackerDBInterface* db) :
    db(db)
{}

void WeightTrackerService::addEntry(const std::string& userInput)
{
    float weight = 0;

    try
    {
        weight = std::stof(userInput);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << "Invalid Input: not a number.\n";
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << "Input is out of float range.\n";
    }
    //weight = Utility::convertStringToFloat(userInput);

    std::string date = "";
    date = Utility::getDate();

    WeightEntry entry(date, weight);
    entires.push_back(entry);
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
        weeklyAverage += entries[i];
        count++;
    }
    weeklyAverage = weeklyAverage/count;

    return weeklyAverage;
}
