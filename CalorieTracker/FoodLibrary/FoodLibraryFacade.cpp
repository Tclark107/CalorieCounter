#include "FoodLibraryFacade.h"
#include "FoodLibraryService.h"
#include "UserInterface.h"

#include <iostream>

FoodLibraryFacade::FoodLibraryFacade (bool devMode, UserInterface ui) 
{
    foodLibraryService = new FoodLibraryService(devMode);
}
