add_subdirectory(DBInterface)
add_subdirectory(Model)

add_library(FoodLibrary FoodLibrary.cpp)

target_link_libraries(FoodLibrary
    FoodItem
    FoodLibraryDBInterface
    )

target_include_directories(FoodLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
