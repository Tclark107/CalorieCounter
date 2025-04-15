#include "FoodLibraryDBInterfaceFactory.h"
#include "DevFoodLibraryDBInterface.h"
#include "RealFoodLibraryDBInterface.h"

DBInterface* FoodLibraryDBInterfaceFactory::createDBInterface(bool devMode)
{
    if(devMode)
    {
        return new DevFoodLibraryDBInterface();
    }
    else
    {
        return new RealFoodLibraryDBInterface();
    }
}
