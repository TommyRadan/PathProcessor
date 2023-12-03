$ErrorActionPreference = "Stop"

$REPO_ROOT = & git rev-parse --show-toplevel
$BUILD_DIR = "$REPO_ROOT\build"

Write-Host "Starting cleanup process..."

# Check if the build directory exists
if (Test-Path $BUILD_DIR) {
    Write-Host "Removing build directory..."
    if (Test-Path $BUILD_DIR) {
        Remove-Item $BUILD_DIR -Force -Recurse
    }
    Write-Host "Build directory removed."
} else {
    Write-Host "Build directory does not exist, no need to clean."
}

Write-Host "Cleanup completed."
