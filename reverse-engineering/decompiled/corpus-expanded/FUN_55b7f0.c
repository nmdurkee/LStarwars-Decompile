/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55b7f0; label: FUN_0055b7f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055b7f0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((DAT_0093b270 != 0) && (iVar3 = 0, iVar2 = DAT_0093b270, 0 < DAT_0093b278)) {
    do {
      iVar1 = *(int *)(iVar2 + iVar3 * 4);
      if (iVar1 != 0) {
        FUN_005ef880(iVar1);
        iVar2 = DAT_0093b270;
        *(undefined4 *)(DAT_0093b270 + iVar3 * 4) = 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_0093b278);
  }
  return;
}

