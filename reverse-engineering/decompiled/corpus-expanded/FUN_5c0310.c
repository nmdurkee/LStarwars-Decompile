/* Ghidra pseudocode, not original source.
 * ev_36c2cdffab22dec35ae5154a8d67af88b00f5702395280041def6b77535d68b9
 * Entry: 0x5c0310; label: thunk_FUN_005b9150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 thunk_FUN_005b9150(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar5 = param_1[2] * param_2[2] + param_1[1] * param_2[1] + *param_1 * *param_2 + param_1[3];
  fVar6 = param_1[2] * param_3[2] + *param_1 * *param_3 + param_3[1] * param_1[1] + param_1[3];
  if (((uint)fVar5 & 0x80000000) == 0) {
    param_1 = (float *)0x3f800000;
  }
  else {
    param_1 = (float *)0xbf800000;
  }
  fVar1 = 1.0;
  if (((uint)fVar6 & 0x80000000) != 0) {
    fVar1 = -1.0;
  }
  if (fVar1 == (float)param_1) {
    return 0;
  }
  fVar1 = param_3[1];
  fVar2 = param_2[1];
  fVar3 = param_3[2];
  fVar4 = param_2[2];
  fVar5 = -fVar5 / (fVar6 - fVar5);
  fVar6 = fVar5 * (*param_3 - *param_2);
  *param_4 = fVar6;
  fVar1 = (fVar1 - fVar2) * fVar5;
  param_4[1] = fVar1;
  fVar5 = (fVar3 - fVar4) * fVar5;
  param_4[2] = fVar5;
  *param_4 = *param_2 + fVar6;
  param_4[1] = param_2[1] + fVar1;
  param_4[2] = fVar5 + param_2[2];
  return 1;
}

