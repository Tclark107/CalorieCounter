#ifndef AppManager_H
#define AppManager_H

#include <string>
#include <vector>

enum Option 
{
    EXIT_LOOP = 1,
    TRACK_ITEM,
    SHOW_LIBRARY,
    SHOW_TODAYS_MACROS,
    SHOW_HISTORY,
    ADD_ITEM_TO_LIBRARY,
    RECORD_WEIGHT,
    AVERAGE_WEIGHT,
    INVALID_OPTION
};

class DBInterface;
class UserInterface;
class Date;
class WeightTrackerFacade;
class CalorieTrackerManager;

class AppManager 
{
    public:
        AppManager();
        ~AppManager();

        AppManager(bool devMode);
        void startUp();
        void run();
        void shutDown();

        bool handleInput(std::string input);
        void showTodaysMacros();
        void trackItem();
        void showHistory();
        void recordWeight();
        void getAverageWeight();

    private:
        bool devMode;
        UserInterface *ui;
        WeightTrackerFacade *wt;
        CalorieTrackerManager *ctm;

};

#endif
