#ifndef FILEIO_DBINTERFACE_H 
#define FILEIO_DBINTERFACE_H 

#include <fstream>
#include <string>
#include <vector>

#include "DBInterface.h"

class FileIODBInterface : public DBInterface
{
    public:
        FileIODBInterface();

        bool connect() override;
        bool disconnect() override;
        void loadData() override;  // Load data from the database
        void saveData() override;  // Save data to the database
        void displayData() override;  // Display the data
        std::vector<std::string> getData() override;

        void addItem(const std::string& item) override;


    private:
        std::fstream fileIODB;
        std::vector<std::string> fileIOData;
};

#endif
