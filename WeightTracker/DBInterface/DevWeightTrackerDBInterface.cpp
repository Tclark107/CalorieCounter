#include "DevWeightTrackerDBInterface.h"

#include <iostream>
#include <algorithm>

DevWeightTrackerDBInterface::DevWeightTrackerDBInterface() {}

bool DevWeightTrackerDBInterface::connect()
{
    weightDB.open("../TristanDB/WeightTest.txt", std::ios::in | std::ios::out);
    if(!weightDB)
    {
        return false;
    }
    return true;
}
