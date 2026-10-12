/* Ghidra analysis pseudocode, not original source.
 * ev_82de32114f0a758998fb1b139028178946084d97602e6dd81f3d90db1eb3e6aa
 * Entry: 0x5adf80; label: FUN_005adf80
 */

int FUN_005adf80(int param_1)

{
  int *piVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  
  piVar1 = *(int **)(param_1 + 0x46b8);
  iVar2 = 0;
  if (((piVar1 != (int *)0x0) && (*piVar1 != 0)) &&
     (uVar4 = (uint)*(ushort *)(piVar1 + 2), uVar4 != 0)) {
    puVar3 = (ushort *)(*piVar1 + 0x10c);
    do {
      iVar2 = iVar2 + (uint)*puVar3;
      puVar3 = puVar3 + 0x9e;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return iVar2;
}

