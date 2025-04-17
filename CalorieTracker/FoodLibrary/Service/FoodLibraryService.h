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

        void addEntry(const std::string, 
                      const int,
                      const double,
                      const double,
                      const double);

        void saveEntryToDataBase(const std::string&);
        void saveEntryInternal(const std::string, 
                               const int,
                               const double,
                               const double,
                               const double);
        void saveDataFromDatabase();
        void displayLibrary();

    private:
        DBInterface* db;
        bool devMode;
        std::unordered_map<std::string, FoodItem> items;
};
#endif 
