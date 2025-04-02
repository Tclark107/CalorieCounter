add_library(CalorieHistory CalorieHistory.cpp)

target_include_directories(CalorieHistory PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/FoodItem
    )
