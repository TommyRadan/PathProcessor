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

#include <Geometry/VerticalLine.hpp>

namespace Geometry
{
    /**
     * This constructor constructs VerticalLine from X and Y coordinates.
     *
     * @param x - X coordinate.
     * @param y - Y coordinate.
     */
    VerticalLine::VerticalLine(const float x, const float y) :
        m_X { x },
        m_Y { y }
    {}

    /**
     * This constructor constructs VerticalLine from Point.
     *
     * @param p - The Point.
     */
    VerticalLine::VerticalLine(const Point& p) :
        m_X { p.GetX() },
        m_Y { p.GetY() }
    {}

    /**
     * X coordinate getter.
     *
     * @return X coordinate.
     */
    const float VerticalLine::GetX(void) const
    {
        return m_X;
    }

    /**
     * Y coordinate getter.
     *
     * @return Y coordinate.
     */
    const float VerticalLine::GetY(void) const
    {
        return m_Y;
    }

    /**
     * Gets distance from VerticalLine to Point.
     *
     * @param p - The Point.
     *
     * @return Returns float which represents distance.
     */
    const float VerticalLine::GetDistance(const Point& p) const
    {
        const Geometry::Point referentPoint(this->GetX(), this->GetY(), p.GetZ());
        return referentPoint.Distance(p);
    }
}
