#include "RealLibraryDBInterface.h"

#include <iostream>

RealLibraryDBInterface::RealLibraryDBInterface() 
{
    setFileName("/home/t_jclark/PROJECTS/CalorieCounterData/FoodLibrary.txt");
}

std::vector<std::string> RealLibraryDBInterface::getData()
{
    std::vector<std::string> result;
    return result;
}
