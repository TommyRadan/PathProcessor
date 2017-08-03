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
#include <cmath>

#include <Geometry/Point.hpp>

/**
 * This test case tests Point construction in multiple ways.
 */
TEST(Point, Construction)
{
    // Test main constructor
    Geometry::Point a(5.0f, 4.0f, 1.0f);
    ASSERT_FLOAT_EQ(a.X, 5.0f);
    ASSERT_FLOAT_EQ(a.Y, 4.0f);
    ASSERT_FLOAT_EQ(a.Z, 1.0f);

    // Test compound literal construction
    Geometry::Point b = {2.0f, 7.0f, 3.0f};
    ASSERT_FLOAT_EQ(b.X, 2.0f);
    ASSERT_FLOAT_EQ(b.Y, 7.0f);
    ASSERT_FLOAT_EQ(b.Z, 3.0f);

    // Test assignment operator
    Geometry::Point c = a;
    ASSERT_FLOAT_EQ(c.X, 5.0f);
    ASSERT_FLOAT_EQ(c.Y, 4.0f);
    ASSERT_FLOAT_EQ(c.Z, 1.0f);

    // Test copy constructor
    Geometry::Point d(a);
    ASSERT_FLOAT_EQ(d.X, 5.0f);
    ASSERT_FLOAT_EQ(d.Y, 4.0f);
    ASSERT_FLOAT_EQ(d.Z, 1.0f);
}

/**
 * This test case tests Point memory independence.
 */
TEST(Point, Independence)
{
    Geometry::Point a(0.0f, 4.0f, 7.0f);
    Geometry::Point b(5.0f, 0.0f, 2.0f);

    ASSERT_FLOAT_EQ(a.X, 0.0f);
    ASSERT_FLOAT_EQ(a.Y, 4.0f);
    ASSERT_FLOAT_EQ(a.Z, 7.0f);

    a.X = 3.0f;
    a.Y = 2.0f;
    a.Z = 5.0f;

    ASSERT_FLOAT_EQ(a.X, 3.0f);
    ASSERT_FLOAT_EQ(a.Y, 2.0f);
    ASSERT_FLOAT_EQ(a.Z, 5.0f);
    ASSERT_FLOAT_EQ(b.X, 5.0f);
    ASSERT_FLOAT_EQ(b.Y, 0.0f);
    ASSERT_FLOAT_EQ(b.Z, 2.0f);
}

/**
 * This test case test Point's Distance method.
 */
TEST(Point, Distance)
{
    Geometry::Point a(0.0f, 0.0f, 0.0f);
    Geometry::Point b(5.0f, 0.0f, 0.0f);

    // Basic Test
    ASSERT_FLOAT_EQ(a.Distance(b), 5.0f);
    ASSERT_FLOAT_EQ(a.Distance(b), b.Distance(a));
    ASSERT_FLOAT_EQ(a.Distance(a), 0.0f);
    ASSERT_FLOAT_EQ(b.Distance(b), 0.0f);

    // Test distance to center from every angle of the sphere
    for (float angleZ = 0.0f; angleZ < 2 * M_PI; angleZ += 0.1f)
    {
        for (float angleY = 0.0f; angleY < 2 * M_PI; angleY += 0.1f)
        {
            for (float distance = 0.2f; distance < 2.2f; distance += 0.2f)
            {
                b.X = distance * sinf(angleY) * cosf(angleZ);
                b.Y = distance * sinf(angleY) * sinf(angleZ);
                b.Z = distance * cosf(angleY);

                ASSERT_FLOAT_EQ(b.Distance(a), distance);
                ASSERT_FLOAT_EQ(a.Distance(b), distance);
            }
        }
    }
}
