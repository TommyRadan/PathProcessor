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

#include <Geometry/Triangle.hpp>

namespace Geometry
{
    /**
     * This constructor constructs Triangle from three Points.
     *
     * @param a - Point A.
     * @param b - Point B.
     * @param c - Point C.
     */
    Triangle::Triangle(const Point& a, const Point& b, const Point& c) :
        m_A { a },
        m_B { b },
        m_C { c }
    {}

    /**
     * Getter for Point A.
     *
     * @return Point A.
     */
    const Point Triangle::GetA() const
    {
        return m_A;
    }

    /**
     * Getter for Point B.
     *
     * @return Point B.
     */
    const Point Triangle::GetB() const
    {
        return m_B;
    }

    /**
     * Getter for Point C.
     *
     * @return Point C.
     */
    const Point Triangle::GetC() const
    {
        return m_C;
    }

    /**
     * Setter for Point A.
     *
     * @return Point A.
     */
    void Triangle::SetA(Point a)
    {
        m_A = a;
    }

    /**
     * Setter for Point B.
     *
     * @return Point B.
     */
    void Triangle::SetB(Point b)
    {
        m_B = b;
    }

    /**
     * Setter for Point C.
     *
     * @return Point C.
     */
    void Triangle::SetC(Point c)
    {
        m_C = c;
    }
}
