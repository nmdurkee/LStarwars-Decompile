/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x54fce0; label: FUN_0054fce0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0054fce0(float *param_1,float param_2,float param_3,float *param_4,float param_5,float param_6)

{
  float *pfVar1;
  float fVar2;
  
  fVar2 = *param_4;
  pfVar1 = param_4 + 2;
  param_4 = (float *)(param_4[1] - param_1[1]);
  if ((param_3 != param_2) || (param_6 != param_5)) {
    param_4 = (float *)(((param_2 + param_5) / (param_3 + param_6)) * (float)param_4);
  }
  if ((param_5 + param_2) * (param_5 + param_2) <
      (*pfVar1 - param_1[2]) * (*pfVar1 - param_1[2]) +
      (fVar2 - *param_1) * (fVar2 - *param_1) + (float)param_4 * (float)param_4) {
    return 0;
  }
  return 1;
}

