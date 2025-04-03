#include <iostream>
#include <ctime>

#include "CalorieHistory.h"
#include "DBInterface.h"

int main()
{
    //1) Load In History by calling DBInterface
    //2) Kick of UserLoop
    std::string name = "Chicken";
    int calories = 45;
    double proteins = 8;
    double fats = 1;
    double carbs = 0;

    FoodItem chicken(name, calories, proteins, fats, carbs);
    std::cout << "chicken calories " << chicken.getCalories() << std::endl;

    
    FoodItem beef("beef", calories, proteins, fats, carbs);
    FoodItem yogurt("yogurt", calories, proteins, fats, carbs);
    FoodItem shake("shake", calories, proteins, fats, carbs);
    FoodItem pbut("pbut", calories, proteins, fats, carbs);
    FoodItem fish("fish", calories, proteins, fats, carbs);

    DBInterface dbInterface;
    CalorieHistory& ch = CalorieHistory::getInstance();

    std::vector<std::pair<Date,std::vector<FoodItem>>>& history = ch.getHistory();
    dbInterface.updateCalorieHistory();

    Date today = ch.getCurrentDate();

    std::cout << "Todays date is " << today << std::endl;
    calories = ch.getTotalDaysCalories(today);
    std::cout << "Today you ate " << calories << " calories. ";
    std::cout << "What would you like to do now? " << std:: endl;
    ch.saveDate(today,beef);
    ch.saveDate(today,yogurt);
    ch.saveDate(today,beef);
    ch.saveDate(today,shake);
    ch.saveDate(today,pbut);

    calories = ch.getTotalDaysCalories(today);
    std::cout << "Today you ate " << calories << " calories. ";

    dbInterface.saveCalorieHistory();
    //if(todaysCalories == 0)
    //{
    //    int userCal = 0;
    //    std::cout << "You haven't added calories in for today. " 
    //        << "How many calories do you want to add: ";
    //    std::cin >> userCal;
    //    std::cout << "Thank you you have logged " << userCal 
    //        << " calories."
    //    updateTodaysCalories(userCal);
    //}
    //else
    //{
    //    int userCal = 0;
    //    std::cout << "What would you like to add today? " << std::endl;
    //}
        
}
