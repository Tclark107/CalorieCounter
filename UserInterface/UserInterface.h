#include <iostream>
#include <string>

#include "CalorieHistory.h"
//#include "FoodLibrary.h"

class UserInterface {
    public:
        UserInterface();
        void UserInterfaceStart();
        void todaysData(Date today);
    
    private:
        CalorieHistory& ch = CalorieHistory::getInstance();
        //std::vector<std::pair<Date,std::vector<FoodItem>>>& history = ch.getHistory();


    
};
