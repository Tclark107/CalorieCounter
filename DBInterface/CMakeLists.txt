add_library(CalorieCalculator CalorieCalculator.cpp)

target_include_directories(DBInterface PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    )
