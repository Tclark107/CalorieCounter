add_library(WeightTrackerService WeightTrackerService.cpp
    )

target_link_libraries(WeightTrackerService
    Utility
    WeightEntry
    )

target_include_directories( WeightTrackerService PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../Model
    ${CMAKE_CURRENT_SOURCE_DIR}/../DBInterface
    ${CMAKE_CURRENT_SOURCE_DIR}/../../DBInterface
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Utility
    )
