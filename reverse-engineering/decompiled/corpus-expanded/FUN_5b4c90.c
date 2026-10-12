/* Ghidra pseudocode, not original source.
 * ev_d58eb7bbc0b728a6aebb219ddf07867fbf193ab17bd10fe9485a456632c89c4f
 * Entry: 0x5b4c90; label: FUN_005b4c90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b4c90(float *param_1,float param_2)

{
  *param_1 = param_2 * *param_1;
  param_1[1] = param_1[1] * param_2;
  param_1[2] = param_2 * param_1[2];
  return;
}

