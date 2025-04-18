#include "HistoryDBInterfaceFactory.h"
#include "DevHistoryDBInterface.h"
#include "RealHistoryDBInterface.h"

DBInterface* HistoryDBInterfaceFactory::createDBInterface(bool devMode)
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
