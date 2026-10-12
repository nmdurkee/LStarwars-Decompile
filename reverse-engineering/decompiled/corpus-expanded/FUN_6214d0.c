/* Ghidra pseudocode, not original source.
 * ev_df1722bf86f416057db1e0e925a798d75462d70944199476382a8f5b3ee202ce
 * Entry: 0x6214d0; label: FUN_006214d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006214d0(undefined4 param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  
  if (DAT_02912f48 != 0) {
    uVar1 = (undefined1)param_1;
    uVar2 = param_1._1_1_;
    param_1._0_2_ = CONCAT11(param_1._2_1_,param_1._3_1_);
    param_1 = CONCAT13(uVar1,CONCAT12(uVar2,(undefined2)param_1));
  }
  FUN_00621440(&param_1,4);
  return;
}

