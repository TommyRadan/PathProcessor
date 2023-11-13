# PathProcessor

PathProcessor is a lightweight, command-line utility for converting STL files to G-code, tailored for CNC milling machines. It simplifies the process of preparing 3D models for CNC machining by automating the conversion of STL geometry to machine-readable G-code.

## Features

- Convert STL files to G-code.
- Customize tool working area and subdivisions.
- Set spindle radius and angle parameters.

## Getting Started

### Prerequisites

- CMake
- Make
- C++ compiler (e.g., GCC, Clang, ...)
- clang-format (for style formatting)
- doxygen (for generating documentation)

### Building the Project

To build the project, use the provided scripts in the `scripts` directory:

```bash
# To build the project
./scripts/build.sh

# To clean the build
./scripts/clean.sh
```

These scripts handle the configuration and compilation of the project using CMake and Make.

## Usage

To use PathProcessor, run the executable with the following command-line arguments:

```bash
pp [options]
```

Options:

```
-i --input: Specify the STL file input.
-o --output: Specify the G-code file output.
-wax --working-area-x: Set the tool working area X dimension.
-way --working-area-y: Set the tool working area Y dimension.
-waz --working-area-z: Set the tool working area Z dimension.
-sdx --subdivision-x: Set the tool subdivision X.
-sdy --subdivision-y: Set the tool subdivision Y.
-sdz --subdivision-z: Set the tool subdivision Z.
-r --radius: Specify the spindle radius.
-a --angle: Specify the spindle angle.
```

Example:

```
bash
./pp -i model.stl -o output.gcode -wax 200 -way 200 -waz 100 -sdx 10 -sdy 10 -sdz 5 -r 2 -a 30
```

## License

This project is licensed under the MIT License.
