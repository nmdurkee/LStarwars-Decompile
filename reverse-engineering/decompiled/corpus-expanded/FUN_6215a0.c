/* Ghidra pseudocode, not original source.
 * ev_df1722bf86f416057db1e0e925a798d75462d70944199476382a8f5b3ee202ce
 * Entry: 0x6215a0; label: FUN_006215a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006215a0(ushort param_1)

{
  if (DAT_02912f48 != 0) {
    param_1 = CONCAT11((char)param_1,(char)(param_1 >> 8));
  }
  _param_1 = (uint)param_1;
  FUN_00621440(&param_1,2);
  return;
}

