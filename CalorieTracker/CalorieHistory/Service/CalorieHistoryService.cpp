#include "CalorieHistoryService.h"

#include "HistoryDBInterfaceFactory.h"

CalorieHistoryService::CalorieHistoryService() :
db(nullptr),
devMode(devMode)
{
    db = HistoryDBInterfaceFactory::createDBInterface(devMode);

    db->connect();
    db->loadData();
    db->displayData();
    db->disconnect();
    //saveFromDatabase()
}

//void CalorieHistoryService::saveFromDatabase()
//{
//
//}
int CalorieHistoryService::getTotalCalories(Date date)
{
    int result = 0;
    for(int i = history.size() - 1; i >= 0; i--)
    {
        // make a find date function
        if(date == history[i].first)
        {
            for(auto entry : history[i].second)
            {
                result += entry.getCalories();
            }
        }
    }
    return result;
}

double CalorieHistoryService::getTotalProteins(Date date)
{
    int result = 0;
    for(int i = history.size() - 1; i >= 0; i--)
    {
        // make a find date function
        if(date == history[i].first)
        {
            for(auto entry : history[i].second)
            {
                result += entry.getProteins();
            }
        }
    }
    return result;
}

double CalorieHistoryService::getTotalFats(Date date)
{
    int result = 0;
    for(int i = history.size() - 1; i >= 0; i--)
    {
        // make a find date function
        if(date == history[i].first)
        {
            for(auto entry : history[i].second)
            {
                result += entry.getFats();
            }
        }
    }
    return result;
}

double CalorieHistoryService::getTotalCarbohydrates(Date date)
{
    int result = 0;
    for(int i = history.size() - 1; i >= 0; i--)
    {
        // make a find date function
        if(date == history[i].first)
        {
            for(auto entry : history[i].second)
            {
                result += entry.getCarbohydrates();
            }
        }
    }
    return result;
}

void CalorieHistoryService::showHistory()
{
}
