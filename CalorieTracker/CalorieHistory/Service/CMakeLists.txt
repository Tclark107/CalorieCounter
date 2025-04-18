add_library(CalorieHistoryService CalorieHistoryService.cpp)

target_link_libraries(CalorieHistoryService
    Utility
    History
    HistoryDBInterface
    )

target_include_directories(CalorieHistoryService PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../Model
    ${CMAKE_CURRENT_SOURCE_DIR}/../DBInterface
    ${CMAKE_SOURCE_DIR}/DBInterface
    ${CMAKE_SOURCE_DIR}/Utility
    )
