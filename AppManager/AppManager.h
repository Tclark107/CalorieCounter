#ifndef AppManager_H
#define AppManager_H

#include <string>
#include <vector>

enum Option 
{
    EXIT_LOOP = 1,
    TRACK_ITEM,
    SHOW_LIBRARY,
    showDateData,
    SHOW_HISTORY,
    ADD_ITEM_TO_LIBRARY,
    recWeight,
    AVERAGE_WEIGHT,
    invalidOption
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
