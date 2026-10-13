param([ValidateSet('all','movement-phase28-20261013','script-phase19-20261013','world-phase17-20261013','world-phase16-consumer-20261013','world-phase16-20261013','movement-phase27-20261013','script-phase18-20261013','scene-phase13-20261013-backend-init','scene-phase12-20261013-target-pipeline','scene-phase11-20261013-refresh','world-phase15-composed-20261013','world-phase15-20261013','movement-phase26-20261013','movement-phase25-20261013','movement-phase24-20261013','script-phase17-20261013','scene-phase11-20261013-viewport','scene-phase11-20261013-context','world-phase14-composed-20261013','world-phase14-20261013','movement-phase23-20261013','movement-phase22-20261013','script-phase16-20261013','script-phase15-20261013','scene-phase10-20261013-bindings','scene-phase9-20261013-renderer-composition','world-phase13-composed-20261013','world-phase13-20261013','world-phase12-20261013','movement-phase21-20261013','movement-phase20-20261013','movement-phase19-20261013','script-phase14-20261013','scene-phase8-20261013-light','scene-phase7-20261013-light','scene-phase6-20261013-renderer','movement-phase18-20261013','movement-phase17-20261013','movement-phase16-20261013','movement-phase15-20261013','movement-phase14-20261013','script-phase13-20261013','world-phase11-20261013','scene-phase5-20261013-composition','movement-phase13-20261013','movement-phase12-20261013','scene-phase5-20261013-alternate','world-phase10-20261013','world-phase9-20261013','movement-phase11-20261013','script-phase12-20261013','script-phase11-20261013','scene-phase5-20261013-reuse','scene-phase5-20261013-viewport','movement-phase10-20261013','script-phase10-20261013','world-phase8-20261013','world-phase7-20261013','scene-phase5-20261013','movement-phase9-20261013','movement-phase8-20261013','script-phase9-20261013','script-phase8-20261013','world-phase6-20261013','script-phase7-20261013','world-phase5-20261013','movement-phase7-20261013','movement-phase6-20261013','script-phase6-20261013','movement-phase5-20261013','scene-phase4-20261013','movement-phase4-20261013','world-phase4-20261013','scene-phase3-20261013','world-phase3-20261013','script-phase5-20261013','script-phase4-20261013','script-phase3-20261013','movement-phase3-20261013','scene-next-20261013','world-next-20261013','script-next-20261013','actor-next-20261013','grid-visibility-20261013','world-loading-20261013','script-contract-20261013','frame-paused','animation-shadow-geometry-pipeline','sound-mask','geometry-shadow-pass-state','geometry-shadow-setup','animation-shadow-cylinder','gameplay-path-relocation','sound-initialization-pipeline','geometry-shadow-power','sound-text-configuration','gameplay-path-steering-composition','animation-shadow-ellipse','text-numbers','animation-shadow-polygon-pipeline','geometry-shadow-selection','gameplay-path-steering','animation-shadow-polygons','text-lines','text-dispatch','animation-shadow-consumer','geometry-shadow-players','text-tokens','geometry-shadow-visibility-chain','sound-configuration','gameplay-path-dispatch','geometry-shadow-light','animation-character-queue-packets','build-playback','gameplay-path-corners','geometry-shadow-camera','geometry-shadow-extraction','geometry-shadow-volume','animation-character-effects-packets','animation-character-mixed-packets','geometry-shadow-frustum','gameplay-path-corner-math','gameplay-path-transition','sound-playback','animation-character-billboard-packets','geometry-shadow-lifecycle','gameplay-path-alias','sound-groups','geometry-shadow-construction','animation-character-shadow-packets','geometry-shadow-registry','gameplay-path-refresh','gameplay-path-angle','sound-definition','geometry-dynamic-shadow','sound-record','animation-character-bounds','sound-initialization','gameplay-path-corridor','geometry-shadow-context','sound-hash','animation-character-secondary','geometry-dynamic-sway','gameplay-path-arcsine','graph-build-failure','animation-secondary-visibility','geometry-sway','gameplay-path-targeting','gameplay-path-nextpoint','animation-character-packets','build-sound','geometry-dynamic-billboard','gameplay-graph-lifecycle','build-failure','geometry-dynamic-fade','animation-full-dispatch','gameplay-named-lifecycle','gameplay-named-reinitialization','geometry-dynamic-skin','animation-billboard','animation-x87-double','graph-actor','gameplay-path-routing','animation-skin-dispatch','geometry-dynamic-material','level-mode','animation-character-pipeline','geometry-material-lifecycle','category','gameplay-path-binding','animation-shadow-queue','geometry-material-refresh','gizmo-activation','geometry-material-pool','animation-character-visibility','actor-force','gameplay-reinitialization','geometry-material-clone','animation-layer-submission','force-action','gameplay-activation','geometry-dynamic-submission','force-conditions','animation-morph-packets','geometry-dynamic-selection','terrain-object-conditions','animation-override-expression','gameplay-expression-loading','geometry-dynamic-bounds','animation-morph-mesh','gizmo-conditions','gameplay-retreat-token','gameplay-retreat-expression','actor-status','gameplay-expression','geometry-ordinary-packets','party-control','animation-morph','spatial-conditions','geometry-dynamic-command','effect-activation','gameplay-opponent-retreat','animation-script-override','geometry-finish-pipeline','run-speed','locator-random-conditions','gameplay-attack-opponent','animation-points','geometry-dynamic-queue','gameplay-engage-opponent','locator-selection','locator-set-command','distance-rounding','animation-packet-pose','geometry-dynamic-packets','locator-culling','locator-traversal','gameplay-opponent-targeting','animation-skeletal-blend','geometry-shader-emission','geometry-sorted-shader','locator-reservations','animation-skeletal','gameplay-transfer-script-bridge','geometry-sorted-packets','gameplay-player-transfer','camera-effects','geometry-frame-reset','scene-animation-bounds','camera-command','gameplay-tag-control','gameplay-actor-identity','geometry-static-finish','camera-state','gameplay-actor-state','scene-animation-pose','geometry-scheduling','gameplay-facing','scene-animation-update','gameplay-perception','geometry-entry','gameplay-obstacle-binding','geometry-room-outputs','scenery-names','gameplay-locator','gameplay-movement','gameplay-trigger','gameplay-obstacle','geometry-traversal','geometry-volumes','navigation','gameplay-createcreatures','gameplay-createsplinecreatures','geometry-visibility','combat-kill','gameplay-conditions','geometry-rooms','combat','animation','gameplay','gameplay-message','gameplay-state','gameplay-visibility','input','frame','geometry')][string]$Module='all')
$ErrorActionPreference='Stop'
$analysisDirectory=Split-Path $PSScriptRoot -Parent
$verifier=Join-Path $PSScriptRoot 'bin/RecoveredSourceVerify.exe'
if(-not(Test-Path -LiteralPath $verifier)){throw 'Build first using reconstructed/build.ps1.'}
$cases=[ordered]@{
 'movement-phase28-20261013'=@('reports/movement-phase28-20261013-fixtures.json.gz','reports/movement-phase28-20261013-managed-check.json')
 'script-phase19-20261013'=@('reports/script-phase19-20261013-native-fixtures.json','reports/script-phase19-20261013-managed-check.json')
 'world-phase17-20261013'=@('reports/world-phase17-20261013-vectors.json','reports/world-phase17-20261013-managed-tests.json')
 'world-phase16-consumer-20261013'=@('reports/world-phase16-20261013-consumer-vectors.json','reports/world-phase16-20261013-consumer-managed-tests.json')
 'world-phase16-20261013'=@('reports/world-phase16-20261013-vectors.json','reports/world-phase16-20261013-managed-tests.json')
 'movement-phase27-20261013'=@('reports/movement-phase27-20261013-fixtures.json.gz','reports/movement-phase27-20261013-managed-check.json')
 'script-phase18-20261013'=@('reports/script-phase18-20261013-native-fixtures.json','reports/script-phase18-20261013-managed-check.json')
 'scene-phase13-20261013-backend-init'=@('reports/scene-phase13-20261013-backend-init-native-fixtures.json.gz','reports/scene-phase13-20261013-backend-init-csharp-validation.json')
 'scene-phase12-20261013-target-pipeline'=@('reports/scene-phase12-20261013-target-pipeline-native-fixtures.json.gz','reports/scene-phase12-20261013-target-pipeline-csharp-validation.json')
 'scene-phase11-20261013-refresh'=@('reports/scene-phase11-20261013-refresh-native-fixtures.json.gz','reports/scene-phase11-20261013-refresh-csharp-validation.json')
 'world-phase15-composed-20261013'=@('reports/world-phase15-20261013-composed-vectors.json','reports/world-phase15-20261013-composed-managed-tests.json')
 'world-phase15-20261013'=@('reports/world-phase15-20261013-vectors.json','reports/world-phase15-20261013-managed-tests.json')
 'movement-phase26-20261013'=@('reports/movement-phase26-20261013-fixtures.json.gz','reports/movement-phase26-20261013-managed-check.json')
 'movement-phase25-20261013'=@('reports/movement-phase25-20261013-fixtures.json.gz','reports/movement-phase25-20261013-managed-check.json')
 'movement-phase24-20261013'=@('reports/movement-phase24-20261013-fixtures.json.gz','reports/movement-phase24-20261013-managed-check.json')
 'script-phase17-20261013'=@('reports/script-phase17-20261013-native-fixtures.json','reports/script-phase17-20261013-managed-check.json')
 'scene-phase11-20261013-viewport'=@('reports/scene-phase11-20261013-viewport-native-fixtures.json.gz','reports/scene-phase11-20261013-viewport-csharp-validation.json')
 'scene-phase11-20261013-context'=@('reports/scene-phase11-20261013-context-native-fixtures.json.gz','reports/scene-phase11-20261013-context-csharp-validation.json')
 'world-phase14-composed-20261013'=@('reports/world-phase14-20261013-composed-vectors.json','reports/world-phase14-20261013-composed-managed-tests.json')
 'world-phase14-20261013'=@('reports/world-phase14-20261013-vectors.json','reports/world-phase14-20261013-managed-tests.json')
 'movement-phase23-20261013'=@('reports/movement-phase23-20261013-fixtures.json.gz','reports/movement-phase23-20261013-managed-check.json')
 'movement-phase22-20261013'=@('reports/movement-phase22-20261013-fixtures.json.gz','reports/movement-phase22-20261013-managed-check.json')
 'script-phase16-20261013'=@('reports/script-phase16-20261013-native-fixtures.json','reports/script-phase16-20261013-managed-check.json')
 'script-phase15-20261013'=@('reports/script-phase15-20261013-native-fixtures.json','reports/script-phase15-20261013-managed-check.json')
 'scene-phase10-20261013-bindings'=@('reports/scene-phase10-20261013-bindings-native-fixtures.json.gz','reports/scene-phase10-20261013-bindings-csharp-validation.json')
 'scene-phase9-20261013-renderer-composition'=@('reports/scene-phase9-20261013-renderer-composition-native-fixtures.json.gz','reports/scene-phase9-20261013-renderer-composition-csharp-validation.json')
 'world-phase13-composed-20261013'=@('reports/world-phase13-20261013-composed-vectors.json','reports/world-phase13-20261013-composed-managed-tests.json')
 'world-phase13-20261013'=@('reports/world-phase13-20261013-vectors.json','reports/world-phase13-20261013-managed-tests.json')
 'world-phase12-20261013'=@('reports/world-phase12-20261013-vectors.json','reports/world-phase12-20261013-managed-tests.json')
 'movement-phase21-20261013'=@('reports/movement-phase21-20261013-fixtures.json.gz','reports/movement-phase21-20261013-managed-check.json')
 'movement-phase20-20261013'=@('reports/movement-phase20-20261013-fixtures.json.gz','reports/movement-phase20-20261013-managed-check.json')
 'movement-phase19-20261013'=@('reports/movement-phase19-20261013-fixtures.json.gz','reports/movement-phase19-20261013-managed-check.json')
 'script-phase14-20261013'=@('reports/script-phase14-20261013-native-fixtures.json','reports/script-phase14-20261013-managed-check.json')
 'scene-phase8-20261013-light'=@('reports/scene-phase8-20261013-light-native-fixtures.json.gz','reports/scene-phase8-20261013-light-csharp-validation.json')
 'scene-phase7-20261013-light'=@('reports/scene-phase7-20261013-light-native-fixtures.json.gz','reports/scene-phase7-20261013-light-csharp-validation.json')
 'scene-phase6-20261013-renderer'=@('reports/scene-phase6-20261013-renderer-native-fixtures.json.gz','reports/scene-phase6-20261013-renderer-csharp-validation.json')
 'movement-phase18-20261013'=@('reports/movement-phase18-20261013-fixtures.json.gz','reports/movement-phase18-20261013-managed-check.json')
 'movement-phase17-20261013'=@('reports/movement-phase17-20261013-fixtures.json.gz','reports/movement-phase17-20261013-managed-check.json')
 'movement-phase16-20261013'=@('reports/movement-phase16-20261013-fixtures.json.gz','reports/movement-phase16-20261013-managed-check.json')
 'movement-phase15-20261013'=@('reports/movement-phase15-20261013-fixtures.json.gz','reports/movement-phase15-20261013-managed-check.json')
 'movement-phase14-20261013'=@('reports/movement-phase14-20261013-fixtures.json.gz','reports/movement-phase14-20261013-managed-check.json')
 'script-phase13-20261013'=@('reports/script-phase13-20261013-native-fixtures.json','reports/script-phase13-20261013-managed-check.json')
 'world-phase11-20261013'=@('reports/world-phase11-20261013-vectors.json','reports/world-phase11-20261013-managed-tests.json')
 'scene-phase5-20261013-composition'=@('reports/scene-phase5-20261013-composition-native-fixtures.json.gz','reports/scene-phase5-20261013-composition-csharp-validation.json')
 'movement-phase13-20261013'=@('reports/movement-phase13-20261013-fixtures.json.gz','reports/movement-phase13-20261013-managed-check.json')
 'movement-phase12-20261013'=@('reports/movement-phase12-20261013-fixtures.json.gz','reports/movement-phase12-20261013-managed-check.json')
 'scene-phase5-20261013-alternate'=@('reports/scene-phase5-20261013-alternate-native-fixtures.json.gz','reports/scene-phase5-20261013-alternate-csharp-validation.json')
 'world-phase10-20261013'=@('reports/world-phase10-20261013-vectors.json','reports/world-phase10-20261013-managed-tests.json')
 'world-phase9-20261013'=@('reports/world-phase9-20261013-vectors.json','reports/world-phase9-20261013-managed-tests.json')
 'movement-phase11-20261013'=@('reports/movement-phase11-20261013-fixtures.json.gz','reports/movement-phase11-20261013-managed-check.json')
 'script-phase12-20261013'=@('reports/script-phase12-20261013-native-fixtures.json','reports/script-phase12-20261013-managed-check.json')
 'script-phase11-20261013'=@('reports/script-phase11-20261013-native-fixtures.json','reports/script-phase11-20261013-managed-check.json')
 'scene-phase5-20261013-reuse'=@('reports/scene-phase5-20261013-reuse-native-fixtures.json.gz','reports/scene-phase5-20261013-reuse-csharp-validation.json')
 'scene-phase5-20261013-viewport'=@('reports/scene-phase5-20261013-viewport-native-fixtures.json.gz','reports/scene-phase5-20261013-viewport-csharp-validation.json')
 'movement-phase10-20261013'=@('reports/movement-phase10-20261013-fixtures.json.gz','reports/movement-phase10-20261013-managed-check.json')
 'script-phase10-20261013'=@('reports/script-phase10-20261013-native-fixtures.json','reports/script-phase10-20261013-managed-check.json')
 'world-phase8-20261013'=@('reports/world-phase8-20261013-vectors.json','reports/world-phase8-20261013-managed-tests.json')
 'world-phase7-20261013'=@('reports/world-phase7-20261013-vectors.json','reports/world-phase7-20261013-managed-tests.json')
 'scene-phase5-20261013'=@('reports/scene-phase5-20261013-native-fixtures.json.gz','reports/scene-phase5-20261013-csharp-validation.json')
 'movement-phase9-20261013'=@('reports/movement-phase9-20261013-fixtures.json.gz','reports/movement-phase9-20261013-managed-check.json')
 'movement-phase8-20261013'=@('reports/movement-phase8-20261013-fixtures.json.gz','reports/movement-phase8-20261013-managed-check.json')
 'script-phase9-20261013'=@('reports/script-phase9-20261013-combined-fixtures.json','reports/script-phase9-20261013-managed-check.json')
 'script-phase8-20261013'=@('reports/script-phase8-20261013-native-fixtures.json','reports/script-phase8-20261013-managed-check.json')
 'world-phase6-20261013'=@('reports/world-phase6-20261013-vectors.json','reports/world-phase6-20261013-managed-tests.json')
 'script-phase7-20261013'=@('reports/script-phase7-20261013-native-fixtures.json','reports/script-phase7-20261013-managed-check.json')
 'world-phase5-20261013'=@('reports/world-phase5-20261013-vectors.json','reports/world-phase5-20261013-managed-tests.json')
 'movement-phase7-20261013'=@('reports/movement-phase7-20261013-fixtures.json.gz','reports/movement-phase7-20261013-managed-check.json')
 'movement-phase6-20261013'=@('reports/movement-phase6-20261013-fixtures.json.gz','reports/movement-phase6-20261013-managed-check.json')
 'script-phase6-20261013'=@('reports/script-phase6-20261013-native-fixtures.json','reports/script-phase6-20261013-managed-check.json')
 'movement-phase5-20261013'=@('reports/movement-phase5-20261013-fixtures.json.gz','reports/movement-phase5-20261013-managed-check.json')
 'scene-phase4-20261013'=@('reports/scene-phase4-20261013-native-fixtures.json.gz','reports/scene-phase4-20261013-csharp-validation.json')
 'movement-phase4-20261013'=@('reports/movement-phase4-20261013-fixtures.json.gz','reports/movement-phase4-20261013-managed-check.json')
 'world-phase4-20261013'=@('reports/world-phase4-20261013-vectors.json','reports/world-phase4-20261013-managed-tests.json')
 'scene-phase3-20261013'=@('reports/scene-phase3-20261013-native-fixtures.json.gz','reports/scene-phase3-20261013-csharp-validation.json')
 'world-phase3-20261013'=@('reports/world-phase3-20261013-vectors.json','reports/world-phase3-20261013-managed-tests.json')
 'script-phase5-20261013'=@('reports/script-phase5-20261013-native-fixtures.json','reports/script-phase5-20261013-managed-check.json')
 'script-phase4-20261013'=@('reports/script-phase4-20261013-native-fixtures.json','reports/script-phase4-20261013-managed-check.json')
 'script-phase3-20261013'=@('reports/script-phase3-20261013-native-fixtures.json','reports/script-phase3-20261013-managed-check.json')
 'movement-phase3-20261013'=@('reports/movement-phase3-20261013-fixtures.json.gz','reports/movement-phase3-20261013-managed-check.json')
 'scene-next-20261013'=@('reports/scene-next-20261013-native-fixtures.json.gz','reports/scene-next-20261013-csharp-validation.json')
 'world-next-20261013'=@('reports/world-next-20261013-vectors.json','reports/world-next-20261013-managed-tests.json')
 'script-next-20261013'=@('reports/script-next-20261013-native-fixtures.json','reports/script-next-20261013-managed-check.json')
 'actor-next-20261013'=@('reports/actor-next-20261013-fixtures.json','reports/actor-next-20261013-managed-check.json')
 'grid-visibility-20261013'=@('reports/scene-visibility-20261013-native-fixtures.json.gz','reports/grid-visibility-20261013-csharp-validation.json')
 'world-loading-20261013'=@('reports/world-loading-20261013-vectors.json','reports/world-loading-20261013-managed-tests.json')
 'script-contract-20261013'=@('reports/script-contract-20261013-native-fixtures.json','reports/script-contract-20261013-managed-check.json')
 'frame-paused'=@('reports/frame-paused-20261013-tests.json','reports/frame-paused-csharp-validation.json')
 'geometry-shadow-volume'=@('reports/geometry-shadow-volume-fixtures.json.gz','reports/geometry-shadow-volume-csharp-validation.json')
 'animation-character-effects-packets'=@('reports/animation-character-effects-packets-native-fixtures.json.gz','reports/animation-character-effects-packets-csharp-validation.json')
 'animation-character-mixed-packets'=@('reports/animation-character-mixed-packets-native-fixtures.json.gz','reports/animation-character-mixed-packets-csharp-validation.json')
 'geometry-shadow-frustum'=@('reports/geometry-shadow-frustum-fixtures.json.gz','reports/geometry-shadow-frustum-csharp-validation.json')
 'gameplay-path-corner-math'=@('reports/gameplay-path-corner-math-native-fixtures.json','reports/gameplay-path-corner-math-csharp-validation.json')
 'gameplay-path-transition'=@('reports/gameplay-path-transition-native-fixtures.json','reports/gameplay-path-transition-csharp-validation.json')
 'animation-character-queue-packets'=@('reports/animation-character-queue-packets-native-fixtures.json.gz','reports/animation-character-queue-packets-csharp-validation.json')
 'sound-configuration'=@('reports/native-sound-configuration-vectors.json.gz','reports/native-sound-configuration-csharp-validation.json')
 'gameplay-path-dispatch'=@('reports/gameplay-path-dispatch-native-fixtures.json','reports/gameplay-path-dispatch-csharp-validation.json')
 'geometry-shadow-light'=@('reports/geometry-shadow-light-fixtures.json.gz','reports/geometry-shadow-light-csharp-validation.json')
 'text-tokens'=@('reports/native-text-tokens-vectors.json.gz','reports/native-text-tokens-csharp-validation.json')
 'geometry-shadow-visibility-chain'=@('reports/geometry-shadow-visibility-chain-fixtures.json.gz','reports/geometry-shadow-visibility-chain-csharp-validation.json')
 'text-lines'=@('reports/native-text-lines-vectors.json.gz','reports/native-text-lines-csharp-validation.json')
 'text-dispatch'=@('reports/native-text-dispatch-vectors.json.gz','reports/native-text-dispatch-csharp-validation.json')
 'animation-shadow-consumer'=@('reports/animation-shadow-consumer-native-fixtures.json.gz','reports/animation-shadow-consumer-csharp-validation.json')
 'geometry-shadow-players'=@('reports/geometry-shadow-players-fixtures.json.gz','reports/geometry-shadow-players-csharp-validation.json')
 'gameplay-path-steering'=@('reports/gameplay-path-steering-native-fixtures.json','references/native-animation-sine-table.f32','reports/gameplay-path-angle-table.u16','reports/gameplay-path-steering-csharp-validation.json')
 'animation-shadow-polygons'=@('reports/animation-shadow-polygons-native-fixtures.json.gz','reports/animation-shadow-polygons-csharp-validation.json')
 'text-numbers'=@('reports/native-text-numbers-vectors.json.gz','reports/native-text-numbers-csharp-validation.json')
 'animation-shadow-polygon-pipeline'=@('reports/animation-shadow-polygon-pipeline-native-fixtures.json.gz','reports/animation-shadow-polygon-pipeline-csharp-validation.json')
 'geometry-shadow-selection'=@('reports/geometry-shadow-selection-fixtures.json.gz','reports/geometry-shadow-selection-csharp-validation.json')
 'gameplay-path-steering-composition'=@('reports/gameplay-path-steering-composition-native-fixtures.json','references/native-animation-sine-table.f32','reports/gameplay-path-angle-table.u16','reports/gameplay-path-steering-composition-csharp-validation.json')
 'animation-shadow-ellipse'=@('reports/animation-shadow-ellipse-native-fixtures.json.gz','reports/animation-shadow-ellipse-csharp-validation.json')
 'sound-text-configuration'=@('reports/native-sound-text-configuration-vectors.json.gz','reports/native-sound-text-configuration-csharp-validation.json')
 'sound-initialization-pipeline'=@('reports/native-sound-initialization-pipeline-vectors.json.gz','reports/sound-initialization-pipeline-csharp-validation.json')
 'gameplay-path-relocation'=@('reports/gameplay-path-relocation-native-fixtures.json','reports/gameplay-path-relocation-csharp-validation.json')
 'animation-shadow-cylinder'=@('reports/animation-shadow-cylinder-native-fixtures.json.gz','reports/animation-shadow-cylinder-csharp-validation.json')
 'geometry-shadow-setup'=@('reports/geometry-shadow-setup-fixtures.json.gz','reports/geometry-shadow-setup-csharp-validation.json')
 'geometry-shadow-pass-state'=@('reports/geometry-shadow-pass-state-fixtures.json.gz','reports/geometry-shadow-pass-state-csharp-validation.json')
 'sound-mask'=@('reports/native-sound-mask-vectors.json.gz','reports/sound-mask-csharp-validation.json')
 'animation-shadow-geometry-pipeline'=@('reports/animation-shadow-geometry-pipeline-native-fixtures.json.gz','reports/animation-shadow-geometry-pipeline-csharp-validation.json')
 'geometry-shadow-power'=@('reports/geometry-shadow-power-fixtures.json.gz','reports/geometry-shadow-power-csharp-validation.json')
 'build-playback'=@('reports/native-build-playback-vectors.json.gz','references/native-animation-sine-table.f32','reports/native-build-playback-csharp-validation.json')
 'gameplay-path-corners'=@('reports/gameplay-path-corners-native-fixtures.json','references/native-animation-sine-table.f32','reports/gameplay-path-corners-csharp-validation.json')
 'geometry-shadow-camera'=@('reports/geometry-shadow-camera-fixtures.json.gz','reports/geometry-shadow-camera-csharp-validation.json')
 'geometry-shadow-extraction'=@('reports/geometry-shadow-extraction-fixtures.json.gz','reports/geometry-shadow-extraction-csharp-validation.json')
 'sound-playback'=@('reports/native-sound-playback-vectors.json.gz','reports/native-sound-playback-csharp-validation.json')
 'animation-character-billboard-packets'=@('reports/animation-character-billboard-packets-native-fixtures.json.gz','reports/animation-character-billboard-packets-csharp-validation.json')
 'geometry-shadow-lifecycle'=@('reports/geometry-shadow-lifecycle-fixtures.json.gz','reports/geometry-shadow-lifecycle-csharp-validation.json')
 'gameplay-path-alias'=@('reports/gameplay-path-alias-native-fixtures.json','reports/gameplay-path-angle-table.u16','references/native-animation-sine-table.f32','reports/gameplay-path-alias-csharp-validation.json')
 'sound-groups'=@('reports/native-sound-groups-vectors.json.gz','reports/native-sound-groups-csharp-validation.json')
 'geometry-shadow-construction'=@('reports/geometry-shadow-construction-fixtures.json.gz','reports/geometry-shadow-construction-csharp-validation.json')
 'animation-character-shadow-packets'=@('reports/animation-character-shadow-packets-native-fixtures.json.gz','reports/animation-character-shadow-packets-csharp-validation.json')
 'geometry-shadow-registry'=@('reports/geometry-shadow-registry-fixtures.json.gz','reports/geometry-shadow-registry-csharp-validation.json')
 'gameplay-path-refresh'=@('reports/gameplay-path-refresh-native-fixtures.json','reports/gameplay-path-angle-table.u16','references/native-animation-sine-table.f32','reports/gameplay-path-refresh-csharp-validation.json')
 'gameplay-path-angle'=@('reports/gameplay-path-angle-native-fixtures.json','reports/gameplay-path-angle-csharp-validation.json')
 'sound-definition'=@('reports/native-sound-definition-vectors.json.gz','reports/native-sound-definition-csharp-validation.json')
 'geometry-dynamic-shadow'=@('reports/geometry-dynamic-shadow-fixtures.json.gz','reports/geometry-dynamic-shadow-csharp-validation.json')
 'sound-record'=@('reports/native-sound-record-vectors.json.gz','reports/native-sound-record-csharp-validation.json')
 'animation-character-bounds'=@('reports/animation-character-bounds-native-fixtures.json.gz','reports/animation-character-bounds-csharp-validation.json')
 'sound-initialization'=@('reports/native-sound-initialization-vectors.json.gz','reports/native-sound-initialization-csharp-validation.json')
 'gameplay-path-corridor'=@('reports/gameplay-path-corridor-native-fixtures.json','references/native-animation-sine-table.f32','reports/gameplay-path-corridor-csharp-validation.json')
 'geometry-shadow-context'=@('reports/geometry-shadow-context-fixtures.json.gz','reports/geometry-shadow-context-csharp-validation.json')
 'animation-layer-submission'=@('reports/animation-layer-submission-native-fixtures.json.gz','reports/animation-layer-submission-csharp-validation.json')
 'animation-character-visibility'=@('reports/animation-character-visibility-native-fixtures.json.gz','reports/animation-character-visibility-csharp-validation.json')
 'gameplay-path-routing'=@('reports/gameplay-path-routing-native-fixtures.json','reports/gameplay-path-routing-csharp-validation.json')
 'animation-skin-dispatch'=@('reports/animation-skin-dispatch-native-fixtures.json.gz','reports/animation-skin-dispatch-csharp-validation.json')
 'graph-actor'=@('reports/native-graph-actor-vectors.json.gz','reports/native-graph-actor-csharp-validation.json')
 'animation-billboard'=@('reports/animation-billboard-native-fixtures.json.gz','reports/animation-billboard-csharp-validation.json')
 'animation-x87-double'=@('reports/animation-x87-double-tests.json','reports/animation-x87-double-csharp-validation.json')
 'gameplay-named-lifecycle'=@('reports/gameplay-named-lifecycle-native-fixtures.json','reports/gameplay-named-lifecycle-csharp-validation.json')
 'gameplay-named-reinitialization'=@('reports/gameplay-named-reinitialization-native-fixtures.json','references/native-animation-sine-table.f32','reports/gameplay-named-reinitialization-csharp-validation.json')
 'geometry-dynamic-skin'=@('reports/geometry-dynamic-skin-fixtures.json.gz','reports/geometry-dynamic-skin-csharp-validation.json')
 'animation-full-dispatch'=@('reports/animation-full-dispatch-fixtures.json','reports/animation-full-dispatch-csharp-validation.json')
 'build-failure'=@('reports/native-build-failure-vectors.json.gz','reports/native-build-failure-csharp-validation.json')
 'geometry-dynamic-fade'=@('reports/geometry-dynamic-fade-fixtures.json.gz','reports/geometry-dynamic-fade-csharp-validation.json')
 'gameplay-graph-lifecycle'=@('reports/gameplay-graph-lifecycle-native-fixtures.json','reports/gameplay-graph-lifecycle-csharp-validation.json')
 'build-sound'=@('reports/native-build-sound-vectors.json.gz','references/native-animation-sine-table.f32','reports/native-build-sound-csharp-validation.json')
 'geometry-dynamic-billboard'=@('reports/geometry-dynamic-billboard-fixtures.json.gz','reports/geometry-dynamic-billboard-csharp-validation.json')
 'gameplay-path-targeting'=@('reports/gameplay-path-targeting-native-fixtures.json','reports/gameplay-path-targeting-csharp-validation.json')
 'gameplay-path-nextpoint'=@('reports/gameplay-path-nextpoint-native-fixtures.json','reports/gameplay-path-nextpoint-csharp-validation.json')
 'animation-character-packets'=@('reports/animation-character-packets-native-fixtures.json.gz','reports/animation-character-packets-csharp-validation.json')
 'graph-build-failure'=@('reports/native-graph-build-failure-vectors.json.gz','reports/native-graph-build-failure-csharp-validation.json')
 'animation-secondary-visibility'=@('reports/animation-secondary-visibility-native-fixtures.json.gz','reports/animation-secondary-visibility-csharp-validation.json')
 'geometry-sway'=@('reports/geometry-sway-fixtures.json.gz','reports/geometry-sway-csharp-validation.json')
 'gameplay-path-arcsine'=@('reports/gameplay-path-arcsine-native-fixtures.json','reports/gameplay-path-arcsine-csharp-validation.json')
 'sound-hash'=@('reports/native-sound-hash-vectors.json.gz','reports/native-sound-hash-csharp-validation.json')
 'animation-character-secondary'=@('reports/animation-character-secondary-native-fixtures.json.gz','reports/animation-character-secondary-csharp-validation.json')
 'geometry-dynamic-sway'=@('reports/geometry-dynamic-sway-fixtures.json.gz','reports/geometry-dynamic-sway-csharp-validation.json')
 'level-mode'=@('reports/native-level-mode-vectors.json','reports/native-level-mode-csharp-validation.json')
 'animation-character-pipeline'=@('reports/animation-character-pipeline-native-fixtures.json.gz','reports/animation-character-pipeline-csharp-validation.json')
 'category'=@('reports/native-category-vectors.json','reports/native-category-csharp-validation.json')
 'gameplay-path-binding'=@('reports/gameplay-path-binding-native-fixtures.json','references/native-animation-sine-table.f32','reports/gameplay-path-binding-csharp-validation.json')
 'animation-shadow-queue'=@('reports/animation-shadow-queue-native-fixtures.json.gz','reports/animation-shadow-queue-csharp-validation.json')
 'gizmo-activation'=@('reports/native-gizmo-activation-vectors.json','reports/native-gizmo-activation-csharp-validation.json')
 'actor-force'=@('reports/native-actor-force-vectors.json','reports/native-actor-force-csharp-validation.json')
 'gameplay-reinitialization'=@('reports/gameplay-reinitialization-native-fixtures.json','references/native-animation-sine-table.f32','reports/gameplay-reinitialization-csharp-validation.json')
 'force-action'=@('reports/native-force-action-vectors.json.gz','reports/native-force-action-csharp-validation.json')
 'gameplay-activation'=@('reports/gameplay-activation-native-fixtures.json','reports/gameplay-activation-csharp-validation.json')
 'force-conditions'=@('reports/native-force-conditions-vectors.json','reports/native-force-conditions-csharp-validation.json')
 'animation-morph-packets'=@('reports/animation-morph-packets-native-fixtures.json.gz','reports/animation-morph-packets-csharp-validation.json')
 'terrain-object-conditions'=@('reports/native-terrain-object-conditions-vectors.json','reports/native-terrain-object-conditions-csharp-validation.json')
 'animation-override-expression'=@('reports/animation-override-expression-native-fixtures.json.gz','reports/animation-override-expression-csharp-validation.json')
 'gameplay-expression-loading'=@('reports/gameplay-expression-loading-native-fixtures.json','reports/gameplay-expression-loading-csharp-validation.json')
 'animation-morph-mesh'=@('reports/animation-morph-mesh-native-fixtures.json.gz','reports/animation-morph-mesh-csharp-validation.json')
 'gizmo-conditions'=@('reports/native-gizmo-conditions-vectors.json','reports/native-gizmo-conditions-csharp-validation.json')
 'gameplay-retreat-token'=@('reports/gameplay-retreat-token-composition-native-fixtures.json','reports/gameplay-retreat-token-composition-csharp-validation.json')
 'gameplay-retreat-expression'=@('reports/gameplay-retreat-expression-native-fixtures.json','reports/gameplay-retreat-expression-csharp-validation.json')
 'actor-status'=@('reports/native-actor-status-vectors.json','reports/native-actor-status-csharp-validation.json')
 'gameplay-expression'=@('reports/gameplay-expression-native-fixtures.json','reports/gameplay-expression-csharp-validation.json')
 'party-control'=@('reports/native-party-control-vectors.json','reports/native-party-control-csharp-validation.json')
 'animation-morph'=@('reports/animation-morph-native-fixtures.json.gz','reports/animation-morph-csharp-validation.json')
 'spatial-conditions'=@('reports/native-spatial-conditions-vectors.json','reports/native-spatial-conditions-csharp-validation.json')
 'effect-activation'=@('reports/native-effect-activation-vectors.json','reports/native-effect-activation-csharp-validation.json')
 'gameplay-opponent-retreat'=@('reports/gameplay-opponent-retreat-native-fixtures.json','reports/gameplay-opponent-retreat-csharp-validation.json')
 'animation-script-override'=@('reports/animation-script-override-native-fixtures.json.gz','reports/animation-script-override-csharp-validation.json')
 'run-speed'=@('reports/native-run-speed-vectors.json','reports/native-run-speed-csharp-validation.json')
 'locator-random-conditions'=@('reports/native-locator-random-conditions-vectors.json','reports/native-locator-random-conditions-csharp-validation.json')
 'gameplay-attack-opponent'=@('reports/gameplay-attack-opponent-native-fixtures.json','reports/gameplay-attack-opponent-csharp-validation.json')
 'animation-points'=@('reports/animation-points-native-fixtures.json.gz','references/native-animation-sine-table.f32','reports/animation-points-csharp-validation.json')
 'gameplay-engage-opponent'=@('reports/gameplay-engage-opponent-native-fixtures.json','reports/gameplay-engage-opponent-csharp-validation.json')
 'locator-selection'=@('reports/native-locator-selection-vectors.json','reports/native-locator-selection-csharp-validation.json')
 'locator-set-command'=@('reports/native-locator-set-command-vectors.json','reports/native-locator-set-command-csharp-validation.json')
 'distance-rounding'=@('reports/native-distance-rounding-vectors.json','reports/native-distance-rounding-csharp-validation.json')
 'animation-packet-pose'=@('reports/animation-packet-pose-native-fixtures.json.gz','references/native-animation-sine-table.f32','reports/animation-packet-pose-csharp-validation.json')
 'locator-culling'=@('reports/native-locator-culling-vectors.json','reports/native-locator-culling-csharp-validation.json')
 'locator-traversal'=@('reports/native-locator-traversal-vectors.json','reports/native-locator-traversal-csharp-validation.json')
 'gameplay-opponent-targeting'=@('reports/gameplay-opponent-targeting-native-fixtures.json','reports/gameplay-opponent-targeting-csharp-validation.json')
 'animation-skeletal-blend'=@('reports/animation-skeletal-blend-native-fixtures.json.gz','references/native-animation-sine-table.f32','reports/animation-skeletal-blend-csharp-validation.json')
 'locator-reservations'=@('reports/native-locator-reservations-vectors.json','reports/native-locator-reservations-csharp-validation.json')
 'animation-skeletal'=@('reports/animation-skeletal-native-fixtures.json.gz','references/native-animation-sine-table.f32','reports/animation-skeletal-csharp-validation.json')
 'gameplay-transfer-script-bridge'=@('reports/gameplay-transfer-script-bridge-native-fixtures.json','reports/gameplay-transfer-script-bridge-csharp-validation.json')
 'gameplay-player-transfer'=@('reports/gameplay-player-transfer-native-fixtures.json','reports/gameplay-player-transfer-csharp-validation.json')
 'camera-effects'=@('reports/native-camera-effects-vectors.json.gz','reports/native-camera-effects-csharp-validation.json')
 'scene-animation-bounds'=@('reports/scene-animation-bounds-native-fixtures.json.gz','references/native-animation-sine-table.f32','reports/scene-animation-bounds-csharp-validation.json')
 'camera-command'=@('reports/native-camera-command-vectors.json','references/native-animation-sine-table.f32','reports/native-camera-command-csharp-validation.json')
 'gameplay-tag-control'=@('reports/gameplay-tag-control-native-fixtures.json','reports/gameplay-tag-control-csharp-validation.json')
 'gameplay-actor-identity'=@('reports/gameplay-actor-identity-native-fixtures.json','reports/gameplay-actor-identity-csharp-validation.json')
 'camera-state'=@('reports/native-camera-state-vectors.json','reports/native-camera-state-csharp-validation.json')
 'gameplay-actor-state'=@('reports/gameplay-actor-state-native-fixtures.json','reports/gameplay-actor-state-csharp-validation.json')
 'scene-animation-pose'=@('reports/scene-animation-pose-native-fixtures.json.gz','references/native-animation-sine-table.f32','reports/scene-animation-pose-csharp-validation.json')
 'gameplay-facing'=@('reports/gameplay-facing-native-fixtures.json','reports/gameplay-facing-helper-native-fixtures.json','references/native-animation-sine-table.f32','reports/gameplay-facing-csharp-validation.json')
 'scene-animation-update'=@('reports/scene-animation-update-native-fixtures.json.gz','reports/scene-animation-update-csharp-validation.json')
 'gameplay-perception'=@('reports/native-perception-vectors.json','reports/native-perception-csharp-validation.json')
 'gameplay-obstacle-binding'=@('reports/native-obstacle-binding-vectors.json','reports/native-obstacle-binding-csharp-validation.json')
 'scenery-names'=@('reports/native-scenery-name-vectors.json','reports/native-scenery-name-csharp-validation.json')
 'gameplay-locator'=@('reports/gameplay-locator-binding-native-fixtures.json','reports/gameplay-locator-binding-csharp-validation.json')
 'gameplay-movement'=@('reports/gameplay-movement-native-fixtures.json','reports/gameplay-movement-csharp-validation.json')
 'gameplay-trigger'=@('reports/gameplay-trigger-native-fixtures.json.gz','references/native-animation-sine-table.f32','reports/gameplay-trigger-csharp-validation.json')
 'gameplay-obstacle'=@('reports/native-obstacle-vectors.json','reports/native-obstacle-csharp-validation.json','reports/native-obstacle-review-tests.json')
 'navigation'=@('reports/native-connections-vectors.json','reports/native-connections-csharp-validation.json','reports/native-connections-review-tests.json')
 'gameplay-createcreatures'=@('reports/gameplay-createcreatures-native-fixtures.json','reports/gameplay-createcreatures-csharp-validation.json')
 'gameplay-createsplinecreatures'=@('reports/gameplay-createsplinecreatures-native-fixtures.json','reports/gameplay-createsplinecreatures-csharp-validation.json')
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
 if($Module -eq 'all' -or $Module -eq 'geometry-traversal'){
  & python tools/geometry-portal-runtime-check.py --harness $verifier --module geometry-traversal
  if($LASTEXITCODE -ne 0){throw 'Compiled portal traversal differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-room-outputs'){
  & python tools/geometry-portal-room-outputs-check.py --harness $verifier --module geometry-room-outputs
  if($LASTEXITCODE -ne 0){throw 'Compiled room-output differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-entry'){
  & $verifier geometry-entry reconstructed/geometry/fixtures/portal-entry.bin references/native-animation-sine-table.f32 reports/geometry-portal-entry-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled portal-entry harness failed.'}
  & python tools/geometry-portal-entry-check.py --compare reports/geometry-portal-entry-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled portal-entry differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-scheduling'){
  & $verifier geometry-scheduling reconstructed/geometry/fixtures/scene-scheduling.bin references/native-animation-sine-table.f32 reports/geometry-scene-scheduling-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled scene-scheduling harness failed.'}
  & python tools/geometry-scene-scheduling-check.py --compare reports/geometry-scene-scheduling-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled scene-scheduling differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-static-finish'){
  & $verifier geometry-static-finish reconstructed/geometry/fixtures/static-finish.bin.gz reports/geometry-static-finish-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled static-finish harness failed.'}
  & python tools/geometry-static-finish-check.py --compare reports/geometry-static-finish-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled static-finish differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-sorted-packets'){
  & $verifier geometry-sorted-packets reconstructed/geometry/fixtures/sorted-packets.bin.gz reports/geometry-sorted-packets-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled sorted-packets harness failed.'}
  & python tools/geometry-sorted-packets-check.py --compare reports/geometry-sorted-packets-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled sorted-packets differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-shader-emission'){
  & $verifier geometry-shader-emission reconstructed/geometry/fixtures/shader-emission.bin.gz reports/geometry-shader-emission-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled shader-emission harness failed.'}
  & python tools/geometry-shader-emission-check.py --compare reports/geometry-shader-emission-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled shader-emission differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-sorted-shader'){
  & $verifier geometry-sorted-shader reconstructed/geometry/fixtures/sorted-shader.bin.gz reports/geometry-sorted-shader-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled sorted-shader harness failed.'}
  & python tools/geometry-sorted-shader-check.py --compare reports/geometry-sorted-shader-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled sorted-shader differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-dynamic-packets'){
  & $verifier geometry-dynamic-packets reconstructed/geometry/fixtures/dynamic-material-packets.bin.gz reports/geometry-dynamic-packets-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled dynamic-packets harness failed.'}
  & python tools/geometry-dynamic-packets-check.py --compare reports/geometry-dynamic-packets-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled dynamic-packets differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-finish-pipeline'){
  & $verifier geometry-finish-pipeline reconstructed/geometry/fixtures/scene-finish-pipeline.bin.gz reports/geometry-finish-pipeline-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled finish-pipeline harness failed.'}
  & python tools/geometry-finish-pipeline-check.py --compare reports/geometry-finish-pipeline-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled finish-pipeline differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-dynamic-command'){
  & $verifier geometry-dynamic-command reconstructed/geometry/fixtures/dynamic-command-support.bin.gz reports/geometry-dynamic-command-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled dynamic-command harness failed.'}
  & python tools/geometry-dynamic-command-check.py --compare reports/geometry-dynamic-command-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled dynamic-command differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-ordinary-packets'){
  & $verifier geometry-ordinary-packets reconstructed/geometry/fixtures/ordinary-mesh-packets.bin.gz reports/geometry-ordinary-packets-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled ordinary-packets harness failed.'}
  & python tools/geometry-ordinary-packets-check.py --compare reports/geometry-ordinary-packets-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled ordinary-packets differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-dynamic-submission'){
  & $verifier geometry-dynamic-submission reconstructed/geometry/fixtures/dynamic-submission.bin.gz reports/geometry-dynamic-submission-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled dynamic-submission harness failed.'}
  & python tools/geometry-dynamic-submission-check.py --compare reports/geometry-dynamic-submission-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled dynamic-submission differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-material-pool'){
  & $verifier geometry-material-pool reconstructed/geometry/fixtures/material-pool.bin.gz reports/geometry-material-pool-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled material-pool harness failed.'}
  & python tools/geometry-material-pool-check.py --compare reports/geometry-material-pool-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled material-pool differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-material-refresh'){
  & $verifier geometry-material-refresh reconstructed/geometry/fixtures/material-refresh.bin.gz reports/geometry-material-refresh-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled material-refresh harness failed.'}
  & python tools/geometry-material-refresh-check.py --compare reports/geometry-material-refresh-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled material-refresh differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-dynamic-material'){
  & $verifier geometry-dynamic-material reconstructed/geometry/fixtures/dynamic-material.bin.gz reports/geometry-dynamic-material-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled dynamic-material harness failed.'}
  & python tools/geometry-dynamic-material-check.py --compare reports/geometry-dynamic-material-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled dynamic-material differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-material-lifecycle'){
  & $verifier geometry-material-lifecycle reconstructed/geometry/fixtures/material-lifecycle.bin.gz reports/geometry-material-lifecycle-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled material-lifecycle harness failed.'}
  & python tools/geometry-material-lifecycle-check.py --compare reports/geometry-material-lifecycle-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled material-lifecycle differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-material-clone'){
  & $verifier geometry-material-clone reconstructed/geometry/fixtures/material-clone-cache.bin.gz reports/geometry-material-clone-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled material-clone harness failed.'}
  & python tools/geometry-material-clone-check.py --compare reports/geometry-material-clone-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled material-clone differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-dynamic-selection'){
  & $verifier geometry-dynamic-selection reconstructed/geometry/fixtures/dynamic-selection.bin.gz reports/geometry-dynamic-selection-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled dynamic-selection harness failed.'}
  & python tools/geometry-dynamic-selection-check.py --compare reports/geometry-dynamic-selection-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled dynamic-selection differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-dynamic-bounds'){
  & $verifier geometry-dynamic-bounds reconstructed/geometry/fixtures/dynamic-bounds.bin.gz reports/geometry-dynamic-bounds-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled dynamic-bounds harness failed.'}
  & python tools/geometry-dynamic-bounds-check.py --compare reports/geometry-dynamic-bounds-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled dynamic-bounds differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-dynamic-queue'){
  & $verifier geometry-dynamic-queue reconstructed/geometry/fixtures/dynamic-material-queue.bin.gz reports/geometry-dynamic-queue-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled dynamic-queue harness failed.'}
  & python tools/geometry-dynamic-queue-check.py --compare reports/geometry-dynamic-queue-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled dynamic-queue differential failed.'}
 }
 if($Module -eq 'all' -or $Module -eq 'geometry-frame-reset'){
  & $verifier geometry-frame-reset reconstructed/geometry/fixtures/frame-reset.bin.gz reports/geometry-frame-reset-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled frame-reset harness failed.'}
  & python tools/geometry-frame-reset-check.py --compare reports/geometry-frame-reset-csharp.bin
  if($LASTEXITCODE -ne 0){throw 'Compiled frame-reset differential failed.'}
 }
}finally{Pop-Location}
