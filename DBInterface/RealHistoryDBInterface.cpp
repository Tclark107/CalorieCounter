#include "RealHistoryDBInterface.h"

#include <iostream>
#include <algorithm>

RealHistoryDBInterface::RealHistoryDBInterface() {}

bool RealHistoryDBInterface::connect()
{
    historyDB.open("../TristanDB/History.txt", std::ios::in | std::ios::out);
    if(!historyDB)
    {
        std::cerr << "Error opening HistroyDB.\n";
        return false;
    }
    return true;
}

bool RealHistoryDBInterface::disconnect()
{
    if(historyDB.is_open())
    {
        historyDB.close();
        return true;
    }
    return false;
}

void RealHistoryDBInterface::loadData()
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

bool RealHistoryDBInterface::inHistory(const std::string& date)
{
    if(historyData.find(date) != historyData.end()) return true;
    return false;
}
std::vector<std::string> RealHistoryDBInterface::getData()
{
    std::vector<std::string> data;
    int i = 0;
    for(const auto& pair : historyData)
    {
        data[i] = pair.second;
        i++;
    }

    return data;
}

void RealHistoryDBInterface::addItem(const std::string& newItem)
{
    std::string date = getDate(newItem);
    historyData[date] = newItem;
}

std::string RealHistoryDBInterface::getDate(const std::string& input)
{
    std::string date = input.substr(0,10);
    std::cout << "This is my new function and date looks like " << date 
        << " but input looks like "<< input << std::endl;
    return date;
}

void RealHistoryDBInterface::saveData()
{
    std::cout << "RealHistoryDBInterface::saveData()\n";
    for(const auto& pair: historyData)
    {
        std::cout << pair.second << std::endl;
        historyDB << pair.second << std::endl;
    }
}

void RealHistoryDBInterface::displayData()
{
    std::cout << "RealHistoryDBInterface::displayData()\n";
    for(const auto& pair: historyData)
    {
        std::cout << pair.second << std::endl;
    }
    std::cout << std::endl;
}
