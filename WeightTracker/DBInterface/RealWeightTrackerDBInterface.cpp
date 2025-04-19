#include "RealWeightTrackerDBInterface.h"

#include <iostream>
#include <algorithm>

RealWeightTrackerDBInterface::RealWeightTrackerDBInterface() 
{
    setFileName("/home/t_jclark/PROJECTS/CalorieCounterData/Weight.txt");
}

std::vector<std::string> RealWeightTrackerDBInterface::getData()
{
    std::vector<std::string> result;
    return result;
}
