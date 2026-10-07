cmake_minimum_required(VERSION 3.20)
project(elevator-dispatch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(elevator_core
    src/generator.cpp
)

target_include_directories(elevator_core PUBLIC src)
target_compile_options(elevator_core PUBLIC
    -Wall -Wextra -Wpedantic -Wconversion
)

add_executable(gen src/main.cpp)
target_link_libraries(gen PRIVATE elevator_core)
