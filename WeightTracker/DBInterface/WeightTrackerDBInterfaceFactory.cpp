#include "WeightTrackerDBInterfaceFactory.h"
#include "DevWeightTrackerDBInterface.h"
//#include "RealWeightTrackerDBInterface.h"

DBInterface* WeightTrackerDBInterfaceFactory::createDBInterface(bool devMode)
{
    if(devMode)
    {
        return new DevWeightTrackerDBInterface();
    }
    else
    {
        //return new RealWeightTrackerDBInterface();
        return nullptr;
    }
}
