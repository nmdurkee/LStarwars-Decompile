/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x54fe80; label: FUN_0054fe80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0054fe80(float *param_1,float *param_2,float *param_3)

{
  if (0.0 <= (param_1[2] - param_2[2]) * param_3[2] +
             (*param_1 - *param_2) * *param_3 + (param_1[1] - param_2[1]) * param_3[1]) {
    return 1;
  }
  return 0;
}

