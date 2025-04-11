#ifndef WEIGHT_TRACKER_SERVICE_H
#define WEIGHT_TRACKER_SERVICE_H

#include "WeightEntry.h"

#include <vector>
#include <string>

class WeightTrackerService
{
    public:
        WeightTrackerService();

        void addEntry(const std::string& entry);
        std::vector<WeightEntry> getAllEntries() const;
        float calculateWeeklyAverage() const;
        std::string getHistory();

    private:
        std::vector<WeightEntry> entries;
};
#endif 
