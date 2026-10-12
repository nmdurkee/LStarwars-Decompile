/* Ghidra analysis pseudocode, not original source.
 * ev_3b4ca00fd279b908d0ecc0345d0e63acf8414f1fac0e020351d2be86095d22cc
 * Entry: 0x565ba0; label: FUN_00565ba0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00565ba0(void)

{
  if (DAT_00950740 != '\0') {
    DAT_00950740 = '\0';
    FUN_005d4290(1);
    FUN_005d5220(DAT_0095076c);
    FUN_005f3950();
    _DAT_00950774 = 0;
  }
  return;
}

