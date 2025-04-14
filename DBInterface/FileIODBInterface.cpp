#include "FileIODBInterface.h"

#include <iostream>
#include <algorithm>

FileIODBInterface::FileIODBInterface() {}

bool FileIODBInterface::connect()
{
    fileIODB.open("../TristanDB/MockDB.txt", std::ios::in | std::ios::out);
    if(!fileIODB)
    {
        std::cerr << "Error opening HistroyDB.\n";
        return false;
    }
    return true;
}

bool FileIODBInterface::disconnect()
{
    if(fileIODB.is_open())
    {
        fileIODB.close();
        return true;
    }
    return false;
}

void FileIODBInterface::loadData()
{
    std::string line;
    std::string word;
    while(std::getline(fileIODB, line))
    {
        if(line.empty() || std::all_of(line.begin(), line.end(), isspace))
        {
            continue;
        }
        fileIOData.push_back(line);
    }
}

std::vector<std::string> FileIODBInterface::getData()
{
    return fileIOData;
}

void FileIODBInterface::addItem(const std::string& newItem)
{
    fileIOData.push_back(newItem);
}

void FileIODBInterface::saveData()
{
    std::cout << "FileIODBInterface::saveData()\n";
    for(int i = 0; i < fileIOData.size(); i++)
    {
        std::cout << fileIOData[i] << std::endl;
        fileIODB << fileIOData[i] << std::endl; 
    }
}

void FileIODBInterface::displayData()
{
    std::cout << "FileIODBInterface::displayData()\n";
    for(int i = 0; i < fileIOData.size(); i++)
    {
        std::cout << fileIOData[i] << std::endl;
    }
    std::cout << std::endl;
}
