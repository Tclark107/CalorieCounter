#include "DBInterface.h"

DBInterface::DBInterface() {}

DBInterface::DBInterface(bool devMode) :
devMode(devMode) 
{
    openFileIO();
}

void DBInterface::openFileIO()
{
    if(devMode)
    {
        std::cout << "Running in Dev Mode" << std::endl;
        historyDBOut.open("../TristanDB/HistoryTest.txt");
        historyDBIn.open("../TristanDB/HistoryTest.txt");
        libraryDBOut.open("../TristanDB/FoodLibraryTest.txt");
        libraryDBIn.open("../TristanDB/FoodLibraryTest.txt");
    }
    else
    {
        historyDBOut.open("../TristanDB/History.txt");
        historyDBIn.open("../TristanDB/History.txt");
        libraryDBOut.open("../TristanDB/FoodLibrary.txt");
        libraryDBIn.open("../TristanDB/FoodLibrary.txt");
    }
}

void DBInterface::closeFileIO()
{
    if(historyDBOut.is_open()) historyDBOut.close();
    if(historyDBIn.is_open()) historyDBIn.close();
    if(libraryDBOut.is_open()) libraryDBOut.close();
    if(libraryDBIn.is_open()) libraryDBIn.close();
}


void DBInterface::saveCalorieHistory()
{
    //TODO: if file exists, otherwise create it"
    //TODO: make this relative path
    if(!historyDBOut)
    {
        std::cerr << "Error opening file for writing.\n";
    }

    CalorieHistory& ch = CalorieHistory::getInstance();
    std::vector<std::pair<Date,std::vector<FoodItem>>>& history = ch.getHistory();

    for(auto& entry : history)
    {
        historyDBOut << entry.first << " "
                << ch.getTotalCalories(entry.first) << " ";

        int numberOfEntries = entry.second.size();
        historyDBOut << numberOfEntries << " ";
        for(int i = 0; i < numberOfEntries; i++)
        {
            historyDBOut << entry.second[i].getName() << "-"
                    << entry.second[i].getCalories() << "-"
                    << entry.second[i].getProteins() << "-"
                    << entry.second[i].getFats() << "-"
                    << entry.second[i].getCarbohydrates() << " ";
        }
        historyDBOut << "\n";
    }

    historyDBOut.close();
}

void DBInterface::updateCalorieHistory()
{
    if(!historyDBIn)
    {
        std::cerr << "Error opening file for reading. \n";
    }

    CalorieHistory& ch = CalorieHistory::getInstance();
    std::vector<std::pair<Date,std::vector<FoodItem>>>& history = ch.getHistory();

    std::vector<std::vector<std::string>> historyData;
    
    std::string line;
    std::string word;
    while(std::getline(historyDBIn, line))
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
    historyDBIn.close();
}

void DBInterface::updateFoodLibrary()
{
    if(!libraryDBIn)
    {
        std::cerr << "Error opening file for reading. \n";
    }

	FoodLibrary& fl = FoodLibrary::getInstance();
	std::unordered_map<std::string, FoodItem>& foodLibrary = fl.getFoodLibrary();
    
    std::vector<std::vector<std::string>> FoodLibraryData;
    std::string line;
    std::string word;
    while(std::getline(libraryDBIn, line))
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
    if(!libraryDBOut)
    {
        std::cerr << "Error opening file for writing.\n";
    }

    FoodLibrary& fl = FoodLibrary::getInstance();
	std::unordered_map<std::string, FoodItem>& foodLibrary = fl.getFoodLibrary();

    for(auto& pair : foodLibrary)
    {
        libraryDBOut << pair.second << "\n";
    }
}
