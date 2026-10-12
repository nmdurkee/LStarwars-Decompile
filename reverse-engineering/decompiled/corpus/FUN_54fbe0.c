/* Ghidra analysis pseudocode, not original source.
 * ev_ec07135468de31ab5fb92b99d3a0e31a017920018520f35a1e7400fac21801d6
 * Entry: 0x54fbe0; label: FUN_0054fbe0
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

