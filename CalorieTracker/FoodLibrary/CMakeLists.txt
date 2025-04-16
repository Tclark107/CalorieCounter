add_subdirectory(Model)
add_subdirectory(Service)
add_subdirectory(DBInterface)

add_library(FoodLibrary FoodLibraryFacade.cpp)

target_link_libraries(FoodLibrary
    FoodLibraryService
    FoodItem
    FoodLibraryDBInterface
    )

target_include_directories(FoodLibrary PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/DBInterface
    ${CMAKE_CURRENT_SOURCE_DIR}/Model
    ${CMAKE_CURRENT_SOURCE_DIR}/Service
    ${CMAKE_SOURCE_DIR}/UserInterface
    )
