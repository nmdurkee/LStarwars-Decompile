/* Ghidra pseudocode, not original source.
 * ev_5f8bd7f02bbfa9819b1ea6d4f28ed7de24e0304b6779d959c9b1888bbc6517da
 * Entry: 0x5b6ff0; label: FUN_005b6ff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005b6ff0(float *param_1,float *param_2)

{
  return (float10)((param_1[0xf] - param_2[0xf]) * (param_1[0xf] - param_2[0xf]) +
                  (param_1[0xe] - param_2[0xe]) * (param_1[0xe] - param_2[0xe]) +
                  (param_1[0xd] - param_2[0xd]) * (param_1[0xd] - param_2[0xd]) +
                  (param_1[0xc] - param_2[0xc]) * (param_1[0xc] - param_2[0xc]) +
                  (param_1[0xb] - param_2[0xb]) * (param_1[0xb] - param_2[0xb]) +
                  (param_1[10] - param_2[10]) * (param_1[10] - param_2[10]) +
                  (param_1[9] - param_2[9]) * (param_1[9] - param_2[9]) +
                  (param_1[8] - param_2[8]) * (param_1[8] - param_2[8]) +
                  (param_1[7] - param_2[7]) * (param_1[7] - param_2[7]) +
                  (param_1[6] - param_2[6]) * (param_1[6] - param_2[6]) +
                  (param_1[4] - param_2[4]) * (param_1[4] - param_2[4]) +
                  (param_1[3] - param_2[3]) * (param_1[3] - param_2[3]) +
                  (*param_1 - *param_2) * (*param_1 - *param_2) +
                  (param_1[1] - param_2[1]) * (param_1[1] - param_2[1]) +
                  (param_1[2] - param_2[2]) * (param_1[2] - param_2[2]) +
                  (param_1[5] - param_2[5]) * (param_1[5] - param_2[5]));
}

