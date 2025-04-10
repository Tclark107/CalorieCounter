#include "WeightTrackerService.h"

WeightTrackerService::WeightTrackerService(WeightTrackerDBInterface* db) :
    db(db)
{}

void WeightTrackerService::addEntry(const WeightEntry& entry)
{
}

std::vector<WeightEntry> getAllEntries() const
{
    std::vector<WeightEntry> entries;
    return entries;
}

float WeightTrackerService::calculateWeeklyAverage() const
{
    float weeklyAverage = 0;
    return weeklyAverage;
}
