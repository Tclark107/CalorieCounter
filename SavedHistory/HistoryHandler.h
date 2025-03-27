#ifndef HISTORYHANDLER_H
#define HISTORYHANDLER_H

#include <unordered_map>

#include "SavedHistory.h"

class HistoryHandler 
{
    public:
        Date getCurrentDate();
        bool checkDate();
        void saveDate();

}

#endif

