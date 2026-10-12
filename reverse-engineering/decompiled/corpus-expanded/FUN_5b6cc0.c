/* Ghidra pseudocode, not original source.
 * ev_5f8bd7f02bbfa9819b1ea6d4f28ed7de24e0304b6779d959c9b1888bbc6517da
 * Entry: 0x5b6cc0; label: FUN_005b6cc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b6cc0(undefined4 *param_1,float *param_2)

{
  *param_1 = 0;
  param_1[1] = -param_2[2];
  param_1[2] = param_2[1];
  param_1[3] = 0;
  param_1[4] = param_2[2];
  param_1[5] = 0;
  param_1[6] = -*param_2;
  param_1[7] = 0;
  param_1[8] = -param_2[1];
  param_1[9] = *param_2;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0x3f800000;
  return;
}

