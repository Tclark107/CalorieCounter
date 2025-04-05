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
              << "[5] to see what you have eaten all time\n";
              // create a new item
}

std::string UserInterface::getUserInput()
{
    std::string input;
    std::cin >> input;
    return input;
}

void displayMessage(std::string message)
{
    std::cout << message << std::endl;
}
