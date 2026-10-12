Recovered.Geometry - original PC animated material UV contracts

MaterialUv.cs is dependency-free C# source, compiled successfully with the
installed .NET Framework 4 compiler. It is a small recovered runtime module,
not a renderer, complete game, Unity project, or recovered original source file.
Names and object-oriented API are reconstructed; formulas/field offsets derive
from the original PC instructions documented in reports/geometry-uv-findings.txt.

Core API
  UvMaterial.DecodeCurrentRecord: exactly 708-byte current PC record.
  NativeSineTable.DecodeLittleEndian: original 32768-entry float32 table.
  MaterialUv.Advance: explicit delta, ref float phase clock, ordered memberships.
  MaterialUv.Tick: speed-scaled advance followed by unscaled clock/reset helper.

Use the original table at references/native-animation-sine-table.f32.
SHA256: 8daf7a6f0fe07a15e813f802ba564bfb2ee2540de287edfd9d9f28e7325b024b.
Do not replace it with a host Math.Sin table if exact PC quantization matters.
Preserve list order and duplicate material memberships. The original evaluator
does not deduplicate them. A handle of -1 skips a layer; exact disable-byte 1
skips the material. Mode 128 writes zero. Negative linear fractions remain
negative because wrapping subtracts truncation, not floor.

Clock integration
Original platform frame function 0x4fd050 passes previous platform delta at
0x297dbfc into 0x601330 before measuring/replacing that delta. The outer game
loop separately caps its world-update delta. Tick accepts the platform delta;
using a capped game/simulation delta would not reproduce the observed caller.
ResetEligible represents displayScene+0x78 -> owningHeader+0x158 != 0.
Caller owns synchronization and current scene registration.

Build (PowerShell, working directory this geometry directory)
  $csc = 'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe'
  & $csc /nologo /target:library /out:Recovered.Geometry.dll .\MaterialUv.cs .\SceneSubmission.cs .\Clipping.cs ..\animation\AnimationPlayback.cs ..\animation\CharacterContexts.cs
  & $csc /nologo /target:exe /out:GeometryUvHarness.exe /reference:Recovered.Geometry.dll .\harness\Program.cs
No external packages, Unity APIs, native DLLs, or original executable are linked.
The core can also be compiled with the other Recovered namespaces into one DLL.
The Main harness is separate and must not be included in a runtime library.

Differential test (from workspace root)
  python reverse-engineering/tools/geometry-recovered-uv-check.py
Optional --harness and --assembly paths support the combined-library build.
This creates 618 configuration fixtures and invokes the ordinary compiled
harness, then compares its output against original instructions in Unicorn.
Unicorn and original binary are used only by the Python test, never the core.

Current validation status
Core and harness compilation passed. Ordinary execution of this generated
harness returned OS Access denied, reproduced independently by the root agent
including a central combined-library build. No ACL or security settings were
changed; no alternative host is used. Therefore the COMPILED C# differential
comparison is pending, not claimed passed. See geometry-recovered-source.json.
The independent JS/Python contract comparison already passed 9270 original UV
ticks and 8 wrapper cases (geometry-uv-native-validation.json), but that result
does not by itself prove the C# implementation or CLR floating-point behavior.

Limits
Integer-conversion phases outside signed32, nonfinite conversion inputs, and
invalid material-index lists throw instead of guessing CPU-specific behavior.
The observed finite authored domain is supported. Legacy 628-byte records are
rejected because the ordinary native loader does not demonstrably expand them.
Graphics upload, texture scripts, shader state and scheduling are separate work.

Additional CPU submission projections
SceneSubmission.cs adds bounded normal-scene visibility/LOD/fade, paired
display-item control patches and signed sort insertion. EvaluateVisibility
requires caller-provided portal/tree bitsets and a frustum callback; it does
not implement those original visibility oracles, shadow extrusion or GPU work.
DistanceFade retains the original equal-endpoint NaN edge; ClampInstanceAlpha
also preserves NaN. See geometry-visibility-findings.txt and the2,025 passing
original-x86 contract assertions in geometry-visibility-native-validation.json.
These validate the independent recovered contracts, not compiled C# execution.
All native-address/method coverage mappings are in geometry-recovered-source.json.

CPU CLIPPING
Clipping.cs adds prepared-frustum, room-plane and portal-polygon predicates.
It uses FiniteX87 from animation/AnimationPlayback.cs to preserve native64-bit
significand rounding at authored plane boundaries. Clipping is not complete
portal traversal or a camera-matrix producer. See geometry-clipping-findings.txt
and geometry-recovered-source.json for fixture counts and dependency hashes.
