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

        //std::string setName(std::string name);
        //void setCalories(int calories);
        //void setProteins(double proteins);
        //void setFats(double fats);
        //void setCarbohydrates(double carbohydrates);

    private:
        std::string name;
        int calories;
        double proteins;
        double fats;
        double carbohydrates;
};

#endif
