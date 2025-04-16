#include "CalorieTrackerManager.h"
#include "FoodLibraryFacade.h"
#include "UserInterface.h"

#include <iostream>

CalorieTrackerManager::CalorieTrackerManager () {}

CalorieTrackerManager::CalorieTrackerManager(bool devMode, UserInterface* ui)
{
    try
    {
        fl = new FoodLibraryFacade(devMode, ui);
        //ch = new CalorieHistoryFacade(devMode, ui);
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Memory allocation failed during start u: " 
            << e.what() 
            << std::endl;
    }

}

CalorieTrackerManager::~CalorieTrackerManager () 
{
    delete fl;
    //delete ch;
}

/*
//
//td::string AppManager::getUserItem()
//
//   std::string name;
//   std::string prompt = "What is the name of the item you would like to add";
//   ui->displayMessage(prompt);
//   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//   std::getline(std::cin, name);
//
//   return name;



FoodItem AppManager::createUserItem(std::string name)
{
    std::string prompt = "";
    std::string placeHolder = "";

    int calories = 0;
    double proteins = 0;
    double fats = 0;
    double carbs = 0;

    prompt = "How many calories are in " + name + "?";
    ui->displayMessage(prompt);
    std::cin >> placeHolder;
    calories = std::stoi(placeHolder);

    prompt = "How many proteins are in " + name + "?";
    ui->displayMessage(prompt);
    std::cin >> placeHolder;
    proteins = std::stod(placeHolder);

    prompt = "How many fats are in " + name + "?";
    ui->displayMessage(prompt);
    std::cin >> placeHolder;
    fats = std::stod(placeHolder);

    prompt = "How many carbs are in " + name + "?";
    ui->displayMessage(prompt);
    std::cin >> placeHolder;
    carbs = std::stod(placeHolder);

    FoodLibrary& fl = FoodLibrary::GetInstance();
    FoodItem food(name, calories, proteins, fats, carbs);
    return food;
}

void AppManager::trackItem()
{
    CalorieHistory& ch = CalorieHistory::GetInstance();
    FoodLibrary& fl = FoodLibrary::GetInstance();

    Date today = ch.getCurrentDate();
    std::string foodItem = getUserItem();

    if(fl.inLibrary(foodItem))
    {
        //std::cout << "What amount in oz did you eat?\n"; 
        ch.saveDate(today, fl.getItem(foodItem));
    }
    else
    {
        FoodItem food;
        food = createUserItem(foodItem);
        ch.saveDate(today, food);

        addFoodToLibrary(food);
        addFoodToLibraryDataBase(food);
    }
}

void AppManager::loadHistoryData(std::vector<std::string>& historyData)
{
    historyDB->connect();

    historyDB->loadData();
    historyData = historyDB->getData();

    historyDB->disconnect();
}


void AppManager::saveHistoryDataToHistory(const std::vector<std::string>& historyData)
{
    std::cout << "Loading Data to History\n";
    std::vector<std::string> parsedDateInfo;
    std::vector<std::string> parsedItem;

    Date date;
    CalorieHistory& ch = CalorieHistory::GetInstance();

    for(const auto& item : historyData)
    {
        parsedDateInfo = splitBySpaces(item);
        date = createDate(parsedDateInfo);

        for(int i = 5; i < parsedDateInfo.size(); i++)
        {
            parsedItem = splitByDashes(parsedDateInfo[i]);
            FoodItem newFoodItem = createFoodItem(parsedItem);
            ch.saveDate(date, newFoodItem);
        }
    }
}

std::vector<std::string> AppManager::splitBySpaces(const std::string item)
{
    std::istringstream iss(item);
    std::vector<std::string> words;
    std::string word;
    while(iss >> word)
    {
        words.push_back(word);
    }
    return words;
}

std::vector<std::string> AppManager::splitByDashes(const std::string item)
{
    std::istringstream iss(item);
    std::vector<std::string> words;
    std::string word;
    while(std::getline(iss, word, '-'))
    {
        words.push_back(word);
    }
    return words;
}

Date AppManager::createDate(const std::vector<std::string> parsedItem)
{
    int year = 0;
    unsigned char month = 0;
    unsigned char day = 0;

    if(parsedItem.size() < 3)
    {
        std::cerr << "Error: Not enough elements in parsedItem to construct a Date. "
            << "Date has " << parsedItem.size() << " elements.\n";
    }

    try
    {
        year = std::stoi(parsedItem[0]);
        month = static_cast<unsigned char>(std::stoi(parsedItem[1]));
        day = static_cast<unsigned char>(std::stoi(parsedItem[2]));
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Error: Parsed item index out of range. " << e.what() << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "Error: Invalid argument during string to number conversions. " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "General error during parsing: " << e.what() << std::endl;
    }

    Date date(year, month, day);
    return date;
}
bool AppManager::isDevMode()
{
    return devMode;
}

void AppManager::addDatatoHistoryDatabase()
{
    CalorieHistory& ch = CalorieHistory::GetInstance();
    Date date = ch.getCurrentDate();
    std::string strDateData = ch.toString(date);
    historyDB->addItem(strDateData);
}

void AppManager::displayTodaysMacros()
{
    CalorieHistory& ch = CalorieHistory::GetInstance();
    Date today = ch.getCurrentDate();
    int calories = ch.getTotalCalories(today);
    int proteins = ch.getTotalProteins(today);
    int fats = ch.getTotalFats(today);
    int carbs = ch.getTotalCarbohydrates(today);

    std::cout << std::endl;
    std::cout << "Today you have had " << calories << " calories, "
        << proteins << " grams of protien, " 
        << fats << " grams of fat, and " 
        << carbs << " grams of carbohydrates.\n";
    std::cout << std::endl;
}

*/
