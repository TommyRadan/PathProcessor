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

#include <geometry/path.hpp>

#include <argp.hpp>

namespace geometry
{
path::path()
{
	float wax = argp_get_working_area_x();
	float way = argp_get_working_area_y();
	int sdx = argp_get_subdivision_x();
	int sdy = argp_get_subdivision_y();
	bool yGoingPositive = true;

	for (int i = 0; i < sdx; ++i) {
		float currX = wax / (sdx - 1) * i - wax / 2;

		for (int j = 0; j < sdy; ++j) {
			float currY = way / (sdy - 1) * j - way / 2;

			if (!yGoingPositive) {
				currY = -currY;
			}

			m_Points.emplace_back(point{currX, currY, 0.0f});
		}

		// Switch the direction
		yGoingPositive = !yGoingPositive;
	}
}

std::vector<point> &path::GetData()
{
	return m_Points;
}
} // namespace geometry
