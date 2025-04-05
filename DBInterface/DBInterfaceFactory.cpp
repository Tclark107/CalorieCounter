#include "DBInterfaceFactory.h"
#include "DevDBInterface.h"
#include "RealDBInterface.h"

DBInterfaceFactory::createDBInterface(bool devMode)
{
    if(devMode)
    {
        return new DevDBInterface();
    }
    else
    {
        return new RealDBInterface();
    }
}
