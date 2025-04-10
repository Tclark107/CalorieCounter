#ifndef DEV_WEIGHT_TRACKER_DB_INTERFACE_H
#define DEV_WEIGHT_TRACKER_DB_INTERFACE_H

#include "WeightTrackerDBInterface.h"

#include <vector>
#include <string>

class DevWeightTrackerDBInterface public WeightTrackerDBInterface
{
    public:
        std::vector<std::string> loadRawEntries() override;
        void saveEntry() override;
};

#endif
