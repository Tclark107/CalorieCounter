#ifndef WEIGHT_TRACKER_H
#define WEIGHT_TRACKER_H

class WeightTracker 
{
    public:
        WeightTracker(bool devMode, UserInterface* ui);
        ~WeightTracker();

        void recordWeight();
        void displayProgress();

    private:
        WeightTrackerService* service;
        UserInterface* ui;


};

#endif
