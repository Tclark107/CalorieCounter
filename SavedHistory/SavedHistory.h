#ifndef SAVEDHISTORY_H
#define SAVEDHISTORY_H

#include <chrono>
#include <format>
#include <vector>

using namespace std::chrono;
class Date
{
    public:
        Date();
        Date(int year, int month, int day);
    private:
        int year;
        int month;
        int day;
}

class SavedHistory
{
    public:
        SavedHistory();
        SavedHistory(int year, int month, int day);
        Date getCurrentDate();
        bool checkDate();
        
    private:
        std::vector<Date> dates;

};
#endif
