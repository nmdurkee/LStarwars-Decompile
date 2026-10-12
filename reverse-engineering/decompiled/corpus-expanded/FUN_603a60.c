/* Ghidra pseudocode, not original source.
 * ev_a67b1d7875d7de5d33c5f2e23ff7bb43dcd4ff34aaa1a90d4ca40378ea72f78c
 * Entry: 0x603a60; label: FUN_00603a60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00603a60(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = 0;
  param_1 = param_1 + 1;
  if (0 < iVar1) {
    do {
      if (7 < iVar2) {
        return;
      }
      FUN_00741300(0x4e,iVar2,param_1);
      iVar2 = iVar2 + 1;
      param_1 = param_1 + 4;
    } while (iVar2 < iVar1);
  }
  return;
}

