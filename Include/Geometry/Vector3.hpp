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

#pragma once

namespace Geometry
{
    /**
     * This class holds one three-dimensional vector and provides basic
     * operations such as adding, subtracting, multiplication, division,
     * cross and dot.
     */
    struct Vector3
    {
		Vector3(const float x, const float y, const float z);

        Vector3& operator+=(const Vector3& v);
        Vector3& operator-=(const Vector3& v);

        const Vector3 operator+(const Vector3& v) const;
        const Vector3 operator-(const Vector3& v) const;

        friend Vector3 operator*(const Vector3& v, const float n);
        friend Vector3 operator*(const float n, const Vector3& v);

        friend Vector3 operator/(const Vector3& v, const float n);
        friend Vector3 operator/(const float n, const Vector3& v);

        const Vector3 Cross(const Vector3& v) const;

        const float Dot(const Vector3& v) const;
        const float Angle(const Vector3& v) const;

        const float Length(void) const;
        const float Distance(const Vector3& v) const;

        const Vector3 Normal(void) const;

        // Data
        float X, Y, Z;
    };
}
