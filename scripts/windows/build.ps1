Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$env:PATH = "$env:USERPROFILE\scoop\apps\gcc\current\bin;$env:USERPROFILE\scoop\shims;$env:PATH"
& "venv\Scripts\Activate.ps1"
conan install . --build=missing
conan build .
