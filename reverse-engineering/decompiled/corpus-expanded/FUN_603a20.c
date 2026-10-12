/* Ghidra pseudocode, not original source.
 * ev_a67b1d7875d7de5d33c5f2e23ff7bb43dcd4ff34aaa1a90d4ca40378ea72f78c
 * Entry: 0x603a20; label: FUN_00603a20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00603a20(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = param_1 + 2;
  iVar3 = (int)(*param_1 + 3 + (*param_1 + 3 >> 0x1f & 3U)) >> 2;
  iVar2 = 0;
  if (0 < iVar3) {
    do {
      if (0x1f < iVar2) {
        return;
      }
      FUN_00741300(0x4f,iVar2,piVar1);
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 4;
    } while (iVar2 < iVar3);
  }
  return;
}

