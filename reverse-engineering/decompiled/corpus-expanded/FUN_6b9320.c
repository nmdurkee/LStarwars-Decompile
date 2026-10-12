/* Ghidra pseudocode, not original source.
 * ev_53ad6b1d8bb34752a747640de0a0339f355d943428ba011e4ade8e8202156388
 * Entry: 0x6b9320; label: FUN_006b9320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b9320(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_02973bac) {
    iVar2 = 0;
    iVar1 = DAT_02973b90;
    do {
      if (*(int *)(iVar2 + 0x14 + iVar1) != 0) {
        (**(code **)(**(int **)(iVar2 + 0x14 + iVar1) + 0x44))();
        iVar1 = DAT_02973b90;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x18;
    } while (iVar3 < DAT_02973bac);
  }
  return;
}

