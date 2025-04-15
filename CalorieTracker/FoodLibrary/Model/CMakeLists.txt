add_library(FoodItem FoodItem.cpp)

target_include_directories( FoodItem PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    )
