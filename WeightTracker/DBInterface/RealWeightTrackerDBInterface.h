#ifndef REAL_WEIGHT_TRACKER_DB_INTERFACE_H
#define REAL_WEIGHT_TRACKER_DB_INTERFACE_H

#include "FileIODBInterface.h"

#include <fstream>
#include <vector>
#include <string>

class RealWeightTrackerDBInterface : public FileIODBInterface
{
    public:
        RealWeightTrackerDBInterface();
        std::vector<std::string> getData() override;
};

#endif
