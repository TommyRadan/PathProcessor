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

#include <Controller/CollisionDetection.hpp>
#include <Geometry/VerticalLine.hpp>
#include <cmath>

namespace Controller
{
    /**
     * This function test Cone against Point and determines if there is a collision.
     *
     * @param cone - Cone for testing.
     * @param point - Point for testing.
     *
     * @return True - If there is any collision.
     * @return False - If there is no collision.
     */
    static const bool IsInCollision(const Geometry::Cone& cone, const Geometry::Point& point)
    {
        const Geometry::VerticalLine coneCenter { cone.GetPosition() };

        // Point is bellow cone
        if (point.GetZ() < cone.GetPosition().GetZ())
        {
            return false;
        }

        // Point is further from the center then cone radius
        if (coneCenter.GetDistance(point) > cone.GetRadius())
        {
            return false;
        }

        const float deltaX { point.GetX() - cone.GetPosition().GetX() };
        const float deltaY { point.GetY() - cone.GetPosition().GetY() };
        const float deltaZ { point.GetZ() - cone.GetPosition().GetZ() };

        const float deltaXY { sqrtf(powf(deltaX, 2.0f) + powf(deltaY, 2.0f)) };
        const float coneToPointAngle { atanf(deltaZ / deltaXY) };

        return (coneToPointAngle > cone.GetAngle());
    }

    /**
     * This function test Cone against Triangle and determines if there is a collision.
     *
     * @param cone - Cone for testing.
     * @param triangle - Triangle for testing.
     *
     * @return True - If there is any collision.
     * @return False - If there is no collision.
     */
    static const bool IsInCollision(const Geometry::Cone& cone, const Geometry::Triangle& triangle)
    {
        const bool isCollisionA { IsInCollision(cone, triangle.GetA()) };
        const bool isCollisionB { IsInCollision(cone, triangle.GetB()) };
        const bool isCollisionC { IsInCollision(cone, triangle.GetC()) };

        return (isCollisionA || isCollisionB || isCollisionC);
    }

    /**
     * This function tests Cone against Mesh and determines if there is a collision.
     *
     * @param cone - Cone for testing.
     * @param mesh - Mesh for testing.
     *
     * @return True - If there is any collision.
     * @return False - If there is no collision.
     */
    const bool IsInCollision(const Geometry::Cone& cone, const Geometry::Mesh& mesh)
    {
        bool verdict { false };

        for (auto& triangle : mesh.GetData())
        {
            if (IsInCollision(cone, triangle))
            {
                verdict = true;
                break;
            }
        }

        return verdict;
    }
}
