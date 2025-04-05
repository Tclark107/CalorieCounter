#ifndef CALORIETRACKERMANAGER_H
#define CALORIETRACKERMANAGER_H

#include "DBInterface.h"
#include "CalorieCalculator.h"
#include "CalorieHistory.h"
#include "FoodItem.h"
#include "FoodLibrary.h"
#include "UserInterface.h"

class CalorieTrackerManager 
{
    public:
        CalorieTrackerManager();
        CalorieTrackerManager(bool devMode);
        void startUp();

    private:
        bool devMode;
};

#endif
