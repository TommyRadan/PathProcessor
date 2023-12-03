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

#include <generator.hpp>

#include <math.h>

#include <argp.hpp>

#include <geometry/cone.hpp>
#include <geometry/vertical_line.hpp>

static const bool is_in_collision(const geometry::cone &cone, const geometry::point &point)
{
	const geometry::vertical_line cone_center{cone.get_position()};

	// Point is bellow the cone
	if (point.z < cone.get_position().z) {
		return false;
	}

	// Point is further from the center then cone radius
	if (cone_center.get_distance(point) > cone.get_radius()) {
		return false;
	}

	const float delta_x{point.x - cone.get_position().x};
	const float delta_y{point.y - cone.get_position().y};
	const float delta_z{point.z - cone.get_position().z};

	const float delta_xy{sqrtf(powf(delta_x, 2.0f) + powf(delta_y, 2.0f))};
	const float cone_to_point_angle_radians{atanf(delta_z / delta_xy)};
	const float cone_to_point_angle_degrees =
		cone_to_point_angle_radians * (180.0f / float(M_PI));

	return (cone_to_point_angle_degrees > 90.0f - cone.get_angle());
}

static const bool is_in_collision(const geometry::cone &cone, const geometry::triangle &triangle)
{
	const bool is_collision_a{is_in_collision(cone, triangle.a)};
	const bool is_collision_b{is_in_collision(cone, triangle.b)};
	const bool is_collision_c{is_in_collision(cone, triangle.b)};

	return (is_collision_a || is_collision_b || is_collision_c);
}

const bool is_in_collision(const geometry::cone &cone, const geometry::mesh &mesh)
{
	bool verdict{false};

	for (auto &triangle : mesh.get_data()) {
		if (is_in_collision(cone, triangle)) {
			verdict = true;
			break;
		}
	}

	return verdict;
}

static bool point_process(geometry::point &point, const geometry::mesh &mesh)
{
	float waz = argp_get_working_area_z();
	int sdz = argp_get_subdivision_z();
	float radius = argp_get_spindle_radius();
	float angle = argp_get_spindle_angle();

	float currX = point.x;
	float currY = point.y;

	geometry::cone cone{geometry::point{currX, currY, -waz / 2}, angle, radius};

	if (!is_in_collision(cone, mesh)) {
		return false;
	}

	for (int i = 0; i < sdz; ++i) {
		const float currZ = waz / (sdz - 1) * i - waz / 2;
		const geometry::cone spindle{geometry::point{currX, currY, currZ}, angle, radius};

		if (!is_in_collision(spindle, mesh)) {
			point.z = currZ;
			break;
		}
	}

	return true;
}

geometry::path generate_path(const geometry::mesh &mesh)
{
	geometry::path path;

	for (auto &point : path.get_data()) {
		if (!point_process(point, mesh)) {
			/*path.GetData().erase(std::find(path.GetData().begin(),
							path.GetData().end(),
							point));*/
		}
	}

	return path;
}
