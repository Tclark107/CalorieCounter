#ifndef CALORIE_TRACKER_MANAGER_H
#define CALORIE_TRACKER_MANAGER_H

class UserInterface;
class FoodLibraryFacade;

class CalorieTrackerManager
{
    public:
        CalorieTrackerManager ();
        CalorieTrackerManager(bool devMode, UserInterface* ui);
        ~CalorieTrackerManager ();

    private:
        FoodLibraryFacade* fl;
        //CalorieHistoryFacade* ch;
};

#endif
