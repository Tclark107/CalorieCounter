add_library(DBInterface 
            DevDBInterface.cpp
            RealDBInterface.cpp
            ${PROJECT_SOURCE_DIR}/CalorieHistory/CalorieHistory.cpp
            ${PROJECT_SOURCE_DIR}/FoodItem/FoodItem.cpp)

target_include_directories(DBInterface PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/CalorieHistory
    ${PROJECT_SOURCE_DIR}/FoodItem
    )
