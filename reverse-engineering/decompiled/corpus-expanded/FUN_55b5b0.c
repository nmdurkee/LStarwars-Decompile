/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55b5b0; label: FUN_0055b5b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055b5b0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0x2980) != 0) && (iVar3 = 0, 0 < DAT_0093b278)) {
    iVar2 = 0;
    do {
      iVar1 = *(int *)(iVar2 + *(int *)(param_1 + 0x2980));
      if (iVar1 != 0) {
        FUN_005ef880(iVar1);
      }
      *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x2980)) = 0;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x10;
    } while (iVar3 < DAT_0093b278);
  }
  return;
}

