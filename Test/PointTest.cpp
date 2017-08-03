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
    ASSERT_NEAR(a.X, 5.0f, 0.0001f);
    ASSERT_NEAR(a.Y, 4.0f, 0.0001f);
    ASSERT_NEAR(a.Z, 1.0f, 0.0001f);

    // Test compound literal construction
    Geometry::Point b = {2.0f, 7.0f, 3.0f};
    ASSERT_NEAR(b.X, 2.0f, 0.0001f);
    ASSERT_NEAR(b.Y, 7.0f, 0.0001f);
    ASSERT_NEAR(b.Z, 3.0f, 0.0001f);

    // Test assignment operator
    Geometry::Point c = a;
    ASSERT_NEAR(c.X, 5.0f, 0.0001f);
    ASSERT_NEAR(c.Y, 4.0f, 0.0001f);
    ASSERT_NEAR(c.Z, 1.0f, 0.0001f);

    // Test copy constructor
    Geometry::Point d(a);
    ASSERT_NEAR(d.X, 5.0f, 0.0001f);
    ASSERT_NEAR(d.Y, 4.0f, 0.0001f);
    ASSERT_NEAR(d.Z, 1.0f, 0.0001f);

    // Test independence
    c.X = 7.0f;
    c.Y = 3.0f;
    c.Z = 4.0f;

    ASSERT_NEAR(a.X, 5.0f, 0.0001f);
    ASSERT_NEAR(a.Y, 4.0f, 0.0001f);
    ASSERT_NEAR(a.Z, 1.0f, 0.0001f);
    ASSERT_NEAR(b.X, 2.0f, 0.0001f);
    ASSERT_NEAR(b.Y, 7.0f, 0.0001f);
    ASSERT_NEAR(b.Z, 3.0f, 0.0001f);
    ASSERT_NEAR(d.X, 5.0f, 0.0001f);
    ASSERT_NEAR(d.Y, 4.0f, 0.0001f);
    ASSERT_NEAR(d.Z, 1.0f, 0.0001f);
}

/**
 * This test case test Point's Distance method.
 */
TEST(Point, Distance)
{
    Geometry::Point a(0.0f, 0.0f, 0.0f);
    Geometry::Point b(5.0f, 0.0f, 0.0f);

    // Basic Test
    ASSERT_NEAR(a.Distance(b), 5.0f, 0.0001f);

    // Test distance reflection
    ASSERT_EQ(a.Distance(b), b.Distance(a));

    // Test distance to center from every angle of the sphere
    for (float angleZ = 0.0f; angleZ < 2 * M_PI; angleZ += 0.01f)
    {
        for (float angleY = 0.0f; angleY < 2 * M_PI; angleY += 0.01f)
        {
            b.X = sinf(angleY) * cosf(angleZ);
            b.Y = sinf(angleY) * sinf(angleZ);
            b.Z = cosf(angleY);

            ASSERT_NEAR(b.Distance(a), 1.0f, 0.0001f);
        }
    }

    // Just like above, only this time it's testing distance to non-center coordinate
    // And also distance is variable
    a.X = 74.5f;
    a.Y = -4.3f;
    a.Z = 15.2f;
    for (float angleZ = 0.0f; angleZ < 2 * M_PI; angleZ += 0.1f)
    {
        for (float angleY = 0.0f; angleY < 2 * M_PI; angleY += 0.1f)
        {
            for (float distance = 0.2f; distance < 2.2f; distance += 0.2f)
            {
                b.X = distance * sinf(angleY) * cosf(angleZ) + 74.5f;
                b.Y = distance * sinf(angleY) * sinf(angleZ) - 4.3f;
                b.Z = distance * cosf(angleY) + 15.2f;

                ASSERT_NEAR(b.Distance(a), distance, 0.0001f);
            }
        }
    }
}
