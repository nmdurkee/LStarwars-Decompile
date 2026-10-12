/* Ghidra analysis pseudocode, not original source.
 * ev_b9433c7f5b60e61c8ae549a75e6ee409cf02164bae1bfdd2a40ff6f2bd4737bb
 * Entry: 0x566da0; label: FUN_00566da0
 */

int FUN_00566da0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  if ((*(int *)(param_1 + 0x50c8) != 0) && (iVar3 = *(int *)(param_1 + 0x50c0), 0 < iVar3)) {
    piVar2 = (int *)(*(int *)(param_1 + 0x50c8) + 0xa0);
    do {
      iVar1 = iVar1 + (int)*(char *)((int)piVar2 + 0x6d) * *piVar2;
      piVar2 = piVar2 + 0x45;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar1;
}

