#include <iostream>
#include <ctime>

#include "DBInterface.h"
#include "UserInterface.h"

int main()
{
    DBInterface dbInterface;
    dbInterface.updateCalorieHistory();
    dbInterface.updateFoodLibrary();

    UserInterface UI;
    UI.UserInterfaceStart();
}
