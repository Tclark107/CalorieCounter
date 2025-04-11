#include "DevLibraryDBInterface.h"

#include <iostream>
#include <algorithm>

DevLibraryDBInterface::DevLibraryDBInterface() {}

bool DevLibraryDBInterface::connect()
{
    libraryDB.open("../TristanDB/FoodLibraryTest.txt", std::ios::in | std::ios::out);
    if(!libraryDB)
    {
        std::cerr << "Error opening HistroyDB.\n";
        return false;
    }
    return true;
}

bool DevLibraryDBInterface::disconnect()
{
    if(libraryDB.is_open())
    {
        libraryDB.close();
        return true;
    }
    return false;
}

void DevLibraryDBInterface::loadData()
{
    std::string line;
    std::string word;
    while(std::getline(libraryDB, line))
    {
        if(line.empty() || std::all_of(line.begin(), line.end(), isspace))
        {
            continue;
        }
        libraryData.push_back(line);
    }
}

std::vector<std::string> DevLibraryDBInterface::getData()
{
    return libraryData;
}

void DevLibraryDBInterface::addItem(const std::string& newItem)
{
    libraryData.push_back(newItem);
}

void DevLibraryDBInterface::saveData()
{
    std::cout << "DevLibraryDBInterface::saveData()\n";
    for(int i = 0; i < libraryData.size(); i++)
    {
        std::cout << libraryData[i] << std::endl;
        libraryDB << libraryData[i] << std::endl; 
    }
}

void DevLibraryDBInterface::displayData()
{
    std::cout << "DevLibraryDBInterface::displayData()\n";
    for(int i = 0; i < libraryData.size(); i++)
    {
        std::cout << libraryData[i] << std::endl;
    }
    std::cout << std::endl;
}
