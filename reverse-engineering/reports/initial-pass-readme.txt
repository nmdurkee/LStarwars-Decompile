LEGO STAR WARS: THE COMPLETE SAGA — REVERSE-ENGINEERING WORKSPACE
Initial static-analysis pass | 2026-10-12

The supplied game is the native x86 PC version of LEGO Star Wars: The Complete Saga.
This workspace contains extracted assets, format documentation, focused native-code
analysis, reproducible tools and preserved evidence. It is not recovered original
source code or a complete reconstruction of the game. The current scope is reverse
engineering; no Unity or Quest implementation has been created.

START HERE
All paths in this document are relative to reverse-engineering/ unless stated otherwise.

 reports/asset-findings.txt
   Detailed, source-cited findings for Negotiations level structure, characters,
   AI scripts, puzzle graphs, cameras, GIZ objects and graphics/animation containers.
 reports/native-findings.txt
   Executable identity, camera command paths, physical Xbox input layout, partial
   gameplay-input mapping, native addresses and REA evidence identifiers.
 reports/archive-format.txt
   Verified DAT index schema, filename hash algorithm and extraction coverage.
 reports/verification.json
   Machine-readable archive/extraction verification and parser negative tests.
 extracted/
   Recovered files with their internal paths preserved.
 decompiled/
   Ten focused Ghidra pseudocode files and stick-filter assembly. These are analysis
   artifacts with inferred types and synthetic names, not buildable original code.

WHAT WAS RECOVERED

1. Archive structure and contents
All seven DAT archives were indexed: 12,459 entries with resolved original paths.
Every filename hash matched uniquely and every payload range passed bounds checks.
The installed DAT files total 4,278,430,452 bytes. Expanded archive sizes are storage
measurements, not runtime memory or headset requirements.

 Archive          Indexed   Extracted in this pass
 GAME.DAT          12,174    12,174 (all entries)
 EPISODE_I.DAT         61         7 (Negotiations graphics)
 EPISODE_II.DAT        44         0
 EPISODE_III.DAT       46         0
 EPISODE_IV.DAT        51         0
 EPISODE_V.DAT         46         0
 EPISODE_VI.DAT        37         0
 Total             12,459    12,181

GAME.DAT includes supporting content across the game: character files, scripts,
level configuration and many other assets. Most remaining episode graphics payloads
were indexed but not extracted. Existing loose audio/video files were inventoried.

Our ttdat.mjs implements the observed MkDat v4, index-type -3 index format, including
name-tree traversal and the TT-specific filename hash. It does not implement
compression. Payload extraction uses Luigi Auriemma's QuickBMS and the unmodified
ttgames.bms 0.9.11a. See reports/all-assets.json, asset-types.json and *.DAT.index.json.

2. Readable gameplay data, with Negotiations as the focused sample
Character text contains movement tuning, health, abilities and named animation
bindings. For example, Qui-Gon's configuration gives hit_points 4, run_speed 1.2,
jump_speed 2.3 and gravity -6; their engine units and effective runtime behavior
are not yet established.

Level text names characters, locators, doors, destinations, camera settings and
interactions. The Negotiations A/B/C relationships and distinct configured Story
and Free Play exit destinations are documented in asset-findings.txt.

SCP files contain readable state-machine behavior for tutorial progression, TC14,
Jedi companions, spawned enemies and a Droideka camera sequence. All 27 non-PAK AI
siblings in areas A/B/C were located byte-for-byte inside their corresponding
AI.PAK files. This proves the data association, not which runtime load path is used.
A malformed shipped PKDROID.SCP block was recorded without modifying the game data.

GIT files are plaintext puzzle/flow graphs, not geometry. The focused parser recovered
190 FlowBox nodes and 188 Child links across A/B/C, with all referenced IDs resolving
when Collapse groups are included. Editor graph positions are not world coordinates.

3. Binary asset formats — partially decoded
All five Negotiations GIZ files pass a bounded outer-chunk parser through exact EOF.
Chunk names and payload sizes are known; obstacle/Force/etc. inner object layouts
remain unresolved.

The Negotiations A GSC and Qui-Gon GHG expose NU20 chunk structures, name tables,
DDS-header candidates and graphics/rig-related labels. The reports record bounded
chunk walks and retain unknown tails. Vertex/index layouts, material assignments,
transforms, skeleton hierarchy, skin weights, textures as complete sets, animation
tracks, collision and navigation are not decoded. No usable mesh or animation
exporter has been produced.

4. Focused native analysis
The supplied executable is a wrapped PE32 x86 program with Direct3D 9, DirectInput 8,
XInput1_3 and Bink32 imports and Nu2-era build strings. A separate copy was unpacked
with Steamless, then analyzed through REA 6.4.0 and Ghidra 12.1.4. The original
executable was not modified or executed.

Ghidra recognized 7,624 procedures. Focused pseudocode was saved for camera-cut,
camera-shake, camera-state/timing, controller initialization/polling, stick filtering
and input mapping/consumers. A scan yielded 1,057 candidate command-name/function
records; only 227 matched recognized procedure entries. The associations are
explicitly marked as candidates pending semantic confirmation.

The CameraCut path parses parameters matching shipped scripts, then writes camera
state and timing. The XInput polling path yields the physical button/stick/trigger
staging layout. A downstream mapping routine is identified, but default gameplay
bindings and movement consumption remain unresolved. Pseudocode loses some x87
calculations and has inconsistent inferred prototypes; it must be checked against
assembly before translation. See native-findings.txt for addresses and evidence.

