#ifndef DEV_HISTORY_DB_INTERFACE_H 
#define DEV_HISTORY_DB_INTERFACE_H 

#include <fstream>
#include <string>
#include <vector>

#include "FileIODBInterface.h"

class DevHistoryDBInterface : public FileIODBInterface
{
    public:
        DevHistoryDBInterface();
        std::vector<std::string> getData();
};

#endif
