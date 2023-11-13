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

static const bool IsInCollision(const geometry::cone &cone, const geometry::point &point)
{
	const geometry::vertical_line coneCenter{cone.GetPosition()};

	// Point is bellow the cone
	if (point.z < cone.GetPosition().z) {
		return false;
	}

	// Point is further from the center then cone radius
	if (coneCenter.GetDistance(point) > cone.GetRadius()) {
		return false;
	}

	const float deltaX{point.x - cone.GetPosition().x};
	const float deltaY{point.y - cone.GetPosition().y};
	const float deltaZ{point.z - cone.GetPosition().z};

	const float deltaXY{sqrtf(powf(deltaX, 2.0f) + powf(deltaY, 2.0f))};
	const float coneToPointAngleRadians{atanf(deltaZ / deltaXY)};
	const float coneToPointAngleDegrees = coneToPointAngleRadians * (180.0f / float(M_PI));

	return (coneToPointAngleDegrees > 90.0f - cone.GetAngle());
}

static const bool IsInCollision(const geometry::cone &cone, const geometry::triangle &triangle)
{
	const bool isCollisionA{IsInCollision(cone, triangle.a)};
	const bool isCollisionB{IsInCollision(cone, triangle.b)};
	const bool isCollisionC{IsInCollision(cone, triangle.b)};

	return (isCollisionA || isCollisionB || isCollisionC);
}

const bool IsInCollision(const geometry::cone &cone, const geometry::mesh &mesh)
{
	bool verdict{false};

	for (auto &triangle : mesh.GetData()) {
		if (IsInCollision(cone, triangle)) {
			verdict = true;
			break;
		}
	}

	return verdict;
}

static bool ProcessThePoint(geometry::point &point, const geometry::mesh &mesh)
{
	float waz = argp_get_working_area_z();
	int sdz = argp_get_subdivision_z();
	float radius = argp_get_spindle_radius();
	float angle = argp_get_spindle_angle();

	float currX = point.x;
	float currY = point.y;

	if (!IsInCollision(geometry::cone{geometry::point{currX, currY, -waz / 2}, angle, radius},
			   mesh)) {
		return false;
	}

	for (int i = 0; i < sdz; ++i) {
		const float currZ = waz / (sdz - 1) * i - waz / 2;
		const geometry::cone spindle{geometry::point{currX, currY, currZ}, angle, radius};

		if (!IsInCollision(spindle, mesh)) {
			point.z = currZ;
			break;
		}
	}

	return true;
}

geometry::path generate_path(const geometry::mesh &mesh)
{
	geometry::path path;

	for (auto &point : path.GetData()) {
		if (!ProcessThePoint(point, mesh)) {
			/*path.GetData().erase(std::find(path.GetData().begin(),
							path.GetData().end(),
							point));*/
		}
	}

	return path;
}
