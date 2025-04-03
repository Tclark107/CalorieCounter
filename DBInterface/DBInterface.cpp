#include "DBInterface.h"

DBInterface::DBInterface() {}

void DBInterface::saveCalorieHistory()
{
    //TODO: if file exists, otherwise create it"
    //TODO: make this relative path
    std::ofstream outFile("../TristanDB/exampleHistoryOut.txt");

    if(!outFile)
    {
        std::cerr << "Error opening file for writing.\n";
    }

    CalorieHistory& ch = CalorieHistory::getInstance();
    std::vector<std::pair<Date,std::vector<FoodItem>>>& history = ch.getHistory();

    for(auto& entry : history)
    {
        outFile << entry.first << " ";
        for(int i = 0; i < entry.second.size() - 1; i++)
        {
            outFile << entry.second[i].getName() << " "
                    << entry.second[i].getCalories() << " "
                    << entry.second[i].getProteins() << " "
                    << entry.second[i].getFats() << " "
                    << entry.second[i].getCarbohydrates() << " ";
        }
        outFile << "\n";
    }

    outFile.close();
}

std::vector<std::pair<Date,std::vector<FoodItem>>> getCalorieHistory()
{
    std::ifstream inFile("../TristanDB/exampleHistoryIn.txt");
    if(!inFile)
    {
        std::cerr << "Error opening file for reading. \n";
    }

    std::vector<std::pair<Date,std::vector<FoodItem>>> result;
    
    //TODO: save history
    std::string line;
    while(std::getline(inFile, line))
    {
        std::cout << line << std::endl;
    }

    inFile.close();
    
    return result;
}


