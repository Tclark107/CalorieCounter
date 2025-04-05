#ifndef DBINTERFACE_H 
#define DBINTERFACE_H 

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "CalorieHistory.h"
#include "FoodLibrary.h"

class DBInterface {
    public:
        DBInterface();

        void saveCalorieHistory();
        void updateCalorieHistory();
        void saveFoodLibrary();
        void updateFoodLibrary();

    private:
        bool devMode;
        std::fstream historyDB;
        std::fstream libraryDB;

        void openFileIO();
        void closeFileIO();
};

#endif
