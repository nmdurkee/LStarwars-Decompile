/* Ghidra pseudocode, not original source.
 * ev_df1722bf86f416057db1e0e925a798d75462d70944199476382a8f5b3ee202ce
 * Entry: 0x621820; label: FUN_00621820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00621820(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 local_4;
  
  FUN_006216f0(&local_4,4);
  if (DAT_02912f48 != 0) {
    uVar1 = (undefined1)local_4;
    uVar2 = local_4._1_1_;
    local_4._0_2_ = CONCAT11(local_4._2_1_,local_4._3_1_);
    local_4 = CONCAT13(uVar1,CONCAT12(uVar2,(undefined2)local_4));
  }
  return local_4;
}

