add_library(DBInterface DBInterface.cpp)

target_include_directories(DBInterface PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/CalorieHistory
    ${PROJECT_SOURCE_DIR}/FoodItem
    )
