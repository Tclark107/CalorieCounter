add_library(AppManager AppManager.cpp)

target_include_directories(AppManager PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/FoodLibrary
    ${PROJECT_SOURCE_DIR}/CalorieHistory
    ${PROJECT_SOURCE_DIR}/CalorieCalculator
    ${PROJECT_SOURCE_DIR}/DBInterface
    ${PROJECT_SOURCE_DIR}/UserInterface
    ${PROJECT_SOURCE_DIR}/WeightTracker
    )

target_link_libraries(AppManager PUBLIC
        DBInterface
        FoodLibrary
        CalorieHistory
        CalorieCalculator
        UserInterface
        WeightTracker
        )
