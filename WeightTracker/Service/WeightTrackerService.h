#ifndef WEIGHT_TRACKER_SERVICE_H
#define WEIGHT_TRACKER_SERVICE_H

#include "WeightEntry.h"

#include <vector>

class WeightTrackerService
{
    public:
        WeightTrackerService();

        void addEntry(const std::string& entry);
        std::vector<WeightEntry> getAllEntries() const;
        float calculateWeeklyAverage() const;

    private:
        std::vector<WeightEntry> entries;
};
#endif 
