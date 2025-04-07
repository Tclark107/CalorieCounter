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
        
        //std::unordered_map<std::string, FoodItem>& getFoodLibrary();
        //std::unordered_map<std::string, FoodItem>& getFoodLibrary()
        //{
        //    return foodLibrary;
        //}

		void showFoodLibrary();
        void addItem(FoodItem food);
        FoodItem getItem(std::string food);
        FoodItem createItem(std::string name,
                            int calories,
                            double proteins,
                            double fats,
                            double carbs);
        bool inLibrary(std::string item);
    private:
        std::unordered_map<std::string, FoodItem> foodLibrary;
        FoodLibrary() {};
};

#endif
