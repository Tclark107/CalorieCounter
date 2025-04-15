#include "RealLibraryDBInterface.h"

#include <iostream>

RealLibraryDBInterface::RealLibraryDBInterface() 
{
    setFileName("../TristanDB/FoodLibrary.txt");
}

std::vector<std::string> RealLibraryDBInterface::getData()
{
    std::vector<std::string> result;
    return result;
}
