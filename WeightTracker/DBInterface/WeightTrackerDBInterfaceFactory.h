#ifndef WEIGHT_TRACKER_DBINTERFACE_FACTORY_H
#define WEIGHT_TRACKER_DBINTERFACE_FACTORY_H

#include "DBInterface.h"

class WeightTrackerDBInterfaceFactory
{
    public:
        static DBInterface* createDBInterface(bool devMode);
};

#endif
