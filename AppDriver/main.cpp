#include <iostream>

#include "DBInterface.h"
#include "UserInterface.h"

int main(int argc, char* argv[])
{
    bool devMode = false;
    if(argc > 0)
    {
        std::string arg = argv[1];
        if(arg == "true" || arg == "1")
        {
            devMode = true;
        }
    }

    DBInterface dbInterface(devMode);
    dbInterface.updateCalorieHistory();
    dbInterface.updateFoodLibrary();

    UserInterface UI;
    UI.UserInterfaceStart();
}
