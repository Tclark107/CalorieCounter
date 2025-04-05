#include <iostream>

#include "CalorieTrackerManager.h"

int main(int argc, char* argv[])
{
    bool devMode = false;
    if(argc > 1)
    {
        std::string arg = argv[1];
        if(arg == "true" || arg == "1")
        {
            devMode = true;
        }
    }

    CalorieTrackerManager calorieTrackerManager(devMode);
    calorieTrackerManager.startUp();
}
