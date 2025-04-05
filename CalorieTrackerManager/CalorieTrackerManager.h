#ifndef CALORIETRACKERMANAGER_H
#define CALORIETRACKERMANAGER_H

#include "DBInterface.h"
#include "CalorieCalculator.h"
#include "CalorieHistory.h"
#include "FoodItem.h"
#include "FoodLibrary.h"

class CalorieTrackerManager 
{
    public:
        CalorieTrackerManager();
        CalorieTrackerManager(bool devMode);

    private:
        bool devMode;
};

#endif
