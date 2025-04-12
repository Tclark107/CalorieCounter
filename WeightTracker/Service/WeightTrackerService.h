#ifndef WEIGHT_TRACKER_SERVICE_H
#define WEIGHT_TRACKER_SERVICE_H

#include "WeightEntry.h"

#include <vector>
#include <string>

class DBInterface;

class WeightTrackerService
{
    public:
        WeightTrackerService(bool);

        void addEntry(const std::string& entry);
        std::vector<WeightEntry> getAllEntries() const;
        float calculateWeeklyAverage() const;
        std::string getHistory();

    private:
        DBInterface* db;
        bool devMode;
        std::vector<WeightEntry> entries;
};
#endif 
