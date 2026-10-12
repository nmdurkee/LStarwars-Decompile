/* Ghidra pseudocode, not original source.
 * ev_a67b1d7875d7de5d33c5f2e23ff7bb43dcd4ff34aaa1a90d4ca40378ea72f78c
 * Entry: 0x603980; label: FUN_00603980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00603980(int param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    iVar2 = 0;
    do {
      pcVar1 = (char *)(*(int *)(param_1 + 8) + iVar2);
      if (*pcVar1 == -0x7e) {
        *pcVar1 = -0x7e;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x10;
    } while (iVar3 < *(int *)(param_1 + 4));
  }
  return;
}

