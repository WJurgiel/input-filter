cmake_minimum_required(VERSION 3.29)
project(input_filter)

set(CMAKE_CXX_STANDARD 20)
include_directories(Include)
add_subdirectory(Source)
include(CTest)

add_executable(input_filter main.cpp
        Source/Graph.cpp
        Source/Node.cpp
        Source/GraphComparator.cpp
)
add_subdirectory(external)
add_subdirectory(Test)