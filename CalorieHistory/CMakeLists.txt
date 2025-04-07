add_library(CalorieHistory CalorieHistory.cpp)

target_link_libraries(CalorieHistory PUBLIC FoodLibrary)

target_include_directories(CalorieHistory PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    )
