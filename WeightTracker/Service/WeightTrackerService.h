#ifndef WEIGHT_TRACKER_SERVICE_H
#define WEIGHT_TRACKER_SERVICE_H

#include "WeightEntry.h"
#include "WeightTrackerDBInterface.h"

#include <vector>

class WeightTrackerService
{
    public:
        WeightTrackerService(WeightTrackerDBInterface* db);

        void addEntry(const WeightEntry& entry);
        std::vector<WeightEntry> getAllEntries() const;
        float calculateWeeklyAverage() const;

    private:
        WeightTrackerDBInterface* db;
};
#endif 
