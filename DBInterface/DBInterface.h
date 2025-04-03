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
        void updateFoodLibrary();
        void saveFoodLibrary();
};

#endif
