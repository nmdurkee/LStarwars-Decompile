/* Ghidra analysis pseudocode, not original source.
 * ev_3b4ca00fd279b908d0ecc0345d0e63acf8414f1fac0e020351d2be86095d22cc
 * Entry: 0x565700; label: FUN_00565700
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00565700(void)

{
  int iVar1;
  
  if (_DAT_00950760 <= 0.0) {
    return;
  }
  FUN_005d4290(1);
  FUN_006e6b90();
  iVar1 = FUN_006e6b90();
  FUN_005db880(0,0,0x2800,iVar1,0x80ffffff,DAT_009506fc);
  FUN_005db880(0,0xe20 - iVar1,0x2800,iVar1,0x80ffffff,DAT_009506fc);
  FUN_005f3950();
  return;
}

