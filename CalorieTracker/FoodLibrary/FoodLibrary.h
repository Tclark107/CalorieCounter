#ifndef FOODLIBRARY_H
#define FOODLIBRARY_H

#include <unordered_map>
#include <string>

#include "FoodItem.h"

class FoodLibrary
{
    public:
        static FoodLibrary& GetInstance()
        {
            static FoodLibrary instance;
            return instance;
        }

        FoodLibrary(const FoodLibrary&) = delete;
        void operator=(const FoodLibrary&) = delete;
        
        bool inLibrary(std::string item);
		void showFoodLibrary();
        void addItem(FoodItem food);
        //void editItem(std::string item);
        FoodItem getItem(std::string food);
        FoodItem createItem(std::string name,
                            double calories,
                            double proteins,
                            double fats,
                            double carbs);

        std::string toString(FoodItem food);
    private:
        std::unordered_map<std::string, FoodItem> foodLibrary;
        FoodLibrary() {};
};

#endif
