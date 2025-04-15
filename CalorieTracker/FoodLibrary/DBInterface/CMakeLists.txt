add_library(FoodLibraryDBInterface 
    FoodLibraryDBInterfaceFactory.cpp
    DevFoodLibraryDBInterface.cpp
    RealFoodLibraryDBInterface.cpp
    ../../DBInterface/FileIODBInterface.cpp
    )

target_include_directories(FoodLibraryDBInterface PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../../DBInterface
    )
