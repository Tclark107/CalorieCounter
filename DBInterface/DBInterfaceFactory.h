#ifndef DBINTERFACEFACTORY_H
#define DBINTERFACEFACTORY_H
class DBInterfaceFactory
{
    public:
        static DBInterface* createDBInterface(bool devMode);
};
