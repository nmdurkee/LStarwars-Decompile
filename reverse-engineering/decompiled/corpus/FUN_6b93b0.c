/* Ghidra analysis pseudocode, not original source.
 * ev_7ed3362792c3ecc1c7f2b3fdd5b033605c88aa142786b47e04128bf45777c493
 * Entry: 0x6b93b0; label: FUN_006b93b0
 */

void FUN_006b93b0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < DAT_02973bac) {
    iVar1 = 0;
    do {
      if (*(int *)(iVar1 + 0x14 + DAT_02973b90) != 0) {
        (**(code **)(**(int **)(iVar1 + 0x14 + DAT_02973b90) + 0x54))(param_1,param_2);
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x18;
    } while (iVar2 < DAT_02973bac);
  }
  return;
}

