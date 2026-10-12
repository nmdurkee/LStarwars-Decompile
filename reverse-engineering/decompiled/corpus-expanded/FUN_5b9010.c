/* Ghidra pseudocode, not original source.
 * ev_ef3b2a8ba8bea7724eb7ddbe17370c631fd0c0f4e2170ed1a1745c7d6977e716
 * Entry: 0x5b9010; label: FUN_005b9010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b9010(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  *param_1 = *param_3;
  param_1[1] = param_3[1];
  fVar1 = param_3[2];
  param_1[2] = fVar1;
  param_1[3] = -(*param_1 * *param_2 + param_2[1] * param_1[1] + param_2[2] * fVar1);
  return;
}

