/* Ghidra pseudocode, not original source.
 * ev_df1722bf86f416057db1e0e925a798d75462d70944199476382a8f5b3ee202ce
 * Entry: 0x621520; label: FUN_00621520
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00621520(undefined4 param_1)

{
  undefined1 uVar1;
  undefined4 local_4;
  
  local_4 = param_1;
  if (DAT_02912f48 != 0) {
    local_4._2_1_ = (undefined1)((uint)param_1 >> 0x10);
    local_4._1_1_ = (undefined1)((uint)param_1 >> 8);
    uVar1 = local_4._1_1_;
    local_4._0_2_ = CONCAT11(local_4._2_1_,param_1._3_1_);
    local_4 = CONCAT13((char)param_1,CONCAT12(uVar1,(undefined2)local_4));
  }
  FUN_00621440(&local_4,4);
  return;
}

