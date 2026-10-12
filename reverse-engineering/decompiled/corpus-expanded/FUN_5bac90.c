/* Ghidra pseudocode, not original source.
 * ev_3bb2d5213416039971b6dd1caa939c59b1318a27f895c0ebb43a5b863f1b474b
 * Entry: 0x5bac90; label: FUN_005bac90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bac90(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  *param_2 = *param_1 * -18.0;
  param_2[1] = param_1[1] * -18.0;
  param_2[2] = param_1[2] * -18.0;
  *param_2 = *param_2 + param_1[3] * 36.0;
  param_2[1] = param_1[4] * 36.0 + param_2[1];
  param_2[2] = param_1[5] * 36.0 + param_2[2];
  *param_2 = *param_2 - param_1[6] * 18.0;
  param_2[1] = param_2[1] - param_1[7] * 18.0;
  param_2[2] = param_2[2] - param_1[8] * 18.0;
  *param_2 = param_1[0xc] * 18.0 + *param_2;
  param_2[1] = param_1[0xd] * 18.0 + param_2[1];
  param_2[2] = param_1[0xe] * 18.0 + param_2[2];
  *param_2 = *param_2 - param_1[0xf] * 36.0;
  param_2[1] = param_2[1] - param_1[0x10] * 36.0;
  param_2[2] = param_2[2] - param_1[0x11] * 36.0;
  *param_2 = param_1[0x12] * 18.0 + *param_2;
  param_2[1] = param_1[0x13] * 18.0 + param_2[1];
  param_2[2] = param_1[0x14] * 18.0 + param_2[2];
  *param_3 = param_1[0x18] * -18.0;
  param_3[1] = param_1[0x19] * -18.0;
  param_3[2] = param_1[0x1a] * -18.0;
  *param_3 = param_1[0x1b] * 36.0 + *param_3;
  param_3[1] = param_1[0x1c] * 36.0 + param_3[1];
  param_3[2] = param_1[0x1d] * 36.0 + param_3[2];
  *param_3 = *param_3 - param_1[0x1e] * 18.0;
  param_3[1] = param_3[1] - param_1[0x1f] * 18.0;
  param_3[2] = param_3[2] - param_1[0x20] * 18.0;
  *param_3 = param_1[0x24] * 18.0 + *param_3;
  param_3[1] = param_1[0x25] * 18.0 + param_3[1];
  param_3[2] = param_1[0x26] * 18.0 + param_3[2];
  *param_3 = *param_3 - param_1[0x27] * 36.0;
  param_3[1] = param_3[1] - param_1[0x28] * 36.0;
  param_3[2] = param_3[2] - param_1[0x29] * 36.0;
  *param_3 = param_1[0x2a] * 18.0 + *param_3;
  param_3[1] = param_1[0x2b] * 18.0 + param_3[1];
  param_3[2] = param_1[0x2c] * 18.0 + param_3[2];
  *param_4 = param_1[3] * -18.0;
  param_4[1] = param_1[4] * -18.0;
  param_4[2] = param_1[5] * -18.0;
  *param_4 = param_1[6] * 36.0 + *param_4;
  param_4[1] = param_1[7] * 36.0 + param_4[1];
  param_4[2] = param_1[8] * 36.0 + param_4[2];
  *param_4 = *param_4 - param_1[9] * 18.0;
  param_4[1] = param_4[1] - param_1[10] * 18.0;
  param_4[2] = param_4[2] - param_1[0xb] * 18.0;
  *param_4 = param_1[0xf] * 18.0 + *param_4;
  param_4[1] = param_1[0x10] * 18.0 + param_4[1];
  param_4[2] = param_1[0x11] * 18.0 + param_4[2];
  *param_4 = *param_4 - param_1[0x12] * 36.0;
  param_4[1] = param_4[1] - param_1[0x13] * 36.0;
  param_4[2] = param_4[2] - param_1[0x14] * 36.0;
  *param_4 = param_1[0x15] * 18.0 + *param_4;
  param_4[1] = param_1[0x16] * 18.0 + param_4[1];
  param_4[2] = param_1[0x17] * 18.0 + param_4[2];
  *param_5 = param_1[0x1b] * -18.0;
  param_5[1] = param_1[0x1c] * -18.0;
  param_5[2] = param_1[0x1d] * -18.0;
  *param_5 = param_1[0x1e] * 36.0 + *param_5;
  param_5[1] = param_1[0x1f] * 36.0 + param_5[1];
  param_5[2] = param_1[0x20] * 36.0 + param_5[2];
  *param_5 = *param_5 - param_1[0x21] * 18.0;
  param_5[1] = param_5[1] - param_1[0x22] * 18.0;
  param_5[2] = param_5[2] - param_1[0x23] * 18.0;
  *param_5 = param_1[0x27] * 18.0 + *param_5;
  param_5[1] = param_1[0x28] * 18.0 + param_5[1];
  param_5[2] = param_1[0x29] * 18.0 + param_5[2];
  *param_5 = *param_5 - param_1[0x2a] * 36.0;
  param_5[1] = param_5[1] - param_1[0x2b] * 36.0;
  param_5[2] = param_5[2] - param_1[0x2c] * 36.0;
  *param_5 = param_1[0x2d] * 18.0 + *param_5;
  param_5[1] = param_1[0x2e] * 18.0 + param_5[1];
  param_5[2] = param_1[0x2f] * 18.0 + param_5[2];
  return;
}

