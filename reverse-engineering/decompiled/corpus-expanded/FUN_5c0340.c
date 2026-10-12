/* Ghidra pseudocode, not original source.
 * ev_36c2cdffab22dec35ae5154a8d67af88b00f5702395280041def6b77535d68b9
 * Entry: 0x5c0340; label: thunk_FUN_005b4a50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void thunk_FUN_005b4a50(float *param_1,float *param_2)

{
  *param_1 = *param_1 * *param_2;
  param_1[1] = param_1[1] * param_2[1];
  param_1[2] = param_1[2] * param_2[2];
  param_1[4] = *param_2 * param_1[4];
  param_1[5] = param_1[5] * param_2[1];
  param_1[6] = param_2[2] * param_1[6];
  param_1[8] = param_1[8] * *param_2;
  param_1[9] = param_1[9] * param_2[1];
  param_1[10] = param_1[10] * param_2[2];
  param_1[0xc] = *param_2 * param_1[0xc];
  param_1[0xd] = param_1[0xd] * param_2[1];
  param_1[0xe] = param_2[2] * param_1[0xe];
  return;
}

