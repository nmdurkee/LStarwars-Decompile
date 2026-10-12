/* Ghidra analysis pseudocode, not original source.
 * ev_ec07135468de31ab5fb92b99d3a0e31a017920018520f35a1e7400fac21801d6
 * Entry: 0x54fc70; label: FUN_0054fc70
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

