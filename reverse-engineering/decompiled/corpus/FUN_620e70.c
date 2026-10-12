/* Ghidra analysis pseudocode, not original source.
 * ev_0f83c18e3dd08d4f7d4ef8091875e15de78b7d8ec17e52e6723de9bddd8785d9
 * Entry: 0x620e70; label: FUN_00620e70
 */

void FUN_00620e70(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (DAT_02912e88 != 0) {
    if (DAT_02912f38 != 0) {
      iVar1 = FUN_006d6c20(0x38);
      if (iVar1 == 0) {
        FUN_00620bf0(PTR_DAT_0080f7ec,param_2);
        goto LAB_00620eb7;
      }
    }
    FUN_00620870(PTR_DAT_0080f7ec);
  }
LAB_00620eb7:
  if (param_1 != 0) {
    if (DAT_02912f38 == 0) {
      FUN_006204f0(PTR_DAT_0080f7ec);
      return;
    }
    FUN_006200d0(PTR_DAT_0080f7ec,param_2,param_1);
  }
  return;
}

