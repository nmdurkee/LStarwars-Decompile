/* Ghidra pseudocode, not original source.
 * ev_c83b5e11bc7efa0def1389adc4a2304c53105cec15af0e74717438b1c42d0b82
 * Entry: 0x5b4080; label: FUN_005b4080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b4080(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  if (*param_3 <= *param_2) {
    fVar1 = *param_3;
  }
  else {
    fVar1 = *param_2;
  }
  *param_1 = fVar1;
  if (param_3[1] <= param_2[1]) {
    fVar1 = param_3[1];
  }
  else {
    fVar1 = param_2[1];
  }
  param_1[1] = fVar1;
  if (param_3[2] <= param_2[2]) {
    fVar1 = param_3[2];
  }
  else {
    fVar1 = param_2[2];
  }
  param_1[2] = fVar1;
  if (param_2[3] < param_3[3]) {
    param_1[3] = param_2[3];
    return;
  }
  param_1[3] = param_3[3];
  return;
}

