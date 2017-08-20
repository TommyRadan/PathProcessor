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

#include <Geometry/Path.hpp>
#include <Controller/Settings.hpp>

/**
 * This test case tests empty Path construction.
 */
TEST(Path, Construction)
{
    Controller::Settings* settings = Controller::Settings::GetInstance();
    settings->SetSubdivisionX(0);
    settings->SetSubdivisionY(0);
    settings->SetSubdivisionZ(0);

    Geometry::Path path;

    ASSERT_EQ(path.GetData().size(), 0);

    Controller::Settings::ReleaseInstance();
}

/**
 * This test case tests construction of the default path.
 */
TEST(Path, DefaultPathConstruction)
{
    Controller::Settings* settings = Controller::Settings::GetInstance();
    settings->SetWorkingAreaX(1.0f);
    settings->SetWorkingAreaY(1.0f);
    settings->SetSubdivisionX(3);
    settings->SetSubdivisionY(3);

    Geometry::Path path;

    ASSERT_EQ(path.GetData().size(), 9);

    for (auto& point : path.GetData())
    {
        EXPECT_FLOAT_EQ(point.GetZ(), 0.0f);
    }

    EXPECT_FLOAT_EQ(path.GetData()[0].GetX(), -0.5f);
    EXPECT_FLOAT_EQ(path.GetData()[0].GetY(), -0.5f);

    EXPECT_FLOAT_EQ(path.GetData()[1].GetX(), -0.5f);
    EXPECT_FLOAT_EQ(path.GetData()[1].GetY(),  0.0f);

    EXPECT_FLOAT_EQ(path.GetData()[2].GetX(), -0.5f);
    EXPECT_FLOAT_EQ(path.GetData()[2].GetY(),  0.5f);

    EXPECT_FLOAT_EQ(path.GetData()[3].GetX(),  0.0f);
    EXPECT_FLOAT_EQ(path.GetData()[3].GetY(),  0.5f);

    EXPECT_FLOAT_EQ(path.GetData()[4].GetX(),  0.0f);
    EXPECT_FLOAT_EQ(path.GetData()[4].GetY(),  0.0f);

    EXPECT_FLOAT_EQ(path.GetData()[5].GetX(),  0.0f);
    EXPECT_FLOAT_EQ(path.GetData()[5].GetY(), -0.5f);

    EXPECT_FLOAT_EQ(path.GetData()[6].GetX(),  0.5f);
    EXPECT_FLOAT_EQ(path.GetData()[6].GetY(), -0.5f);

    EXPECT_FLOAT_EQ(path.GetData()[7].GetX(),  0.5f);
    EXPECT_FLOAT_EQ(path.GetData()[7].GetY(),  0.0f);

    EXPECT_FLOAT_EQ(path.GetData()[8].GetX(),  0.5f);
    EXPECT_FLOAT_EQ(path.GetData()[8].GetY(),  0.5f);

    Controller::Settings::ReleaseInstance();
}
