#ifndef CALORIE_HISTORY_SERVICE_H 
#define CALORIE_HISTORY_SERVICE_H 

#include <vector>
#include <string>
#include <utility>

class DBInterface;
class History;

class CalorieHistoryService
{
    public:
        CalorieHistoryService(bool);

        void saveFromDatabase();

        //int getTotalCalories(std::string date);
        //double getTotalProteins(std::string date);
        //double getTotalFats(std::string date);
        //double getTotalCarbohydrates(std::string date);
        
        void displayHistory();

        //std::string toString();
        
    private:
        DBInterface* db;
        bool devMode;
        History* history;

};

#endif
