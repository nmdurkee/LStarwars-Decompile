/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bb8e0; label: FUN_005bb8e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bb8e0(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  *param_2 = *param_1 * -6.0;
  param_2[1] = param_1[1] * -6.0;
  param_2[2] = param_1[2] * -6.0;
  *param_2 = *param_2 + param_1[0xc] * 18.0;
  param_2[1] = param_1[0xd] * 18.0 + param_2[1];
  param_2[2] = param_1[0xe] * 18.0 + param_2[2];
  *param_2 = *param_2 - param_1[0x18] * 18.0;
  param_2[1] = param_2[1] - param_1[0x19] * 18.0;
  param_2[2] = param_2[2] - param_1[0x1a] * 18.0;
  *param_2 = *param_2 + param_1[0x24] * 6.0;
  param_2[1] = param_1[0x25] * 6.0 + param_2[1];
  param_2[2] = param_1[0x26] * 6.0 + param_2[2];
  *param_3 = *param_2;
  param_3[1] = param_2[1];
  param_3[2] = param_2[2];
  *param_5 = param_1[9] * -6.0;
  param_5[1] = param_1[10] * -6.0;
  param_5[2] = param_1[0xb] * -6.0;
  *param_5 = param_1[0x15] * 18.0 + *param_5;
  param_5[1] = param_1[0x16] * 18.0 + param_5[1];
  param_5[2] = param_1[0x17] * 18.0 + param_5[2];
  *param_5 = *param_5 - param_1[0x21] * 18.0;
  param_5[1] = param_5[1] - param_1[0x22] * 18.0;
  param_5[2] = param_5[2] - param_1[0x23] * 18.0;
  *param_5 = param_1[0x2d] * 6.0 + *param_5;
  param_5[1] = param_1[0x2e] * 6.0 + param_5[1];
  param_5[2] = param_1[0x2f] * 6.0 + param_5[2];
  *param_4 = *param_5;
  param_4[1] = param_5[1];
  param_4[2] = param_5[2];
  return;
}

