#ifndef CALORIETRACKERMANAGER_H
#define CALORIETRACKERMANAGER_H

#include <string>

enum Option 
{
    exitloop = 1,
    track,
    showLibrary,
    showDateData,
    showHistory,
    invalidOption
};

class DBInterface;
class UserInterface;

class CalorieTrackerManager 
{
    public:
        CalorieTrackerManager();
        CalorieTrackerManager(bool devMode);
        void startUp();
        void shutDown();
        void run();
        bool handleInput(std::string input);
        bool isDevMode();

    private:
        bool devMode;
        DBInterface *dbi;
        UserInterface *ui;
};

#endif
