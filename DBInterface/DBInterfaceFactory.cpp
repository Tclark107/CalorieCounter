#include "DBInterfaceFactory.h"
#include "RealLibraryDBInterface.h"
#include "RealHistoryDBInterface.h"
#include "DevLibraryDBInterface.h"
#include "DevHistoryDBInterface.h"

DBInterface* DBInterfaceFactory::createLibraryDBInterface(bool devMode)
{
    if(devMode)
    {
        return new DevLibraryDBInterface();
        return nullptr;
    }
    else
    {
        return new RealLibraryDBInterface();
    }
}

DBInterface* DBInterfaceFactory::createHistoryDBInterface(bool devMode)
{
    if(devMode)
    {
        return new DevHistoryDBInterface();
        return nullptr;
    }
    else
    {
        return new RealHistoryDBInterface();
    }
}
