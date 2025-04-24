#ifndef CALORIE_HISTORY_FACADE_H
#define CALORIE_HISTORY_FACADE_H

#include <string>

class UserInterface;
class CalorieHistoryService;

class CalorieHistoryFacade
{
    public:
        CalorieHistoryFacade(bool devMode, UserInterface* ui);

        void displayHistory();
        void addItemToHistory();
        void trackItem(const std::string, const std::string);
        void saveHistory();

    private:
        UserInterface* ui;
        CalorieHistoryService* cHS;
        //foodLibraryfacade
};

#endif
