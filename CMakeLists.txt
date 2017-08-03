cmake_minimum_required(VERSION 3.7)

###################################################################
# Application Main Build
###################################################################

project(PathProcessing)

set(CMAKE_CXX_STANDARD 11)

include_directories(Include/)

set(SOURCE_FILES
        Source/Controller/main.cpp
        Source/Controller/Settings.cpp
        Source/Geometry/Point.cpp)

add_executable(PathProcessing ${SOURCE_FILES})

###################################################################
# Application Tests
###################################################################

include(ExternalProject)
ExternalProject_Add(gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG master
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
        TIMEOUT 10
        INSTALL_COMMAND "")

ExternalProject_Get_Property(gtest
        source_dir
        binary_dir)

add_executable(UnitTest
        Test/PointTest.cpp
        Source/Geometry/Point.cpp)

add_dependencies(UnitTest gtest)
include_directories(${source_dir}/googletest/include)
target_link_libraries(UnitTest ${binary_dir}/googlemock/gtest/libgtest.a)
target_link_libraries(UnitTest ${binary_dir}/googlemock/gtest/libgtest_main.a)

enable_testing()
add_test(NAME UnitTest
         COMMAND runUnitTests)
