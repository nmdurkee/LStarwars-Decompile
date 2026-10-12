/* Ghidra pseudocode, not original source.
 * ev_3bb2d5213416039971b6dd1caa939c59b1318a27f895c0ebb43a5b863f1b474b
 * Entry: 0x5ba650; label: FUN_005ba650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ba650(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  *param_2 = *param_1 * -3.0;
  param_2[1] = param_1[1] * -3.0;
  param_2[2] = param_1[2] * -3.0;
  *param_2 = *param_2 + param_1[0xc] * 3.0;
  param_2[1] = param_1[0xd] * 3.0 + param_2[1];
  param_2[2] = param_1[0xe] * 3.0 + param_2[2];
  *param_3 = param_1[0x18] * -3.0;
  param_3[1] = param_1[0x19] * -3.0;
  param_3[2] = param_1[0x1a] * -3.0;
  *param_3 = param_1[0x24] * 3.0 + *param_3;
  param_3[1] = param_1[0x25] * 3.0 + param_3[1];
  param_3[2] = param_1[0x26] * 3.0 + param_3[2];
  *param_4 = param_1[9] * -3.0;
  param_4[1] = param_1[10] * -3.0;
  param_4[2] = param_1[0xb] * -3.0;
  *param_4 = param_1[0x15] * 3.0 + *param_4;
  param_4[1] = param_1[0x16] * 3.0 + param_4[1];
  param_4[2] = param_1[0x17] * 3.0 + param_4[2];
  *param_5 = param_1[0x21] * -3.0;
  param_5[1] = param_1[0x22] * -3.0;
  param_5[2] = param_1[0x23] * -3.0;
  *param_5 = param_1[0x2d] * 3.0 + *param_5;
  param_5[1] = param_1[0x2e] * 3.0 + param_5[1];
  param_5[2] = param_1[0x2f] * 3.0 + param_5[2];
  return;
}

