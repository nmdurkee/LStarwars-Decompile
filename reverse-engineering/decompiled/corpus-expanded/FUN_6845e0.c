/* Ghidra pseudocode, not original source.
 * ev_8f65dc07aca5ead6ac5de11150d58420913a4b73213f2c7b5665ab54197e4ce2
 * Entry: 0x6845e0; label: FUN_006845e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006845e0(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int local_4;
  
  iVar2 = 0;
  if (0 < DAT_02962094) {
    iVar3 = 0;
    do {
      sVar1 = *(short *)(iVar3 + 0x182 + DAT_029620a4);
      if ((sVar1 != 0) && (*(char *)(*(int *)(DAT_0296209c + sVar1 * 4) + 0x2f1) == '\x04')) {
        local_4 = iVar2;
        FUN_00684400(&local_4);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x330;
    } while (iVar2 < DAT_02962094);
  }
  return;
}

