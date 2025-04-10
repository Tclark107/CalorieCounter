add_library(WeightTrackerDBInterface 
    DevWeightTrackerDBInterface.cpp)

target_include_directories(WeightTrackerDBInterface PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    )
