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

#include <STL/StlFileReader.hpp>

#include <fstream>
#include <stdexcept>
#include <sstream>
#include <Controller/Settings.hpp>

namespace STL
{
    /**
     * This functions counts words in one line.
     *
     * @param line - The line.
     *
     * @return Number of words.
     */
    static uint32_t CountWords(const std::string& string)
    {
        uint32_t word_count { 0U };
        std::stringstream ss { string };
        std::string word;
        while (ss >> word) ++word_count;
        return word_count;
    }

    /**
     * This function check if the line is valid.
     *
     * @param line - The line.
     *
     * @return Result of validating.
     */
    static bool IsValidLine(const std::string& line)
    {
        std::stringstream stream { line };
        std::string control;

        if (line.empty())
        {
            return false;
        }

        stream >> control;

        return (control == "v") && (CountWords(line) == 4);
    }

    /**
     * This function opens a file and reads valid stl lines into vector.
     *
     * @param fileName - File name.
     *
     * @return Vector of strings containing valid lines.
     */
    std::vector<std::string> StlFileRead()
    {
        Controller::Settings* settings { Controller::Settings::GetInstance() };
        const std::string& inputFileName { settings->GetInputFileName() };

        std::ifstream file(inputFileName);
        std::vector<std::string> result;

        if (!file.is_open())
        {
            std::string message("Could not open a file: ");
            throw std::invalid_argument(message + inputFileName);
        }

        while (file.good())
        {
            std::string line;
            std::getline(file, line);

            if (!IsValidLine(line))
            {
                continue;
            }

            result.emplace_back(line);
        }

        file.close();
        return result;
    }
}
