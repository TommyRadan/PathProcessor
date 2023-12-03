$ErrorActionPreference = "Stop"

$REPO_ROOT = & git rev-parse --show-toplevel
$BUILD_TYPE = "Release"

# Check for command line arguments
foreach ($arg in $args) {
    switch ($arg) {
        '-d' { $BUILD_TYPE = "Debug"; break }
        '--debug' { $BUILD_TYPE = "Debug"; break }
        '-c' { 
            Write-Host "Cleaning build directory..."
            if (Test-Path "$REPO_ROOT/build") {
                Remove-Item "$REPO_ROOT/build" -Force -Recurse
            }
            break
        }
        '--clean' { 
            Write-Host "Cleaning build directory..."
            if (Test-Path "$REPO_ROOT/build") {
                Remove-Item "$REPO_ROOT/build" -Force -Recurse
            }
            break
        }
        default { }
    }
}

Write-Host "Building project in $BUILD_TYPE mode..."

# Create the build directory if it doesn't exist
New-Item "$REPO_ROOT/build" -ItemType Directory -Force | Out-Null

# Run CMake with the specified build type
cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE -B "$REPO_ROOT/build" -S "$REPO_ROOT" -G "Unix Makefiles"

# Compile the project
make -C "$REPO_ROOT/build"

Write-Host "Build completed."
