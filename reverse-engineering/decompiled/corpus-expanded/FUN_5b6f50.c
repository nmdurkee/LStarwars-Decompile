/* Ghidra pseudocode, not original source.
 * ev_5f8bd7f02bbfa9819b1ea6d4f28ed7de24e0304b6779d959c9b1888bbc6517da
 * Entry: 0x5b6f50; label: FUN_005b6f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005b6f50(float *param_1)

{
  return (float10)((param_1[9] * param_1[4] - param_1[8] * param_1[5]) * param_1[2] +
                  ((param_1[10] * param_1[5] - param_1[9] * param_1[6]) * *param_1 -
                  (param_1[10] * param_1[4] - param_1[8] * param_1[6]) * param_1[1]));
}

