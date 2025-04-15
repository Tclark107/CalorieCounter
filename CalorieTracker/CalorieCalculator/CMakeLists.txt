add_library(CalorieCalculator CalorieCalculator.cpp)

target_include_directories(CalorieCalculator PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/FoodLibrary
    )

