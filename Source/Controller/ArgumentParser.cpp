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
        std::cout << "PathProcessor - Lightweight STL to G-Code converter" << std::endl << std::endl;
        std::cout << "  --input -i       - STL file input" << std::endl;
        std::cout << "  --output -o      - G-code file output" << std::endl;
#endif
    }

    /**
     * This function parses one argument and sets value to Settings class.
     *
     * @param arg - One Argument to parse.
     *
     * @return Returns true if parsing is successful.
     */
    static bool ParseArgument(const Argument arg)
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

        return false;
    }

    /**
     * This functions parses all command line arguments.
     *
     * @param argc - Argument count.
     * @param argv - Argument vector.
     *
     * @return Returns true if parsing is successful.
     */
    bool ParseArguments(int argc, char** argv)
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
