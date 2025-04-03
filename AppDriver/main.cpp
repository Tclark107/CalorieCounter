#include <iostream>
#include <ctime>

#include "DBInterface.h"
#include "UserInterface.h"

void loadCalorieHistory()
{
    DBInterface dbInterface;
    CalorieHistory& ch = CalorieHistory::getInstance();

    std::vector<std::pair<Date,std::vector<FoodItem>>>& history = ch.getHistory();
    dbInterface.updateCalorieHistory();
}

int main()
{
    loadCalorieHistory();

    UserInterface UI;
    UI.UserInterfaceStart();
}
