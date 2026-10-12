/* Ghidra pseudocode, not original source.
 * ev_d58eb7bbc0b728a6aebb219ddf07867fbf193ab17bd10fe9485a456632c89c4f
 * Entry: 0x5b5700; label: FUN_005b5700
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b5700(float *param_1,float *param_2,float *param_3)

{
  int iVar1;
  float *pfVar2;
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
  
  if ((param_1 != param_2) && (param_1 != param_3)) {
    *param_1 = param_3[8] * param_2[2] + *param_2 * *param_3 + param_2[1] * param_3[4];
    param_1[1] = param_3[9] * param_2[2] + *param_2 * param_3[1] + param_2[1] * param_3[5];
    param_1[2] = param_3[10] * param_2[2] + param_2[1] * param_3[6] + param_3[2] * *param_2;
    param_1[3] = 0.0;
    param_1[4] = param_2[6] * param_3[8] + *param_3 * param_2[4] + param_2[5] * param_3[4];
    param_1[5] = param_2[6] * param_3[9] + param_2[4] * param_3[1] + param_2[5] * param_3[5];
    param_1[6] = param_2[6] * param_3[10] + param_2[5] * param_3[6] + param_3[2] * param_2[4];
    param_1[7] = 0.0;
    param_1[8] = param_2[10] * param_3[8] + param_2[8] * *param_3 + param_3[4] * param_2[9];
    param_1[9] = param_3[9] * param_2[10] + param_3[5] * param_2[9] + param_2[8] * param_3[1];
    param_1[10] = param_2[10] * param_3[10] + param_2[8] * param_3[2] + param_2[9] * param_3[6];
    param_1[0xb] = 0.0;
    param_1[0xe] = 0.0;
    param_1[0xd] = 0.0;
    param_1[0xc] = 0.0;
    param_1[0xf] = 1.0;
    return;
  }
  local_40[0] = param_3[8] * param_2[2] + *param_2 * *param_3 + param_2[1] * param_3[4];
  local_40[1] = param_3[9] * param_2[2] + *param_2 * param_3[1] + param_2[1] * param_3[5];
  local_40[2] = param_3[10] * param_2[2] + param_2[1] * param_3[6] + param_3[2] * *param_2;
  local_40[3] = 0.0;
  local_40[4] = param_2[6] * param_3[8] + *param_3 * param_2[4] + param_2[5] * param_3[4];
  local_2c = param_2[6] * param_3[9] + param_2[4] * param_3[1] + param_2[5] * param_3[5];
  local_28 = param_2[6] * param_3[10] + param_2[5] * param_3[6] + param_3[2] * param_2[4];
  local_24 = 0;
  local_20 = param_2[10] * param_3[8] + param_2[8] * *param_3 + param_3[4] * param_2[9];
  local_1c = param_3[9] * param_2[10] + param_3[5] * param_2[9] + param_2[8] * param_3[1];
  local_18 = param_2[10] * param_3[10] + param_2[8] * param_3[2] + param_2[9] * param_3[6];
  local_14 = 0;
  local_8 = 0;
  local_c = 0;
  local_10 = 0;
  local_4 = 0x3f800000;
  pfVar2 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

