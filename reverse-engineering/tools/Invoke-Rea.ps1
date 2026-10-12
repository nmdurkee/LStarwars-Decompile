$ErrorActionPreference = 'Stop'
$analysisRoot = Split-Path -Parent $PSScriptRoot
$env:GHIDRA_INSTALL_DIR = Join-Path $PSScriptRoot 'ghidra\ghidra_12.1.4_PUBLIC'
$env:JAVA_HOME = Join-Path $PSScriptRoot 'jdk\jdk-21.0.12.1+1'
$env:REA_ANALYSIS_PROVIDER = 'ghidra'
$nodePath = (Get-Command node.exe -ErrorAction Stop).Source
& $nodePath (Join-Path $PSScriptRoot 'rea\node_modules\rea-agents\scripts\rea.mjs') @args
exit $LASTEXITCODE
