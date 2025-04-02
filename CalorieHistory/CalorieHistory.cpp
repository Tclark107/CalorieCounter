#include "CalorieHistory.h"

Date::Date(int year, unsigned char month, unsigned char day) :
    year (year),
    month (month),
    day (day)
{}

CalorieHistory::CalorieHistory()
{
    Date today = getCurrentDate();
    saveDate(today);
}

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

    if(checkDate(date))
    {
        std::cout << "Why are you trying to save a date that is "
            << "already saved" << std::endl;
        return;
    }

    history.push_back(std::make_pair(date,std::vector<FoodItem>()));
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

