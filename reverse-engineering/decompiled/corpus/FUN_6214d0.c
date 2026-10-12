/* Ghidra analysis pseudocode, not original source.
 * ev_0f83c18e3dd08d4f7d4ef8091875e15de78b7d8ec17e52e6723de9bddd8785d9
 * Entry: 0x6214d0; label: FUN_006214d0
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

