/* Ghidra pseudocode, not original source.
 * ev_8a909e0f7cdee8f131d9fa101a03e4afa99ad6c03186a84914f93ab3f48399ec
 * Entry: 0x620070; label: FUN_00620070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00620070(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6)

{
  *(uint *)(PTR_DAT_0080f7ec + 0x90) =
       (((((param_6 & 1) * 2 | param_5 & 1) * 2 | param_4 & 1) * 2 | param_3 & 1) * 2 | param_2 & 1)
       * 2 | param_1 & 1 | *(uint *)(PTR_DAT_0080f7ec + 0x90) & 0xffffffc0;
  return;
}

