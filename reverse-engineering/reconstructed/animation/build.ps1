param([switch]$CompileOnly)
$ErrorActionPreference = 'Stop'
$animationDirectory = $PSScriptRoot
$analysisRoot = Split-Path (Split-Path $animationDirectory -Parent) -Parent
$compilerPath = Join-Path $env:WINDIR 'Microsoft.NET\Framework64\v4.0.30319\csc.exe'
$buildDirectory = Join-Path $animationDirectory 'build'
New-Item -ItemType Directory -Path $buildDirectory -Force | Out-Null
& $compilerPath /nologo /target:library /optimize+ /platform:anycpu "/out:$buildDirectory\Recovered.Animation.dll" "$animationDirectory\CharacterContexts.cs" "$animationDirectory\RespawnState.cs" "$animationDirectory\AnimationPlayback.cs" "$animationDirectory\IdleScheduling.cs" "$animationDirectory\AnimationControl.cs"
if ($LASTEXITCODE -ne 0) { throw 'Library compilation failed' }
& $compilerPath /nologo /target:exe /optimize+ /platform:anycpu "/out:$buildDirectory\AnimationDifferentialHarness.exe" "/reference:$buildDirectory\Recovered.Animation.dll" "$animationDirectory\DifferentialHarness.cs"
if ($LASTEXITCODE -ne 0) { throw 'Harness compilation failed' }
if ($CompileOnly) { return }
& "$buildDirectory\AnimationDifferentialHarness.exe" "$analysisRoot\reports\animation-portable-cases.bin" "$analysisRoot\reports\animation-portable-differential.json"
if ($LASTEXITCODE -ne 0) { throw 'Native differential verification failed' }
