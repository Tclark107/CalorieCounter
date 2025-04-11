#ifndef WEIGHT_TRACKER_DB_INTERFACE_H
#define WEIGHT_TRACKER_DB_INTERFACE_H

#include <vector>
#include <string>

class WeightTrackerDBInterface
{
    public:
        virtual std::vector<std::string> loadRawEntries() = 0;
        virtual void saveEntry(const std::string& line) = 0;
};

#endif
