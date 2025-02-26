Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

Write-Host "`nBuilding the Docker image with BuildKit enabled..." -ForegroundColor Cyan
$env:DOCKER_BUILDKIT = "1"
docker build -t fedora-ci .

Write-Host "`nRunning the Docker container..." -ForegroundColor Cyan
docker run --rm fedora-ci
