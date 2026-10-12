/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55ce20; label: FUN_0055ce20
 */

int FUN_0055ce20(int param_1,uint param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      if (((((*(uint *)(iVar1 + 0x1fc) & 1) != 0) &&
           ((param_4 == 0 || ((*(uint *)(iVar1 + 0x1fc) & 0x1000) != 0)))) &&
          ((param_2 == 0 || ((*(uint *)(iVar1 + 0x1f8) & param_2) == param_2)))) &&
         (((param_1 == -1 || (*(short *)(iVar1 + 0x1064) == param_1)) &&
          ((param_3 == 0 ||
           ((*(char *)(iVar1 + 0x28b) == '\0' &&
            ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(iVar1 + 0x7b5) * 0x10 + 8) & 0x8000) == 0))))))
         )) {
        if (param_5 == 0) {
          return iVar1;
        }
        if (*(short *)(iVar1 + 0x1070) == -1) {
          return iVar1;
        }
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x10d8;
    } while (iVar2 < DAT_0093d500);
  }
  return 0;
}

