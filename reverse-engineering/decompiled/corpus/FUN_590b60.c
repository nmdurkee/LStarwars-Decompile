/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x590b60; label: FUN_00590b60
 */

int FUN_00590b60(int param_1)

{
  int *piVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  
  piVar1 = *(int **)(param_1 + 0x46a8);
  iVar2 = 0;
  if (((piVar1 != (int *)0x0) && (*piVar1 != 0)) &&
     (uVar4 = (uint)*(ushort *)(piVar1 + 1), uVar4 != 0)) {
    puVar3 = (ushort *)(*piVar1 + 0x56);
    do {
      iVar2 = iVar2 + (uint)*puVar3;
      puVar3 = puVar3 + 0x3e;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return iVar2;
}

