/* Ghidra pseudocode, not original source.
 * ev_d58eb7bbc0b728a6aebb219ddf07867fbf193ab17bd10fe9485a456632c89c4f
 * Entry: 0x5b49f0; label: FUN_005b49f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b49f0(float *param_1,float *param_2)

{
  param_1[0xc] = param_1[0xc] -
                 (param_1[8] * param_2[2] + *param_1 * *param_2 + param_1[4] * param_2[1]);
  param_1[0xd] = param_1[0xd] -
                 (param_1[9] * param_2[2] + param_1[5] * param_2[1] + param_1[1] * *param_2);
  param_1[0xe] = param_1[0xe] -
                 (param_1[10] * param_2[2] + param_1[6] * param_2[1] + param_1[2] * *param_2);
  return;
}

