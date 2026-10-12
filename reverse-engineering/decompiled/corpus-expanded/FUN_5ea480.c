/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5ea480; label: FUN_005ea480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005ea480(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 local_4;
  
  iVar4 = 0;
  local_4 = 0;
  if (*param_1 == 0) {
    return 0;
  }
  iVar1 = *(int *)(*param_1 + 0x110);
  piVar2 = *(int **)(param_1[2] + 0xb0);
  if (0 < *piVar2) {
    do {
      iVar3 = *(int *)(*(int *)(iVar1 + 0x50) + *(int *)(piVar2[1] + iVar4 * 4) * 4);
      if (iVar3 == 0) {
        return local_4;
      }
      local_4 = 1;
      do {
        *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xfffffff1 | 1;
        FUN_00601030(iVar3);
        *(short *)(iVar3 + 0x2c0) = *(short *)(iVar3 + 0x2c0) + 1;
        iVar3 = *(int *)(iVar3 + 0x30);
      } while (iVar3 != 0);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *piVar2);
  }
  return local_4;
}

