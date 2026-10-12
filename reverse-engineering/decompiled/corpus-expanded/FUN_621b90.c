/* Ghidra pseudocode, not original source.
 * ev_df1722bf86f416057db1e0e925a798d75462d70944199476382a8f5b3ee202ce
 * Entry: 0x621b90; label: FUN_00621b90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00621b90(int param_1,undefined4 param_2)

{
  FUN_004f2740(param_2," %.2d:%.2d:%.2d",*(byte *)(param_1 + 3) - 0x41,*(byte *)(param_1 + 2) - 0x41
               ,*(byte *)(param_1 + 1) - 0x41);
  return;
}

