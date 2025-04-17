#include "FoodLibraryService.h"
#include "Utility.h"
#include "FoodLibraryDBInterfaceFactory.h"
#include "FileIODBInterface.h"

#include <iostream>
#include <sstream>

FoodLibraryService::FoodLibraryService(bool devMode) : 
db(nullptr),
devMode(devMode),
items()
{
    db = FoodLibraryDBInterfaceFactory::createDBInterface(devMode);

    db->connect();
    db->loadData();
    db->displayData();
    db->disconnect();
    saveDataFromDatabase();
}

void FoodLibraryService::saveDataFromDatabase()
{
    FileIODBInterface* fileIODB = dynamic_cast<FileIODBInterface*>(db);

    int dbSize = fileIODB->getSize();
    std::string foodItem = "";
    std::vector<std::string> parsedFoodItem;

    std::string name = "";
    int calories = 0;
    double proteins = 0;
    double fats = 0;
    double carbs = 0;
    
    for(int i = 0; i < dbSize; i++)
    {
        foodItem = fileIODB->getItem(i);
        parsedFoodItem = Utility::splitByDashes(foodItem);
        name = parsedFoodItem[0];
        calories = Utility::convertStringToInt(parsedFoodItem[1]);
        proteins = Utility::convertStringToDouble(parsedFoodItem[2]);
        fats = Utility::convertStringToDouble(parsedFoodItem[3]);
        carbs = Utility::convertStringToDouble(parsedFoodItem[4]);
        
        saveEntryInternal(name, calories, proteins, fats, carbs);
    }
}

void FoodLibraryService::addEntry(const std::string name,
                                  const int calories,
                                  const double proteins,
                                  const double fats,
                                  const double carbs)
{
    saveEntryInternal(name, calories, proteins, fats, carbs);
}

void FoodLibraryService::saveEntryToDataBase(const std::string& name)
{

    std::string foodData = name + "-"
                     + std::to_string(items[name].getCalories()) + "-"
                     + std::to_string(items[name].getProteins()) + "-"
                     + std::to_string(items[name].getFats()) + "-"
                     + std::to_string(items[name].getCarbohydrates());
    //set precision

    std::cout << foodData << std::endl;

    FileIODBInterface* fileIODB = dynamic_cast<FileIODBInterface*>(db);
    fileIODB->connect();
    //fileIODB->saveItem(foodData);
    fileIODB->saveData();
    fileIODB->displayData();
    fileIODB->disconnect();
}

void FoodLibraryService::saveEntryInternal(const std::string name,
                                           const int calories,
                                           const double proteins,
                                           const double fats,
                                           const double carbs)
{
    FoodItem item(name, calories, proteins, fats, carbs);
    items[name] = item;
}

void FoodLibraryService::displayLibrary()
{
    std::cout << std::endl;
    std::cout << "FoodLibraryService::displayLibrary()\n";
    for(auto& pair : items)
    {
    	std::cout << pair.first << " "; 
    	std::cout << pair.second << std::endl;
    }
    std::cout << std::endl;
}
