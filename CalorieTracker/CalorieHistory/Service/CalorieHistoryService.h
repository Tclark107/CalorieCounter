#ifndef CALORIE_HISTORY_SERVICE_H 
#define CALORIE_HISTORY_SERVICE_H 

#include <vector>
#include <string>
#include <utility>

class CalorieHistoryService
{
    public:
        CalorieHistoryService(const CalorieHistoryService&) = delete;

        int getTotalCalories(std::string date);
        double getTotalProteins(std::string date);
        double getTotalFats(std::string date);
        double getTotalCarbohydrates(std::string date);
        
        void showHistory();

        //std::string toString();
        
    private:

};

#endif
