#include "DevWeightTrackerDBInterface.h"

#include <iostream>
#include <algorithm>

DevWeightTrackerDBInterface::DevWeightTrackerDBInterface() {}

bool DevWeightTrackerDBInterface::connect()
{
    weightDB.open("../TristanDB/WeightTest.txt", std::ios::in | std::ios::out);
    if(!weightDB)
    {
        return false;
    }
    return true;
}

bool DevWeightTrackerDBInterface::disconnect()
{
    if(weightDB.is_open())
    {
        weightDB.close();
        return true;
    }
    return false;
}

void DevWeightTrackerDBInterface::loadData()
{
    std::string line;
    std::string word;
    while(std::getline(weightDB, line))
    {
        if(line.empty() || std::all_of(line.begin(), line.end(), isspace))
        {
            continue;
        }
        weightData.push_back(line);
    }
}

std::vector<std::string> DevWeightTrackerDBInterface::getData()
{
    return weightData;
}

void DevWeightTrackerDBInterface::addItem(const std::string& newItem)
{
    weightData.push_back(newItem);
}

void DevWeightTrackerDBInterface::saveData()
{
    std::cout << "DevWeightTrackerDBInterface::saveData()\n";
    for(int i = 0; i < weightData.size(); i++)
    {
        std::cout << weightData[i] << std::endl;
        weightDB << weightData[i] << std::endl; 
    }
}

void DevWeightTrackerDBInterface::displayData()
{
    std::cout << "DevWeightTrackerDBInterface::displayData()\n";
    for(int i = 0; i < weightData.size(); i++)
    {
        std::cout << weightData[i] << std::endl;
    }
    std::cout << std::endl;
}
