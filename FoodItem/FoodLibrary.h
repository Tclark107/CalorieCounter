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

		void showFoodLibrary()
		{
			std::cout << std::endl;
			for(auto& pair : foodLibrary)
			{
				std::cout << pair.first << " "; 
				std::cout << pair.second << std::endl;
			}
			std::cout << std::endl;
		}

    private:
        std::unordered_map<std::string, FoodItem> foodLibrary;
        FoodLibrary() {};
};

#endif
