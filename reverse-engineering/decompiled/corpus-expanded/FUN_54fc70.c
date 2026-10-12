/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x54fc70; label: FUN_0054fc70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0054fc70(float *param_1,float param_2,float *param_3,float param_4)

{
  if ((param_3[2] - param_1[2]) * (param_3[2] - param_1[2]) +
      (*param_3 - *param_1) * (*param_3 - *param_1) +
      (param_3[1] - param_1[1]) * (param_3[1] - param_1[1]) <=
      (param_2 + param_4) * (param_2 + param_4)) {
    return 1;
  }
  return 0;
}

