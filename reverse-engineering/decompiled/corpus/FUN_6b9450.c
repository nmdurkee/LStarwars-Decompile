/* Ghidra analysis pseudocode, not original source.
 * ev_7ed3362792c3ecc1c7f2b3fdd5b033605c88aa142786b47e04128bf45777c493
 * Entry: 0x6b9450; label: FUN_006b9450
 */

void FUN_006b9450(void)

{
  int iVar1;
  int iVar2;
  
  if (0 < DAT_02973bac) {
    iVar1 = 0;
    iVar2 = 0;
    do {
      if (*(int *)(iVar1 + 0x14 + DAT_02973b90) != 0) {
        (**(code **)(**(int **)(iVar1 + 0x14 + DAT_02973b90) + 0x5c))();
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x18;
    } while (iVar2 < DAT_02973bac);
  }
  return;
}

