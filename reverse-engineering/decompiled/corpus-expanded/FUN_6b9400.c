/* Ghidra pseudocode, not original source.
 * ev_53ad6b1d8bb34752a747640de0a0339f355d943428ba011e4ade8e8202156388
 * Entry: 0x6b9400; label: FUN_006b9400
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b9400(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < DAT_02973bac) {
    iVar1 = 0;
    do {
      if (*(int *)(iVar1 + 0x14 + DAT_02973b90) != 0) {
        (**(code **)(**(int **)(iVar1 + 0x14 + DAT_02973b90) + 0x58))(param_1,param_2);
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x18;
    } while (iVar2 < DAT_02973bac);
  }
  return;
}

