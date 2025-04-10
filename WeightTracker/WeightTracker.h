#ifndef WEIGHT_TRACKER_H
#define WEIGHT_TRACKER_H

#include <map>
#include <string>

class WeightTracker 
{
    public:
        WeightTracker();
        void trackWeight(const std::string&, const int&);
        std::map<std::string,int> getWeightHistory();
        int getWeight(const std::string& date);

    private:
        std::map<std::string, int> weightHistory;


};

#endif
