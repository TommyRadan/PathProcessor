#!/bin/bash

set -e

REPO_ROOT="$(git rev-parse --show-toplevel)"
BUILD_TYPE=Release

# Check for command line arguments
for arg in "$@"
do
    case $arg in
        -d|--debug)
        BUILD_TYPE=Debug
        shift # Remove --debug from processing
        ;;
        -c|--clean)
        echo "Cleaning build directory..."
        rm -rf "$REPO_ROOT/build/"
        shift # Remove --clean from processing
        ;;
        *)
        # Unknown option
        ;;
    esac
done

echo "Building project in $BUILD_TYPE mode..."

# Create the build directory if it doesn't exist
mkdir -p "$REPO_ROOT/build"

# Run CMake with the specified build type
cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE -B "$REPO_ROOT/build" -S "$REPO_ROOT" -G "Unix Makefiles"

# Compile the project
make -C "$REPO_ROOT/build"

echo "Build completed."
