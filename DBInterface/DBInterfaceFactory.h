#ifndef DBINTERFACEFACTORY_H
#define DBINTERFACEFACTORY_H

#include "DBInterface.h"

class DBInterfaceFactory
{
    public:
        static DBInterface* createLibraryDBInterface(bool devMode);
        static DBInterface* createHistoryDBInterface(bool devMode);
};

#endif
