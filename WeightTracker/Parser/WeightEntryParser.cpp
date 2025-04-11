#include "WeightEntryParser.h"

static WeightEntry parseFromString(const std::string& line)
{
    std::string date = "";
    float weight = 0;
    WeightEntry entry(date, weight);
    return entry;
}

std::string WeightEntryParser::toString(const WeightEntry& entry)
{
    std::string strEntry = "";
    return strEntry;
}