VALIDATION AND PRESERVATION

- All 12,459 index entries: unique filename-hash matches and valid payload bounds.
- All 12,181 expected extracted files: present with their declared expanded size.
- 37 deterministic uncompressed samples: exact byte matches against archive offsets.
- Four negative parser cases: rejected unknown index type, truncated index,
  out-of-range payload and unresolved path hash.
- Five Negotiations GIZ carriers: bounded outer parsing reaches exact EOF.
- Original executable SHA-256 unchanged after unpacking/analysis; all seven DAT
  hashes are recorded in reports/source-sha256.json.
- REA evidence exported and session closed successfully with a saved snapshot:
    reports/rea-evidence-bundle.json      23 evidence records
    reports/rea-analysis.snapshot.json  saved query/evidence state
    reports/rea/                        individual responses and tool schemas
  The snapshot is REA's saved analysis state, not an exported editable Ghidra project.
  A fresh provider session may still need to import/analyze the binary.

No running-game validation was performed. Extracted-file sizes and spot comparisons
do not establish semantic correctness for every compressed asset. The reports
separate observed facts, interpretations and unresolved questions.

REPRODUCING LOCAL CHECKS
Run these commands in PowerShell from the SW workspace root. Node.js must be on PATH.
Paths are quoted where needed. Extraction keeps existing output files; it does not
write to the original archives.

 # Regenerate all index reports, check extracted coverage and run parser tests:
 node reverse-engineering/tools/verify.mjs

 # Re-run the focused asset analysis:
 node reverse-engineering/reports/analyze-assets.mjs

 # Inspect the outer chunks of one GIZ file:
 node reverse-engineering/reports/inspect-giz.mjs "reverse-engineering/extracted/LEVELS/EPISODE_I/NEGOTIATIONS/NEGOTIATIONS_A/NEGOTIATIONS_A.GIZ"

 # Re-extract GAME.DAT or the selected Negotiations graphics:
 node reverse-engineering/tools/extract.mjs GAME.DAT
 node reverse-engineering/tools/extract.mjs EPISODE_I.DAT "{}NEGOTIATIONS{}"

 # Inspect PE headers, imports, ASCII strings and candidate dispatch records:
 node reverse-engineering/tools/inspect-pe.mjs "reverse-engineering/binary/LEGOStarWarsSaga.packed.exe.unpacked.exe" "reverse-engineering/reports/unpacked-pe"

 # Run the workspace-local REA launcher (sets local JDK/Ghidra environment):
 .\reverse-engineering\tools\Invoke-Rea.ps1 --help

REA was not registered globally in Codex or other application configuration. The
local launcher can run its MCP server with the mcp argument. A connected REA client
can reopen the unpacked binary with provider_id "ghidra" and snapshot_path pointing
to reports/rea-analysis.snapshot.json. Preserve the recorded binary hash; addresses
and saved results refer specifically to that file. The scripts and requests used
in this pass are retained in tools/rea-session.mjs and rea-queue/*.done.json.

TOOL/REFERENCE PROVENANCE

REA workflow and local package (6.4.0):
 https://github.com/morluto/rea
 tools/rea/node_modules/rea-agents/skills/reverse-engineer-anything/SKILL.md
Windows Ghidra provider notes:
 https://github.com/morluto/rea/blob/main/docs/windows-ghidra-p0.md
Ghidra (12.1.4): https://github.com/NationalSecurityAgency/ghidra
Temurin JDK (21.0.12.1+1): https://github.com/adoptium/temurin21-binaries
QuickBMS (0.12.0) / ttgames.bms (0.9.11a):
 https://aluigi.altervista.org/quickbms.htm
 https://aluigi.altervista.org/bms/ttgames.bms
Steamless (3.1.0.5): https://github.com/atom0s/Steamless
Microsoft XINPUT_GAMEPAD layout:
 https://learn.microsoft.com/en-us/windows/win32/api/xinput/ns-xinput-xinput_gamepad

Release metadata and source references are retained under references/. Download
hash verification for Ghidra/JDK is in reports/tool-download-verification.json.
OpenSaga and BrickVault were examined as external leads. OpenSaga targets a different
Android x86 build; its symbols/layouts cannot be assumed to match this PC binary.
Neither project supplies proof of our observed PC layouts or a completed port here.
 https://github.com/opensagadev/saga
 https://github.com/connorh315/BrickVault

NEXT REVERSE-ENGINEERING WORK, IN ORDER

1. Finish one small graphics sample: Negotiations A GSC and Qui-Gon GHG. Decode
   VBIB vertex/index layouts and instance transforms; correlate materials/textures,
   bounds and names. Validate ranges and produce a viewable geometry export.
2. Decode one skeleton and one AN3/BSA animation pair, including hierarchy, bind
   transforms and skin weights. Check the reconstructed pose numerically/visually.
3. Follow 0x006dae50 and the configuration used by 0x006d7d80 to recover default
   logical action bindings. Reconstruct 0x006d4880 from assembly to settle analog
   filtering; then trace movement vectors into character control.
4. Trace regular follow-camera and rendering/frustum use, plus camera-related
   scripting, to determine dependencies beyond the known CameraCut path.
5. Decode collision/navigation and GIZ payloads, then tie script commands and flow
   graph nodes to native evaluators. Use a small runtime trace to verify timing,
   movement units and loading assumptions before expanding to further levels.

These are the remaining investigations, not implemented features. The eventual
Unity/Quest tabletop concept remains a later application of the recovered behavior.
