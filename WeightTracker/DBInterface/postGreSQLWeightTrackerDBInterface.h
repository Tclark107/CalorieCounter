#ifndef POSTGRESQL_WEIGHT_TRACKER_DB_INTERFACE_H
#define POSTGRESQL_WEIGHT_TRACKER_DB_INTERFACE_H

#include "FileIODBInterface.h"

#include <fstream>
#include <vector>
#include <string>

class postgresqlWeightTrackerDBInterface : public FileIODBInterface
{
    public:
        postgresqlWeightTrackerDBInterface(const std::string& conninfo);
        ~postgresqlWeightTrackerDBInterface();
        std::vector<std::string> getData() override;

    private:
        PGconn* conn;
};

#endif
