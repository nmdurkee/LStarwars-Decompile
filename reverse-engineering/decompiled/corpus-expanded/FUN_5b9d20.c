/* Ghidra pseudocode, not original source.
 * ev_3bb2d5213416039971b6dd1caa939c59b1318a27f895c0ebb43a5b863f1b474b
 * Entry: 0x5b9d20; label: FUN_005b9d20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b9d20(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  
  if (param_4 == (float *)0x0) {
    fVar1 = 0.0;
  }
  else {
    fVar1 = *param_4;
  }
  param_1[2] = fVar1;
  fVar1 = param_2[2];
  *param_1 = *param_2 + ((param_1[2] - fVar1) * *param_3) / param_3[2];
  param_1[1] = ((param_1[2] - fVar1) * param_3[1]) / param_3[2] + param_2[1];
  return;
}

