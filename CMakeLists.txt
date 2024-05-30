# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Pangolution VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable for the main application
add_executable(Pangolution
    main.cpp
    Pangolin.cpp
    Utility.cpp
)

# Include directories
target_include_directories(Pangolution PUBLIC "${PROJECT_SOURCE_DIR}")

# Link libraries (if any)
# target_link_libraries(Pangolution PRIVATE some_library)
