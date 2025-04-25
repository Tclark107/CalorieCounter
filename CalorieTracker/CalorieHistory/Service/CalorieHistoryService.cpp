#include "CalorieHistoryService.h"
#include "Utility.h"
#include "History.h"
#include "HistoryDBInterfaceFactory.h"
#include "FileIODBInterface.h"

#include <iostream>

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

    std::string date = "";
    std::vector<std::string> parsedDate;

    int dbSize = fileIODB->getSize();
    for(int i = 0; i < dbSize; i++)
    {
        date = fileIODB->getItem(i);
        parsedDate = Utility::splitByColons(date);
        date = parsedDate[0];
        std::cout << "Date: " << date;
        for(int j = 1; j < parsedDate.size(); j++)
        {
            history->addItemToDate(date, parsedDate[j]);
        }
        std::string output = history->getHistory(parsedDate[0]);
        std::cout << "Printing date saved in Model\n";
        std::cout << output << std::endl;
    }
}

void CalorieHistoryService::writeToDatabase()
{
    std::cout << "CalorieHistoryService::writeToDatabase()\n";
    std::vector<std::string> dates = history->getAllDates();

    std::string todaysDate = Utility::getDate();
    FileIODBInterface* fileIODB = dynamic_cast<FileIODBInterface*>(db);

    fileIODB->connect();

    std::string date = "";
    std::vector<std::string> parsedDate;
    
    bool dateExists = false;
    int dbSize = fileIODB->getSize();
    for(int i = 0; i < dbSize; i++)
    {
        date = fileIODB->getItem(i);
        parsedDate = Utility::splitByColons(date);
        date = parsedDate[0];

        if(date == todaysDate)
        {
            dateExists = true;
            std::cout << "Its today" << std::endl;
            std::cout << "todays history = " << history->getHistory(todaysDate) << std::endl;
            fileIODB->replaceItem(history->getHistory(todaysDate), i);
        }
    }

    if(!dateExists)
    {
        fileIODB->addItem(history->getHistory(todaysDate));
    }

    fileIODB->displayData();
    fileIODB->saveData();

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
