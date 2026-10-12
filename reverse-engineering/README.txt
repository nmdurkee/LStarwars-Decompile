LEGO STAR WARS: THE COMPLETE SAGA - PC REVERSE ENGINEERING
Updated 2026-10-12

All seven supplied DAT archives are recovered. Every one of the 12,459 files,
9,692,364,695 expanded bytes, matches an independent decoder byte for byte.
This workspace contains decoded assets, viewable scenes and characters, native
pseudocode, reproducible parsers, behavior checks and preserved evidence.
Portable C# fragments are available in reconstructed/; they are not a complete game.

This is a substantial recovery workspace, not a recovered buildable C++ source
project or a complete playable reconstruction. Current work is reverse engineering
only. Unity/Quest work has not started. Original game files were not modified.

START HERE (paths relative to this folder)
 reports/source-completion.txt              portable source status and missing work
 reconstructed/README.txt                   build and native-reference verifier commands
 reports/archive-format.txt                 verified archive/codec specification
 reports/geometry-findings.txt              geometry, textures, materials, rendering
 reports/animation-findings.txt             rigs, skin, morphs, clips and scene motion
 reports/gameplay-findings.txt              levels, puzzles, AI, collision and configs
 reports/native-input-camera.txt            PC controller/camera contracts
 reports/animation-locomotion-findings.txt   movement, jump/gravity, exact tuning
 reports/geometry-material-findings.txt     native material and shader contracts
 reports/native-architecture.txt            startup and frame-loop navigation
 reports/gameplay-native-index.json         bounded native verification ledger
 reports/gameplay-native-save-audio.txt     save layout and native audio contracts
 INVESTIGATION.json                        coverage ledger and remaining work
 reports/geometry-remaining-gaps.json       explicit rendering/metadata limitations

RECOVERED FILES AND VIEWABLE EXPORTS
 extracted/                                all original internal archive paths
 exports/geometry/<source path>/scene.gltf  all 789 level graphics carriers
 exports/characters/assets/                all 688 character graphics carriers
 exports/animated-scenes/                  185 scenes with recovered motion bindings
 exports/collision/                        269 collision meshes and source properties
 exports/geometry/textures/                original embedded DDS plus PNG previews
 exports/animation/                        decoded skeletal/morph animation data
 exports/animation-scene-states/            decoded SALI visibility/state sidecars
 exports/shaders/                          original shader text, bytecode, disassembly

Keep each glTF beside its binary buffers, metadata and referenced shared textures.
Exported coordinates retain the original engine space; no tabletop scale or Unity
coordinate conversion is silently baked in. Source names/IDs and raw fields remain
available for cross-format joins. The glTF files are inspection/interchange assets.
Approximate PBR materials and synchronized scene previews do not reproduce native
lighting, game-triggered playback, visibility or puzzle state.

COVERAGE
- All 1,477 GSC/GHG carriers: 153,367 mesh records, 49,155 materials,
  31,406 embedded texture allocations, 5,249 named splines, 49,272 named objects.
  All 789 GSC exports: 20,504,967 unique triangles; zero glTF errors/warnings.
- All 688 character exports: rigs, skins, rigid attachments, morphs and compatible
  clips; 11,794 clip instances, 8,009 morph target instances; zero errors/warnings.
  Two thermal-detonator carriers contain rigs without render meshes.
- All 15,608 DDS previews independently matched; raw DDS retain mips, cube faces
  and HDR values. Two fonts decoded; two RAW images retain channel-order candidates.
- All 2,911 AN3, 2,340 BSA, 205 CU2, 78 ANM and 789 scene carriers decoded.
  185 animated scenes contain 19,780 bound objects and 15,006 source clips.
  All validate. Their synchronized 30 fps timeline is an inspection choice.
- All 173 AI2 navigation and 269 TER collision carriers parsed through EOF:
  645,546 collision faces, 10,051 nav points, 10,301 nav links; platform joins retained.
  GIZ: 248 complete, two zero placeholders, one shipped truncated backup documented.
- Text catalogs cover character tuning, level routing, state machines, puzzle
  graphs, effects, audio, localized text and links. All 31 archive extensions have
  an assigned parser/catalog or an explicitly documented preserved dependency.
- Original 158,575-byte Nu2 HLSL template recovered exactly from the executable.
  38 embedded shader allocations yield 35 unique readable compiled bytecodes.
  All 49,109 current materials: 170,936 original feature-builder calls and
  4,567,137 uniform scalar comparisons pass. The ordinary PC loader does not expand
  the 46 legacy layouts into the current material format; they remain separate. Billboard shader/constant contracts are recovered.

NATIVE CODE
 decompiled/corpus/              first dispatch-seeded Ghidra pseudocode pass
 decompiled/corpus-expanded/     broader boundary-seeded Ghidra pseudocode pass
 decompiled/corpus-supplemental/  26 inspected virtual-only method entries
 reports/native-corpus-index.json / native-expanded-corpus-index.json
 reports/native-supplemental-corpus-index.json / native-supplemental-plan.json
 reports/rea/                    original REA responses and Evidence IDs
 reports/native-boundary-seeds.json  reproducible boundary hypotheses and limits

Expanded corpus: all 14,656 recognized internal functions exported; zero failures.
The supplemental profile adds 26 virtual-only methods, all successfully exported.
The combined three-profile corpus contains 14,697 distinct function entries.
Fifteen entries exist only in the first profile; profile boundaries can differ.

 reports/native-catalog.sqlite   searchable pseudocode, names, calls, assets, RTTI
 reports/native-rtti.json         120 type descriptors and 114 virtual tables
 reports/native-contract-aliases.json  semantic labels with evidence/confidence

