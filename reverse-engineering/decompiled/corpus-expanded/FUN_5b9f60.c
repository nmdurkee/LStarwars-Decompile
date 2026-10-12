/* Ghidra pseudocode, not original source.
 * ev_3bb2d5213416039971b6dd1caa939c59b1318a27f895c0ebb43a5b863f1b474b
 * Entry: 0x5b9f60; label: FUN_005b9f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b9f60(float *param_1,float *param_2)

{
  *param_2 = param_1[3] + ((*param_1 + param_1[1] * 3.0) - param_1[2] * 3.0);
  param_2[1] = param_1[2] * 3.0 - param_1[1] * 6.0;
  *param_2 = param_1[1] * 3.0;
  *param_2 = *param_1;
  return;
}

