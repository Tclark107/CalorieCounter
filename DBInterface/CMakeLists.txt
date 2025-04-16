add_library(DBInterface 
            FileIODBInterface.cpp
            RealHistoryDBInterface.cpp
            DevHistoryDBInterface.cpp
            DBInterfaceFactory.cpp
            )

target_include_directories(DBInterface PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    )
