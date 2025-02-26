Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$VerbosePreference = "Continue"

if (-Not (Get-Command scoop -ErrorAction SilentlyContinue)) {
    Invoke-Expression "&([scriptblock]::Create((iwr -useb get.scoop.sh)))"
}

scoop update
scoop install cmake python ninja gcc

python -m venv venv
& "venv\Scripts\Activate.ps1"
python -m pip install --upgrade pip
pip install conan

$ConanProfileDir = "$env:USERPROFILE\.conan2\profiles"
if (-Not (Test-Path $ConanProfileDir)) {
    New-Item -ItemType Directory -Path $ConanProfileDir -Force
}

$ConanProfilePath = Join-Path $ConanProfileDir "default"
if (-Not (Test-Path $ConanProfilePath)) {
    Set-Content -Path $ConanProfilePath -Value @"
[settings]
os=Windows
arch=x86_64
build_type=Release
compiler=gcc
compiler.version=13
compiler.libcxx=libstdc++11
compiler.cppstd=20

[conf]
tools.cmake.cmaketoolchain:generator=Ninja
"@
}
