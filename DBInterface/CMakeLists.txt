add_library(DBInterface 
            RealHistoryDBInterface.cpp
            RealLibraryDBInterface.cpp
            DevHistoryDBInterface.cpp
            DevLibraryDBInterface.cpp
            DBInterfaceFactory.cpp
            )

target_include_directories(DBInterface PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    )
