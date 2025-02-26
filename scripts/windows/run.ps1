$env:PATH = "$env:USERPROFILE\scoop\shims;$env:PATH"
& "venv\Scripts\Activate.ps1"

$EXEC = "hillel-game"

Push-Location "build\Release"
.\$EXEC
Pop-Location