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
        FoodItem getItem(const std::string);
        bool inLibrary(const std::string);
        std::string toString(FoodItem item);

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
