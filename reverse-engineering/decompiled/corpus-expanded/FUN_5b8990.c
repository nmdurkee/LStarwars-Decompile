/* Ghidra pseudocode, not original source.
 * ev_ef3b2a8ba8bea7724eb7ddbe17370c631fd0c0f4e2170ed1a1745c7d6977e716
 * Entry: 0x5b8990; label: FUN_005b8990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b8990(float *param_1,float *param_2,float *param_3,float param_4,float param_5)

{
  *param_1 = param_4 * *param_2 + param_5 * *param_3;
  param_1[1] = param_3[1] * param_5 + param_2[1] * param_4;
  param_1[2] = param_3[2] * param_5 + param_2[2] * param_4;
  param_1[3] = param_4 * param_2[3] + param_3[3] * param_5;
  return;
}

