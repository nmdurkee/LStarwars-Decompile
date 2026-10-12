/* Ghidra analysis pseudocode, not original source.
 * ev_0f83c18e3dd08d4f7d4ef8091875e15de78b7d8ec17e52e6723de9bddd8785d9
 * Entry: 0x6213e0; label: FUN_006213e0
 */

undefined4 FUN_006213e0(void)

{
  DAT_02912f40 = 0;
  if (DAT_0080f884 != -1) {
    if (DAT_02912f44 != 0) {
      FUN_006213a0();
    }
    if ((DAT_02912f3c != 0) && (DAT_02912f3c == 1)) {
      FUN_004f99e0(DAT_0080f884);
      DAT_0080f884 = 0xffffffff;
      DAT_02912f3c = 0;
      return 1;
    }
  }
  return 0;
}

