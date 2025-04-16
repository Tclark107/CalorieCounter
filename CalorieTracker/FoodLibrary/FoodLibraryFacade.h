#ifndef FOOD_LIBRARY_FACADE_H
#define FOOD_LIBRARY_FACADE_H

class UserInterface;
class FoodLibraryService;

class FoodLibraryFacade
{
    public:
        FoodLibraryFacade(bool devMode, UserInterface* ui);

    private:
        FoodLibraryService* foodLibraryService;
};

#endif
