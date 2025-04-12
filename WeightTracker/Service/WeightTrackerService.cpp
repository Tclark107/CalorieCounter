#include "WeightTrackerService.h"
#include "Utility.h"
#include "DevWeightTrackerDBInterface.h"
#include "WeightTrackerDBInterfaceFactory.h"

#include <iostream>
#include <sstream>

WeightTrackerService::WeightTrackerService(bool devMode) : 
db(nullptr),
devMode(devMode),
entries()
{
    db = WeightTrackerDBInterfaceFactory::createDBInterface(devMode);
    db->connect();
    db->loadData();
    db->displayData();
    db->disconnect();
}

void WeightTrackerService::addEntry(const std::string& userInput)
{
    float weight = 0;
    weight = Utility::convertStringToFloat(userInput);

    std::string date = "";
    date = Utility::getDate();
    std::cout << "date = " << date << std::endl;
    std::cout << "weight = " << weight << std::endl;

    std::string weightData = date + " " + userInput;
    db->connect();
    db->addItem(weightData);
    db->displayData();
    db->saveData();
    db->disconnect();

    WeightEntry entry(date, weight);
    entries.push_back(entry);
}

std::vector<WeightEntry> WeightTrackerService::getAllEntries() const
{
    std::vector<WeightEntry> entries;
    return entries;
}

std::string WeightTrackerService::getHistory()
{
    std::stringstream ss;
    ss << std::endl;

    for(int i = entries.size() - 1; i >= 0; i--)
    {
        ss << entries[i].getWeight() << " ";
    }
    ss << std::endl;
    
    std::string result = ss.str();
    return result;
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
