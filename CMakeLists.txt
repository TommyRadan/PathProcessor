cmake_minimum_required(VERSION 3.2)

project(PathProcessing)
set(CMAKE_CXX_STANDARD 11)

###################################################################
# Application Main Build
###################################################################

include_directories(Include/)

set(INCLUDE_FILES
        Include/Controller/Settings.hpp
        Include/Controller/StlLoader.hpp
        Include/Controller/StlFileReader.hpp
        Include/Controller/ArgumentParser.hpp
        Include/Geometry/Point.hpp
        Include/Geometry/VerticalLine.hpp
        Include/Geometry/Triangle.hpp
        Include/Geometry/Mesh.hpp)

set(SOURCE_FILES
        Source/Controller/Settings.cpp
        Source/Controller/StlLoader.cpp
        Source/Controller/StlFileReader.cpp
        Source/Controller/ArgumentParser.cpp
        Source/Geometry/Point.cpp
        Source/Geometry/VerticalLine.cpp
        Source/Geometry/Triangle.cpp
        Source/Geometry/Mesh.cpp)

add_executable(PathProcessing
        Source/Controller/main.cpp
        ${SOURCE_FILES}
        ${INCLUDE_FILES})

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
        Test/VerticalLineTest.cpp
        Test/TriangleTest.cpp
        Test/SettingsTest.cpp
        Test/MeshTest.cpp
        Test/StlLoaderTest.cpp
        Test/ArgumentParserTest.cpp
        ${SOURCE_FILES}
        ${INCLUDE_FILES})

target_compile_definitions(UnitTest PRIVATE -DUNDER_TEST)

find_package (Threads)
add_dependencies(UnitTest gtest)
include_directories(${source_dir}/googletest/include)
target_link_libraries(UnitTest
        ${binary_dir}/googlemock/gtest/libgtest.a
        ${binary_dir}/googlemock/gtest/libgtest_main.a
        ${CMAKE_THREAD_LIBS_INIT})
