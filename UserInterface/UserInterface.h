#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <string>

class UserInterface {
    public:
        UserInterface();

        void displayPrompt();
        std::string getUserInput();
        void displayMessage(std::string message);
};

#endif

