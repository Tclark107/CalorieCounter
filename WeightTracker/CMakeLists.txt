add_library(WeightTracker WeightTracker.cpp)

target_include_directories(WeightTracker PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/CalorieHistory
    ${PROJECT_SOURCE_DIR}/FoodLibrary
    )

