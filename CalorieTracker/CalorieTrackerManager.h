#ifndef CALORIE_TRACKER_MANAGER_H
#define CALORIE_TRACKER_MANAGER_H

class UserInterface;
class FoodLibraryFacade;
class CalorieHistoryFacade;

class CalorieTrackerManager
{
    public:
        CalorieTrackerManager ();
        CalorieTrackerManager(bool devMode, UserInterface* ui);
        ~CalorieTrackerManager ();

        void showLibrary();
        void addItemToLibrary();
        void trackItemToday();
        void saveHistory();

        void showHistory();

    private:
        FoodLibraryFacade* fl;
        CalorieHistoryFacade* ch;
};

#endif
