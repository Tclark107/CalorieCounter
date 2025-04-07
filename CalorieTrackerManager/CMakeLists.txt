add_library(CalorieTrackerManager CalorieTrackerManager.cpp)

target_include_directories(CalorieTrackerManager PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/FoodItem
    ${PROJECT_SOURCE_DIR}/CalorieHistory
    ${PROJECT_SOURCE_DIR}/CalorieCalculator
    ${PROJECT_SOURCE_DIR}/DBInterface
    ${PROJECT_SOURCE_DIR}/UserInterface
    )

target_link_libraries(CalorieTrackerManager PUBLIC
        DBInterface
        FoodItem
        CalorieHistory
        CalorieCalculator
        UserInterface
        )
