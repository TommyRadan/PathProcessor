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

#include <output.hpp>

#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

void path_to_file(std::string file_name, geometry::path &path)
{
	std::vector<std::string> lines;

	for (auto &point : path.get_data()) {
		std::string line;
		std::ostringstream stream(line);

		stream << "G1 ";
		stream << "X" << std::fixed << std::setprecision(4) << point.x << " ";
		stream << "Y" << std::fixed << std::setprecision(4) << point.y << " ";
		stream << "Z" << std::fixed << std::setprecision(4) << point.z;

		lines.emplace_back(stream.str());
	}

	std::ofstream file(file_name);

	if (!file.is_open()) {
		std::string message("Can not open file for writing: ");
		throw std::invalid_argument(message + file_name);
	}

	for (auto &line : lines) {
		file << line << std::endl;
	}

	file.close();
}
