#include <iostream>
#include <string>

#include "CalorieHistory.h"
#include "FoodLibrary.h"
#include "DBInterface.h"

enum Option 
{
    exitloop = 1,
    track,
    showLibrary,
    showDateData,
    showHistory,
    invalidOption
};

class UserInterface {
    public:
        UserInterface();
        void UserInterfaceStart();
        void todaysData(Date today);
        void trackItem();
    
    private:
        Date today;
        CalorieHistory& ch = CalorieHistory::getInstance();
	    FoodLibrary& fl = FoodLibrary::getInstance();
    
};
