/* Ghidra analysis pseudocode, not original source.
 * ev_93d7dcfdde9a808337523cfea9e371187d945893e914ed56ca2b2926a7aff66e
 * Entry: 0x62a400; label: FUN_0062a400
 */

int FUN_0062a400(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int extraout_EDX;
  
  DAT_02912eb0 = param_1;
  if (*(int *)(param_1 + 0x3c) == 0) {
    iVar1 = FUN_00629e20(param_1,param_2,param_3);
    return iVar1;
  }
  iVar1 = FUN_0062a400(*(int *)(param_1 + 0x3c),param_2,param_3);
  if (DAT_02912eb0 != 0) {
    if (iVar1 != 0) {
      iVar1 = *(int *)(param_1 + 0x3c);
      if (*(int *)(param_1 + 0x3c) == 0) {
        iVar1 = param_1;
      }
      FUN_006271a0(iVar1);
      return extraout_EDX;
    }
    iVar1 = FUN_00627320(param_1,param_3);
  }
  return iVar1;
}

