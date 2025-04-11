#ifndef WEIGHT_ENTRY_PARSER_H
#define WEIGHT_ENTRY_PARSER_H

#include "WeightEntry.h"

#include <string>

class WeightEntryParser
{
    public:
        static WeightEntry parseFromString(const std::string& line);
        static std::string toString(const WeightEntry& entry);
};

#endif
