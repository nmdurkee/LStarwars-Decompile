/* Ghidra analysis pseudocode, not original source.
 * ev_0d221f2c9357ed308f9b597510bd130964f67481868d3ff45e1443ef5eb3d7b9
 * Entry: 0x621900; label: FUN_00621900
 */

void FUN_00621900(undefined4 *param_1)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  undefined4 local_4;
  
  FUN_006216f0(&local_4,4);
  puVar2 = param_1;
  if (DAT_02912f48 != 0) {
    uVar1 = (undefined1)local_4;
    uVar3 = local_4._1_1_;
    local_4._0_2_ = CONCAT11(local_4._2_1_,local_4._3_1_);
    local_4 = CONCAT13(uVar1,CONCAT12(uVar3,(undefined2)local_4));
  }
  *param_1 = local_4;
  FUN_006216f0(&param_1,4);
  if (DAT_02912f48 != 0) {
    uVar1 = param_1._0_1_;
    uVar3 = param_1._1_1_;
    param_1._0_2_ = CONCAT11(param_1._2_1_,param_1._3_1_);
    param_1._0_3_ = CONCAT12(uVar3,param_1._0_2_);
    param_1 = (undefined4 *)CONCAT13(uVar1,param_1._0_3_);
  }
  puVar2[1] = param_1;
  FUN_006216f0(&param_1,4);
  if (DAT_02912f48 != 0) {
    uVar1 = param_1._0_1_;
    uVar3 = param_1._1_1_;
    param_1._0_2_ = CONCAT11(param_1._2_1_,param_1._3_1_);
    param_1._0_3_ = CONCAT12(uVar3,param_1._0_2_);
    param_1 = (undefined4 *)CONCAT13(uVar1,param_1._0_3_);
  }
  puVar2[2] = param_1;
  return;
}

