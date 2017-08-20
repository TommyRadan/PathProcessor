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

#include <STL/StlLoader.hpp>

/**
 * This test case tests how loader behaves when it gets nothing.
 */
TEST(StlLoader, EmptyFile)
{
    Geometry::Mesh mesh;

    mesh = STL::StlToMesh({});

    ASSERT_EQ(mesh.GetData().size(), 0);
}

TEST(StlLoader, NotEnoughPoints)
{
    Geometry::Mesh mesh;
    std::vector<std::string> lines;

    lines.emplace_back("v 5.6 3.9 2.8");
    lines.emplace_back("v 4.3 6.3 1.0");

    EXPECT_ANY_THROW(mesh = STL::StlToMesh(lines););
}

TEST(StlLoader, InvalidLine)
{
    Geometry::Mesh mesh;
    std::vector<std::string> lines;

    lines.emplace_back("v 5.6 3.9 2.8");
    lines.emplace_back("v 4.3 6.3 1.0");
    lines.emplace_back("y test 6.32 g");

    EXPECT_ANY_THROW(mesh = STL::StlToMesh(lines););
}

TEST(StlLoader, BasicOneTriangle)
{
    Geometry::Mesh mesh;
    std::vector<std::string> lines;

    lines.emplace_back("v 5.6 3.9 2.8");
    lines.emplace_back("v 4.3 6.3 1.0");
    lines.emplace_back("v 3.7 2.3 3.9");

    mesh = STL::StlToMesh(lines);

    ASSERT_FLOAT_EQ(mesh.GetData()[0].GetA().GetX(), 5.6f);
    ASSERT_FLOAT_EQ(mesh.GetData()[0].GetA().GetY(), 3.9f);
    ASSERT_FLOAT_EQ(mesh.GetData()[0].GetA().GetZ(), 2.8f);

    ASSERT_FLOAT_EQ(mesh.GetData()[0].GetB().GetX(), 4.3f);
    ASSERT_FLOAT_EQ(mesh.GetData()[0].GetB().GetY(), 6.3f);
    ASSERT_FLOAT_EQ(mesh.GetData()[0].GetB().GetZ(), 1.0f);

    ASSERT_FLOAT_EQ(mesh.GetData()[0].GetC().GetX(), 3.7f);
    ASSERT_FLOAT_EQ(mesh.GetData()[0].GetC().GetY(), 2.3f);
    ASSERT_FLOAT_EQ(mesh.GetData()[0].GetC().GetZ(), 3.9f);
}
