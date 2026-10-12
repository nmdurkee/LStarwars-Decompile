/* Ghidra pseudocode, not original source.
 * ev_ea7efa1563e3e8089df6b32d8c4fce6d2180bcae0d447e350c78ef2ad3ca8169
 * Entry: 0x677fb0; label: FUN_00677fb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00677fb0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  fVar1 = -param_2[2] * param_1[2] + -*param_2 * *param_1 + -param_2[1] * param_1[1] + 0.0003;
  *param_3 = *param_2 + fVar1 * *param_1;
  param_3[1] = param_1[1] * fVar1 + param_2[1];
  param_3[2] = fVar1 * param_1[2] + param_2[2];
  return;
}

