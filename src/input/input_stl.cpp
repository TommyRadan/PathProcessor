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
#include <cstdint>
#include <array>

static uint32_t get_word_count(const std::string &string)
{
	uint32_t word_count{0U};
	std::stringstream ss{string};
	std::string word;
	while (ss >> word) {
		++word_count;
	}
	return word_count;
}

static bool is_line_valid(const std::string &line)
{
	std::stringstream stream{line};
	std::string control;

	if (line.empty()) {
		return false;
	}

	stream >> control;

	return (control == "vertex") && (get_word_count(line) == 4);
}

static std::vector<std::string> split_file(std::string file_name)
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

		if (!is_line_valid(line)) {
			continue;
		}

		result.emplace_back(line);
	}

	file.close();
	return result;
}

static geometry::point create_point(const std::string &line)
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

static geometry::triangle create_triangle(std::array<std::string, 3> lines)
{
	geometry::triangle result;

	result.a = create_point(lines[0]);
	result.b = create_point(lines[1]);
	result.c = create_point(lines[2]);

	return result;
}

geometry::mesh file_to_mesh(std::string file_name)
{
	std::vector<std::string> stl_file = split_file(file_name);
	geometry::mesh mesh;

	if (stl_file.size() % 3 != 0) {
		std::string message("Wrong number of lines provided! Num of lines: ");
		std::string numOfLines = std::to_string(stl_file.size());
		throw std::invalid_argument(message + numOfLines);
	}

	for (int i = 0; i < stl_file.size() - 2; i += 3) {
		std::array<std::string, 3> lines;

		lines[0] = stl_file[i];
		lines[1] = stl_file[i + 1];
		lines[2] = stl_file[i + 2];

		geometry::triangle triangle = create_triangle(lines);
		mesh.add_triangle(triangle);
	}

	return mesh;
}
