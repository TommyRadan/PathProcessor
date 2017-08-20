cmake_minimum_required(VERSION 3.2)

project(PathProcessing)
set(CMAKE_CXX_STANDARD 11)

###################################################################
# Application Main Build
###################################################################

include_directories(Include/)

set(INCLUDE_FILES
        Include/Controller/Settings.hpp
        Include/Controller/ArgumentParser.hpp
        Include/STL/StlLoader.hpp
        Include/STL/StlFileReader.hpp
        Include/G-Code/GCodeLoader.hpp
        Include/G-Code/GCodeFileWriter.hpp
        Include/Geometry/Point.hpp
        Include/Geometry/VerticalLine.hpp
        Include/Geometry/Triangle.hpp
        Include/Geometry/Mesh.hpp
        Include/Geometry/Path.hpp
        Include/Geometry/Cone.hpp)

set(SOURCE_FILES
        Source/Controller/Settings.cpp
        Source/Controller/ArgumentParser.cpp
        Source/STL/StlLoader.cpp
        Source/STL/StlFileReader.cpp
        Source/G-Code/GCodeLoader.cpp
        Source/G-Code/GCodeFileWriter.cpp
        Source/Geometry/Point.cpp
        Source/Geometry/VerticalLine.cpp
        Source/Geometry/Triangle.cpp
        Source/Geometry/Mesh.cpp
        Source/Geometry/Path.cpp
        Source/Geometry/Cone.cpp)

add_executable(PathProcessing
        Source/Controller/EntryPoint.cpp
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
        Test/PathTest.cpp
        Test/GCodeLoaderTest.cpp
        Test/ConeTest.cpp
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
