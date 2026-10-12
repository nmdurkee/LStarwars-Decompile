/* Ghidra pseudocode, not original source.
 * ev_36c2cdffab22dec35ae5154a8d67af88b00f5702395280041def6b77535d68b9
 * Entry: 0x5bf910; label: FUN_005bf910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005bf910(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_18 = *param_2 - *param_1;
  local_14 = param_2[1] - param_1[1];
  local_10 = param_2[2] - param_1[2];
  fVar3 = (float10)FUN_005c0240(local_10 * local_10 + local_14 * local_14 + local_18 * local_18);
  fVar2 = 1.0 / (float)fVar3;
  local_c = *param_3 - *param_1;
  local_8 = param_3[1] - param_1[1];
  local_4 = param_3[2] - param_1[2];
  fVar1 = fVar2 * local_18 * local_c + local_14 * fVar2 * local_8 + fVar2 * local_10 * local_4;
  if (fVar1 < 0.0 == (fVar1 == 0.0)) {
    if (fVar1 < (float)fVar3) {
      local_18 = *param_1 + fVar1 * fVar2 * local_18;
      local_14 = fVar1 * local_14 * fVar2 + param_1[1];
      local_10 = param_1[2] + fVar2 * local_10 * fVar1;
    }
    else {
      local_18 = *param_2;
      local_14 = param_2[1];
      local_10 = param_2[2];
    }
  }
  else {
    local_18 = *param_1;
    local_14 = param_1[1];
    local_10 = param_1[2];
  }
  fVar3 = (float10)FUN_005b3c50(&local_18,param_3,&local_c);
  if (param_4 != (float *)0x0) {
    *param_4 = local_18;
    param_4[1] = local_14;
    param_4[2] = local_10;
  }
  return (float10)(float)fVar3;
}

