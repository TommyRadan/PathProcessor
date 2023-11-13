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
 * Class which holds VerticalLine information.
 */
struct vertical_line {
	/**
	 * This constructor constructs VerticalLine from X and Y coordinates.
	 *
	 * @param x - X coordinate.
	 * @param y - Y coordinate.
	 */
	vertical_line(const float x, const float y);

	/**
	 * This constructor constructs VerticalLine from Point.
	 *
	 * @param p - The Point.
	 */
	explicit vertical_line(const point &p);

	/**
	 * X coordinate getter.
	 *
	 * @return X coordinate.
	 */
	const float GetX() const;

	/**
	 * Y coordinate getter.
	 *
	 * @return Y coordinate.
	 */
	const float GetY() const;

	/**
	 * Gets distance from VerticalLine to Point.
	 *
	 * @param p - The Point.
	 *
	 * @return Returns float which represents distance.
	 */
	const float GetDistance(const point &p) const;

      private:
	float m_X;
	float m_Y;
};
} // namespace geometry
