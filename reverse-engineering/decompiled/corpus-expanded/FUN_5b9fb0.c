/* Ghidra pseudocode, not original source.
 * ev_3bb2d5213416039971b6dd1caa939c59b1318a27f895c0ebb43a5b863f1b474b
 * Entry: 0x5b9fb0; label: FUN_005b9fb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b9fb0(float *param_1,float param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = 1.0 - param_2;
  *param_3 = *param_1;
  fVar1 = param_1[1] * param_2 + fVar3 * *param_1;
  param_3[1] = fVar1;
  fVar2 = param_1[1] * fVar3 + param_1[2] * param_2;
  param_3[2] = fVar2 * param_2 + fVar1 * fVar3;
  param_4[3] = param_1[3];
  fVar1 = param_1[3] * param_2 + param_1[2] * fVar3;
  param_4[2] = fVar1;
  fVar1 = fVar1 * param_2 + fVar3 * fVar2;
  param_4[1] = fVar1;
  fVar1 = fVar3 * param_3[2] + fVar1 * param_2;
  *param_4 = fVar1;
  param_3[3] = fVar1;
  return;
}

