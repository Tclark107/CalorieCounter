#include "postgreSQLWeightTrackerDBInterface.h"

#include <iostream>
#include <algorithm>
#include <libpq-fe.h>

postgresqlWeightTrackerDBInterface::postgresqlWeightTrackerDBInterface(const std::string& conninfo) 
{
    conn = PQconnectdb(conninfo.c_str());
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << "Connection to database failed: " << PQerrorMessage(conn) << "\n";
        PQfinish(conn);
        conn = nullptr;
    }
}

postgresqlWeightTrackerDBInterface::~postgresqlWeightTrackerDBInterface() 
{
    if (conn) PQfinish(conn);
}

std::vector<std::string> postgresqlWeightTrackerDBInterface::getData()
{
    std::vector<std::string> result;
    return result;
}
