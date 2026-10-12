/* Ghidra pseudocode, not original source.
 * ev_c83b5e11bc7efa0def1389adc4a2304c53105cec15af0e74717438b1c42d0b82
 * Entry: 0x5b3dc0; label: FUN_005b3dc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b3dc0(float *param_1,float *param_2,float *param_3)

{
  param_1[3] = param_2[3] + param_3[3];
  *param_1 = *param_2 + *param_3;
  param_1[1] = param_2[1] + param_3[1];
  param_1[2] = param_2[2] + param_3[2];
  return;
}

