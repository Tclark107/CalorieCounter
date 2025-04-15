#ifndef REALLIBRARYDBINTERFACE_H 
#define REALLIBRARYDBINTERFACE_H 

#include <fstream>
#include <string>
#include <vector>

#include "DBInterface.h"

class RealLibraryDBInterface : public FileIODBInterface
{
    public:
        RealLibraryDBInterface();
        bool connect() override;
};

#endif
