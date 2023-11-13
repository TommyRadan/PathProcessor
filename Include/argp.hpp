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

#include <string>

/**
 * @brief Parses command line arguments and saves their values internally.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return true if parsing is successful and the program can continue.
 * @return false if help was displayed or an error occurred, suggesting the program should exit.
 */
const bool argp_parse(int argc, char **argv);

/**
 * @brief Retrieves the input file path specified in the command line arguments.
 *
 * @return A string representing the input file path.
 */
const std::string argp_get_input_file();

/**
 * @brief Retrieves the output file path specified in the command line arguments.
 *
 * @return A string representing the output file path.
 */
const std::string argp_get_output_file();

/**
 * @brief Retrieves the X dimension of the working area as specified in the command line arguments.
 *
 * @return The X dimension of the working area.
 */
const float argp_get_working_area_x();

/**
 * @brief Retrieves the Y dimension of the working area as specified in the command line arguments.
 *
 * @return The Y dimension of the working area.
 */
const float argp_get_working_area_y();

/**
 * @brief Retrieves the Z dimension of the working area as specified in the command line arguments.
 *
 * @return The Z dimension of the working area.
 */
const float argp_get_working_area_z();

/**
 * @brief Retrieves the subdivision in the X direction as specified in the command line arguments.
 *
 * @return The subdivision count in the X direction.
 */
const int argp_get_subdivision_x();

/**
 * @brief Retrieves the subdivision in the Y direction as specified in the command line arguments.
 *
 * @return The subdivision count in the Y direction.
 */
const int argp_get_subdivision_y();

/**
 * @brief Retrieves the subdivision in the Z direction as specified in the command line arguments.
 *
 * @return The subdivision count in the Z direction.
 */
const int argp_get_subdivision_z();

/**
 * @brief Retrieves the spindle radius as specified in the command line arguments.
 *
 * @return The spindle radius.
 */
const float argp_get_spindle_radius();

/**
 * @brief Retrieves the spindle angle as specified in the command line arguments.
 *
 * @return The spindle angle.
 */
const float argp_get_spindle_angle();
