/* Ghidra analysis pseudocode, not original source.
 * ev_5e4e6a590c471e22d2a814bcf9fd12a554b410855fef8706c3d4a3775c91fbe8
 * Entry: 0x6e8fac; label: FUN_006e8fac
 */

void FUN_006e8fac(void)

{
  ushort in_FPUControlWord;
  
  if ((DAT_029a9c44 != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    FUN_006f6ad0();
    return;
  }
  __cintrindisp1();
  return;
}

