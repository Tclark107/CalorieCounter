#ifndef FOODITEM_H
#define FOODITEM_H

#include <string>
#include <iostream>

class FoodItem {
    public:
        FoodItem();
        FoodItem(std::string name,
                 double caloriesPerGram, 
                 double proteinsPerGram, 
                 double fatsPerGram, 
                 double carbsPerGram);

        std::string getName();
        double getCaloriesPerGram();
        double getProteinsPerGram();
        double getFatsPerGram();
        double getCarbsPerGram();

        void setName(std::string name);
        void setCaloriesPerGram(double caloriesPerGram);
        void setProteinsPerGram(double proteinsPerGram);
        void setFatsPerGram(double fatsPerGram);
        void setCarbsPerGram(double carbsPerGram);

		//google why we should use const here
		//friend std::ostream& operator<<(std::ostream& os, const FoodItem& food);
		friend std::ostream& operator<<(std::ostream& os, FoodItem& food);

    private:
        std::string name;
        double caloriesPerGram;
        double proteinsPerGram;
        double fatsPerGram;
        double carbsPerGram;
};

#endif