The 932 recovered virtual slots are bounded candidate sequences, after excluding
inspected adjacent string data. They reference 528 distinct code targets.
RTTI provides original mangled class names; it does not recover full C++ layouts.

Pseudocode is not original source. Names/types can be wrong; x87 floating-point,
custom register ABIs and indirect calls require assembly checks. The expanded
profile uses caller-asserted boundary seeds, not proven original source boundaries.
Counts therefore do not measure a percentage of all game behavior recovered.
OpenSaga is pinned as a cross-build (Android) reference. PC addresses, layouts and
behavior are independently checked where reports claim PC verification.

BEHAVIOR VERIFICATION
Isolated original PC x86 functions run in Unicorn memory, without launching the
Windows game or invoking its OS APIs. Tests cover millions of animation samples,
scene pose matrices and state tracks; archive hash/codec; controller transforms,
button mapping and movement angles; save checksums; audio config/group selection;
script dispatch lookup and GIT predicates; script condition/action scheduling;
navigation and ATS texture programs; material features and uniform calculations.
Movement and exact tuning parsing pass 81,327 isolated native cases. Gameplay totals and suite boundaries are maintained in
reports/gameplay-native-index.json. Fixture counts do not measure recovered behavior.
Each report describes state setup, hooks (if any), numeric tolerances and limits.
No end-to-end running-game equivalence is claimed.

All 12,459 archive files were independently decoded/compared; 51 real LZ2K chunks
also matched the original native decoder. Native normalization/hash lookup matched
all 12,459 paths. Parsers reject tested malformed inputs. Khronos validation
establishes glTF conformance, not visual or gameplay fidelity.

SEARCH THE RECOVERED NATIVE CODE (from SW workspace root)
 python reverse-engineering/tools/native-search.py CameraCut
 python reverse-engineering/tools/native-search.py --address 0x54b3d0
 python reverse-engineering/tools/native-search.py --callers 0x4faea0
 python reverse-engineering/tools/native-search.py --class HLSLShaderBuilder

The search database opens read-only and needs no running REA/Ghidra process.
Names distinguish native table entries, unconfirmed candidates and manually
assigned semantic labels. Call edges are pseudocode references, not a complete
verified call graph. Rebuild with native-catalog.py then native-catalog-metadata.py.

REPRODUCE FROM THE SW WORKSPACE ROOT
 node reverse-engineering/tools/verify.mjs --all
 node reverse-engineering/tools/tt-lz2k.mjs --all
 node reverse-engineering/tools/tt-lz2k-tests.mjs
 python reverse-engineering/tools/native-archive-paths.py
 python reverse-engineering/tools/native-archive-emulate.py

Independent extraction without QuickBMS (output files must not already exist):
 node reverse-engineering/tools/tt-extract.mjs GAME.DAT CHARS/BIBFORTUNA/EVADERIGHT.BSA output-new
Use '*' as the filter for an entire archive. See each subsystem findings file for
its export and verification commands.

REA/Ghidra/JDK and Python packages are workspace-local under tools/. REA 6.4.0,
Ghidra 12.1.4, Java 21, Unicorn 2.1.4, Capstone 5.0.9 and pinned source references
are retained. tools/Invoke-Rea.ps1 starts the local REA launcher. No global REA
registration was added. A saved REA snapshot retains query/evidence state; it is
not an editable Ghidra project and reopening can require fresh analysis.

IDENTITY AND PROVENANCE
Original EXE SHA-256:
085688e73561c61f4619fcf1f3006c56425ca365e80ea5fc0175bab334cec671
Separate unpacked analysis copy SHA-256:
6c9c2b35aa9452ba36c4f816a4ae50e3e8de133971ae1899a20de102d7e20adb
reports/source-sha256.json and binary-provenance.json retain original hashes and
unpacking details. Primary references:
 https://github.com/morluto/rea
 https://github.com/opensagadev/saga
 https://github.com/BrickBench/BrickBench
 https://aluigi.altervista.org/bms/ttgames.bms
Pinned commits/tool versions and cross-version limitations are recorded per report.

REMAINING WORK
Many runtime rules still require semantic reconstruction: full character/context
state machines and combat, AI scheduling and puzzle orchestration, level streaming,
complete cutscene playback, special vehicle behaviors, live render-state bindings,
alternate legacy material consumers, complete visibility scheduling and native GPU pixel
comparisons. Swept collision edge/vertex handling and accepted platform contacts
need broader runtime validation. Base movement, navigation, material and billboard
contracts have bounded native checks; the full game has not been executed.
The extracted data and original shaders preserve information for these next steps.

Historical first-pass reports (asset-findings.txt, native-findings.txt,
verification.json, initial-pass-readme.txt) remain as evidence but contain
superseded coverage limits. Use this README and subsystem findings above for the
current recovery state.

PORTABLE SOURCE CHECKPOINT
Build: & .\reconstructed\build.ps1 (from this directory).
Source map: reconstructed/source-manifest.json and reports/source-completion.json.
Current compile and execution evidence: reports/reconstructed-build.json and
reports/reconstructed-execution-status.json. Compilation is not behavioral proof.
Detailed new work: native-combat-contract.json, animation-source-function-map.json,
gameplay-scp-transition-contract.json, geometry-visibility-native-validation.json,
and native-frame-dispatch.json in reports/. All are bounded contracts.
