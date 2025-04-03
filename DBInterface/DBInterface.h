#ifndef DBINTERFACE_H 
#define DBINTERFACE_H 

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "CalorieHistory.h"

class DBInterface {
    public:
        DBInterface();
        void saveCalorieHistory();
        void updateCalorieHistory();
        //void getFoodHistory();
        //void saveFoodHistory();
};

#endif
