#include "FileIODBInterface.h"

#include <iostream>
#include <algorithm>

FileIODBInterface::FileIODBInterface() {}

FileIODBInterface::~FileIODBInterface() {}

void FileIODBInterface::setFileName(const std::string newFileName)
{
    filename = newFileName;
}

bool FileIODBInterface::connect()
{
    std::cout << "FileIODBInterface::connect()\n";
    fileIODB.open(filename, std::ios::in | std::ios::out);
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

std::string FileIODBInterface::getItem(const int index)
{
    return fileIOData[index];
}

int FileIODBInterface::getSize()
{
    return fileIOData.size();
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

void FileIODBInterface::saveItem(const std::string item)
{
    fileIODB << item << std::endl;
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
