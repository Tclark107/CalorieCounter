#ifndef REAL_HISTORY_DB_INTERFACE_H 
#define REAL_HISTORY_DB_INTERFACE_H 

#include <string>
#include <vector>

#include "FileIODBInterface.h"

class RealHistoryDBInterface : public FileIODBInterface
{
    public:
        RealHistoryDBInterface();
        std::vector<std::string> getData();
};

#endif
