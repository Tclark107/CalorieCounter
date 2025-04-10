#include "WeightEntry.h"

WeightEntry::WeightEntry(const std::string& date, float weight) :
    date(date),
    weight(weight)
{}

std::string WeightEntry::getDate() const
{
    return date;
}

float WeightEntry::getWeight() const
{
    return weight;
}
