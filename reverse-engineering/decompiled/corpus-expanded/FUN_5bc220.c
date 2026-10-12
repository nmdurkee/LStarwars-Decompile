/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bc220; label: FUN_005bc220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bc220(float *param_1,float *param_2)

{
  *param_1 = param_2[0xf] * 2.0 + (*param_2 * 2.0 - param_2[6] * 4.0);
  param_1[1] = param_2[0x10] * 2.0 + (param_2[1] * 2.0 - param_2[7] * 4.0);
  param_1[2] = param_2[0x11] * 2.0 + (param_2[2] * 2.0 - param_2[8] * 4.0);
  return;
}

