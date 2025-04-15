#ifndef DEVLIBRARYDBINTERFACE_H 
#define DEVLIBRARYDBINTERFACE_H 

#include <fstream>
#include <string>
#include <vector>

#include "DBInterface.h"

class DevLibraryDBInterface : public FileIODBInterface
{
    public:
        DevLibraryDBInterface();
        bool connect()

};

#endif
