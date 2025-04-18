add_subdirectory(Model)
add_subdirectory(Service)
add_subdirectory(DBInterface)

add_library(CalorieHistory CalorieHistoryFacade.cpp)

target_link_libraries(CalorieHistory 
    History
    CalorieHistoryService
    HistoryDBInterface
    )

target_include_directories(CalorieHistory PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Model
    ${CMAKE_CURRENT_SOURCE_DIR}/Service
    ${CMAKE_CURRENT_SOURCE_DIR}/DBInterface
    ${CMAKE_SOURCE_DIR}/UserInterface
    )
