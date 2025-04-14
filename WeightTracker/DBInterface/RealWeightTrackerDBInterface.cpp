#include "RealWeightTrackerDBInterface.h"

#include <iostream>
#include <algorithm>

RealWeightTrackerDBInterface::RealWeightTrackerDBInterface() 
{
    setFileName("../TristanDB/Weight.txt");
}

std::vector<std::string> RealWeightTrackerDBInterface::getData()
{
    std::vector<std::string> result;
    return result;
}
