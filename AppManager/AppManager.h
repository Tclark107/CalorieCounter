#ifndef AppManager_H
#define AppManager_H

#include <string>
#include <vector>

enum Option 
{
    exitloop = 1,
    track,
    SHOW_LIBRARY,
    showDateData,
    showHistory,
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
        void shutDown();
        void run();
        bool handleInput(std::string input);
        void recordWeight();
        void getAverageWeight();

    private:
        bool devMode;
        UserInterface *ui;
        WeightTrackerFacade *wt;
        CalorieTrackerManager *ctm;

};

#endif
