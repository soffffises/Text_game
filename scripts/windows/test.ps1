Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$env:PATH = "$env:USERPROFILE\scoop\shims;$env:PATH"
& "venv\Scripts\Activate.ps1"

Write-Host "`nSTAGE ONE: Testing the C++ library..." -ForegroundColor Cyan
Push-Location "build\Release"
ctest --output-on-failure
Pop-Location

Write-Host "`nSTAGE TWO: Testing the Python wrapper library..." -ForegroundColor Cyan
$env:PYTHONPATH = "$PWD\build\Release;$PWD\test;$env:PYTHONPATH"
python -m unittest test_pysort