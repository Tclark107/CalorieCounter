#ifndef FOODLIBRARY_H
#define FOODLIBRARY_H

#include <unordered_map>
#include <string>

class FoodLibrary
{
    public:
        static FoodLibrary& getInstance()
        {
            static FoodLibrary instance;
            return instance;
        }

        FoodLibrary(const FoodLibrary&) = delete;
        void operator=(const FoodLibrary&) = delete;
        
        std::unordered_map<std::string, FoodItem>& getFoodLibrary()
        {
            return foodLibrary;
        }

    private:
        std::unordered_map<std::string, FoodItem> foodLibrary;
        FoodLibrary() {};
};

#endif
