#!/bin/bash

set -e

REPO_ROOT="$(git rev-parse --show-toplevel)"
BUILD_DIR="$REPO_ROOT/build"

echo "Starting cleanup process..."

# Check if the build directory exists
if [ -d "$BUILD_DIR" ]; then
    echo "Removing build directory..."
    rm -rf "$BUILD_DIR"
    echo "Build directory removed."
else
    echo "Build directory does not exist, no need to clean."
fi

echo "Cleanup completed."
