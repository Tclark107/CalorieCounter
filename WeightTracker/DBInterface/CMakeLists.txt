add_library(WeightTrackerDBInterface 
    WeightTrackerDBInterfaceFactory.cpp
    DevWeightTrackerDBInterface.cpp
    RealWeightTrackerDBInterface.cpp
    )

target_include_directories(WeightTrackerDBInterface PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../../DBInterface
    )
