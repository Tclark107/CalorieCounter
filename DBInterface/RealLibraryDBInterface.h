#ifndef REALLIBRARYDBINTERFACE_H 
#define REALLIBRARYDBINTERFACE_H 

#include <fstream>
#include <string>
#include <vector>

#include "DBInterface.h"

class RealLibraryDBInterface : public DBInterface
{
    public:
        RealLibraryDBInterface();

        bool connect() override;
        bool disconnect() override;
        void loadData() override;  // Load data from the database
        void saveData() override;  // Save data to the database
        void displayData() override;  // Display the data
        std::vector<std::string> getData() override;

        void addItem(const std::string& item) override;


    private:
        std::fstream libraryDB;
        std::vector<std::string> libraryData;
};

#endif
