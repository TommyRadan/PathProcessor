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

#include <Geometry/Point.hpp>
#include <cmath>

namespace Geometry
{
    /**
     * Default constructor.
     */
    Point::Point() :
        m_X { 0.0f },
        m_Y { 0.0f },
        m_Z { 0.0f }
    {}

    /**
     * Class constructor.
     *
     * @param x - X component.
     * @param y - Y component.
     * @param z - Z component.
     */
    Point::Point(float x, float y, float z) :
        m_X { x },
        m_Y { y },
        m_Z { z }
    {}

    /**
     * Gets distance between two Points.
     *
     * @param p - The other Point.
     *
     * @return Distance between Points.
     */
    const float Point::Distance(const Point& p) const
    {
        const float dx = m_X - p.m_X;
        const float dy = m_Y - p.m_Y;
        const float dz = m_Z - p.m_Z;

        return sqrtf(dx * dx + dy * dy + dz * dz);
    }

    /**
     * Equals operator between two Points.
     *
     * @param p - Point to compare to.
     *
     * @return True - The Points are the same.
     * @return False - The Points are different.
     */
    bool Point::operator==(const Point& p)
    {
        const bool x = (m_X == p.m_X);
        const bool y = (m_Y == p.m_Y);
        const bool z = (m_Z == p.m_Z);

        return x && y && z;
    }

    /**
     * Gets X coordinate.
     *
     * @return X coordinate.
     */
    const float Point::GetX() const
    {
        return m_X;
    }

    /**
     * Gets Y coordinate.
     *
     * @return Y coordinate.
     */
    const float Point::GetY() const
    {
        return m_Y;
    }

    /**
     * Gets Z coordinate.
     *
     * @return Z coordinate.
     */
    const float Point::GetZ() const
    {
        return m_Z;
    }

    /**
     * Sets X coordinate.
     *
     * @param x - X coordinate.
     */
    void Point::SetX(float x)
    {
        m_X = x;
    }

    /**
     * Sets Y coordinate.
     *
     * @param y - Y coordinate.
     */
    void Point::SetY(float y)
    {
        m_Y = y;
    }

    /**
     * Sets Z coordinate.
     *
     * @param z - Z coordinate.
     */
    void Point::SetZ(float z)
    {
        m_Z = z;
    }
}
