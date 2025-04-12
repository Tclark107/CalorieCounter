#include "RealWeightTrackerDBInterface.h"

#include <iostream>
#include <algorithm>

RealWeightTrackerDBInterface::RealWeightTrackerDBInterface() {}

bool RealWeightTrackerDBInterface::connect()
{
    weightDB.open("../TristanDB/Weight.txt", std::ios::in | std::ios::out);
    if(!weightDB)
    {
        return false;
    }
    return true;
}

bool RealWeightTrackerDBInterface::disconnect()
{
    if(weightDB.is_open())
    {
        weightDB.close();
        return true;
    }
    return false;
}

void RealWeightTrackerDBInterface::loadData()
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

std::vector<std::string> RealWeightTrackerDBInterface::getData()
{
    return weightData;
}

void RealWeightTrackerDBInterface::addItem(const std::string& newItem)
{
    weightData.push_back(newItem);
}

void RealWeightTrackerDBInterface::saveData()
{
    std::cout << "RealWeightTrackerDBInterface::saveData()\n";
    for(int i = 0; i < weightData.size(); i++)
    {
        std::cout << weightData[i] << std::endl;
        weightDB << weightData[i] << std::endl; 
    }
}

void RealWeightTrackerDBInterface::displayData()
{
    std::cout << "RealWeightTrackerDBInterface::displayData()\n";
    for(int i = 0; i < weightData.size(); i++)
    {
        std::cout << weightData[i] << std::endl;
    }
    std::cout << std::endl;
}
