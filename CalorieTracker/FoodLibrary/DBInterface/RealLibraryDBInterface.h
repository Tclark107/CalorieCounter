#ifndef REALLIBRARYDBINTERFACE_H 
#define REALLIBRARYDBINTERFACE_H 

#include <fstream>
#include <string>
#include <vector>

#include "FileIODBInterface.h"

class RealLibraryDBInterface : public FileIODBInterface
{
    public:
        RealLibraryDBInterface();
        std::vector<std::string> getData();
};

#endif
