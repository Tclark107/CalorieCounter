#ifndef WEIGHT_TRACKER_H
#define WEIGHT_TRACKER_H

class UserInterface;

class WeightTracker 
{
    public:
        WeightTracker(bool devMode, UserInterface* ui);
        //~WeightTracker();

        void recordWeight();
        void displayProgress();

    private:
        bool devMode;
        UserInterface* ui;
};

#endif
