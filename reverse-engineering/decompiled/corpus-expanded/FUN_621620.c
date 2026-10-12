/* Ghidra pseudocode, not original source.
 * ev_df1722bf86f416057db1e0e925a798d75462d70944199476382a8f5b3ee202ce
 * Entry: 0x621620; label: FUN_00621620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00621620(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  undefined1 uVar4;
  
  puVar3 = param_1;
  uVar1 = *param_1;
  param_1 = (undefined4 *)uVar1;
  if (DAT_02912f48 != 0) {
    param_1._0_1_ = (undefined1)uVar1;
    uVar2 = param_1._0_1_;
    param_1._3_1_ = (undefined1)((uint)uVar1 >> 0x18);
    param_1._2_1_ = (undefined1)((uint)uVar1 >> 0x10);
    param_1._1_1_ = (undefined1)((uint)uVar1 >> 8);
    uVar4 = param_1._1_1_;
    param_1._0_2_ = CONCAT11(param_1._2_1_,param_1._3_1_);
    param_1._0_3_ = CONCAT12(uVar4,param_1._0_2_);
    param_1 = (undefined4 *)CONCAT13(uVar2,param_1._0_3_);
  }
  FUN_00621440(&param_1,4);
  uVar1 = puVar3[1];
  param_1 = (undefined4 *)uVar1;
  if (DAT_02912f48 != 0) {
    param_1._0_1_ = (undefined1)uVar1;
    uVar2 = param_1._0_1_;
    param_1._3_1_ = (undefined1)((uint)uVar1 >> 0x18);
    param_1._2_1_ = (undefined1)((uint)uVar1 >> 0x10);
    param_1._1_1_ = (undefined1)((uint)uVar1 >> 8);
    uVar4 = param_1._1_1_;
    param_1._0_2_ = CONCAT11(param_1._2_1_,param_1._3_1_);
    param_1._0_3_ = CONCAT12(uVar4,param_1._0_2_);
    param_1 = (undefined4 *)CONCAT13(uVar2,param_1._0_3_);
  }
  FUN_00621440(&param_1,4);
  uVar1 = puVar3[2];
  param_1 = (undefined4 *)uVar1;
  if (DAT_02912f48 != 0) {
    param_1._0_1_ = (undefined1)uVar1;
    uVar2 = param_1._0_1_;
    param_1._3_1_ = (undefined1)((uint)uVar1 >> 0x18);
    param_1._2_1_ = (undefined1)((uint)uVar1 >> 0x10);
    param_1._1_1_ = (undefined1)((uint)uVar1 >> 8);
    uVar4 = param_1._1_1_;
    param_1._0_2_ = CONCAT11(param_1._2_1_,param_1._3_1_);
    param_1._0_3_ = CONCAT12(uVar4,param_1._0_2_);
    param_1 = (undefined4 *)CONCAT13(uVar2,param_1._0_3_);
  }
  FUN_00621440(&param_1,4);
  return;
}

