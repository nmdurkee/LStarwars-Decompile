/* Ghidra pseudocode, not original source.
 * ev_df1722bf86f416057db1e0e925a798d75462d70944199476382a8f5b3ee202ce
 * Entry: 0x621b40; label: FUN_00621b40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00621b40(int param_1,undefined4 param_2)

{
  FUN_004f2740(param_2," %.2d/%.2d/%d %.2d:%.2d:%.2d",*(byte *)(param_1 + 4) - 0x41,
               *(byte *)(param_1 + 5) - 0x41,*(byte *)(param_1 + 6) + 0x77b,
               *(byte *)(param_1 + 3) - 0x41,*(byte *)(param_1 + 2) - 0x41,
               *(byte *)(param_1 + 1) - 0x41);
  return;
}

