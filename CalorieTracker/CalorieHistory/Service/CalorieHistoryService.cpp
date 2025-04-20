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
        for(int j = 3; j < parsedDate.size(); j++)
        {
            history->addItemToDate(date, parsedDate[j]);
        }
        std::string output = history->getHistory(parsedDate[0]);
        std::cout << "Printing date saved in Model\n";
        std::cout << output << std::endl;
    }

}

/*
int CalorieHistoryService::getTotalCalories(std::string date)
{
    int result = 0;
    for(int i = history.size() - 1; i >= 0; i--)
    {
        // make a find const std::string function
        if(const std::string == history[i].first)
        {
            for(auto entry : history[i].second)
            {
                result += entry.getCalories();
            }
        }
    }
    return result;
}

double CalorieHistoryService::getTotalProteins(std::string date)
{
    int result = 0;
    for(int i = history.size() - 1; i >= 0; i--)
    {
        // make a find const std::string function
        if(const std::string == history[i].first)
        {
            for(auto entry : history[i].second)
            {
                result += entry.getProteins();
            }
        }
    }
    return result;
}

double CalorieHistoryService::getTotalFats(std::string date)
{
    int result = 0;
    for(int i = history.size() - 1; i >= 0; i--)
    {
        // make a find const std::string function
        if(const std::string == history[i].first)
        {
            for(auto entry : history[i].second)
            {
                result += entry.getFats();
            }
        }
    }
    return result;
}

double CalorieHistoryService::getTotalCarbohydrates(std::string date)
{
    int result = 0;
    for(int i = history.size() - 1; i >= 0; i--)
    {
        // make a find const std::string function
        if(const std::string == history[i].first)
        {
            for(auto entry : history[i].second)
            {
                result += entry.getCarbohydrates();
            }
        }
    }
    return result;
}
*/

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
