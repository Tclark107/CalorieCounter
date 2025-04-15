add_library(FoodLibrary FoodLibrary.cpp FoodItem.cpp)

target_link_libraries()

target_include_directories(FoodLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
