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

#include <Geometry/Mesh.hpp>

/**
 * This test case tests Mesh construction.
 */
TEST(Mesh, Construction)
{
    Geometry::Mesh mesh;

    ASSERT_EQ(mesh.GetData().size(), 0);
}

/**
 * This test case tests adding a Triangle to the Mesh.
 */
TEST(Mesh, AddingTriangle)
{
    Geometry::Mesh mesh;
    Geometry::Point p1(5.0f, 4.0f, 3.0f);
    Geometry::Point p2(5.0f, 3.0f, 4.0f);
    Geometry::Point p3(4.0f, 5.0f, 3.0f);

    ASSERT_EQ(mesh.GetData().size(), 0);

    Geometry::Triangle triangle(p1, p2, p3);

    mesh.AddTriangle(triangle);

    ASSERT_EQ(mesh.GetData().size(), 1);
}
