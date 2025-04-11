add_executable(AppDriver main.cpp)

# Link the libraries
target_link_libraries(AppDriver 
                      CalorieTrackerManager
                      CalorieCalculator 
                      FoodLibrary
                      CalorieHistory
                      DBInterface
                      UserInterface
                      WeightTracker
                      Utility
                      )

# Include directories
target_include_directories(AppDriver PUBLIC
            ${PROJECT_SOURCE_DIR}/CalorieTrackerManager
            ${PROJECT_SOURCE_DIR}/CalorieCalculator
            ${PROJECT_SOURCE_DIR}/FoodLibrary
            ${PROJECT_SOURCE_DIR}/CalorieHistory
            ${PROJECT_SOURCE_DIR}/DBInterface
            ${PROJECT_SOURCE_DIR}/UserInterface
            ${PROJECT_SOURCE_DIR}/WeightTracker
            ${PROJECT_SOURCE_DIR}/Utility
            )

