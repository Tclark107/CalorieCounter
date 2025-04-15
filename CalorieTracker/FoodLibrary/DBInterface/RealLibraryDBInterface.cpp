#include "RealLibraryDBInterface.h"

#include <iostream>

RealLibraryDBInterface::RealLibraryDBInterface() 
{
    filename = "../TristanDB/FoodLibrary.txt";
}

bool RealLibraryDBInterface::connect()
{
    libraryDB.open(filename, std::ios::in | std::ios::out);
    if(!libraryDB)
    {
        std::cerr << "Error opening HistroyDB.\n";
        return false;
    }
    return true;
}
