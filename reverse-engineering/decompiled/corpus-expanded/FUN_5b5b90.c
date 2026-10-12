/* Ghidra pseudocode, not original source.
 * ev_d58eb7bbc0b728a6aebb219ddf07867fbf193ab17bd10fe9485a456632c89c4f
 * Entry: 0x5b5b90; label: FUN_005b5b90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b5b90(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  float local_40 [5];
  float local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  fVar1 = (param_2[9] * param_2[4] - param_2[8] * param_2[5]) * param_2[2] +
          ((param_2[10] * param_2[5] - param_2[9] * param_2[6]) * *param_2 -
          (param_2[4] * param_2[10] - param_2[8] * param_2[6]) * param_2[1]);
  if (fVar1 == 0.0) {
    fVar1 = 0.0;
  }
  else {
    fVar1 = 1.0 / fVar1;
  }
  local_40[0] = fVar1 * (param_2[10] * param_2[5] - param_2[9] * param_2[6]);
  fVar2 = -fVar1;
  local_40[4] = fVar2 * (param_2[4] * param_2[10] - param_2[8] * param_2[6]);
  local_20 = (param_2[9] * param_2[4] - param_2[8] * param_2[5]) * fVar1;
  local_40[1] = (param_2[1] * param_2[10] - param_2[9] * param_2[2]) * fVar2;
  local_2c = (*param_2 * param_2[10] - param_2[8] * param_2[2]) * fVar1;
  local_1c = (param_2[9] * *param_2 - param_2[8] * param_2[1]) * fVar2;
  local_40[2] = (param_2[6] * param_2[1] - param_2[5] * param_2[2]) * fVar1;
  local_28 = (param_2[6] * *param_2 - param_2[4] * param_2[2]) * fVar2;
  local_18 = (*param_2 * param_2[5] - param_2[4] * param_2[1]) * fVar1;
  local_40[3] = 0.0;
  local_24 = 0;
  local_14 = 0;
  local_4 = 0x3f800000;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  pfVar4 = local_40;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

