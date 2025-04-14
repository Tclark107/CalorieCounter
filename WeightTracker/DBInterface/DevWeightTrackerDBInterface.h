#ifndef DEV_WEIGHT_TRACKER_DB_INTERFACE_H
#define DEV_WEIGHT_TRACKER_DB_INTERFACE_H

#include "FileIODBInterface.h"

#include <fstream>
#include <vector>
#include <string>

class DevWeightTrackerDBInterface : public FileIODBInterface
{
    public:
        DevWeightTrackerDBInterface();
        std::vector<std::string> getData() override;
};

#endif
