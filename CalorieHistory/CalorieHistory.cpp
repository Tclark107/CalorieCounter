#include "CalorieHistory.h"

Date::Date(int year, unsigned char month, unsigned char day) :
    year (year),
    month (month),
    day (day)
{}

Date CalorieHistory::getCurrentDate()
{
    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);

    Date todaysDate(static_cast<int>(now->tm_year + 1900),
                    static_cast<unsigned char>(now->tm_mon + 1),
                    static_cast<unsigned char>(now->tm_mday)
                    );
    
    return todaysDate;
}

void CalorieHistory::saveDate(Date date)
{
    //TODO: put error checking if it exists
    //TODO: write a date output overwritten function"
    //TODO: do this using error calls or exceptions

    //if(checkDate(date))
    //{
    //    std::cout << "Why are you trying to save a date that is "
    //        << "already saved" << std::endl;
    //    return;
    //}

    history.push_back(std::make_pair(date,std::vector<FoodItem>()));
}

void CalorieHistory::saveDate(Date date, FoodItem item)
{
    // TODO:findDate Function that returns an Index of where the date is
    // If date found then do this
    bool dateFound = false;
    for(int i = i = history.size() - 1; i >= 0; i--)
    {
        if(date == history[i].first)
        {
            history[i].second.push_back(item);
            dateFound = true;
        }
    }
    if(!dateFound)
    {
        std::vector<FoodItem> newEntry;
        newEntry.push_back(item);
        history.push_back(std::make_pair(date, newEntry));
    }
}

bool CalorieHistory::checkDate(Date date)
{
    //TODO: put error checking if it exists
    //TODO: write a date output overwritten function"
    //TODO: do this using error calls or exceptions
    
    for(int i = history.size() - 1; i >= 0; i--)
    {
        if(date == history[i].first) return true;
    }
    return false;
}


int CalorieHistory::getTotalCalories(Date date)
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

double CalorieHistory::getTotalProteins(Date date)
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

double CalorieHistory::getTotalFats(Date date)
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

double CalorieHistory::getTotalCarbohydrates(Date date)
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




void CalorieHistory::showHistory()
{

}

