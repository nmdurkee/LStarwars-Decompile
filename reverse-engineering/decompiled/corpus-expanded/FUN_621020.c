/* Ghidra pseudocode, not original source.
 * ev_8a909e0f7cdee8f131d9fa101a03e4afa99ad6c03186a84914f93ab3f48399ec
 * Entry: 0x621020; label: FUN_00621020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00621020(int param_1)

{
  *(uint *)(PTR_DAT_0080f7ec + 0x90) =
       *(uint *)(PTR_DAT_0080f7ec + 0x90) ^
       (param_1 << 6 ^ *(uint *)(PTR_DAT_0080f7ec + 0x90)) & 0x40;
  return;
}

