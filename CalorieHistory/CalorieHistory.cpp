#include "CalorieHistory.h"

#include <sstream>
#include <iomanip>
#include <algorithm>

Date::Date(int year, unsigned char month, unsigned char day) :
    year (year),
    month (month),
    day (day)
{}

Date CalorieHistory::getCurrentDate()
{
    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);
    std::cout << "Date is " << static_cast<int>(now->tm_year + 1900)
        << " " << static_cast<int>(now->tm_mon + 1)
        << " " << static_cast<int>(now->tm_mday);
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
    for(int i = history.size() - 1; i >= 0; i--)
    {
        if(date == history[i].first)
        {
            history[i].second.push_back(item);
            dateFound = true;
            break;
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
    std::cout << std::endl;
    std::cout << "CalorieHistory::showHistory()\n";
    for(int i = history.size() - 1; i >= 0; i--)
    {
        std::cout << history[i].first << ": ";
        for(int j = 0; j < history[i].second.size(); j++)
        {

            std::cout << history[i].second[j] << " - ";
        }
        std::cout << std::endl;
    }    
    std::cout << std::endl;
}

std::string CalorieHistory::toString(const Date& date)
{
    std::cout << "CalorieHistory::toString(const Date& date)\n";
    std::stringstream ss;
    showHistory();
    int totalCalories = getTotalCalories(date);
    for(int i = history.size() - 1; i >= 0; i--)
    {
        if(date == history[i].first)
        {
            std::cout << "histifirst " << history[i].first << std::endl;
            ss << history[i].first << " "
                << totalCalories << " "
                << history[i].second.size() << " ";
            for(int j = 0; j < history[i].second.size(); j++)
            {
                std::cout << history[i].second[j] << " == ";
                ss << history[i].second[j] << " ";
            }
            std::cout << std::endl;
        }
    }
    std::string result = ss.str();
    return result;
}
