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

#include <Geometry/Vector3.hpp>
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
    Vector3::Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f) :
            X{ x },
            Y{ y },
            Z{ z }
    {}

    /**
     * The addition assignment operator.
     *
     * @param v - Vector3 to be added.
     *
     * @return Returns itself(Vector3) for operator chaining.
     */
    Vector3& Vector3::operator+=(const Vector3& v)
    {
        this->X += v.X;
        this->Y += v.Y;
        this->Z += v.Z;
        return *this;
    }

    /**
     * The subtraction assignment operator.
     *
     * @param v - Vector3 to be subtracted.
     *
     * @return Returns itself(Vector3) for operator chaining.
     */
    Vector3& Vector3::operator-=(const Vector3& v)
    {
        this->X -= v.X;
        this->Y -= v.Y;
        this->Z -= v.Z;
        return *this;
    }

    /**
     * The addition operator.
     *
     * @param v - Vector3 to be added.
     *
     * @return Returns resulting Vector3.
     */
    const Vector3 Vector3::operator+(const Vector3& v) const
    {
        return Vector3(this->X + v.X, this->Y + v.Y, this->Z + v.Z);
    }

    /**
     * The subtraction operator.
     *
     * @param v - Vector3 to be subtracted.
     *
     * @return Returns resulting Vector3.
     */
    const Vector3 Vector3::operator-(const Vector3& v) const
    {
        return Vector3(this->X - v.X, this->Y - v.Y, this->Z - v.Z);
    }

    /**
     * The multiplication operator friend function.
     *
     * @param v - Vector3 to be multiplied.
     * @param n - Multiplication factor.
     *
     * @return Returns resulting Vector3.
     */
    Vector3 operator*(const Vector3& v, const float n)
    {
        return Vector3(v.X * n, v.Y * n, v.Z * n);
    }

    /**
     * The multiplication operator friend function.
     *
     * @param n - Multiplication factor.
     * @param v - Vector3 to be multiplied.
     *
     * @return Returns resulting Vector3.
     */
    Vector3 operator*(const float n, const Vector3& v)
    {
        return Vector3(v.X * n, v.Y * n, v.Z * n);
    }

    /**
     * The division operator friend function.
     *
     * @param v - Vector3 to be divided.
     * @param n - Division factor.
     *
     * @return Returns resulting Vector3.
     */
    Vector3 operator/(const Vector3& v, const float n)
    {
        return Vector3(v.X / n, v.Y / n, v.Z / n);
    }

    /**
     * The division operator friend function.
     *
     * @param n - Division factor.
     * @param v - Vector3 to be divided.
     *
     * @return Returns resulting Vector3.
     */
    Vector3 operator/(const float n, const Vector3& v)
    {
        return Vector3(v.X / n, v.Y / n, v.Z / n);
    }

    /**
     * The cross operation method.
     *
     * @param v - Vector with which to do cross operation.
     *
     * @return Returns resulting Vector3.
     */
    const Vector3 Vector3::Cross(const Vector3& v) const
    {
        const float x = this->Y * v.Z - this->Z * v.Y;
        const float y = this->Z * v.X - this->X * v.Z;
        const float z = this->X * v.Y - this->Y * v.X;

        return Vector3(x, y, z);
    }

    /**
     * The dot operation method.
     *
     * @param v - Vector with which to do dot operation.
     *
     * @return Returns resulting float.
     */
    const float Vector3::Dot(const Vector3& v) const
    {
        return this->X * v.X + this->Y * v.Y + this->Z * v.Z;
    }

    /**
     * Returns angle between two vectors.
     *
     * @param v - The other vector.
     *
     * @return Angle between Vector3's in radians.
     */
    const float Vector3::Angle(const Vector3& v) const
    {
        return acos(Dot(v) / Length() / v.Length());
    }

    /**
     * Gets length of the vector.
     *
     * @return Length of the Vector3.
     */
    const float Vector3::Length(void) const
    {
        float x = this->X;
        float y = this->Y;
        float z = this->Z;

        return sqrt(x*x + y*y + z*z);
    }

    /**
     * Gets distance between two vectors.
     *
     * @param v - The other vector.
     *
     * @return Distance between Vector3's.
     */
    const float Vector3::Distance(const Vector3& v) const
    {
        return (*this - v).Length();
    }

    /**
     * Returns normalized vector.
     *
     * @return Normalized Vector3.
     */
    const Vector3 Vector3::Normal(void) const
    {
        return *this / Length();
    }
}
