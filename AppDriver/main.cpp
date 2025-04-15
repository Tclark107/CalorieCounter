#include <iostream>

#include "AppManager.h"

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

    AppManager appManager(devMode);
    appManager.startUp();
}
