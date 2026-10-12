/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x5505a0; label: FUN_005505a0
 */

undefined4 FUN_005505a0(undefined4 param_1,float param_2,float param_3)

{
  int iVar1;
  int extraout_ECX;
  
  if (param_3 != 2e+06) {
    if (DAT_0093b0e0 != (code *)0x0) {
      iVar1 = (*DAT_0093b0e0)();
      if (iVar1 == 0) goto LAB_005505c8;
    }
    param_2 = param_3;
  }
LAB_005505c8:
  FUN_0054fa00();
  *(float *)(extraout_ECX + 4) = -*(float *)(extraout_ECX + 4);
  *(float *)(extraout_ECX + 0x14) = -*(float *)(extraout_ECX + 0x14);
  *(float *)(extraout_ECX + 0x24) = -*(float *)(extraout_ECX + 0x24);
  *(float *)(extraout_ECX + 0x34) = param_2 - (*(float *)(extraout_ECX + 0x34) - param_2);
  return 1;
}

