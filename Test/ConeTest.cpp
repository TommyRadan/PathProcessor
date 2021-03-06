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

#include <Geometry/Cone.hpp>

/**
 * This test case tests Cone construction.
 */
TEST(Cone, Construction)
{
    Geometry::Cone cone({5.0f, 4.0f, 3.0f}, 30.0f, 0.05f);

    EXPECT_EQ(cone.GetPosition().GetX(), 5.0f);
    EXPECT_EQ(cone.GetPosition().GetY(), 4.0f);
    EXPECT_EQ(cone.GetPosition().GetZ(), 3.0f);
    EXPECT_EQ(cone.GetAngle(), 30.0f);
    EXPECT_EQ(cone.GetRadius(), 0.05f);
}
