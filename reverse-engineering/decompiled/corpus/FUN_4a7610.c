/* Ghidra analysis pseudocode, not original source.
 * ev_5c5e85395afb46ea48eeeced9462a622408ed7e413dd4eac1252ab90af09b35e
 * Entry: 0x4a7610; label: FUN_004a7610
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a7610(int param_1)

{
  float fVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x7b5) == '3') {
    if ((*(char *)(param_1 + 0x281) == '\0') ||
       (iVar2 = FUN_004a7490(param_1,(int)*(char *)(param_1 + 0x285)), iVar2 == 0)) {
      if (0.0 < *(float *)(param_1 + 0x784)) {
        fVar1 = *(float *)(param_1 + 0x784) - _DAT_00925018;
        *(float *)(param_1 + 0x784) = fVar1;
        if (fVar1 < 0.0 != (fVar1 == 0.0)) {
          *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        }
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x784) = 0x3e800000;
    }
    if (*(char *)(param_1 + 0x281) != '\0') {
      FUN_00681f40("Char_Slide_Lp",param_1 + 0x19c);
      return;
    }
  }
  else {
    FUN_004a74e0(param_1,1);
  }
  return;
}

