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

#include <STL/StlLoader.hpp>
#include <sstream>
#include <stdexcept>

namespace STL
{
    /**
     * This function constructs a Point from a line of STL file.
     *
     * @param line - The line.
     *
     * @return A Point which was constructed.
     */
    static Geometry::Point ConstructPoint(const std::string& line)
    {
        std::istringstream stream(line);
        char control;
        float coordinates[3];
        stream >> control >> coordinates[0] >> coordinates[1] >> coordinates[2];

        if (control != 'v')
        {
            throw std::invalid_argument("Point construction failed! Input: \"" + line + "\"");
        }

        return {coordinates[0], coordinates[1], coordinates[2]};
    }

    /**
     * This function constructs a Triangle from three lines of STL file.
     *
     * @param line1 - First line.
     * @param line2 - Second line.
     * @param line3 - Third line.
     *
     * @return A Triangle which was constructed.
     */
    static Geometry::Triangle ConstructTriangle(const std::string& line1,
                                                const std::string& line2,
                                                const std::string& line3)
    {
        Geometry::Triangle result;

        result.SetA(ConstructPoint(line1));
        result.SetB(ConstructPoint(line2));
        result.SetC(ConstructPoint(line3));

        return result;
    }

    /**
     * This function converts a vector of stl file lines to Mesh.
     *
     * @param stlFile - Vector of strings which together represent a STL file.
     *
     * @return Resulting Mesh.
     */
    Geometry::Mesh StlToMesh(const std::vector<std::string>& stlFile)
    {
        Geometry::Mesh mesh;

        if (stlFile.size() % 3 != 0)
        {
            std::string message("Wrong number of lines provided! Num of lines: ");
            std::string numOfLines = std::to_string(stlFile.size());
            throw std::invalid_argument(message + numOfLines);
        }

        for (int i = 0; i < stlFile.size();)
        {
            std::string point[3];

            point[0] = stlFile[i++];
            point[1] = stlFile[i++];
            point[2] = stlFile[i++];

            mesh.AddTriangle(ConstructTriangle(point[0], point[1], point[2]));
        }

        return mesh;
    }
}
