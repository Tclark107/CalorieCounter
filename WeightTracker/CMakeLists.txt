add_subdirectory(Model)
add_subdirectory(Parser)
add_subdirectory(Service)
add_subdirectory(DBInterface)

add_library(WeightTracker WeightTracker.cpp)

target_link_libraries(WeightTracker
    WeightTrackerService
    WeightEntry
    WeightTrackerDBInterface
    )

target_include_directories(WeightTracker PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/DBInterface
    ${CMAKE_CURRENT_SOURCE_DIR}/Model
    ${CMAKE_CURRENT_SOURCE_DIR}/Parser
    ${CMAKE_CURRENT_SOURCE_DIR}/Service
    ${CMAKE_CURRENT_SOURCE_DIR}/../UserInterface
    )

