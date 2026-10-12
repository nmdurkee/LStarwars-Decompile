/* Ghidra analysis pseudocode, not original source.
 * ev_b9433c7f5b60e61c8ae549a75e6ee409cf02164bae1bfdd2a40ff6f2bd4737bb
 * Entry: 0x56a1a0; label: FUN_0056a1a0
 */

int FUN_0056a1a0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x50c8);
  if (iVar1 != 0) {
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0x50c0)) {
      do {
        if (*(short *)(iVar1 + 0x102) == param_2) {
          return iVar1;
        }
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0x114;
      } while (iVar2 < *(int *)(param_1 + 0x50c0));
    }
  }
  return 0;
}

