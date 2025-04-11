#include <iostream>

#include "UserInterface.h"

UserInterface::UserInterface()
{
}

void UserInterface::displayPrompt()
{
    std::cout << "What would you like to do today?\n"
              << "[1] to quit\n"
              << "[2] to track calories\n"
              << "[3] to see what foods I have stored\n"
              << "[4] to see what you have eaten today \n"
              << "[5] to see what you have eaten all time\n"
              << "[6] to add an item to the food library\n"
              << "[7] to record your weight\n";
}

std::string UserInterface::getUserInput()
{
    std::string input;
    std::cin >> input;
    return input;
}

void UserInterface::displayMessage(std::string message)
{
    std::cout << message << std::endl;
}
