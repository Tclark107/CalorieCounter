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
        ~FileIODBInterface() override;

        bool connect() override;
        bool disconnect() override;
        void loadData() override;  // Load data from the database
        void saveData() override;  // Save data to the database
        void displayData() override;  // Display the data

        void setFileName(const std::string);
        void addItem(const std::string& item) override;
        std::string getItem(const int index);
        int getSize();
        void saveItem(const std::string item);

    private:
        std::fstream fileIODB;
        std::vector<std::string> fileIOData;
        std::string filename = "../TristanDB/MockDB.txt";
};

#endif
