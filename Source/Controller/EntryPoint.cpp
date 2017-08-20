/*
 *
 * Copyright 2017 Tomislav Radanovic
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include <cstdlib>
#include <iostream>

#include <Controller/ArgumentParser.hpp>
#include <Controller/Settings.hpp>
#include <Controller/PathProcessing.hpp>
#include <Geometry/Mesh.hpp>
#include <STL/StlFileReader.hpp>
#include <STL/StlLoader.hpp>
#include <G-Code/GCodeLoader.hpp>
#include <G-Code/GCodeFileWriter.hpp>

/**
 * This function is called by operating system when the application exits.
 */
static void OnApplicationExit()
{
    Controller::Settings::ReleaseInstance();
}

/**
 * Application entry point.
 *
 * @param argc - count of command line arguments.
 * @param argv - pointer to list of pointers to command line arguments.
 *
 * @return EXIT_SUCCESS - everything went fine.
 * @return EXIT_FAILURE - something went wrong.
 */
int main(int argc, char** argv)
{
    atexit(OnApplicationExit);

    if (!Controller::ParseArguments(argc, argv))
    {
        return EXIT_FAILURE;
    }

    try
    {
        Geometry::Mesh mesh { STL::StlToMesh(STL::StlFileRead()) };
        Geometry::Path path;
        Controller::ProcessThePath(path, mesh);
        GCode::GCodeFileWrite(GCode::PathToGCode(path));
    }
    catch (const std::exception& e)
    {
#ifndef UNDER_TEST
        std::string message { "The application fails with a message: " };
        std::string reason { e.what() };
        std::cout << message << "\"" << reason << "\"" << std::endl;
#endif
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}