#include "DevHistoryDBInterface.h"

#include <iostream>
#include <algorithm>

DevHistoryDBInterface::DevHistoryDBInterface() {}

bool DevHistoryDBInterface::connect()
{
    historyDB.open("../TristanDB/HistoryTest.txt", std::ios::in | std::ios::out);
    if(!historyDB)
    {
        std::cerr << "Error opening HistroyDB.\n";
        return false;
    }
    return true;
}

bool DevHistoryDBInterface::disconnect()
{
    if(historyDB.is_open())
    {
        historyDB.close();
        return true;
    }
    return false;
}

void DevHistoryDBInterface::loadData()
{
    std::string line;
    std::string word;
    std::string date;
    while(std::getline(historyDB, line))
    {
        if(line.empty() || std::all_of(line.begin(), line.end(), isspace))
        {
            continue;
        }
        date = getDate(line);
        historyData[date] = line;
    }
}

bool DevHistoryDBInterface::inHistory(const std::string& date)
{
    if(historyData.find(date) != historyData.end()) return true;
    return false;
}

std::vector<std::string> DevHistoryDBInterface::getData()
{
    if(historyData.empty())
    {
        std::cout << "Food History is empty. No data found." << std::endl;
        return {};
    }

    std::vector<std::string> data;
    int i = 0;
    for(const auto& pair : historyData)
    {
        std::cout << pair.first << " " << pair.second << std::endl;
        data.push_back(pair.second);
    }

    return data;
}

void DevHistoryDBInterface::addItem(const std::string& newItem)
{
    std::string date = getDate(newItem);
    historyData[date] = newItem;
}

std::string DevHistoryDBInterface::getDate(const std::string& input)
{
    std::string date = input.substr(0,10);
    return date;
}

void DevHistoryDBInterface::saveData()
{
    std::cout << "DevHistoryDBInterface::saveData()\n";
    for(const auto& pair: historyData)
    {
        std::cout << pair.second << std::endl;
        historyDB << pair.second << std::endl;
    }
}

void DevHistoryDBInterface::displayData()
{
    std::cout << "DevHistoryDBInterface::displayData()\n";
    for(const auto& pair: historyData)
    {
        std::cout << pair.second << std::endl;
    }
    std::cout << std::endl;
}
