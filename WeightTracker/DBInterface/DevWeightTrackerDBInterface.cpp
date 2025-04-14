#include "DevWeightTrackerDBInterface.h"

#include <iostream>
#include <algorithm>

DevWeightTrackerDBInterface::DevWeightTrackerDBInterface() 
{
    setFileName("../TristanDB/WeightTest.txt");
}

std::vector<std::string> DevWeightTrackerDBInterface::getData()
{
    std::vector<std::string> result;
    return result;
}
