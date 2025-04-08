#include <iostream>

#include "RealHistoryDBInterface.h"

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
    while(std::getline(historyDB, line))
    {
        historyData.push_back(line);
    }
}

std::vector<std::string> RealHistoryDBInterface::getData()
{
    return historyData;
}

void RealHistoryDBInterface::addItem(const std::string& newItem)
{
    historyData.push_back(newItem);
}

void RealHistoryDBInterface::saveData()
{
    std::cout << " In saveddata: logic needed" << std::endl;
    for(int i = 0; i < historyData.size(); i++)
    {
        std::cout << historyData[i] << std::endl;
        historyDB << historyData[i] << std::endl;
    }
}

void RealHistoryDBInterface::displayData()
{
    std::cout << "RealHistoryDBInterface::displayData()\n";
    for(int i = 0; i < historyData.size(); i++)
    {
        std::cout << historyData[i] << std::endl;
    }
    std::cout << std::endl;
}
