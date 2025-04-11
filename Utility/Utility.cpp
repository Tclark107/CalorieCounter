#include "Utility.h"

#include <stdexcept>
#include <ctime>
#include <cstdio>

namespace Utility
{
    float convertStringToFloat(const std::string& input)
    {
        try
        {
            return std::stof(input);
        }
        catch(const std::invalid_argument& e)
        {
            throw std::runtime_error("Invalid float format: " + input);
        }
        catch(const std::out_of_range& e)
        {
            throw std::runtime_error("Float out of range: " + input);
        }
    }

    std::string getDate()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        char buffer[11];
        snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d",
                1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
        return std::string(buffer);
    }
}
