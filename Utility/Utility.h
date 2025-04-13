#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>

namespace Utility
{
    float convertStringToFloat(const std::string& str);
    std::string getDate();
    std::vector<std::string> splitBySpaces(const std::string);
    std::vector<std::string> splitByDashes(const std::string);
    std::vector<std::string> splitByColons(const std::string);
};

#endif
