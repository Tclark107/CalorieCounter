#include "FoodLibraryDBInterfaceFactory.h"
#include "DevLibraryDBInterface.h"
#include "RealLibraryDBInterface.h"

DBInterface* FoodLibraryDBInterfaceFactory::createDBInterface(bool devMode)
{
    if(devMode)
    {
        return new DevLibraryDBInterface();
    }
    else
    {
        return new RealLibraryDBInterface();
    }
}
