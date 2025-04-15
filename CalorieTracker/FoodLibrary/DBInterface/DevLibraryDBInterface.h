#ifndef DEVLIBRARYDBINTERFACE_H 
#define DEVLIBRARYDBINTERFACE_H 

#include <fstream>
#include <string>
#include <vector>

#include "FileIODBInterface.h"

class DevLibraryDBInterface : public FileIODBInterface
{
    public:
        DevLibraryDBInterface();
        std::vector<std::string> getData();
};

#endif
