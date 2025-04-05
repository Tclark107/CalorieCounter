#include "UserInterface.h"

UserInterface::UserInterface()
{
}

void UserInterface::todaysData(Date today)
{
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

void UserInterface::trackItem()
{
	std::unordered_map<std::string, FoodItem>& foodLibrary = fl.getFoodLibrary();
    std::cout << std::endl;
    std::cout << "What would you like to track today?\n";
    std::string foodItem;
    std::cin >> foodItem;
    
    int calories = 0;
    double proteins = 0;
    double fats = 0;
    double carbs = 0;

    if(foodLibrary.find(foodItem) != foodLibrary.end())
    {
        //std::cout << "What amount in oz did you eat?\n"; 
        ch.saveDate(today, foodLibrary[foodItem]);
    }
    else
    {
        std::cout << "I don't have that in my library yet.\n";
            
        //std::cout << "What is the serving siz for " << foodItem;
        //std::string servingSize;
        //std::cin >> servingSize;
    
        std::cout << "How many calories are in " << foodItem << "\n";
        std::cin >> calories;
        std::cout << "How many proteins are in " << foodItem << "\n";
        std::cin >> proteins;
        std::cout << "How many fats are in " << foodItem << "\n";
        std::cin >> fats;
        std::cout << "How many carbohydrates are in " << foodItem << "\n";
        std::cin >> carbs;
    
    	FoodItem newFoodItem(foodItem, calories, proteins, fats, carbs);
    	std::cout << "Your food item is " << newFoodItem << std::endl;
        std::cout << std::endl;
    	ch.saveDate(today, newFoodItem);
    	foodLibrary[foodItem] = newFoodItem;
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

void UserInterface::UserInterfaceStart()
{
    std::cout << "Hello! I am your calorie tracker! \n";
    today = ch.getCurrentDate();
    todaysData(today);


    bool exit = false;
    while(!exit)
    {
        std::cout << "What would you like to do today?\n"
                  << "[1] to quit\n"
                  << "[2] to track calories\n"
                  << "[3] to see what foods I have stored\n"
                  << "[4] to see what you have eaten today \n"
                  << "[5] to see what you have eaten all time\n";
                  // create a new item
        std::string userInput;
        std::cin >> userInput;

         
        Option option = stringToOption(userInput);
        switch(option)
        {
            case exitloop:
                exit = true;
                break;
            case track:
                trackItem();
                break;
            case showLibrary:
                fl.showFoodLibrary();
                break;
            case showDateData:
                todaysData(today);
                break;
            case showHistory:
                ch.showHistory();
                break;
            default:
                std::cout << "Input not recognized, please try again" << std::endl;
                break;
        }
    }
	
    DBInterface db;
    db.saveFoodLibrary();
    db.saveCalorieHistory();
}
