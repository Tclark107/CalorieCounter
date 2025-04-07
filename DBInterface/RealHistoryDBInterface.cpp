#include "RealHistoryDBInterface.h"

RealHistoryDBInterface::RealHistoryDBInterface() {}

bool RealHistoryDBInterface::connect()
{
    historyDB.open("../TristanDB/History.txt", std::ios::in | std::ios::out);
    if(!historyDB)
    {
        std::cerr << "Error opening HistroyDB.\n";
        return false;
    }
    return true;
}

bool RealHistoryDBInterfaceRealDBInterface::disconnect()
{
    if(historyDB.is_open())
    {
        historyDB.close();
    }
}

void RealHistoryDBInterfaceRealDBInterface::loadData()
{
    std::string line;
    std::string word;
    while(std::getline(historyDB, line))
    {
        std::istringstream iss(line);
        std::vector<std::string> words;
        while(iss >> word)
        {
            words.push_back(word);
        }
        historyData.push_back(words);
    }
}

std::vector<std::vector<std::string>> RealHistoryDBInterface::getData()
{
    return historyData;
}

void RealHistoryDBInterface::saveData()
{
}

void DBInterface::saveCalorieHistory()
{
    CalorieHistory& ch = CalorieHistory::getInstance();
    std::vector<std::pair<Date,std::vector<FoodItem>>>& history = ch.getHistory();

    for(auto& entry : history)
    {
        historyDB << entry.first << " "
                << ch.getTotalCalories(entry.first) << " ";

        int numberOfEntries = entry.second.size();
        historyDB << numberOfEntries << " ";
        for(int i = 0; i < numberOfEntries; i++)
        {
            historyDB << entry.second[i].getName() << "-"
                    << entry.second[i].getCalories() << "-"
                    << entry.second[i].getProteins() << "-"
                    << entry.second[i].getFats() << "-"
                    << entry.second[i].getCarbohydrates() << " ";
        }
        historyDB << "\n";
    }
    //call closefileio
    historyDB.close();
}
void DBInterface::updateFoodLibrary()
{
    openFileIO();
    if(!libraryDB)
    {
        std::cerr << "Error opening file for reading. \n";
    }

	FoodLibrary& fl = FoodLibrary::getInstance();
	std::unordered_map<std::string, FoodItem>& foodLibrary = fl.getFoodLibrary();
    
    std::vector<std::vector<std::string>> FoodLibraryData;
    std::string line;
    std::string word;
    while(std::getline(libraryDB, line))
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
    openFileIO();
    if(!libraryDB)
    {
        std::cerr << "Error opening file for writing.\n";
    }

    FoodLibrary& fl = FoodLibrary::GetInstance();
	std::unordered_map<std::string, FoodItem>& foodLibrary = fl.getFoodLibrary();

    for(auto& pair : foodLibrary)
    {
        libraryDB << pair.second << "\n";
    }
}
