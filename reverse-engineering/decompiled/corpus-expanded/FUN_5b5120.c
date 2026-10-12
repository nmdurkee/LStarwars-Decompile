/* Ghidra pseudocode, not original source.
 * ev_d58eb7bbc0b728a6aebb219ddf07867fbf193ab17bd10fe9485a456632c89c4f
 * Entry: 0x5b5120; label: FUN_005b5120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b5120(float *param_1)

{
  *param_1 = -*param_1;
  param_1[1] = -param_1[1];
  param_1[2] = -param_1[2];
  param_1[8] = -param_1[8];
  param_1[9] = -param_1[9];
  param_1[10] = -param_1[10];
  return;
}

