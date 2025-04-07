#include <iostream>

#include "RealLibraryDBInterface.h"

RealLibraryDBInterface::RealLibraryDBInterface() {}

bool RealLibraryDBInterface::connect()
{
    libraryDB.open("../TristanDB/FoodLibrary.txt", std::ios::in | std::ios::out);
    if(!libraryDB)
    {
        std::cerr << "Error opening HistroyDB.\n";
        return false;
    }
    return true;
}

bool RealLibraryDBInterface::disconnect()
{
    if(libraryDB.is_open())
    {
        libraryDB.close();
        return true;
    }
    return false;
}

void RealLibraryDBInterface::loadData()
{
    std::string line;
    std::string word;
    while(std::getline(libraryDB, line))
    {
        libraryData.push_back(line);
    }
}

std::vector<std::string> RealLibraryDBInterface::getData()
{
    return libraryData;
}

void RealLibraryDBInterface::addItem(std::string newItem)
{
    libraryData.push_back(newItem);
}

void RealLibraryDBInterface::saveData()
{
    for(int i = 0; i < libraryData.size(); i++)
    {
        std::cout << libraryData[i] << std::endl;
        libraryDB << libraryData[i] << std::endl; 
    }
}


void RealLibraryDBInterface::displayData()
{
    for(int i = 0; i < libraryData.size(); i++)
    {
        std::cout << libraryData[i] << std::endl;
    }
}
