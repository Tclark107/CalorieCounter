#ifndef WEIGHT_TRACKER_DB_INTERFACE_H
#define WEIGHT_TRACKER_DB_INTERFACE_H

#include "DBInterface.h"

#include <vector>
#include <string>

class WeightTrackerDBInterface : DBInterface
{
    public:
        WeightTrackerDBInterface()

        bool connect() override;
        bool disconnect() override;
        void loadData() override;  // Load data from the database
        void saveData() override;  // Save data to the database
        void displayData() override;  // Display the data

        std::vector<std::string> getData() override;
};

#endif
