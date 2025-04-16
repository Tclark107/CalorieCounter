add_library(FoodLibraryDBInterface 
    FoodLibraryDBInterfaceFactory.cpp
    DevLibraryDBInterface.cpp
    RealLibraryDBInterface.cpp
    ../../../DBInterface/FileIODBInterface.cpp
    )

target_include_directories(FoodLibraryDBInterface PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/DBInterface
    )
