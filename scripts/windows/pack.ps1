Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

$Artifact = "pysort.zip"
$ArtifactDir = "dist"

Remove-Item -Recurse -Force $Artifact, $ArtifactDir -ErrorAction SilentlyContinue
New-Item -ItemType Directory -Path $ArtifactDir | Out-Null
New-Item -ItemType Directory -Path $ArtifactDir\lib | Out-Null
New-Item -ItemType Directory -Path $ArtifactDir\test | Out-Null

Copy-Item -Path "build\Release\*.pyd" -Destination $ArtifactDir\lib
Copy-Item -Path "lib\pysort.py" -Destination $ArtifactDir\lib
Copy-Item -Path "test\test_pysort.py" -Destination $ArtifactDir\test

New-Item -Force -Path $ArtifactDir\lib\__init__.py -ItemType File
New-Item -Force -Path $ArtifactDir\test\__init__.py -ItemType File

Copy-Item -Force -Path "scripts\deployed\test.ps1" -Destination $ArtifactDir\

Compress-Archive -Path "$ArtifactDir\*" -DestinationPath $Artifact

Write-Host "Artifact created: $Artifact"
