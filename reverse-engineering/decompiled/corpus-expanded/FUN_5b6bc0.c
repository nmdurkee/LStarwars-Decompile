/* Ghidra pseudocode, not original source.
 * ev_5f8bd7f02bbfa9819b1ea6d4f28ed7de24e0304b6779d959c9b1888bbc6517da
 * Entry: 0x5b6bc0; label: FUN_005b6bc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b6bc0(float *param_1,float *param_2,float *param_3)

{
  *param_1 = *param_2 + *param_3;
  param_1[1] = param_2[1] + param_3[1];
  param_1[2] = param_2[2] + param_3[2];
  param_1[3] = 0.0;
  param_1[4] = param_2[4] + param_3[4];
  param_1[5] = param_2[5] + param_3[5];
  param_1[6] = param_2[6] + param_3[6];
  param_1[7] = 0.0;
  param_1[8] = param_2[8] + param_3[8];
  param_1[9] = param_2[9] + param_3[9];
  param_1[10] = param_2[10] + param_3[10];
  param_1[0xb] = 0.0;
  param_1[0xc] = 0.0;
  param_1[0xd] = 0.0;
  param_1[0xe] = 0.0;
  param_1[0xf] = 1.0;
  return;
}

