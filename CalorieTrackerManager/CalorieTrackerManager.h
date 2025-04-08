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
class Date;

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
        std::string getUserItem();
        FoodItem createUserItem(std::string name);
        void addFoodToLibrary(FoodItem food);
        void addFoodToDataBase(FoodItem food);
        void trackItem();

    private:
        bool devMode;
        DBInterface *libraryDB;
        DBInterface *historyDB;
        UserInterface *ui;

        void loadLibraryData(std::vector<std::string>& libraryData);
        void saveLibraryDataToFoodLibrary(const std::vector<std::string>& libraryData);
        FoodItem createFoodItem(const std::vector<std::string> parsedItem);

        void loadHistoryData(std::vector<std::string>& historyData);
        void saveHistoryDataToHistory(const std::vector<std::string>& libraryData);
        Date createDate(const std::vector<std::string> parsedItem);

        std::vector<std::string> splitBySpaces(const std::string item);
        std::vector<std::string> splitByDashes(const std::string item);
};

#endif
