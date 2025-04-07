#include "DBInterfaceFactory.h"
#include "DevDBInterface.h"
#include "RealDBInterface.h"

DBInterfaceFactory::createLibraryDBInterface(bool devMode)
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

DBInterfaceFactory::createHistoryDBInterface(bool devMode)
{
    if(devMode)
    {
        return new DevHistoryDBInterface();
    }
    else
    {
        return new RealHistoryDBInterface();
    }
}
