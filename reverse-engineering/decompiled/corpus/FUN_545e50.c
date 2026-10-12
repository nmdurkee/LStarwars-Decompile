/* Ghidra analysis pseudocode, not original source.
 * ev_177857cb78ddb8ad13dc6718881af1dfaef05e8a3811f551bff9ab7ba98e27a8
 * Entry: 0x545e50; label: FUN_00545e50
 */

short * FUN_00545e50(void)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = 0;
  psVar2 = DAT_00924850;
  if (0 < DAT_0092484c) {
    do {
      if (*psVar2 == 0) {
        DAT_00924850[iVar1 * 0x26] = 1;
        return DAT_00924850 + iVar1 * 0x26;
      }
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 0x26;
    } while (iVar1 < DAT_0092484c);
  }
  return (short *)0x0;
}

