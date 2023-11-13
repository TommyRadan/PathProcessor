/*
 * Copyright 2017-2023 Tomislav Radanovic
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
 */

#pragma once

#include <geometry/point.hpp>

namespace geometry
{
/**
 * Class that stores information about Cone.
 */
struct cone {
	/**
	 * Default constructor.
	 */
	explicit cone(const point &position, float angle, float radius);

	/**
	 * Getter for Cone position Point.
	 *
	 * @return Position Point.
	 */
	const point &GetPosition() const;

	/**
	 * Getter for Cone angle.
	 *
	 * @return Cone angle.
	 */
	const float GetAngle() const;

	/**
	 * Getter for Cone radius.
	 *
	 * @return Cone radius.
	 */
	const float GetRadius() const;

      private:
	const point m_Position;
	const float m_Angle;
	const float m_Radius;
};
} // namespace geometry
