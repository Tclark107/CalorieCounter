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
    addItemToLibrary,
    invalidOption
};

class DBInterface;
class UserInterface;
class FoodItem;

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
        void createItem();
        void addFoodToLibrary(FoodItem food);

    private:
        bool devMode;
        DBInterface *libraryDB;
        DBInterface *historyDB;
        UserInterface *ui;
};

#endif
