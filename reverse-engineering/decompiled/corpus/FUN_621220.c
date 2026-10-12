/* Ghidra analysis pseudocode, not original source.
 * ev_0f83c18e3dd08d4f7d4ef8091875e15de78b7d8ec17e52e6723de9bddd8785d9
 * Entry: 0x621220; label: FUN_00621220
 */

void FUN_00621220(void)

{
  int iVar1;
  
  iVar1 = DAT_0080f884;
  if (DAT_0080f884 != -1) {
    _memset(&DAT_029110b8,0,0x1000);
    if ((DAT_02912f3c != 0) && (DAT_02912f3c == 1)) {
      FUN_004fb550(iVar1,&DAT_029110b8,0x1000);
      DAT_02900a5c = 0;
    }
  }
  return;
}

