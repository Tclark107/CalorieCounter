#ifndef WEIGHT_TRACKER_H
#define WEIGHT_TRACKER_H

class UserInterface;

class WeightTrackerFacade
{
    public:
        WeightTrackerFacade(bool devMode, UserInterface* ui);
        //~WeightTrackerFacade();

        void recordWeight();
        void displayProgress();

    private:
        bool devMode;
        UserInterface* ui;
};

#endif
