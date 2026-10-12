/* Ghidra analysis pseudocode, not original source.
 * ev_8e49f0d7b7d603436767358480d73156eb2c225a9905dada8633f81c37eed0ad
 * Entry: 0x426b50; label: FUN_00426b50
 */

undefined * FUN_00426b50(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_EDI;
  
  iVar4 = 0;
  iVar3 = -1;
  piVar1 = &DAT_008569dc;
  iVar2 = 0;
  do {
    if (((char)piVar1[1] == '\0') || (*piVar1 != unaff_EDI)) {
      if (iVar3 == -1) {
        iVar3 = iVar2;
      }
    }
    else {
      iVar4 = iVar4 + 1;
      if (iVar4 == 3) {
        return (undefined *)0x0;
      }
    }
    piVar1 = piVar1 + 0xe;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x856c0c);
  if (iVar3 == -1) {
    return (undefined *)0x0;
  }
  return &DAT_008569b8 + iVar3 * 0x38;
}

