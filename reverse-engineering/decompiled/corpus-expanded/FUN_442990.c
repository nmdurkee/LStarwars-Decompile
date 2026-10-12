/* Ghidra pseudocode, not original source.
 * ev_6293e9c45219377b80e3d0963b70152e043cc5400ac7177165af43f16814c89d
 * Entry: 0x442990; label: FUN_00442990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

