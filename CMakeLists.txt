cmake_minimum_required(VERSION 3.7)
project(PathProcessing)

set(CMAKE_CXX_STANDARD 11)

include_directories(Include/)

set(SOURCE_FILES
        Source/Controller/main.cpp
        Source/Controller/Settings.cpp
        Source/Geometry/Vector3.cpp)

add_executable(PathProcessing ${SOURCE_FILES})
