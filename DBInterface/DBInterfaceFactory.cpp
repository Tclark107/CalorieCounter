#include "DBInterfaceFactory.h"
#include "RealHistoryDBInterface.h"
#include "DevHistoryDBInterface.h"

DBInterface* DBInterfaceFactory::createHistoryDBInterface(bool devMode)
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
