/* Ghidra analysis pseudocode, not original source.
 * ev_28935bb75220519b9cd6c8dd2893feffbabc6fed0a1828833445fdd6a861260d
 * Entry: 0x684580; label: FUN_00684580
 */

void FUN_00684580(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_4;
  
  iVar2 = 0;
  if (0 < DAT_02962094) {
    iVar3 = 0;
    iVar1 = DAT_029620a4;
    do {
      if ((*(short *)(iVar3 + 0x182 + iVar1) != 0) && (*(char *)(iVar3 + 0x2f9 + iVar1) != '\0')) {
        local_4 = iVar2;
        FUN_00684400(&local_4);
        iVar1 = DAT_029620a4;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x330;
    } while (iVar2 < DAT_02962094);
  }
  return;
}

