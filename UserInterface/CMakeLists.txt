add_library(UserInterface UserInterface.cpp)

target_include_directories(UserInterface PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    )
