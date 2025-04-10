#ifndef DEVHISTORYDBINTERFACE_H 
#define DEVHISTORYDBINTERFACE_H 

#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "DBInterface.h"

class DevHistoryDBInterface : public DBInterface
{
    public:
        DevHistoryDBInterface();

        bool connect() override;
        bool disconnect() override;
        void loadData() override;  // Load data from the database
        void saveData() override;  // Save data to the database
        void displayData() override;  // Display the data

        std::vector<std::string> getData() override;

        void addItem(const std::string& item);
        std::string getDate(const std::string&);
        bool inHistory(const std::string&);
        //std::vector splitBySpaces();


    private:
        std::fstream historyDB;
        std::map<std::string, std::string> historyData;
};

#endif
