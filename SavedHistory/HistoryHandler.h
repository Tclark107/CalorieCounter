#ifndef HISTORYHANDLER_H
#define HISTORYHANDLER_H

#include <chrono>
#include <format>

using namespace std::chrono;

#include "SavedHistory.h"

class HistoryHandler 
{
    public:
        Date getCurrentDate();
        bool checkDate();
        void saveDate();

}

#endif

