/* Ghidra pseudocode, not original source.
 * ev_fb4a243913288e8884e4b26b9d3f1b2cc90d3774ba2cd7b272b490162dad9d99
 * Entry: 0x468740; label: FUN_00468740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00468740(int param_1)

{
  int *piVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  
  piVar1 = *(int **)(param_1 + 0x46ac);
  iVar2 = 0;
  if (((piVar1 != (int *)0x0) && (*piVar1 != 0)) &&
     (uVar4 = (uint)*(ushort *)((int)piVar1 + 0xe), uVar4 != 0)) {
    puVar3 = (ushort *)(*piVar1 + 0x8a);
    do {
      iVar2 = iVar2 + (uint)*puVar3;
      puVar3 = puVar3 + 0x52;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return iVar2;
}

