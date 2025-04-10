#ifndef WEIGHT_ENTRY_H
#define WEIGHT_ENTRY_H

#include <string>

class WeightEntry
{
    public:
        WeightEntry(const std::string& date, float weight);

        std::string getDate() const;
        float getWeight() const;

    private:
        std::string date;
        float weight;
};

#endif
