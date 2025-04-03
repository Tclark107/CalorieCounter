#include "UserInterface.h"

UserInterface::UserInterface()
{
}

void UserInterface::UserInterfaceStart()
{
    bool exit = false;
    while(!exit)
    {
        std::cout << "Hello! I am your calorie tracker! \n";
        std::cout << "What would you like to do today? "
                  << "[e] to exit, "
                  << "[t] to track calories.\n";
        std::string userInput;
        std::cin >> userInput;
        if(userInput == "e") exit = true;

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
}

