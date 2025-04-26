#include "AppManager.h"
#include "DBInterface.h"
#include "DBInterfaceFactory.h"
#include "UserInterface.h"
#include "WeightTrackerFacade.h"
#include "CalorieTrackerManager.h"

#include <limits>
#include <iostream>

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

void AppManager::shutDown()
{
    ctm->saveHistory();

    delete wt;
    delete ui;
    delete ctm;

    ui = nullptr;
    wt = nullptr;
    ctm = nullptr;
}

Option stringToOption(const std::string& input)
{
    if(input == "1") return EXIT_LOOP;
    if(input == "2") return TRACK_ITEM;
    if(input == "3") return SHOW_LIBRARY;
    if(input == "4") return SHOW_TODAYS_MACROS;
    if(input == "5") return SHOW_HISTORY;
    if(input == "6") return ADD_ITEM_TO_LIBRARY;
    if(input == "7") return RECORD_WEIGHT;
    if(input == "8") return AVERAGE_WEIGHT;
    return INVALID_OPTION;
}

bool AppManager::handleInput(std::string input)
{
    bool quit = false;
    Option option = stringToOption(input);
    switch(option)
    {
        case EXIT_LOOP:
            quit = true;
            break;
        case TRACK_ITEM:
            std::cout << "Track: Under Construction" << std::endl;
            trackItem();
            break;
        case SHOW_LIBRARY:
            ctm->showLibrary();
            break;
        case SHOW_TODAYS_MACROS:
            std::cout << "ShowTodaysDate: Under Construction" << std::endl;
            showTodaysMacros();
            break;
        case SHOW_HISTORY:
            showHistory();
            break;
        case ADD_ITEM_TO_LIBRARY:
            ctm->addItemToLibrary();
            break;
        case RECORD_WEIGHT:
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

void AppManager::showTodaysMacros()
{
    ctm->displayTodaysMacros();
}

void AppManager::trackItem()
{
    ctm->trackItemToday();
}

void AppManager::showHistory()
{
    ctm->showHistory();
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


