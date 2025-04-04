#include "DBInterface.h"

DBInterface::DBInterface() {}

void DBInterface::saveCalorieHistory()
{
    //TODO: if file exists, otherwise create it"
    //TODO: make this relative path
    std::ofstream outFile("../TristanDB/HistoryTest.txt");
    //std::ofstream outFile("../TristanDB/History.txt");
    if(!outFile)
    {
        std::cerr << "Error opening file for writing.\n";
    }

    CalorieHistory& ch = CalorieHistory::getInstance();
    std::vector<std::pair<Date,std::vector<FoodItem>>>& history = ch.getHistory();

    for(auto& entry : history)
    {
        outFile << entry.first << " "
                << ch.getTotalCalories(entry.first) << " ";

        int numberOfEntries = entry.second.size();
        outFile << numberOfEntries << " ";
        for(int i = 0; i < numberOfEntries; i++)
        {
            outFile << entry.second[i].getName() << "-"
                    << entry.second[i].getCalories() << "-"
                    << entry.second[i].getProteins() << "-"
                    << entry.second[i].getFats() << "-"
                    << entry.second[i].getCarbohydrates() << " ";
        }
        outFile << "\n";
    }

    outFile.close();
}

void DBInterface::updateCalorieHistory()
{
    std::ifstream inFile("../TristanDB/HistoryTest.txt");
    //std::ifstream inFile("../TristanDB/History.txt");
    if(!inFile)
    {
        std::cerr << "Error opening file for reading. \n";
    }

    CalorieHistory& ch = CalorieHistory::getInstance();
    std::vector<std::pair<Date,std::vector<FoodItem>>>& history = ch.getHistory();

    std::vector<std::vector<std::string>> historyData;
    
    std::string line;
    std::string word;
    while(std::getline(inFile, line))
    {
        std::istringstream iss(line);
        std::vector<std::string> words;
        while(iss >> word)
        {
            words.push_back(word);
        }
        historyData.push_back(words);
    }
    
    
    for(int i = 0; i < historyData.size(); i++)
    {
        //Note: If string contains non-numeric characters stoi or stoul will throw std:invalid_argument
        // perhaps do some error checking
        int year = std::stoi(historyData[i][0]);
        unsigned char month = static_cast<unsigned char>(std::stoul(historyData[i][1]));
        unsigned char day = static_cast<unsigned char>(std::stoul(historyData[i][2]));
        Date date(year, month, day);    

        int numberOfEntries = std::stoi(historyData[i][4]);
        for(int j = 5; j < historyData[i].size(); j++)
        {
            std::vector<std::string> foodItem;
            std::stringstream ss(historyData[i][j]);
            std::string foodData;
            while(std::getline(ss, foodData, '-'))
            {
                foodItem.push_back(foodData);
            }
            
            FoodItem food(foodItem[0],
                          std::stoi(foodItem[1]),
                          std::stod(foodItem[2]),
                          std::stod(foodItem[3]),
                          std::stod(foodItem[4]));

            ch.saveDate(date,food);

        }
    }
    inFile.close();
}

void DBInterface::updateFoodLibrary()
{
	std::ifstream inFile("../TristanDB/FoodLibraryTest.txt");
	//std::ifstream inFile("../TristanDB/FoodLibrary.txt");
    if(!inFile)
    {
        std::cerr << "Error opening file for reading. \n";
    }

	FoodLibrary& fl = FoodLibrary::getInstance();
	std::unordered_map<std::string, FoodItem>& foodLibrary = fl.getFoodLibrary();
    
    std::vector<std::vector<std::string>> FoodLibraryData;
    std::string line;
    std::string word;
    while(std::getline(inFile, line))
    {
        std::istringstream iss(line);
        std::vector<std::string> words;
        while(iss >> word)
        {
            words.push_back(word);
        }
        FoodLibraryData.push_back(words);
    }

    std::string name;
    int calories = 0;
    double proteins = 0;
    double fats = 0;
    double carbs = 0;
    for(int i = 0; i < FoodLibraryData.size(); i++)
    {
        name = FoodLibraryData[i][0];
        calories = std::stoi(FoodLibraryData[i][1]);
        proteins = std::stod(FoodLibraryData[i][2]);
        fats = std::stod(FoodLibraryData[i][3]);
        carbs = std::stod(FoodLibraryData[i][4]);

        FoodItem newFoodItem(name, calories, proteins, fats, carbs);
        foodLibrary[FoodLibraryData[i][0]] = newFoodItem;
    }
}

void DBInterface::saveFoodLibrary()
{
	std::ofstream outFile("../TristanDB/FoodLibrary.txt");
	//std::ofstream outFile("../TristanDB/FoodLibrary.txt");
    if(!outFile)
    {
        std::cerr << "Error opening file for writing.\n";
    }

    FoodLibrary& fl = FoodLibrary::getInstance();
	std::unordered_map<std::string, FoodItem>& foodLibrary = fl.getFoodLibrary();

    for(auto& pair : foodLibrary)
    {
        outFile << pair.second << "\n";
    }
}
