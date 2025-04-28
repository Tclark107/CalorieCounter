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
        void addItemToLibrary(const std::string);
        std::string getItemFromLibrary(const std::string);

        bool inLibrary(const std::string);

        std::string getUserItemName();
        double getUserItemCalories(const std::string);
        double getUserItemProteins(const std::string);
        double getUserItemFats(const std::string);
        double getUserItemCarbs(const std::string);

        double getItemCaloriesPerGram(const std::string);
        double getItemProteinsPerGram(const std::string);
        double getItemFatsPerGram(const std::string);
        double getItemCarbsPerGram(const std::string);
        
    private:
        UserInterface* ui;
        FoodLibraryService* foodLibraryService;
};

#endif
