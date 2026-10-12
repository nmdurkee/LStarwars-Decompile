/* Ghidra pseudocode, not original source.
 * ev_ea7efa1563e3e8089df6b32d8c4fce6d2180bcae0d447e350c78ef2ad3ca8169
 * Entry: 0x678010; label: FUN_00678010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00678010(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  fVar1 = -param_2[2] * param_1[2] + -*param_2 * *param_1 + -param_2[1] * param_1[1] + 0.0003;
  *param_3 = *param_2 + fVar1 * *param_1;
  param_3[1] = param_1[1] * fVar1 * _DAT_02947c00 + param_2[1];
  param_3[2] = fVar1 * param_1[2] + param_2[2];
  return;
}

