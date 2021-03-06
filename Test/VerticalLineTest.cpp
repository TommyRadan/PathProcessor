/*
 *
 * Copyright 2017-2019 Tomislav Radanovic
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

#include <Geometry/VerticalLine.hpp>

/**
 * This test case tests construction of the VerticalLine.
 */
TEST(VerticalLine, Construction)
{
    Geometry::VerticalLine floatLine(5.0f, 2.0f);

    ASSERT_FLOAT_EQ(floatLine.GetX(), 5.0f);
    ASSERT_FLOAT_EQ(floatLine.GetY(), 2.0f);

    Geometry::Point point(3.0f, 2.0f, 4.0f);
    Geometry::VerticalLine pointLine(point);

    ASSERT_FLOAT_EQ(pointLine.GetX(), 3.0f);
    ASSERT_FLOAT_EQ(pointLine.GetY(), 2.0f);
}

/**
 * This test case tests calculating the distance between two VerticalLines.
 */
TEST(VerticalLine, Distance)
{
    Geometry::VerticalLine line(1.0f, 1.0f);
    Geometry::Point point(1.0f, 2.0f, 7.0f);

    ASSERT_FLOAT_EQ(line.GetDistance(point), 1.0f);
    point.SetZ(-2.0f);
    ASSERT_FLOAT_EQ(line.GetDistance(point), 1.0f);
    point.SetZ(0.0f);
    ASSERT_FLOAT_EQ(line.GetDistance(point), 1.0f);

    point.SetX(1.0f);
    point.SetY(1.0f);
    point.SetZ(7.0f);

    ASSERT_FLOAT_EQ(line.GetDistance(point), 0.0f);
    point.SetZ(-2.0f);
    ASSERT_FLOAT_EQ(line.GetDistance(point), 0.0f);
    point.SetZ(0.0f);
    ASSERT_FLOAT_EQ(line.GetDistance(point), 0.0f);
}
