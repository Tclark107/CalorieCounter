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

        void addEntry(const std::string&);
        std::vector<WeightEntry> getAllEntries() const;
        float calculateWeeklyAverage() const;
        std::string getHistory();
        void saveEntryToDataBase(const std::string&);
        void saveEntryInternal(const std::string, const float);
        void saveDataFromDatabase();

    private:
        DBInterface* db;
        bool devMode;
        std::vector<WeightEntry> entries;
};
#endif 
