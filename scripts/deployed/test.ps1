Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$env:PYTHONPATH = "$PWD\lib;$PWD\test;$env:PYTHONPATH"

Write-Output "Running Python unit tests..."
python -m unittest test_pysort
