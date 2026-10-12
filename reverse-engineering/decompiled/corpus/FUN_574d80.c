/* Ghidra analysis pseudocode, not original source.
 * ev_9251851307bb379bfc9bcabd13d9f753a758e856e200aa29981eaf91127b618c
 * Entry: 0x574d80; label: FUN_00574d80
 */

int FUN_00574d80(int param_1)

{
  short sVar1;
  int iVar2;
  
  if (DAT_00951370 != 0) {
    iVar2 = 0;
    sVar1 = *DAT_00951374;
    while ((sVar1 != -1 && (iVar2 < 0x40))) {
      if (DAT_00951374[iVar2 * 2] == param_1) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      sVar1 = DAT_00951374[iVar2 * 2];
    }
  }
  return 0xff;
}

