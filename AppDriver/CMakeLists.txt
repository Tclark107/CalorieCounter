add_executable(AppDriver main.cpp)

# Link the libraries
target_link_libraries(AppDriver 
                      CalorieCalculator 
                      FoodItem 
                      CalorieHistory
                      DBInterface
                      UserInterface)

# Include directories
target_include_directories(AppDriver PUBLIC
            ${PROJECT_SOURCE_DIR}/CalorieCalculator
            ${PROJECT_SOURCE_DIR}/FoodItem
            ${PROJECT_SOURCE_DIR}/CalorieHistory
            ${PROJECT_SOURCE_DIR}/DBInterface
            ${PROJECT_SOURCE_DIR}/UserInterface
            )

