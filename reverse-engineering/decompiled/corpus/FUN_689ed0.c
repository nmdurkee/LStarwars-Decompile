/* Ghidra analysis pseudocode, not original source.
 * ev_58caf276ebc048efa4d646f9d9307ba49b402b8a20e2023011e3c4448b71b628
 * Entry: 0x689ed0; label: FUN_00689ed0
 */

void FUN_00689ed0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_00689e70(param_1);
  iVar3 = 0;
  if (0 < DAT_02962a08) {
    iVar1 = 0;
    iVar2 = DAT_02962a14;
    do {
      if ((*(int *)(iVar1 + 4 + iVar2) != 0) && (*(char *)(iVar1 + 0x24 + iVar2) == (char)param_1))
      {
        if (*(char *)(iVar1 + 0x27 + iVar2) == '\x03') {
          *(undefined4 *)(DAT_02962a1c + *(short *)(iVar1 + 0x40 + iVar2) * 4) = 0;
          DAT_02962a20 = DAT_02962a20 + -1;
          iVar2 = DAT_02962a14;
        }
        *(undefined4 *)(iVar1 + 4 + iVar2) = 0;
        DAT_029629e0 = DAT_029629e0 + -1;
        iVar2 = DAT_02962a14;
      }
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + 0x50;
    } while (iVar3 < DAT_02962a08);
  }
  iVar3 = (int)(char)param_1;
  (&DAT_02920acc)[iVar3] = 0;
  *(undefined4 *)(&DAT_02961f54 + iVar3 * 4) = 0;
  *(undefined4 *)(&DAT_0292fce8 + iVar3 * 4) = 0;
  (&DAT_0292fd10)[iVar3] = 0;
  (&DAT_0292fc0c)[iVar3] = 0;
  return;
}

