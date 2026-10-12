/* Ghidra pseudocode, not original source.
 * ev_5fa8a0c629ff9dcf3dc3d25725019308ff1f1a9e08c812d6ee08209fa3308603
 * Entry: 0x6558f0; label: FUN_006558f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006558f0(void)

{
  int iVar1;
  int iVar2;
  int local_4;
  
  iVar1 = 0;
  if (0 < DAT_02962094) {
    iVar2 = 0;
    do {
      if (*(short *)(iVar2 + 0x182 + DAT_029620a4) != 0) {
        local_4 = iVar1;
        FUN_006553f0(&local_4);
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x330;
    } while (iVar1 < DAT_02962094);
  }
  return;
}

