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

#include <input.hpp>

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

static uint32_t CountWords(const std::string &string)
{
	uint32_t word_count{0U};
	std::stringstream ss{string};
	std::string word;
	while (ss >> word) {
		++word_count;
	}
	return word_count;
}

static bool IsValidLine(const std::string &line)
{
	std::stringstream stream{line};
	std::string control;

	if (line.empty()) {
		return false;
	}

	stream >> control;

	return (control == "vertex") && (CountWords(line) == 4);
}

static geometry::point ConstructPoint(const std::string &line)
{
	std::istringstream stream(line);
	std::string control;
	float coordinates[3];
	stream >> control >> coordinates[0] >> coordinates[1] >> coordinates[2];

	if (control != "vertex") {
		throw std::invalid_argument("Point construction failed! Input: \"" + line + "\"");
	}

	return {coordinates[0], coordinates[1], coordinates[2]};
}

static geometry::triangle ConstructTriangle(const std::string &line1, const std::string &line2,
					    const std::string &line3)
{
	geometry::triangle result;

	result.a = ConstructPoint(line1);
	result.b = ConstructPoint(line2);
	result.c = ConstructPoint(line3);

	return result;
}

static geometry::mesh StlToMesh(const std::vector<std::string> &stlFile)
{
	geometry::mesh mesh;

	if (stlFile.size() % 3 != 0) {
		std::string message("Wrong number of lines provided! Num of lines: ");
		std::string numOfLines = std::to_string(stlFile.size());
		throw std::invalid_argument(message + numOfLines);
	}

	for (int i = 0; i < stlFile.size();) {
		std::string point[3];

		point[0] = stlFile[i++];
		point[1] = stlFile[i++];
		point[2] = stlFile[i++];

		mesh.AddTriangle(ConstructTriangle(point[0], point[1], point[2]));
	}

	return mesh;
}

geometry::mesh file_to_mesh(std::string file_name)
{
	std::ifstream file(file_name);
	std::vector<std::string> result;

	if (!file.is_open()) {
		std::string message("Could not open a file: ");
		throw std::invalid_argument(message + file_name);
	}

	while (file.good()) {
		std::string line;
		std::getline(file, line);

		if (!IsValidLine(line)) {
			continue;
		}

		result.emplace_back(line);
	}

	file.close();

	return StlToMesh(result);
}
