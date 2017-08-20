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

#include <G-Code/GCodeFileWriter.hpp>
#include <fstream>
#include <stdexcept>
#include <Controller/Settings.hpp>

namespace GCode
{
    /**
     * This function outputs vector of lines into a file.
     *
     * @param fileName - Name of the file.
     * @param lines - Vector of lines to output.
     */
    void GCodeFileWrite(const std::vector<std::string>& lines)
    {
        Controller::Settings* settings = Controller::Settings::GetInstance();
        const std::string& outputFileName = settings->GetOutputFileName();

        std::ofstream file(outputFileName);

        if (!file.is_open())
        {
            std::string message("Can not open file for writing: ");
            throw std::invalid_argument(message + outputFileName);
        }

        for (auto& line : lines)
        {
            file << line << std::endl;
        }

        file.close();
    }
}
