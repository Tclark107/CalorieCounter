add_library(UserInterface UserInterface.cpp)

target_include_directories(UserInterface PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/CalorieHistory
    ${PROJECT_SOURCE_DIR}/FoodItem
    ${PROJECT_SOURCE_DIR}/DBInterface
    )
