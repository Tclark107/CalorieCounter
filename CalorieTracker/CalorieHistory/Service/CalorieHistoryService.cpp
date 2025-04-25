#include "CalorieHistoryService.h"
#include "Utility.h"
#include "History.h"
#include "HistoryDBInterfaceFactory.h"
#include "FileIODBInterface.h"

#include <iostream>
#include <sstream>

CalorieHistoryService::CalorieHistoryService(bool devMode) :
db(nullptr),
history(nullptr),
devMode(devMode)
{
    db = HistoryDBInterfaceFactory::createDBInterface(devMode);
    history = new History();

    db->connect();
    db->loadData();
    db->displayData();
    saveFromDatabase();
    db->disconnect();
}

void CalorieHistoryService::saveFromDatabase()
{
    FileIODBInterface* fileIODB = dynamic_cast<FileIODBInterface*>(db);

    std::string item = "";
    std::stringstream ss;
    std::string date;
    std::vector<std::string> parsedDate;
    std::vector<std::string> parsedItem;

    int dbSize = fileIODB->getSize();
    for(int i = 0; i < dbSize; i++)
    {
        item = fileIODB->getItem(i);
        parsedItem = Utility::splitByColons(item);
        parsedDate = Utility::splitByDashes(parsedItem[0]);
        ss << parsedDate[0] << "-" << parsedDate[1] << "-" << parsedDate[2];
        date = ss.str();

        std::cout << "Date: " << date << std::endl;
        for(int j = 1; j < parsedItem.size(); j++)
        {
            history->addItemToDate(date, parsedItem[j]);
        }
        std::string output = history->getHistory(date);
        std::cout << "Printing date saved in Model\n";
        std::cout << output << std::endl;

        ss.str("");
        ss.clear();
    }
}

void CalorieHistoryService::writeToDatabase()
{
    std::cout << "CalorieHistoryService::writeToDatabase()\n";

    FileIODBInterface* fileIODB = dynamic_cast<FileIODBInterface*>(db);

    fileIODB->connect();
    std::vector<std::string> dates = history->getAllDates();
    displayHistory();
    for(auto& date : dates)
    {
        std::cout << history->getHistory(date) << std::endl;
        std::cout << "blah\n";
        //fileIODB->saveItem(history->getHistory(date));
    }

    fileIODB->saveData();
    fileIODB->displayData();
    fileIODB->disconnect();
}

void CalorieHistoryService::trackItem(const std::string date, const std::string item)
{
    std::cout << "CalorieHistoryService::trackItem(date, item)\n" << std::endl;
    history->addItemToDate(date, item);
}

void CalorieHistoryService::displayHistory()
{
    std::vector<std::string> dates = history->getAllDates();
    std::string output = "";
    for(auto& date : dates)
    {
        output = history->getHistory(date);
        std::cout << output << std::endl;
    }
}
