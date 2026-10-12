/* Ghidra analysis pseudocode, not original source.
 * ev_58caf276ebc048efa4d646f9d9307ba49b402b8a20e2023011e3c4448b71b628
 * Entry: 0x689670; label: FUN_00689670
 */

void FUN_00689670(char param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  iVar1 = param_1 * 4;
  if (((&DAT_029211c8)[param_1] != 0) && (*(int *)(&DAT_0292fc3c + iVar1) != 0)) {
    iVar3 = 0;
    pcVar2 = &DAT_02947db4;
    do {
      if (*pcVar2 == param_1) {
        FUN_0065d630(iVar3,*(undefined4 *)(&DAT_0292fc3c + iVar1));
      }
      pcVar2 = pcVar2 + 0x44;
      iVar3 = iVar3 + 1;
    } while ((int)pcVar2 < 0x2948eb4);
  }
  return;
}

