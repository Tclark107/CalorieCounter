#include "CalorieTrackerManager.h"
#include "DBInterface.h"
#include "CalorieCalculator.h"
#include "CalorieHistory.h"
#include "FoodItem.h"
#include "FoodLibrary.h"
#include "UserInterface.h"

CalorieTrackerManager::CalorieTrackerManager() {}

CalorieTrackerManager::CalorieTrackerManager(bool devMode) :
devMode(devMode),
dbi(nullptr),
ui(nullptr)
{}

void CalorieTrackerManager::startUp()
{
    try 
    {
        dbi = new DBInterface();
        ui = new UserInterface();
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Memory allocation failed during start u: " 
            << e.what() 
            << std::endl;
    }


    dbi->updateCalorieHistory();
    dbi->updateFoodLibrary();
}

void CalorieTrackerManager::shutDown()
{
    dbi->saveCalorieHistory();
    dbi->saveFoodLibrary();

    delete dbi;
    delete ui;

    dbi = nullptr;
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
    return invalidOption;
}

bool CalorieTrackerManager::handleInput(std::string input)
{
    bool quit = false;
    FoodLibrary& fl = FoodLibrary::GetInstance();

    Option option = stringToOption(input);
    switch(option)
    {
        case exitloop:
            quit = true;
            break;
        case track:
            //trackItem();
            break;
        case showLibrary:
            fl.showFoodLibrary();
            break;
        case showDateData:
            //todaysData(today);
            break;
        case showHistory:
            //ch.showHistory();
            break;
        default:
            std::cout << "Input not recognized, please try again" << std::endl;
            break;
    }
    return quit;
}

bool CalorieTrackerManager::isDevMode()
{
    return devMode;
}

//oid UserInterface::trackItem()
//
//   std::unordered_map<std::string, FoodItem>& foodLibrary = fl.getFoodLibrary();
//   std::cout << std::endl;
//   std::cout << "What would you like to track today?\n";
//   std::string foodItem;
//   std::cin >> foodItem;
//   
//   int calories = 0;
//   double proteins = 0;
//   double fats = 0;
//   double carbs = 0;
//
//   if(foodLibrary.find(foodItem) != foodLibrary.end())
//   {
//       //std::cout << "What amount in oz did you eat?\n"; 
//       ch.saveDate(today, foodLibrary[foodItem]);
//   }
//   else
//   {
//       std::cout << "I don't have that in my library yet.\n";
//           
//       //std::cout << "What is the serving siz for " << foodItem;
//       //std::string servingSize;
//       //std::cin >> servingSize;
//   
//       std::cout << "How many calories are in " << foodItem << "\n";
//       std::cin >> calories;
//       std::cout << "How many proteins are in " << foodItem << "\n";
//       std::cin >> proteins;
//       std::cout << "How many fats are in " << foodItem << "\n";
//       std::cin >> fats;
//       std::cout << "How many carbohydrates are in " << foodItem << "\n";
//       std::cin >> carbs;
//   
//   	FoodItem newFoodItem(foodItem, calories, proteins, fats, carbs);
//   	std::cout << "Your food item is " << newFoodItem << std::endl;
//       std::cout << std::endl;
//   	ch.saveDate(today, newFoodItem);
//   	foodLibrary[foodItem] = newFoodItem;
//   }
//

//oid UserInterface::todaysData(Date today)
//
//   int calories = ch.getTotalCalories(today);
//   int proteins = ch.getTotalProteins(today);
//   int fats = ch.getTotalFats(today);
//   int carbs = ch.getTotalCarbohydrates(today);
//
//   std::cout << std::endl;
//   std::cout << "Today you have had " << calories << " calories, "
//       << proteins << " grams of protien, " 
//       << fats << " grams of fat, and " 
//       << carbs << " grams of carbohydrates.\n";
//   std::cout << std::endl;
//




