RECOVERED SOURCE

Portable C# reconstruction of bounded original-PC behavior. This is not the original source tree or a complete playable game.

BUILD (PowerShell, from reverse-engineering/)
  & .\reconstructed\build.ps1
Outputs: reconstructed/bin/Recovered.Runtime.dll and RecoveredSourceVerify.exe.
Uses the installed Framework compiler; no package download or original game linking.

VERIFY
  & .\reconstructed\verify.ps1 -Module all
Or select combat, combat-kill, animation, gameplay, gameplay-message, gameplay-state, gameplay-visibility, gameplay-conditions, gameplay-createcreatures, input, frame, geometry, geometry-rooms, geometry-visibility, geometry-volumes, navigation.
The script stops on failure and writes module reports; it does not change security settings.
Current environment rejects generated EXE launch with Windows Access denied. Compilation succeeds, but extended compiled-source comparisons remain pending.

MODULES
combat: hit flags/protection/shields/health commands, selected hit guards, currency deduction, heart-drop decisions and the Kill command with explicit death/parts dispatch boundaries.
animation: object/context projections, reset/respawn branches, selectors, clip end frames, bounded animation packet updates, idle scheduling, compact controls and event-suppressed player advancement; shared finite x87 arithmetic.
gameplay: puzzle graphs/timers/random/save, SCP state scheduling, messages, SetScriptState and visibility commands, six compact conditions and CreateCreatures with explicit world/spawn/effect adapters.
geometry: material UV state, CPU submission/LOD/fade/sort, prepared frustum/room/portal predicates, room selection, portal visibility propagation and bounded child-volume construction. Full recursive traversal remains incomplete.
frame: transition state helpers and the recovered level-transition tail. Full frame dispatcher is not implemented.
input: built-in Xbox mapping, stick transform, both deadzones, whole generic pad state and camera/socket-relative movement angle. No VR binding is implemented.

navigation: CnxController parsing, route flag dialects, locator/connection lookup, fixed-capacity controller pool, frame masks and ordered state gates with explicit world/target services.

PROVENANCE AND LIMITS
source-manifest.json maps each method to original entrypoints and precise scope.
../reports/source-completion.txt summarizes the status; source-completion.json inventories all14697 recognized entries and tests current source hashes against the build.
../reports/reconstructed-build.json records the compiler and current core hashes.
../reports/reconstructed-execution-status.json separates native/model verification from compiled behavior.
Original x86 functions execute only in isolated Unicorn memory, with adapters identified per suite. Initial combat C# subset passed14553 comparisons. Later C# additions are compiled, not runtime-verified.
These sources have no complete world/level loader, engine bootstrap, renderer, audio backend or game entrypoint. Core mappings may be partial branches; counts are not completion percentages.
