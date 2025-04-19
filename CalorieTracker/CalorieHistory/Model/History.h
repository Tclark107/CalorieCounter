#ifndef HISTORY_H
#define HISTORY_H

#include <map>
#include <vector>
#include <string>

class History
{
    public:
        //Date format YYYY-MM-DD
        //Food format "Food Item"-Calories-Proteins-Fats-Carbs
        //History Format YYYY-MM-DD:FoodItem:FoodItem2:FoodItem3
        History();

        bool inHistory(const std::string);
        int getSize();
        std::string getHistory(const std::string);
        std::string toString(const std::string);
        void addItemToDate(const std::string, const std::string);
        //void displayHistory();

    private:
        std::map<std::string, std::vector<std::string>> history;
};

#endif
