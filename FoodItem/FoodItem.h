#ifndef FOODITEM_H
#define FOODITEM_H

#include <string>
#include <iostream>

class FoodItem {
    public:
        FoodItem();
        FoodItem(std::string name,
                 int calories, 
                 double proteins, 
                 double fats, 
                 double carbohydrates);

        std::string getName();
        int getCalories();
        double getProteins();
        double getFats();
        double getCarbohydrates();

        void setName(std::string name);
        void setCalories(int calories);
        void setProteins(double proteins);
        void setFats(double fats);
        void setCarbohydrates(double carbohydrates);

		//google why we should use const here
		//friend std::ostream& operator<<(std::ostream& os, const FoodItem& food);
		friend std::ostream& operator<<(std::ostream& os, FoodItem& food);

    private:
        std::string name;
        int calories;
        double proteins;
        double fats;
        double carbohydrates;
};

#endif
