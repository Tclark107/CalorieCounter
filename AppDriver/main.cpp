#include <iostream>
#include <ctime>

#include "CalorieHistory.h"

int main()
{
    std::string name = "Chicken";
    int calories = 45;
    double proteins = 8;
    double fats = 1;
    double carbs = 0;

    FoodItem chicken(name, calories, proteins, fats, carbs);
    std::cout << "chicken calories " << chicken.getCalories() << std::endl;

    CalorieHistory history;
    Date today = history.getCurrentDate();
    
    std::cout << "Todays date is " << today << std::endl;
    //getTodaysCalories();
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
