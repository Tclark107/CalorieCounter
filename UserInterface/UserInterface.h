#include <string>

class UserInterface {
    public:
        UserInterface();

        void displayPrompt();
        std::string getUserInput();
        void displayMessage(std::string message);
};
