cmake_minimum_required(VERSION 3.10)

project(CalorieApp LANGUAGES CXX)

# Add subdirectories
add_subdirectory(AppManager)
add_subdirectory(AppDriver)
add_subdirectory(UserInterface)
add_subdirectory(DBInterface)
add_subdirectory(Utility)
add_subdirectory(CalorieTracker)
add_subdirectory(WeightTracker)

