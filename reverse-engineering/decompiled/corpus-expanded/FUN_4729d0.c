/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x4729d0; label: FUN_004729d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004729d0(int param_1)

{
  undefined2 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = *(int **)(param_1 + 0x5074);
  if ((piVar2 != (int *)0x0) && (iVar3 = 0, 0 < *piVar2)) {
    iVar4 = 0;
    do {
      uVar1 = FUN_0067c4f0(piVar2[3] + iVar4,2);
      *(undefined2 *)(*(int *)(*(int *)(param_1 + 0x5074) + 0xc) + 0x80 + iVar4) = uVar1;
      FUN_0067c7b0((int)*(short *)(*(int *)(*(int *)(param_1 + 0x5074) + 0xc) + 0x80 + iVar4),1);
      piVar2 = *(int **)(param_1 + 0x5074);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0xa0;
    } while (iVar3 < *piVar2);
  }
  return;
}

