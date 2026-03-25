cmake_minimum_required(VERSION 3.10)
project(robot)
#[TODO] Implentasikan CMakeList di bawah ini
add_compile_options(-Wall -Wextra -Wpedantic)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# add executable
add_executable(main src/main.cpp src/robot.cpp src/robotair.cpp)

set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)