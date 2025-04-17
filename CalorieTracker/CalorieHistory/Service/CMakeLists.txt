add_library(FoodLibraryService FoodLibraryService.cpp)

target_link_libraries(FoodLibraryService
    Utility
    FoodItem
    FoodLibraryDBInterface
    )

target_include_directories(FoodLibraryService PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../Model
    ${CMAKE_CURRENT_SOURCE_DIR}/../DBInterface
    ${CMAKE_SOURCE_DIR}/DBInterface
    ${CMAKE_SOURCE_DIR}/Utility
    )
