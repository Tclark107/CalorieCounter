add_subdirectory(Model)

add_library(CalorieHistory CalorieHistoryFacade.cpp)

target_link_libraries(CalorieHistory PUBLIC FoodLibrary
    History
    )

target_include_directories(CalorieHistory PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Model
    )
