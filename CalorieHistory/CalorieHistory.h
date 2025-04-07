#ifndef CALORIEHISTORY_H 
#define CALORIEHISTORY_H 

#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <utility>

#include "FoodItem.h"

class Date
{
    public:
        Date() {};
        Date(int year, unsigned char month, unsigned char day);
        int getYear() const { return year; }
        unsigned char getMonth() const { return month; }
        unsigned char getDay() const { return day; }

        bool operator==(const Date& other) const {
         return (year == other.year) && (month == other.month) && (day == other.day);
        }

    private:
        int year;
        unsigned char month;
        unsigned char day;
};

inline std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << std::setw(4) << std::setfill('0') << date.getYear() << ' '
       << std::setw(2) << std::setfill('0') << static_cast<int>(date.getMonth()) << ' '
       << std::setw(2) << std::setfill('0') << static_cast<int>(date.getDay());
    return os;
}

class CalorieHistory
{
    public:
        static CalorieHistory& GetInstance()
        {
            static CalorieHistory instance;
            return instance;
        }

        CalorieHistory(const CalorieHistory&) = delete;
        void operator=(const CalorieHistory&) = delete;

        Date getCurrentDate();

        int getTotalCalories(Date date);
        double getTotalProteins(Date date);
        double getTotalFats(Date date);
        double getTotalCarbohydrates(Date date);
        
        bool checkDate(Date date); // This might be an unneeded function
                                    // Why would the user want to check if the current date
                                    // is there a reason to have this?
                                    // I could see the user maybe wanting to get a specific date??
        void saveDate(Date date);
        void saveDate(Date date, FoodItem item);
        
        void showHistory();

        std::vector<std::pair<Date,std::vector<FoodItem>>>& getHistory()
        {
            return history;
        }
        
        
    private:
        std::vector<std::pair<Date,std::vector<FoodItem>>> history;
        CalorieHistory() {};

};

#endif
