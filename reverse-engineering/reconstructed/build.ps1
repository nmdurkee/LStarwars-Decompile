param([switch]$LibraryOnly)
$ErrorActionPreference = 'Stop'
$reconstructionDirectory = $PSScriptRoot
$analysisDirectory = Split-Path $reconstructionDirectory -Parent
$compiler = Join-Path $env:WINDIR 'Microsoft.NET\Framework64\v4.0.30319\csc.exe'
if (-not (Test-Path -LiteralPath $compiler)) { throw 'Install/use a compatible C# compiler; this build script uses the existing .NET Framework compiler.' }
$manifest = Get-Content -Raw -LiteralPath (Join-Path $reconstructionDirectory 'source-manifest.json') | ConvertFrom-Json
$buildDirectory = Join-Path $reconstructionDirectory 'bin'
New-Item -ItemType Directory -Path $buildDirectory -Force | Out-Null
$sourcePaths = @($manifest.modules | ForEach-Object { $_.files } | ForEach-Object { [IO.Path]::GetFullPath((Join-Path $reconstructionDirectory $_)) })
$compilerArgs = @('/nologo', '/target:library', '/optimize+', '/platform:anycpu', ('/out:' + (Join-Path $buildDirectory 'Recovered.Runtime.dll'))) + $sourcePaths
& $compiler @compilerArgs
if ($LASTEXITCODE -ne 0) { throw 'Recovered library compilation failed.' }
$harnessBuilt = $false
if (-not $LibraryOnly) {
    $harnessPaths = @($manifest.harnessFiles | ForEach-Object { [IO.Path]::GetFullPath((Join-Path $reconstructionDirectory $_)) })
    $compilerArgs = @('/nologo', '/target:exe', '/optimize+', '/platform:anycpu', '/r:System.Web.Extensions.dll', '/main:RecoveredSourceVerify', ('/out:' + (Join-Path $buildDirectory 'RecoveredSourceVerify.exe'))) + $sourcePaths + $harnessPaths
    & $compiler @compilerArgs
    if ($LASTEXITCODE -ne 0) { throw 'Combined verifier compilation failed.' }
    $harnessBuilt = $true
}
$sourceEvidence = @($sourcePaths | ForEach-Object { [ordered]@{path=$_;sha256=(Get-FileHash -Algorithm SHA256 -LiteralPath $_).Hash.ToLowerInvariant()} })
$report = [ordered]@{updated=[DateTime]::UtcNow.ToString('o');compiler=$compiler;libraryCompiled=$true;unifiedVerifierCompiled=$harnessBuilt;librarySha256=(Get-FileHash -Algorithm SHA256 -LiteralPath (Join-Path $buildDirectory 'Recovered.Runtime.dll')).Hash.ToLowerInvariant();sources=$sourceEvidence;execution='Build only. Compilation is not an execution or differential verification pass.'}
$report | ConvertTo-Json -Depth 8 | Set-Content -Encoding UTF8 -LiteralPath (Join-Path $analysisDirectory 'reports/reconstructed-build.json')
Write-Output ('Compiled recovered library from ' + $sourcePaths.Count + ' source files. Verifier compiled: ' + $harnessBuilt)
