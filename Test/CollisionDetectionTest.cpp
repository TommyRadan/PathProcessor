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

#include <Controller/CollisionDetection.hpp>

/**
 * This test case tests basic collision detection.
 */
TEST(CollisionDetection, BasicPositive)
{
    Geometry::Cone cone({0.0f, 0.0f, 0.0f}, 3.14f/4, 1.0f);

    Geometry::Point point1 {0.0f, 0.1f, 0.2f};
    Geometry::Point point2 {0.0f, 3.0f, 0.1f};
    Geometry::Point point3 {0.0f, 3.0f, 0.4f};

    Geometry::Triangle triangle { point1, point2, point3 };

    Geometry::Mesh mesh;
    mesh.AddTriangle(triangle);

    ASSERT_TRUE(Controller::IsInCollision(cone, mesh));
}

/**
 * This test case tests basic collision detection.
 */
TEST(CollisionDetection, BasicPositive2)
{
    Geometry::Cone cone({0.0f, 0.0f, 0.0f}, 3.14f/4, 1.0f);

    Geometry::Point point1 {0.1f, 0.1f, 0.0f};
    Geometry::Point point2 {0.1f, 0.0f, 0.0f};
    Geometry::Point point3 {0.0f, 0.1f, 0.4f};

    Geometry::Triangle triangle { point1, point2, point3 };

    Geometry::Mesh mesh;
    mesh.AddTriangle(triangle);

    ASSERT_TRUE(Controller::IsInCollision(cone, mesh));
}

/**
 * This test case tests basic collision detection.
 */
TEST(CollisionDetection, BasicNegative)
{
    Geometry::Cone cone({0.0f, 0.0f, 0.0f}, 3.14f/4, 1.0f);

    Geometry::Point point1 {0.1f, 0.1f, 0.0f};
    Geometry::Point point2 {0.1f, 0.0f, 0.0f};
    Geometry::Point point3 {0.0f, 0.3f, 0.2f};

    Geometry::Triangle triangle { point1, point2, point3 };

    Geometry::Mesh mesh;
    mesh.AddTriangle(triangle);

    ASSERT_FALSE(Controller::IsInCollision(cone, mesh));
}
