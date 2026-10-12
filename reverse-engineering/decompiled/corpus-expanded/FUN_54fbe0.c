/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x54fbe0; label: FUN_0054fbe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0054fbe0(float *param_1,float param_2,float *param_3)

{
  float fVar1;
  float10 fVar2;
  
  fVar1 = param_1[2] * param_1[2] + *param_1 * *param_1 + param_1[1] * param_1[1];
  if (param_2 * param_2 < fVar1) {
    fVar2 = (float10)FUN_005c0240(fVar1);
    fVar1 = (float)((float10)param_2 / fVar2);
    *param_3 = fVar1 * *param_3;
    param_3[1] = param_3[1] * fVar1;
    param_3[2] = fVar1 * param_3[2];
    return;
  }
  return;
}

