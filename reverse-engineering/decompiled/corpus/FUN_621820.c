/* Ghidra analysis pseudocode, not original source.
 * ev_0d221f2c9357ed308f9b597510bd130964f67481868d3ff45e1443ef5eb3d7b9
 * Entry: 0x621820; label: FUN_00621820
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

