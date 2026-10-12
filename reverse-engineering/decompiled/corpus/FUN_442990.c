/* Ghidra analysis pseudocode, not original source.
 * ev_57da142a35c0111f2a239c45d08c295619c149a30e290e5aab503b2119bb06b8
 * Entry: 0x442990; label: FUN_00442990
 */

float10 FUN_00442990(void)

{
  if (DAT_0093d810 == 0) {
    return (float10)0;
  }
  if ((DAT_0093d814 != 0) && (*(float *)(DAT_0093d810 + 0x69c) < *(float *)(DAT_0093d814 + 0x69c)))
  {
    return (float10)*(float *)(DAT_0093d814 + 0x69c);
  }
  return (float10)*(float *)(DAT_0093d810 + 0x69c);
}

