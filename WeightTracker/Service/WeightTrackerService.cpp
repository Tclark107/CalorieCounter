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
    saveDataFromDatabase();
}

void WeightTrackerService::saveDataFromDatabase()
{
    DevWeightTrackerDBInterface* devDb = dynamic_cast<DevWeightTrackerDBInterface*>(db);

    int dbSize = devDb->getSize();
    std::string weightEntry = "";
    std::vector<std::string> parsedWeightEntry;
    
    for(int i = 0; i < dbSize; i++)
    {
        weightEntry = devDb->getItem(i);
        parsedWeightEntry = Utility::splitByColons(weightEntry);
        std::string date = parsedWeightEntry[0];
        float weight = Utility::convertStringToFloat(parsedWeightEntry[1]);

        saveEntryInternal(date, weight);
    }
}

void WeightTrackerService::addEntry(const std::string& userInput)
{
    float weight = Utility::convertStringToFloat(userInput);
    std::string date = Utility::getDate();
    saveEntryInternal(date, weight);
}

void WeightTrackerService::saveEntryToDataBase(const std::string& userInput)
{
    std::string date = Utility::getDate();
    std::string weightData = date + ":" + userInput;

    db->connect();
    db->addItem(weightData);
    db->displayData();
    db->saveData();
    db->disconnect();
}

void WeightTrackerService::saveEntryInternal(const std::string date, const float weight)
{
    WeightEntry entry(date, weight);
    entries.push_back(entry);
}

//untested
std::string WeightTrackerService::getHistory()
{
    std::stringstream ss;
    ss << std::endl;

    for(int i = entries.size() - 1; i >= 0; i--)
    {
        ss << entries[i].getDate() << " " << entries[i].getWeight() << std::endl;
    }
    ss << std::endl;
    
    std::string result = ss.str();
    return result;
}

float WeightTrackerService::calculateWeeklyAverage() const
{
    float weeklyAverage = 0;
    int vecSize = entries.size();
    std::cout << "vecSize = " << vecSize << std::endl;
    int count = 0;
    for(int i = vecSize - 1; i >= 0; i--)
    {
        if(count > 6) break;
        weeklyAverage += entries[i].getWeight();
        count++;
        std::cout << "count = " << count << std::endl;
        std::cout << "avg = " << weeklyAverage << std::endl;
    }
    weeklyAverage = weeklyAverage/count;

    return weeklyAverage;
}
