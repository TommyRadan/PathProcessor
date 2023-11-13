cmake_minimum_required(VERSION 3.21)

# Read the version from the VERSION file
file(READ "${CMAKE_CURRENT_SOURCE_DIR}/VERSION" VERSION_STRING)
string(STRIP "${VERSION_STRING}" VERSION_STRING)

project(pp VERSION ${VERSION_STRING})
set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/include/)

# Automatically grab all .cpp and .hpp files in the src and include directories
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/include/*.hpp)

add_executable(pp ${SOURCES})

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/code-style.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/generate-docs.cmake)
