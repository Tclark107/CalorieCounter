#include "FoodLibraryService.h"
#include "Utility.h"
#include "FoodLibraryDBInterfaceFactory.h"
#include "FileIODBInterface.h"

#include <iostream>
#include <iomanip>
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
        
        FoodItem item = createItem(name, calories, proteins, fats, carbs);
        saveEntryInternal(item);
    }
}

void FoodLibraryService::addItem(const std::string name,
                                  const int calories,
                                  const double proteins,
                                  const double fats,
                                  const double carbs)
{
    FoodItem item = createItem(name, calories, proteins, fats, carbs);
    saveEntryInternal(item);
}

std::string FoodLibraryService::toString(FoodItem item)
{
    std::stringstream ss;
    ss << item.getName() << "-"
       << item.getCalories() << "-"
       << item.getProteins() << "-"
       << item.getFats() << "-"
       << item.getCarbohydrates();

    std::string result = ss.str();
    return result;
}

std::string FoodLibraryService::getStringItem(const std::string name)
{
    FoodItem item = getItem(name);
    return toString(item);
}
bool FoodLibraryService::inLibrary(const std::string name)
{
    if(items.find(name) != items.end())
    {
        return true;
    }
    return false;
}

int FoodLibraryService::getItemCalories(const std::string name)
{
    if(!inLibrary(name))
    {
        std::cerr << "Trying to get Calories of Item that is not in Library";
        std::cerr << "returning 0\n";
        return 0;
    }
    return items[name].getCalories();
}

double FoodLibraryService::getItemProteins(const std::string name)
{
    if(!inLibrary(name))
    {
        std::cerr << "Trying to get Proteins of Item that is not in Library";
        std::cerr << "returning 0\n";
        return 0;
    }
    return items[name].getProteins();
}

double FoodLibraryService::getItemFats(const std::string name)
{
    if(!inLibrary(name))
    {
        std::cerr << "Trying to get Fats of Item that is not in Library";
        std::cerr << "returning 0\n";
        return 0;
    }
    return items[name].getFats();
}

double FoodLibraryService::getItemCarbs(const std::string name)
{
    if(!inLibrary(name))
    {
        std::cerr << "Trying to get Carbs of Item that is not in Library";
        std::cerr << "returning 0\n";
        return 0;
    }
    return items[name].getCarbohydrates();
}

FoodItem FoodLibraryService::getItem(const std::string name)
{
    return items[name];
}

void FoodLibraryService::saveEntryToDataBase(const std::string& name)
{
    if(!inLibrary(name))
    {
        std::cerr << "FoodLibraryService::saveEntryToDataBase() "
            << "item: " << name << " is not in internal library.\n";
        return;
    }
    FoodItem item = getItem(name);
    std::string foodData = toString(item);
    std::cout << foodData << std::endl;

    writeItemToDB(foodData);
}

void FoodLibraryService::writeItemToDB(const std::string data)
{
    FileIODBInterface* fileIODB = dynamic_cast<FileIODBInterface*>(db);
    fileIODB->connect();
    fileIODB->addItem(data);
    fileIODB->saveData();
    fileIODB->displayData();
    fileIODB->disconnect();
}

FoodItem FoodLibraryService::createItem(std::string name,
                    int calories,
                    double proteins,
                    double fats,
                    double carbs)
{
    FoodItem food;
    food.setName(name);
    food.setCalories(calories);
    food.setProteins(proteins);
    food.setFats(fats);
    food.setCarbohydrates(carbs);
    return food;
}


void FoodLibraryService::saveEntryInternal(FoodItem item)
{
    items[item.getName()] = item;
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
