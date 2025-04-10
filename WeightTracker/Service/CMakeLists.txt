add_library(WeightTrackerService WeightTrackerService.cpp)

target_include_directories( WeightTrackerService PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../Model
    ${CMAKE_CURRENT_SOURCE_DIR}/../DBInterface
    )
