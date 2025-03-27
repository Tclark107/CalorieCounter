#ifndef SAVEDHISTORY_H
#define SAVEDHISTORY_H

#include <unordered_map>

class Date
{
    public:
        Date(int year, int month, int day);
    private:
        int year;
        int month;
        int day;
};

class SavedHistory
{
    public:
        SavedHistory();
        
    private:
        std::unordered_map<Date,int,int,int> dates;

};
#endif
