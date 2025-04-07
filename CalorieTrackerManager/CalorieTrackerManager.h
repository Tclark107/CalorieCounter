#ifndef CALORIETRACKERMANAGER_H
#define CALORIETRACKERMANAGER_H

#include <string>
#include <vector>

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
        ~CalorieTrackerManager();

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

        void loadLibraryData(std::vector<std::string>& libraryData);
        void saveLibraryDataToFoodLibrary(const std::vector<std::string>& libraryData);
        void parseLibraryData(const std::vector<std::string>& libraryData);
        std::vector<std::string> splitBySpaces(const std::string item);
        FoodItem createFoodItem(const std::vector<std::string> parsedItem);
};

#endif
