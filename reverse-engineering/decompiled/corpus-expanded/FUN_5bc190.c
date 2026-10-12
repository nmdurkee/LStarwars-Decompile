/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bc190; label: FUN_005bc190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bc190(float *param_1,float *param_2)

{
  *param_1 = param_2[9] * 2.0 + (*param_2 * 2.0 - param_2[3] * 4.0);
  param_1[1] = param_2[10] * 2.0 + (param_2[1] * 2.0 - param_2[4] * 4.0);
  param_1[2] = param_2[0xb] * 2.0 + (param_2[2] * 2.0 - param_2[5] * 4.0);
  return;
}

