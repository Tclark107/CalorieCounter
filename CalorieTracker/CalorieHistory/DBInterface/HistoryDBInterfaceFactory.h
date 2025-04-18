#ifndef HISTORY_DBINTERFACE_FACTORY_H
#define HISTORY_DBINTERFACE_FACTORY_H

#include "DBInterface.h"

class HistoryDBInterfaceFactory
{
    public:
        static DBInterface* createDBInterface(bool devMode);
};

#endif
