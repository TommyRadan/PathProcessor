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
#include <Controller/Settings.hpp>

/**
 * This test case tests how parser behaves when it gets nothing.
 */
TEST(GCodeLoader, EmptyPath)
{
    Controller::Settings* settings = Controller::Settings::GetInstance();
    settings->SetSubdivisionX(0);
    settings->SetSubdivisionY(0);
    settings->SetSubdivisionZ(0);

    Geometry::Path path;
    std::vector<std::string> file;

    file = GCode::PathToGCode(path);

    ASSERT_EQ(file.size(), 0);

    Controller::Settings::ReleaseInstance();
}

/**
 * This test case tests g-code generation from path of one point.
 */
TEST(GCodeLoader, OnePointPath)
{
    Controller::Settings* settings = Controller::Settings::GetInstance();
    settings->SetSubdivisionX(0);
    settings->SetSubdivisionY(0);
    settings->SetSubdivisionZ(0);

    Geometry::Path path;
    std::vector<std::string> file;

    path.GetData().emplace_back(Geometry::Point{5.3932f, 2.3843f, 0.2012f});

    file = GCode::PathToGCode(path);

    ASSERT_EQ(file.size(), 1);
    ASSERT_STREQ(file[0].c_str(), "G1 X5.3932 Y2.3843 Z0.2012");

    Controller::Settings::ReleaseInstance();
}

/**
 * This test case tests g-code generation from path of two points.
 */
TEST(GCodeLoader, TwoPointsPath)
{
    Controller::Settings* settings = Controller::Settings::GetInstance();
    settings->SetSubdivisionX(0);
    settings->SetSubdivisionY(0);
    settings->SetSubdivisionZ(0);

    Geometry::Path path;
    std::vector<std::string> file;

    path.GetData().emplace_back(Geometry::Point{5.3326f, 2.3123f, 0.2748f});
    path.GetData().emplace_back(Geometry::Point{-3.4542f, 0.0000f, 34.9234f});

    file = GCode::PathToGCode(path);

    ASSERT_EQ(file.size(), 2);
    ASSERT_STREQ(file[0].c_str(), "G1 X5.3326 Y2.3123 Z0.2748");
    ASSERT_STREQ(file[1].c_str(), "G1 X-3.4542 Y0.0000 Z34.9234");

    Controller::Settings::ReleaseInstance();
}
