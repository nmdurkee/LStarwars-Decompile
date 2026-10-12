/* Ghidra analysis pseudocode, not original source.
 * ev_b6d8a17c6b3263d4647da1f5b2d8de4c4a67e85657c53f6d05a13f18932cfd90
 * Entry: 0x5c07c0; label: FUN_005c07c0
 */

void FUN_005c07c0(float *param_1,float param_2)

{
  *param_1 = param_2 * *param_1;
  param_1[1] = param_1[1] * param_2;
  param_1[2] = param_2 * param_1[2];
  param_1[4] = param_1[4] * param_2;
  param_1[5] = param_2 * param_1[5];
  param_1[6] = param_1[6] * param_2;
  param_1[8] = param_2 * param_1[8];
  param_1[9] = param_1[9] * param_2;
  param_1[10] = param_2 * param_1[10];
  return;
}

