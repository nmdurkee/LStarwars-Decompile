/* Ghidra pseudocode, not original source.
 * ev_14412b1be5fe57fadf021e89e905f73790df496cb317f965435f7dd4228acdda
 * Entry: 0x5a1d80; label: FUN_005a1d80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a1d80(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x5034) != 0) && (iVar2 = 0, 0 < *(int *)(param_1 + 0x5038))) {
    iVar1 = 0;
    do {
      FUN_005cfc00(*(int *)(param_1 + 0x5034) + iVar1,0);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x18;
    } while (iVar2 < *(int *)(param_1 + 0x5038));
  }
  return;
}

