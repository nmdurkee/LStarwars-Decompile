/* Ghidra pseudocode, not original source.
 * ev_a2aea1d641189bbcca45d714e231c7fbe07e1298025184ba29836f60d860e436
 * Entry: 0x5e8c60; label: FUN_005e8c60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e8c60(float *param_1,float *param_2,undefined4 param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  FUN_005b44e0(param_4);
  fVar1 = param_1[1];
  fVar2 = param_1[2];
  param_4[4] = -*param_1;
  param_4[5] = -fVar1;
  param_4[6] = -fVar2;
  local_18 = param_4[6] * param_2[1] - param_4[5] * param_2[2];
  local_14 = param_2[2] * param_4[4] - param_4[6] * *param_2;
  local_10 = param_4[5] * *param_2 - param_4[4] * param_2[1];
  local_c = local_10 * param_4[5] - local_14 * param_4[6];
  local_8 = local_18 * param_4[6] - param_4[4] * local_10;
  local_4 = param_4[4] * local_14 - local_18 * param_4[5];
  pfVar3 = (float *)FUN_005e8790(&local_18);
  param_4[8] = *pfVar3;
  param_4[9] = pfVar3[1];
  param_4[10] = pfVar3[2];
  local_18 = param_4[5] * param_4[10] - param_4[9] * param_4[6];
  local_14 = param_4[8] * param_4[6] - param_4[4] * param_4[10];
  *param_4 = local_18;
  param_4[1] = local_14;
  local_10 = param_4[4] * param_4[9] - param_4[8] * param_4[5];
  param_4[2] = local_10;
  FUN_005b5a40(param_3,param_4);
  return;
}

