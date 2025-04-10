#ifndef WEIGHT_TRACKER_DB_INTERFACE_H
#define WEIGHT_TRACKER_DB_INTERFACE_H

class WeightTrackerDBInterface
{
    public:
        virtual ~WeightTrackerDBInterface() = default;

        virtual std::vector<std::string> loadRawEntries() = 0;
        virtual void saveEntry(const std::string& line) = 0;
};

#endif
