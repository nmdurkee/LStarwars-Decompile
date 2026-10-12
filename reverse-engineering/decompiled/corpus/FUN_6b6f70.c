/* Ghidra analysis pseudocode, not original source.
 * ev_7c9627a116e74c10f7e1ba5a6ebe852fd25b4abb6a97a0a4eb0abdf2e857683f
 * Entry: 0x6b6f70; label: FUN_006b6f70
 */

float10 FUN_006b6f70(float param_1)

{
  uint uVar1;
  
  uVar1 = (uint)ROUND(param_1 * -8.0 - 0.5);
  if ((int)uVar1 < 0) {
    return (float10)1.0;
  }
  if (0x45f < (int)uVar1) {
    return (float10)0.0;
  }
  return (float10)(*(float *)(&DAT_0081f8d0 + (uVar1 & 0x1f) * 4) *
                  *(float *)(&DAT_0081f840 + ((int)uVar1 >> 5) * 4));
}

