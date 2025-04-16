add_library(AppManager AppManager.cpp)

target_include_directories(AppManager PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/DBInterface
    ${PROJECT_SOURCE_DIR}/UserInterface
    ${PROJECT_SOURCE_DIR}/CalorieTracker
    ${PROJECT_SOURCE_DIR}/WeightTracker
    )

target_link_libraries(AppManager PUBLIC
        DBInterface
        UserInterface
        CalorieTracker
        WeightTracker
        )
