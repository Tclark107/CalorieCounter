add_subdirectory(Model)
add_subdirectory(Parser)
add_subdirectory(Service)
add_subdirectory(DBInterface)

add_library(WeightTrackerFacade WeightTrackerFacade.cpp)

target_link_libraries(WeightTrackerFacade
    WeightTrackerService
    WeightEntry
    WeightTrackerDBInterface
    )

target_include_directories(WeightTrackerFacade PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/DBInterface
    ${CMAKE_CURRENT_SOURCE_DIR}/Model
    ${CMAKE_CURRENT_SOURCE_DIR}/Parser
    ${CMAKE_CURRENT_SOURCE_DIR}/Service
    ${CMAKE_CURRENT_SOURCE_DIR}/../UserInterface
    )

