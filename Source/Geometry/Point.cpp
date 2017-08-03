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
     * Class constructor.
     *
     * @param x - X component.
     * @param y - Y component.
     * @param z - Z component.
     */
    Point::Point(const float x, const float y, const float z) :
            X{ x },
            Y{ y },
            Z{ z }
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
        const float dx = this->X - p.X;
        const float dy = this->Y - p.Y;
        const float dz = this->Z - p.Z;

        return sqrtf(dx * dx + dy * dy + dz * dz);
    }
}
