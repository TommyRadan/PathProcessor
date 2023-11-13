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

#include "argp.hpp"

#include <iostream>

static std::string _input_file = "input.stl";
static std::string _output_file = "output.gcode";

static float _working_area_x = 2.5f;
static float _working_area_y = 0.5f;
static float _working_area_z = 1.0f;

static int _subdivision_x = 25;
static int _subdivision_y = 5;
static int _subdivision_z = 10;

static float _spindle_radius = 0.01f;
static float _spindle_angle = 30.0f;

static void print_usage()
{
	std::cout << "PathProcessor - Lightweight STL to G-Code converter" << std::endl;
	std::cout << "-i --input - STL file input" << std::endl;
	std::cout << "-o --output - G-code file output" << std::endl;
	std::cout << "-wax  --working-area-x - Tool working area X " << std::endl;
	std::cout << "-way  --working-area-y - Tool working area Y " << std::endl;
	std::cout << "-waz  --working-area-z - Tool working area Z " << std::endl;
	std::cout << "-sdx  --subdivision-x - Tool subdivision X" << std::endl;
	std::cout << "-sdy  --subdivision-y - Tool subdivision Y" << std::endl;
	std::cout << "-sdz  --subdivision-z - Tool subdivision Z" << std::endl;
	std::cout << "-r  --radius - Spindle radius" << std::endl;
	std::cout << "-a  --angle - Spindle angle" << std::endl;
}

static bool parse_argument(const std::string &key, const std::string &value)
{
	if (key == "--input" || key == "-i") {
		_input_file = value;
		return true;
	}

	if (key == "--output" || key == "-o") {
		_output_file = value;
		return true;
	}

	if (key == "--working-area-x" || key == "-wax") {
		_working_area_x = std::stof(value);
		return true;
	}

	if (key == "--working-area-y" || key == "-way") {
		_working_area_y = std::stof(value);
		return true;
	}

	if (key == "--working-area-z" || key == "-waz") {
		_working_area_z = std::stof(value);
		return true;
	}

	if (key == "--subdivision-x" || key == "-sdx") {
		_subdivision_x = std::stoi(value);
		return true;
	}

	if (key == "--subdivision-y" || key == "-sdy") {
		_subdivision_y = std::stoi(value);
		return true;
	}

	if (key == "--subdivision-z" || key == "-sdz") {
		_subdivision_z = std::stoi(value);
		return true;
	}

	if (key == "--radius" || key == "-r") {
		_spindle_radius = std::stof(value);
		return true;
	}

	if (key == "--angle" || key == "-a") {
		_spindle_angle = std::stof(value);
		return true;
	}

	return false;
}

const bool argp_parse(int argc, char **argv)
{
	if (argc == 1 || argc == 2) {
		print_usage();
		return false;
	}

	if ((argc + 1) % 2 != 0) {
		print_usage();
		throw std::runtime_error("Error parsing arguments");
	}

	for (int i = 1; i < argc; i += 2) {
		std::string key = argv[i];
		std::string value = argv[i + 1];

		if (key == "--help" || key == "-h") {
			print_usage();
			return false;
		}

		if (!parse_argument(key, value)) {
			print_usage();
			throw std::runtime_error("Unknown argument " + key);
		}
	}

	return true;
}

const std::string argp_get_input_file()
{
	return _input_file;
}

const std::string argp_get_output_file()
{
	return _output_file;
}

const float argp_get_working_area_x()
{
	return _working_area_x;
}

const float argp_get_working_area_y()
{
	return _working_area_y;
}

const float argp_get_working_area_z()
{
	return _working_area_z;
}

const int argp_get_subdivision_x()
{
	return _subdivision_x;
}

const int argp_get_subdivision_y()
{
	return _subdivision_y;
}

const int argp_get_subdivision_z()
{
	return _subdivision_z;
}

const float argp_get_spindle_radius()
{
	return _spindle_radius;
}

const float argp_get_spindle_angle()
{
	return _spindle_angle;
}
