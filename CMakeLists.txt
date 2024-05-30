cmake_minimum_required(VERSION 3.10)

project(Pangolution VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Pangolution
    main.cpp
    Pangolin.cpp
    Utility.cpp
)

target_include_directories(Pangolution PUBLIC "${PROJECT_SOURCE_DIR}")

# Add compiler flags if needed
# target_compile_options(Pangolution PRIVATE -Wall -Wextra)

# Link libraries if needed
# target_link_libraries(Pangolution PRIVATE some_library)
