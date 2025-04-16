#include "AppManager.h"
#include "DBInterface.h"
#include "DBInterfaceFactory.h"
#include "CalorieHistory.h"
#include "UserInterface.h"
#include "WeightTrackerFacade.h"
#include "CalorieTrackerManager.h"

#include <limits>

AppManager::AppManager() {}

AppManager::AppManager(bool devMode) :
devMode(devMode),
ui(nullptr),
wt(nullptr),
ctm(nullptr)
{}

AppManager::~AppManager()
{
    delete ui;
    delete wt;
    delete ctm;
}

void AppManager::startUp()
{
    try 
    {
        ui = new UserInterface();
        wt = new WeightTrackerFacade(devMode, ui);
        ctm = new CalorieTrackerManager(devMode, ui);
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Memory allocation failed during start u: " 
            << e.what() 
            << std::endl;
    }

    run();
}
void AppManager::shutDown()
{
    delete wt;
    delete ui;
    delete ctm;

    ui = nullptr;
    wt = nullptr;
    ctm = nullptr;
}

void AppManager::run()
{
    bool quit = false;
    std::string input;
    while(!quit)
    {
        ui->displayPrompt();
        input = ui->getUserInput(); 
        quit = handleInput(input);
    }
    shutDown();
}

Option stringToOption(const std::string& input)
{
    if(input == "1") return exitloop;
    if(input == "2") return track;
    if(input == "3") return showLibrary;
    if(input == "4") return showDateData;
    if(input == "5") return showHistory;
    if(input == "6") return addItemToLibrary;
    if(input == "7") return recWeight;
    if(input == "8") return AVERAGE_WEIGHT;
    return invalidOption;
}

bool AppManager::handleInput(std::string input)
{
    bool quit = false;
    Option option = stringToOption(input);
    switch(option)
    {
        case exitloop:
            quit = true;
            break;
        case track:
            std::cout << "Track: Under Construction" << std::endl;
            break;
        case showLibrary:
            std::cout << "ShowLibrary: Under Construction" << std::endl;
            break;
        case showDateData:
            std::cout << "ShowTodaysDate: Under Construction" << std::endl;
            break;
        case showHistory:
            break;
        case addItemToLibrary:
            std::cout << "editLibrary: Under Construction" << std::endl;
            break;
        case recWeight:
            recordWeight();
            break;
        case AVERAGE_WEIGHT:
            getAverageWeight();
            break;
        default:
            std::cout << "Input not recognized, please try again" << std::endl;
            break;
    }
    return quit;
}

void AppManager::getAverageWeight()
{
    std::cout << "AppManager::getAverageWeight()\n";
    wt->getAverageWeight();
}

void AppManager::recordWeight()
{
    std::cout << "AppManager::recordWeight()\n";
    wt->recordWeight();
}


