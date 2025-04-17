#include "CalorieHistoryService.h"

#include <sstream>
#include <iomanip>
#include <algorithm>

Date::Date(int year, unsigned char month, unsigned char day) :
    year (year),
    month (month),
    day (day)
{}

Date CalorieHistoryService::getCurrentDate()
{
    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);
    Date todaysDate(static_cast<int>(now->tm_year + 1900),
                    static_cast<unsigned char>(now->tm_mon + 1),
                    static_cast<unsigned char>(now->tm_mday)
                    );
    
    return todaysDate;
}

void CalorieHistoryService::saveDate(Date date)
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

void CalorieHistoryService::saveDate(Date date, FoodItem item)
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

bool CalorieHistoryService::checkDate(Date date)
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
    std::cout << std::endl;
    std::cout << "CalorieHistoryService::showHistory()\n";
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

std::string CalorieHistoryService::toString(const Date& date)
{
    std::cout << "CalorieHistoryService::toString(const Date& date)\n";
    std::stringstream ss;
    showHistory();
    int totalCalories = getTotalCalories(date);
    for(int i = history.size() - 1; i >= 0; i--)
    {
        if(date == history[i].first)
        {
            ss << history[i].first << " "
                << totalCalories << " "
                << history[i].second.size() << " ";
            for(int j = 0; j < history[i].second.size(); j++)
            {
                ss << history[i].second[j] << " ";
            }
            std::cout << std::endl;
        }
    }
    std::string result = ss.str();
    return result;
}
