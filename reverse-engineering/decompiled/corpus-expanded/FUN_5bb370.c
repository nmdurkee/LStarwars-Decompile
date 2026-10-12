/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bb370; label: FUN_005bb370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bb370(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  *param_2 = *param_1 * -36.0;
  param_2[1] = param_1[1] * -36.0;
  param_2[2] = param_1[2] * -36.0;
  *param_2 = *param_2 + param_1[3] * 72.0;
  param_2[1] = param_1[4] * 72.0 + param_2[1];
  param_2[2] = param_1[5] * 72.0 + param_2[2];
  *param_2 = *param_2 - param_1[6] * 36.0;
  param_2[1] = param_2[1] - param_1[7] * 36.0;
  param_2[2] = param_2[2] - param_1[8] * 36.0;
  *param_2 = *param_2 + param_1[0xc] * 108.0;
  param_2[1] = param_1[0xd] * 108.0 + param_2[1];
  param_2[2] = param_1[0xe] * 108.0 + param_2[2];
  *param_2 = *param_2 - param_1[0xf] * 216.0;
  param_2[1] = param_2[1] - param_1[0x10] * 216.0;
  param_2[2] = param_2[2] - param_1[0x11] * 216.0;
  *param_2 = param_1[0x12] * 108.0 + *param_2;
  param_2[1] = param_1[0x13] * 108.0 + param_2[1];
  param_2[2] = param_1[0x14] * 108.0 + param_2[2];
  *param_2 = *param_2 - param_1[0x18] * 108.0;
  param_2[1] = param_2[1] - param_1[0x19] * 108.0;
  param_2[2] = param_2[2] - param_1[0x1a] * 108.0;
  *param_2 = param_1[0x1b] * 216.0 + *param_2;
  param_2[1] = param_1[0x1c] * 216.0 + param_2[1];
  param_2[2] = param_1[0x1d] * 216.0 + param_2[2];
  *param_2 = *param_2 - param_1[0x1e] * 108.0;
  param_2[1] = param_2[1] - param_1[0x1f] * 108.0;
  param_2[2] = param_2[2] - param_1[0x20] * 108.0;
  *param_2 = param_1[0x24] * 36.0 + *param_2;
  param_2[1] = param_1[0x25] * 36.0 + param_2[1];
  param_2[2] = param_1[0x26] * 36.0 + param_2[2];
  *param_2 = *param_2 - param_1[0x27] * 72.0;
  param_2[1] = param_2[1] - param_1[0x28] * 72.0;
  param_2[2] = param_2[2] - param_1[0x29] * 72.0;
  *param_2 = param_1[0x2a] * 36.0 + *param_2;
  param_2[1] = param_1[0x2b] * 36.0 + param_2[1];
  param_2[2] = param_1[0x2c] * 36.0 + param_2[2];
  *param_3 = *param_2;
  param_3[1] = param_2[1];
  param_3[2] = param_2[2];
  *param_5 = param_1[3] * -36.0;
  param_5[1] = param_1[4] * -36.0;
  param_5[2] = param_1[5] * -36.0;
  *param_5 = param_1[6] * 72.0 + *param_5;
  param_5[1] = param_1[7] * 72.0 + param_5[1];
  param_5[2] = param_1[8] * 72.0 + param_5[2];
  *param_5 = *param_5 - param_1[9] * 36.0;
  param_5[1] = param_5[1] - param_1[10] * 36.0;
  param_5[2] = param_5[2] - param_1[0xb] * 36.0;
  *param_5 = param_1[0xf] * 108.0 + *param_5;
  param_5[1] = param_1[0x10] * 108.0 + param_5[1];
  param_5[2] = param_1[0x11] * 108.0 + param_5[2];
  *param_5 = *param_5 - param_1[0x12] * 216.0;
  param_5[1] = param_5[1] - param_1[0x13] * 216.0;
  param_5[2] = param_5[2] - param_1[0x14] * 216.0;
  *param_5 = param_1[0x15] * 108.0 + *param_5;
  param_5[1] = param_1[0x16] * 108.0 + param_5[1];
  param_5[2] = param_1[0x17] * 108.0 + param_5[2];
  *param_5 = *param_5 - param_1[0x1b] * 108.0;
  param_5[1] = param_5[1] - param_1[0x1c] * 108.0;
  param_5[2] = param_5[2] - param_1[0x1d] * 108.0;
  *param_5 = param_1[0x1e] * 216.0 + *param_5;
  param_5[1] = param_1[0x1f] * 216.0 + param_5[1];
  param_5[2] = param_5[2] + param_1[0x20] * 216.0;
  *param_5 = *param_5 - param_1[0x21] * 108.0;
  param_5[1] = param_5[1] - param_1[0x22] * 108.0;
  param_5[2] = param_5[2] - param_1[0x23] * 108.0;
  *param_5 = param_1[0x27] * 36.0 + *param_5;
  param_5[1] = param_1[0x28] * 36.0 + param_5[1];
  param_5[2] = param_1[0x29] * 36.0 + param_5[2];
  *param_5 = *param_5 - param_1[0x2a] * 72.0;
  param_5[1] = param_5[1] - param_1[0x2b] * 72.0;
  param_5[2] = param_5[2] - param_1[0x2c] * 72.0;
  *param_5 = param_1[0x2d] * 36.0 + *param_5;
  param_5[1] = param_1[0x2e] * 36.0 + param_5[1];
  param_5[2] = param_1[0x2f] * 36.0 + param_5[2];
  *param_4 = *param_5;
  param_4[1] = param_5[1];
  param_4[2] = param_5[2];
  return;
}

