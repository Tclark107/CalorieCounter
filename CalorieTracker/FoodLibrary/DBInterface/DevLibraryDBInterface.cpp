#include "DevLibraryDBInterface.h"

#include <iostream>
#include <algorithm>

DevLibraryDBInterface::DevLibraryDBInterface() 
{
    setFileName("../TristanDB/FoodLibraryTest.txt");
}

std::vector<std::string> DevLibraryDBInterface::getData()
{
    std::vector<std::string> result;
    return result;
}
