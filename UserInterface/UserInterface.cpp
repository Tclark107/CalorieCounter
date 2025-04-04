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

    std::cout << "Today you have had " << calories << " calories, "
        << proteins << " grams of protien, " 
        << fats << " grams of fat, and " 
        << carbs << " grams of carbohydrates.\n";
}

void UserInterface::UserInterfaceStart()
{
    std::cout << "Hello! I am your calorie tracker! \n";
    Date today = ch.getCurrentDate();
    todaysData(today);

	FoodLibrary& fl = FoodLibrary::getInstance();
	std::unordered_map<std::string, FoodItem>& foodLibrary = fl.getFoodLibrary();

    bool exit = false;
    while(!exit)
    {
        std::cout << "What would you like to do today? "
                  << "[e] to exit, "
                  << "[t] to track calories.\n";
        std::string userInput;
        std::cin >> userInput;
        if(userInput == "e") exit = true;
        if(userInput == "t")
        {
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
				std::cout << "myfoodItem is " << newFoodItem << std::endl;
				ch.saveDate(today, newFoodItem);
				foodLibrary[foodItem] = newFoodItem;
            }
        }
    }
	
	fl.showFoodLibrary();
    DBInterface db;
    db.saveFoodLibrary();
    db.saveCalorieHistory();

}
