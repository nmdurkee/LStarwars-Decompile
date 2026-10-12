/* Ghidra pseudocode, not original source.
 * ev_ef3b2a8ba8bea7724eb7ddbe17370c631fd0c0f4e2170ed1a1745c7d6977e716
 * Entry: 0x5b8270; label: FUN_005b8270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b8270(float *param_1,float *param_2)

{
  float fVar1;
  
  fVar1 = 1.0 / (param_2[2] * param_2[2] +
                param_2[1] * param_2[1] + *param_2 * *param_2 + param_2[3] * param_2[3]);
  param_1[3] = fVar1 * param_2[3];
  *param_1 = -*param_2 * fVar1;
  param_1[1] = -param_2[1] * fVar1;
  param_1[2] = -param_2[2] * fVar1;
  return;
}

