#include "CalorieHistoryService.h"

#include "HistoryDBInterfaceFactory.h"

CalorieHistoryService::CalorieHistoryService(bool devMode) :
db(nullptr),
devMode(devMode)
{
    db = HistoryDBInterfaceFactory::createDBInterface(devMode);

    db->connect();
    db->loadData();
    db->displayData();
    db->disconnect();
    saveFromDatabase()
}

void CalorieHistoryService::saveFromDatabase()
{
    FileIODBInterface* fileIODB = dynamic_cast<FileIODBInterface*>(db);
    //read item from db line by line
    //parse it line by line
    //call history, store it in history structure

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
}
