param([ValidateSet('all','geometry-volumes','navigation','gameplay-createcreatures','geometry-visibility','combat-kill','gameplay-conditions','geometry-rooms','combat','animation','gameplay','gameplay-message','gameplay-state','gameplay-visibility','input','frame','geometry')][string]$Module='all')
$ErrorActionPreference='Stop'
$analysisDirectory=Split-Path $PSScriptRoot -Parent
$verifier=Join-Path $PSScriptRoot 'bin/RecoveredSourceVerify.exe'
if(-not(Test-Path -LiteralPath $verifier)){throw 'Build first using reconstructed/build.ps1.'}
$cases=[ordered]@{
 'navigation'=@('reports/native-connections-vectors.json','reports/native-connections-csharp-validation.json','reports/native-connections-review-tests.json')
 'gameplay-createcreatures'=@('reports/gameplay-createcreatures-native-fixtures.json','reports/gameplay-createcreatures-csharp-validation.json')
 'combat-kill'=@('reports/native-combat-kill-vectors.json','reports/native-combat-kill-csharp-validation.json')
 'gameplay-conditions'=@('reports/gameplay-compact-condition-native-fixtures.json','reports/gameplay-compact-condition-csharp-validation.json')
 'combat'=@('reports/native-combat-primitives-vectors.json','reports/native-combat-health-command-vectors.json','reports/native-combat-command-adapter-vectors.json','reports/native-combat-economy-vectors.json','reports/native-combat-csharp-extended-validation.json')
 'animation'=@('reports/animation-portable-cases.bin','reports/animation-csharp-integrated-validation.json')
 'gameplay'=@('reports/gameplay-portable-fixtures.json','reports/gameplay-csharp-integrated-validation.json')
 'gameplay-message'=@('reports/gameplay-message-native-fixtures.json','reports/gameplay-message-csharp-validation.json')
 'gameplay-state'=@('reports/gameplay-state-command-native-fixtures.json','reports/gameplay-state-command-csharp-validation.json')
 'gameplay-visibility'=@('reports/gameplay-visibility-native-fixtures.json','reports/gameplay-visibility-csharp-validation.json')
 'input'=@('reports/native-controller-state-vectors.json','reports/native-input-vectors.json','reports/native-movement-angle-vectors.json','reports/native-stick-vectors.json','reports/native-input-csharp-validation.json')
 'frame'=@('reports/native-frame-branches.json','reports/native-frame-csharp-validation.json')
}
Push-Location -LiteralPath $analysisDirectory
try {
 foreach($name in $cases.Keys){
  if($Module -ne 'all' -and $Module -ne $name){continue}
  $arguments=@($name)+$cases[$name]
  & $verifier @arguments
  if($LASTEXITCODE -ne 0){throw ('Compiled differential failed: '+$name)}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry'){
  & python tools/geometry-recovered-uv-check.py --harness $verifier --assembly (Join-Path $PSScriptRoot 'bin/Recovered.Runtime.dll') --module geometry
  if($LASTEXITCODE -ne 0){throw 'Compiled geometry differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-rooms'){
  & python tools/geometry-room-selection-check.py --harness $verifier --module geometry-rooms
  if($LASTEXITCODE -ne 0){throw 'Compiled room selection differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-visibility'){
  & python tools/geometry-portal-visibility-check.py --harness $verifier --module geometry-visibility
  if($LASTEXITCODE -ne 0){throw 'Compiled portal visibility differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-volumes'){
  & python tools/geometry-portal-volume-check.py --harness $verifier --module geometry-volumes
  if($LASTEXITCODE -ne 0){throw 'Compiled portal volume differential failed.'}
 }
}finally{Pop-Location}
