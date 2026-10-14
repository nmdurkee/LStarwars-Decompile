# LEGO Star Wars: The Complete Saga — reconstruction checkpoint

Reverse-engineering research for the PC x86 game, with an eventual Unity / Quest 3 tabletop mixed-reality adaptation in mind. Current work is source and behavior recovery. This repository is **not the original source code, a complete game, or a Unity project**.

## Current checkpoint

- 14,704 native entries cataloged from retained decompiler profiles and independently verified callback boundaries.
- 1291 native entries mapped to bounded portable implementations in 604 C# core files, across combat, animation, gameplay, geometry, frame transitions, controller input, and navigation.
- 19,579 of 20,836 cataloged script-command uses have bounded native contracts (94.0%). This does not imply equivalent whole-game behavior.
- The integrated C# library and verifier compile. Every core source hash matches the recorded build.
- Original-function tests run in isolated x86 emulation with each suite's adapters documented. These are separate from executing the reconstructed C#.
- The initial combat C# subset passed 14,553 comparisons. Windows currently denies launching newly generated verification executables, so later managed comparisons remain pending.
- Seven archives and 12,459 extracted files were previously independently verified. Original game files remain local.

Counts measure recorded work, **not a percentage of game completion**. Many mapped routines are deliberately limited branches or projections.

## Start here

- [2026-10-14 checkpoint: 8.78% catalog mapping coverage](reverse-engineering/reports/checkpoint-20261014-progress.txt)
- [Stopping checkpoint and progress report](reverse-engineering/reports/reverse-stop-20261013-progress.txt)
- [Latest integrated batch and independent audit](reverse-engineering/reports/reverse-phase15-20261013-summary.txt)
- [Earlier 2026-10-13 recovery batch](reverse-engineering/reports/reverse-engineering-20261013-summary.txt)

- [Current source coverage and gaps](reverse-engineering/reports/source-completion.txt)
- [Analysis overview](reverse-engineering/README.txt)
- [Recovered source build and verification](reverse-engineering/reconstructed/README.txt)
- [Source-to-native mappings](reverse-engineering/reconstructed/source-manifest.json)
- [Investigation ledger](reverse-engineering/INVESTIGATION.json)
- [Latest checkpoint](reverse-engineering/reports/recovery-checkpoint.json)
- [Compilation versus execution status](reverse-engineering/reports/reconstructed-execution-status.json)

The main remaining work includes complete world/level loading, integrated character/combat behavior, outstanding script commands, complete scene visibility integration, renderer and audio backends, and whole-game behavioral validation. Unity and Quest implementation has not begun.

## Restore the evidence after cloning

Large evidence files are stored as ordinary gzip files under checkpoint-artifacts/ to keep every individual Git object below GitHub's normal file limit. Restore them using Python 3.10 or newer, from the repository root:

~~~powershell
python reverse-engineering/tools/publish-evidence.py --restore
~~~

The [artifact manifest](checkpoint-artifacts/manifest.json) records original and compressed SHA-256 hashes. Restoration verifies both and refuses to overwrite a differing local file. Restored evidence files are ignored by Git; their compressed copies are tracked.

## Build the portable fragments

On Windows with the .NET Framework C# compiler installed, invoke the compiler directly with Node:

~~~powershell
node reverse-engineering/reconstructed/build.mjs
~~~

Or use the PowerShell script where script execution is permitted:

~~~powershell
Set-Location reverse-engineering
& .\reconstructed\build.ps1
& .\reconstructed\verify.ps1 -Module all
~~~

The first command builds the library and verifier without launching the game. The second runs managed comparisons against saved native fixtures; it is still blocked by executable-launch restrictions in the original research environment. No security-setting workaround is included.

For the native Python fixtures, install capstone 5.0.9 and unicorn 2.1.4. Image and geometry analysis additionally use Pillow and NumPy. Node-based tools retain package manifests and lockfiles under tools/rea/ and tools/geometry-validation/. Most analysis commands expect the original local layout described in reverse-engineering/README.txt.

## Repository contents

- reverse-engineering/reconstructed/: portable source and verification harnesses.
- reverse-engineering/decompiled/: Ghidra pseudocode, explicitly labeled as generated rather than original source.
- reverse-engineering/tools/: parsers, extractors, native fixtures, validation and reporting scripts.
- reverse-engineering/reports/: findings, provenance, inventories, behavioral contracts and validation results.
- checkpoint-artifacts/: losslessly compressed large evidence and a path/size inventory of omitted local artifacts.

Installed game executables/archives, extracted assets, generated models/textures, downloaded tool installations, dependency caches, and compiled build outputs stay local. The repository retains the tools and evidence needed to reproduce or audit that work; it does not package a playable game. Preserved report paths may refer to the original Windows workspace. Evidence identifiers and source hashes are kept unchanged.

REA was the initial analysis toolkit: https://github.com/morluto/rea. External tools and reference snippets retain their own provenance and rights. This checkpoint does not assert ownership of the original game or license its content.

Local recovery snapshot7:738 distinct mapped entries,207 core files and212 harness files compile.167 bounded command names cover19,231 authored uses. [Independent audit](reverse-engineering/reports/reverse-phase7-20261013-audit.json) passed2,599 additional checks. [Snapshot details](reverse-engineering/reports/reverse-phase7-20261013-summary.txt). Managed replay and whole-game completion remain open; local work continues.

Local recovery snapshot8:744 distinct mapped entries in212 core files with217 harnesses compile.170 bounded command names cover19,286 uses. [Audit](reverse-engineering/reports/reverse-phase8-20261013-audit.json) passed1,350 additional checks. [Snapshot](reverse-engineering/reports/reverse-phase8-20261013-summary.txt). Managed replay and whole-game recovery remain open; work continues locally.

Local recovery snapshot9:760 mapped entries,217 cores and222 harnesses compile.176 bounded command names cover19,381 uses. [Audit](reverse-engineering/reports/reverse-phase9-20261013-audit.json) passed1,244 additional checks. [Snapshot](reverse-engineering/reports/reverse-phase9-20261013-summary.txt). Work continues locally; managed replay and whole-game recovery remain open.

Local recovery snapshot 10: 775 mapped entries in 225 core files and 230 harnesses compile. 189 bounded command names cover 19,533 uses. [Independent audit](reverse-engineering/reports/reverse-phase10-20261013-audit.json) passed 4,849 additional checks. [Snapshot details](reverse-engineering/reports/reverse-phase10-20261013-summary.txt). Local work continues; managed replay and whole-game recovery remain open.
