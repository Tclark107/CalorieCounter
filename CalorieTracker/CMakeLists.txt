add_subdirectory(CalorieHistory)
add_subdirectory(FoodLibrary)
add_subdirectory(CalorieCalculator)

add_library(CalorieTracker CalorieTrackerFacade.cpp)

target_link_libraries(CalorieTracker
    CalorieHistory
    FoodLibrary
    CalorieCalculator
    )

target_include_directories(CalorieTracker PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    )

