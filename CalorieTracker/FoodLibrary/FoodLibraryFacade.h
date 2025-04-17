#ifndef FOOD_LIBRARY_FACADE_H
#define FOOD_LIBRARY_FACADE_H

#include <string>

class UserInterface;
class FoodLibraryService;

class FoodLibraryFacade
{
    public:
        FoodLibraryFacade(bool devMode, UserInterface* ui);
        void displayLibrary();

        void addItemToLibrary();
        std::string getUserItemName();
        int getUserItemCalories(const std::string);
        double getUserItemProteins(const std::string);
        double getUserItemFats(const std::string);
        double getUserItemCarbs(const std::string);


    private:
        UserInterface* ui;
        FoodLibraryService* foodLibraryService;
};

#endif
