#include "DevHistoryDBInterface.h"

#include <iostream>
#include <algorithm>

DevHistoryDBInterface::DevHistoryDBInterface() 
{
    setFileName("../TristanDB/HistoryTest.txt");
}

std::vector<std::string> DevHistoryDBInterface::getData()
{
    std::vector<std::string> result;
    return result;
}
