#ifndef FOOD_LIBRARY_SERVICE_H
#define FOOD_LIBRARY_SERVICE_H

#include "FoodItem.h"

#include <unordered_map>
#include <string>

class DBInterface;

class FoodLibraryService
{
    public:
        FoodLibraryService(bool);

        void saveDataFromDatabase();

        bool inLibrary(const std::string);
        void addItem(const std::string, 
                      const int,
                      const double,
                      const double,
                      const double);
        FoodItem createItem(const std::string, 
                            const int,
                            const double,
                            const double,
                            const double);

        std::string toString(FoodItem item);
        std::string getStringItem(const std::string);
        FoodItem getItem(const std::string);

        int getItemCalories(const std::string);
        double getItemProteins(const std::string);
        double getItemFats(const std::string);
        double getItemCarbs(const std::string);

        void saveEntryToDataBase(const std::string&);
        void saveEntryInternal(FoodItem);
        void writeItemToDB(const std::string);

        void displayLibrary();

    private:
        DBInterface* db;
        bool devMode;
        std::unordered_map<std::string, FoodItem> items;
};
#endif 
