#include "CalorieTrackerManager.h"
#include "DBInterface.h"
#include "DBInterfaceFactory.h"
#include "CalorieCalculator.h"
#include "CalorieHistory.h"
#include "FoodItem.h"
#include "FoodLibrary.h"
#include "UserInterface.h"

#include <limits>

CalorieTrackerManager::CalorieTrackerManager() {}

CalorieTrackerManager::CalorieTrackerManager(bool devMode) :
devMode(devMode),
libraryDB(nullptr),
historyDB(nullptr),
ui(nullptr)
{}

CalorieTrackerManager::~CalorieTrackerManager()
{
    delete libraryDB;
    delete historyDB;
    delete ui;
}

void CalorieTrackerManager::startUp()
{
    try 
    {
        libraryDB = DBInterfaceFactory::createLibraryDBInterface(devMode);
        historyDB = DBInterfaceFactory::createHistoryDBInterface(devMode);
        ui = new UserInterface();
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Memory allocation failed during start u: " 
            << e.what() 
            << std::endl;
    }

    std::vector<std::string> libraryData;
    loadLibraryData(libraryData);
    saveLibraryDataToFoodLibrary(libraryData);

    std::vector<std::string> historyData;
    loadHistoryData(historyData);
    saveHistoryDataToHistory(historyData);

    run();
}

void CalorieTrackerManager::loadLibraryData(std::vector<std::string>& libraryData)
{
    libraryDB->connect();

    libraryDB->loadData();
    libraryData = libraryDB->getData();

    libraryDB->disconnect();
}

void CalorieTrackerManager::saveLibraryDataToFoodLibrary(const std::vector<std::string>& libraryData)
{
    std::cout << "Loading Data to FoodLibrary\n";
    std::vector<std::string> parsedItem;

    FoodItem newFoodItem;
    FoodLibrary& fl = FoodLibrary::GetInstance();

    for(const auto& item : libraryData)
    {
        parsedItem = splitBySpaces(item);       
        newFoodItem = createFoodItem(parsedItem);
        fl.addItem(newFoodItem);
    }
}

void CalorieTrackerManager::loadHistoryData(std::vector<std::string>& historyData)
{
    historyDB->connect();

    historyDB->loadData();
    historyData = historyDB->getData();

    historyDB->disconnect();
}

void CalorieTrackerManager::saveHistoryDataToHistory(const std::vector<std::string>& libraryData)
{
    std::cout << "Loading Data to History\n";
    std::vector<std::string> parsedDateInfo;
    std::vector<std::string> parsedItem;

    Date date;
    CalorieHistory& ch = CalorieHistory::GetInstance();

    for(const auto& item : libraryData)
    {
        parsedDateInfo = splitBySpaces(item);       
        date = createDate(parsedDateInfo);
        for(int i = 5; i < parsedDateInfo.size(); i++)
        {
            parsedItem = splitByDashes(parsedDateInfo[i]);
            FoodItem newFoodItem = createFoodItem(parsedItem);
            ch.saveDate(date, newFoodItem);
        }
        std::cout << std::endl;
    }
}

std::vector<std::string> CalorieTrackerManager::splitBySpaces(const std::string item)
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

std::vector<std::string> CalorieTrackerManager::splitByDashes(const std::string item)
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

FoodItem CalorieTrackerManager::createFoodItem(const std::vector<std::string> parsedItem)
{
    std::string name = parsedItem[0]; 
    int calories = std::stoi(parsedItem[1]);
    double proteins = std::stod(parsedItem[2]);
    double fats = std::stod(parsedItem[3]);
    double carbs = std::stod(parsedItem[4]);

    FoodItem newFoodItem(name, calories, proteins, fats, carbs);
    return newFoodItem;
}

Date CalorieTrackerManager::createDate(const std::vector<std::string> parsedItem)
{
    int year = std::stoi(parsedItem[0]);
    unsigned char month = static_cast<unsigned char>(std::stoi(parsedItem[1]));
    unsigned char day = static_cast<unsigned char>(std::stoi(parsedItem[2]));

    Date date(year, month, day);
    return date;
}

void CalorieTrackerManager::shutDown()
{
    libraryDB->connect();
    libraryDB->saveData();
    libraryDB->disconnect();

    historyDB->connect();
    historyDB->saveData();
    historyDB->disconnect();

    delete libraryDB;
    delete historyDB;
    delete ui;

    libraryDB = nullptr;
    historyDB = nullptr;
    ui = nullptr;
}

void CalorieTrackerManager::run()
{
    bool quit = false;
    std::string input;
    while(!quit)
    {
        ui->displayPrompt();
        input = ui->getUserInput(); 
        quit = handleInput(input);
    }
}

Option stringToOption(const std::string& input)
{
    if(input == "1") return exitloop;
    if(input == "2") return track;
    if(input == "3") return showLibrary;
    if(input == "4") return showDateData;
    if(input == "5") return showHistory;
    if(input == "6") return addItemToLibrary;
    return invalidOption;
}

bool CalorieTrackerManager::handleInput(std::string input)
{
    bool quit = false;
    FoodLibrary& fl = FoodLibrary::GetInstance();
    CalorieHistory& ch = CalorieHistory::GetInstance();

    Option option = stringToOption(input);
    switch(option)
    {
        case exitloop:
            quit = true;
            break;
        case track:
            trackItem();
            break;
        case showLibrary:
            fl.showFoodLibrary();
            libraryDB->displayData();
            break;
        case showDateData:
            //todaysData(today);
            break;
        case showHistory:
            ch.showHistory();
            historyDB->displayData();
            break;
        case addItemToLibrary:
            {
            FoodItem food;
            std::string name = getUserItem();
            food = createUserItem(name);
            addFoodToLibrary(food);
            break;
            }
        default:
            std::cout << "Input not recognized, please try again" << std::endl;
            break;
    }
    return quit;
}

FoodItem CalorieTrackerManager::createUserItem(std::string name)
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

std::string CalorieTrackerManager::getUserItem()
{
    std::string name;
    std::string prompt = "What is the name of the item you would like to add";
    ui->displayMessage(prompt);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);

    return name;
}

void CalorieTrackerManager::addFoodToLibrary(FoodItem food)
{
    FoodLibrary& fl = FoodLibrary::GetInstance();
    fl.addItem(food);
}

bool CalorieTrackerManager::isDevMode()
{
    return devMode;
}

void CalorieTrackerManager::trackItem()
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
    }
}


/*
oid UserInterface::todaysData(Date today)

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

void updateHistory()    
    for(int i = 0; i < historyData.size(); i++)
    {
        //Note: If string contains non-numeric characters stoi or stoul will throw std:invalid_argument
        // perhaps do some error checking
        int year = std::stoi(historyData[i][0]);
        unsigned char month = static_cast<unsigned char>(std::stoul(historyData[i][1]));
        unsigned char day = static_cast<unsigned char>(std::stoul(historyData[i][2]));
        Date date(year, month, day);    

        int numberOfEntries = std::stoi(historyData[i][4]);
        for(int j = 5; j < historyData[i].size(); j++)
        {
            std::vector<std::string> foodItem;
            std::stringstream ss(historyData[i][j]);
            std::string foodData;
            while(std::getline(ss, foodData, '-'))
            {
                foodItem.push_back(foodData);
            }
            
            FoodItem food(foodItem[0],
                          std::stoi(foodItem[1]),
                          std::stod(foodItem[2]),
                          std::stod(foodItem[3]),
                          std::stod(foodItem[4]));

            ch.saveDate(date,food);

        }
    }
    historyDB.close();
}
*/



