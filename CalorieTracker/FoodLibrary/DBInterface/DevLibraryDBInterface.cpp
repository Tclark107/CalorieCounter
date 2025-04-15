#include "DevLibraryDBInterface.h"

#include <iostream>
#include <algorithm>

DevLibraryDBInterface::DevLibraryDBInterface() 
{
    filename = "../TristanDB/FoodLibraryTest.txt";
}

bool DevLibraryDBInterface::connect()
{
    libraryDB.open(filename, std::ios::in | std::ios::out);
    if(!libraryDB)
    {
        std::cerr << "Error opening HistroyDB.\n";
        return false;
    }
    return true;
}
