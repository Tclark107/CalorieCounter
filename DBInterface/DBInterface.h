#ifndef DBINTERFACE_H 
#define DBINTERFACE_H 

#include <fstream>
#include <iostream>
#include <string>

#include "CalorieHistory.h"

class DBInterface {
    public:
        DBInterface();
        void saveCalorieHistory();
        std::vector<std::pair<Date,std::vector<FoodItem>>> getCalorieHistory();
        //void getFoodHistory();
        //void saveFoodHistory();
};

#endif
