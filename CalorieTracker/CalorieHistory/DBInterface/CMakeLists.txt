add_library(HistoryDBInterface 
    HistoryDBInterfaceFactory.cpp
    DevHistoryDBInterface.cpp
    RealHistoryDBInterface.cpp
    ../../../DBInterface/FileIODBInterface.cpp
    )

target_include_directories(HistoryDBInterface PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/DBInterface
    )
