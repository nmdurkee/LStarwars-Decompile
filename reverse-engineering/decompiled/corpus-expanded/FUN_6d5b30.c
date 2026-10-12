/* Ghidra pseudocode, not original source.
 * ev_334294c16a8347b4bc11d90e134269a6e2c30475b5c30bcaa57a53f4585ea308
 * Entry: 0x6d5b30; label: FUN_006d5b30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

