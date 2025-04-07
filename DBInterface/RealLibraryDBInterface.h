#ifndef DBINTERFACE_H 
#define DBINTERFACE_H 

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "CalorieHistory.h"
#include "FoodLibrary.h"

class RealDBInterface : public DBInterface{
    public:
        RealDBInterface();

        bool connect();
        bool close();
        void loadData();  // Load data from the database
        void saveData();  // Save data to the database
        void displayData();  // Display the data

        void saveCalorieHistory();
        void updateCalorieHistory();
        void saveFoodLibrary();
        void updateFoodLibrary();

    private:
        std::fstream historyDB;
        std::fstream libraryDB;
};

#endif
