#include "History.h"

#include <iostream>
#include <sstream>

History::History() {}

bool History::inHistory(const std::string date)
{
    if(history.find(date) != history.end()) return true;
    return false;
}

int History::getSize()
{
    return history.size();
}

std::string History::getHistory(const std::string date)
{
    if(!inHistory(date))
    {
        std::cout << date << " is not in History.";
        return "uh oh";
    }
    
    std::string dateInfo = toString(date);
    return dateInfo;
}

std::string History::toString(const std::string date)
{
    std::stringstream ss;
    ss << date << ":";

    const std::vector<std::string> entries = history[date];
    for(auto & entry : entries)
    {
        ss << entry << ":";
    }
    std::string result = ss.str();
    return result;
}

void History::addItemToDate(const std::string date, const std::string item)
{
    history[date].push_back(item);
}
