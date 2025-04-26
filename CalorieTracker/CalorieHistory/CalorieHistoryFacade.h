#ifndef CALORIE_HISTORY_FACADE_H
#define CALORIE_HISTORY_FACADE_H

#include <string>
#include <vector>

class UserInterface;
class CalorieHistoryService;

class CalorieHistoryFacade
{
    public:
        CalorieHistoryFacade(bool devMode, UserInterface* ui);

        void displayHistory();
        void displayTodaysMacros();
        void trackItem(const std::string, const std::string);
        void saveHistory();
        std::vector<std::string> getTodaysFoodItems();

    private:
        UserInterface* ui;
        CalorieHistoryService* cHS;
};

#endif
