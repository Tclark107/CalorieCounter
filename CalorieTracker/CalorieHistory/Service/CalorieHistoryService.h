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
        void writeToDatabase();

        void displayHistory();
        void trackItem(const std::string, const std::string);

        //std::string toString();
        
    private:
        DBInterface* db;
        bool devMode;
        History* history;

};

#endif
