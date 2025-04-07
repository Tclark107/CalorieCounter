#ifndef DBINTERFACEFACTORY_H
#define DBINTERFACEFACTORY_H
class DBInterfaceFactory
{
    public:
        static DBInterface* createLibraryDBInterface(bool devMode);
        static DBInterface* createHistoryDBInterface(bool devMode);
};

#endif
