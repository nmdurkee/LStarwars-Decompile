/* Ghidra analysis pseudocode, not original source.
 * ev_374b9498cac1f2764533d2b2425c9906eb7f8dc5d78a775ccd4080d89a8f30aa
 * Entry: 0x6d5b30; label: FUN_006d5b30
 */

float10 FUN_006d5b30(int param_1)

{
  float fVar1;
  
  fVar1 = (*(float *)(DAT_02975144 + 0x6314 + param_1 * 4) -
          *(float *)(DAT_02975144 + 0x6320 + param_1 * 4)) * 0.125 +
          *(float *)(DAT_02975144 + 0x6320 + param_1 * 4);
  *(float *)(DAT_02975144 + 0x6320 + param_1 * 4) = fVar1;
  fVar1 = fVar1 * 4.0;
  if (ABS(fVar1) < 0.01) {
    fVar1 = 0.0;
  }
  return (float10)fVar1;
}

