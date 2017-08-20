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

#include <Controller/ArgumentParser.hpp>

#include <string>
#include <iostream>
#include <Controller/Settings.hpp>

namespace Controller
{
    /**
     * This structure holds key and value of one argument.
     */
    struct Argument
    {
        std::string key;
        std::string value;
    };

    /**
     * This function prints usage for the program.
     */
    void PrintUsage()
    {
#ifndef UNDER_TEST
        std::cout << "===================================================================================" << std::endl;
        std::cout << "           PathProcessor - Lightweight STL to G-Code converter" << std::endl;
        std::cout << "===================================================================================" << std::endl;
        std::cout << std::endl;
        std::cout << "   [LONG ARGUMENT] [SHORT ARGUMENT]        [DESCRIPTION]             [DEFAULT]" << std::endl;
        std::cout << "===================================================================================" << std::endl;
        std::cout << "  --input               -i       - STL file input                    input.stl" << std::endl;
        std::cout << "  --output              -o       - G-code file output                output.gcode" << std::endl;
        std::cout << "  --working-area-x      -wax     - Tool working area X coordinate    2.5" << std::endl;
        std::cout << "  --working-area-y      -way     - Tool working area Y coordinate    0.5" << std::endl;
        std::cout << "  --working-area-z      -waz     - Tool working area Z coordinate    1.0" << std::endl;
        std::cout << "  --subdivision-x       -sdx     - Tool subdivision X                25" << std::endl;
        std::cout << "  --subdivision-y       -sdy     - Tool subdivision Y                5" << std::endl;
        std::cout << "  --subdivision-z       -sdz     - Tool subdivision Z                10" << std::endl;
        std::cout << "  --radius              -r       - Spindle radius                    0.01" << std::endl;
        std::cout << "  --angle               -a       - Spindle angle                     30" << std::endl;
        std::cout << std::endl;
#endif
    }

    /**
     * This function parses one argument and sets value to Settings class.
     *
     * @param arg - One Argument to parse.
     *
     * @return True - Everything went fine.
     * @return False - Something went wrong.
     */
    static bool ParseArgument(const Argument& arg)
    {
        Controller::Settings* settings = Controller::Settings::GetInstance();

        if(arg.key == "--input" || arg.key == "-i")
        {
            settings->SetInputFileName(arg.value);
            return true;
        }

        if(arg.key == "--output" || arg.key == "-o")
        {
            settings->SetOutputFileName(arg.value);
            return true;
        }

        if(arg.key == "--working-area-x" || arg.key == "-wax")
        {
            settings->SetWorkingAreaX(std::stof(arg.value));
            return true;
        }

        if(arg.key == "--working-area-y" || arg.key == "-way")
        {
            settings->SetWorkingAreaY(std::stof(arg.value));
            return true;
        }

        if(arg.key == "--working-area-z" || arg.key == "-waz")
        {
            settings->SetWorkingAreaZ(std::stof(arg.value));
            return true;
        }

        if(arg.key == "--subdivision-x" || arg.key == "-sdx")
        {
            settings->SetSubdivisionX(std::stoi(arg.value));
            return true;
        }

        if(arg.key == "--subdivision-y" || arg.key == "-sdy")
        {
            settings->SetSubdivisionY(std::stoi(arg.value));
            return true;
        }

        if(arg.key == "--subdivision-z" || arg.key == "-sdz")
        {
            settings->SetSubdivisionZ(std::stoi(arg.value));
            return true;
        }

        if(arg.key == "--radius" || arg.key == "-r")
        {
            settings->SetSpindleRadius(std::stof(arg.value));
            return true;
        }

        if(arg.key == "--angle" || arg.key == "-a")
        {
            settings->SetSpindleAngle(std::stof(arg.value));
            return true;
        }

        return false;
    }

    /**
     * This functions parses all command line arguments.
     *
     * @param argc - Argument count.
     * @param argv - Argument vector.
     *
     * @return True - Everything went fine.
     * @return False - Something went wrong.
     */
    const bool ParseArguments(int argc, char** argv)
    {
        if ((argc + 1) % 2 != 0)
        {
            PrintUsage();
            return false;
        }

        for (int i = 1; i < argc; i+=2)
        {
            Argument arg;
            arg.key = argv[i];
            arg.value = argv[i + 1];

            if(arg.key == "--help" || arg.key == "-h")
            {
                PrintUsage();
                return false;
            }

            if (!ParseArgument(arg))
            {
                PrintUsage();
                return false;
            }
        }

        return true;
    }
}
