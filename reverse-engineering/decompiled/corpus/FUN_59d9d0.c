/* Ghidra analysis pseudocode, not original source.
 * ev_0d1e553906e4ac29f0c898728bb3c9cf38177ab98ca2cbcdea8e6b852723dd83
 * Entry: 0x59d9d0; label: FUN_0059d9d0
 */

int FUN_0059d9d0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != param_1) {
    iVar2 = 0;
    if (*(char *)(param_2 + 2) != '\0') {
      do {
        iVar1 = *(int *)(*(int *)(param_2 + 0x14) + iVar2 * 4);
        if (*(char *)(iVar1 + 9) != (char)param_4) {
          *(char *)(iVar1 + 9) = (char)param_4;
          param_3 = FUN_0059d9d0(param_1,*(undefined4 *)(*(int *)(param_2 + 0x14) + iVar2 * 4),
                                 param_3,param_4);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)(uint)*(byte *)(param_2 + 2));
    }
    return param_3;
  }
  *(char *)(param_2 + 9) = *(char *)(param_2 + 9) + -1;
  return param_3 + 1;
}

