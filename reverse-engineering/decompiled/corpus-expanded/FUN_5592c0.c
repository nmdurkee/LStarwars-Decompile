/* Ghidra pseudocode, not original source.
 * ev_f8ed381e2b466dd5bc773ab3f84ab60966b69e10a49b3e28fcf3f54e00ea1563
 * Entry: 0x5592c0; label: FUN_005592c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005592c0(int param_1)

{
  int *piVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  
  piVar1 = *(int **)(param_1 + 0x46a4);
  iVar2 = 0;
  if (((piVar1 != (int *)0x0) && (*piVar1 != 0)) &&
     (uVar4 = (uint)*(ushort *)(piVar1 + 2), uVar4 != 0)) {
    puVar3 = (ushort *)(*piVar1 + 0x8a);
    do {
      iVar2 = iVar2 + (uint)*puVar3;
      puVar3 = puVar3 + 0x50;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return iVar2;
}

