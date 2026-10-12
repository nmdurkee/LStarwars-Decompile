/* Ghidra analysis pseudocode, not original source.
 * ev_9251851307bb379bfc9bcabd13d9f753a758e856e200aa29981eaf91127b618c
 * Entry: 0x574e20; label: FUN_00574e20
 */

undefined4 FUN_00574e20(void)

{
  if ((&DAT_00921454)[DAT_00800944 * 0x70] == -1) {
    return 0xffffffff;
  }
  return (&DAT_00800aa8)[(short)(&DAT_00921454)[DAT_00800944 * 0x70] * 7];
}

