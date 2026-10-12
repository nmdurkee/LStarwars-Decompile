/* Ghidra analysis pseudocode, not original source.
 * ev_b9433c7f5b60e61c8ae549a75e6ee409cf02164bae1bfdd2a40ff6f2bd4737bb
 * Entry: 0x5689f0; label: FUN_005689f0
 */

int FUN_005689f0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((param_2 != 0) && (*(int *)(param_2 + 0x50c4) != 0)) && (*(int *)(param_2 + 0x50bc) != 0)) {
    if ((param_1 != 0) && (iVar3 = 0, 0 < *(int *)(param_2 + 0x50bc))) {
      iVar2 = 0;
      do {
        iVar1 = FUN_004f20f0(*(int *)(param_2 + 0x50c4) + 0xd8 + iVar2,param_1);
        if (iVar1 == 0) {
          return iVar3 * 0x100 + *(int *)(param_2 + 0x50c4);
        }
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x100;
      } while (iVar3 < *(int *)(param_2 + 0x50bc));
    }
    return 0;
  }
  return 0;
}

