/* Ghidra analysis pseudocode, not original source.
 * ev_9251851307bb379bfc9bcabd13d9f753a758e856e200aa29981eaf91127b618c
 * Entry: 0x574d00; label: FUN_00574d00
 */

int FUN_00574d00(int param_1)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = 0;
  if (0 < DAT_00951360) {
    psVar2 = (short *)(DAT_00951354 + 0x8a);
    do {
      if (*psVar2 == param_1) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 0x4e;
    } while (iVar1 < DAT_00951360);
  }
  return -1;
}

