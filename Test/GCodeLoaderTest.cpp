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

#include <gtest/gtest.h>

#include <G-Code/GCodeLoader.hpp>

/**
 * This test case tests how parser behaves when it gets nothing.
 */
TEST(GCodeLoader, EmptyPath)
{
    Geometry::Path path;
    std::vector<std::string> file;

    file = GCode::PathToGCode(path);

    ASSERT_EQ(file.size(), 0);
}

TEST(GCodeLoader, OnePointPath)
{
    Geometry::Path path;
    std::vector<std::string> file;

    path.GetData().emplace_back(Geometry::Point{5.3f, 2.3f, 0.2f});

    file = GCode::PathToGCode(path);

    ASSERT_EQ(file.size(), 1);
    ASSERT_STREQ(file[0].c_str(), "G1 X5.3 Y2.3 Z0.2");
}

TEST(GCodeLoader, TwoPointsPath)
{
    Geometry::Path path;
    std::vector<std::string> file;

    path.GetData().emplace_back(Geometry::Point{5.3f, 2.3f, 0.2f});
    path.GetData().emplace_back(Geometry::Point{-3.4f, 0.0f, 34.9f});

    file = GCode::PathToGCode(path);

    ASSERT_EQ(file.size(), 2);
    ASSERT_STREQ(file[0].c_str(), "G1 X5.3 Y2.3 Z0.2");
    ASSERT_STREQ(file[1].c_str(), "G1 X-3.4 Y0.0 Z34.9");
}
