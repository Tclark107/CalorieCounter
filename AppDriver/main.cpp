#include <iostream>
#include <ctime>

#include "DBInterface.h"
#include "UserInterface.h"

int main(int argc, char* argv[])
{
    bool devMode = 0;
    if(argc > 0)
    {
        bool devMode = static_cast<bool>(argv[0]);
    }

    DBInterface dbInterface(devMode);
    dbInterface.updateCalorieHistory();
    dbInterface.updateFoodLibrary();

    UserInterface UI;
    UI.UserInterfaceStart();
}
