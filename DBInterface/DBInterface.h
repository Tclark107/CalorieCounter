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
        DBInterface(bool devMode);

        void saveCalorieHistory();
        void updateCalorieHistory();
        void saveFoodLibrary();
        void updateFoodLibrary();

    private:
        bool devMode;
        std::ofstream historyDBOut;
        std::ifstream historyDBIn;
        std::ofstream libraryDBOut;
        std::ifstream libraryDBIn;

        void openFileIO();
        void closeFileIO();
};

#endif
