#ifndef DBINTERFACE_H 
#define DBINTERFACE_H 

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class RealHistoryDBInterface : public DBInterface{
    public:
        RealDBInterface();

        bool connect() override;
        bool disconnect() override;
        void loadData() override;  // Load data from the database
        void saveData() override;  // Save data to the database
        void displayData() override;  // Display the data

        void saveCalorieHistory();
        void updateCalorieHistory();
        void saveFoodLibrary();
        void updateFoodLibrary();

    private:
        std::fstream historyDB;
        std::fstream libraryDB;

        std::vector<std::vector<std::string>> historyData;
};

#endif
