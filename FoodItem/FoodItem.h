#ifndef FOODITEM_H
#define FOODITEM_H

#include <string>

class FoodItem {
    public:
        FoodItem();
        FoodItem(std::string name,
                 int calories, 
                 double proteins, 
                 double fats, 
                 double carbohydrates);

        int getCalories();
        double getProteins();
        double getFats();
        double getCarbohydrates();

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
