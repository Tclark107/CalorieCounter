#ifndef DEV_WEIGHT_TRACKER_DB_INTERFACE_H
#define DEV_WEIGHT_TRACKER_DB_INTERFACE_H

#include "DBInterface.h"

#include <fstream>
#include <vector>
#include <string>

class DevWeightTrackerDBInterface : public  DBInterface
{
    public:
        DevWeightTrackerDBInterface();
        bool connect() override;
        bool disconnect() override;
        void loadData() override;  // Load data from the database
        void saveData() override;  // Save data to the database
        void displayData() override;  // Display the data
        std::vector<std::string> getData() override;

        void addItem(const std::string&);
    
    private:
        std::fstream weightDB;
        std::vector<std::string> weightData;
};

#endif
