add_library(WeightEntryParser WeightEntryParser.cpp)

target_include_directories( WeightEntryParser PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../Model
    )
