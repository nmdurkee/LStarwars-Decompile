/* Ghidra pseudocode, not original source.
 * ev_48ff0e80e492cdbcfd6e19b242aa934bd4f134661b9f943047c850011602a6eb
 * Entry: 0x6bc200; label: FUN_006bc200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bc200(float *param_1,float param_2,uint param_3)

{
  float *pfVar1;
  float fVar2;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  
  pfVar1 = param_1 + 0xc;
  local_40 = *pfVar1 + param_2 * *param_1;
  local_3c = param_1[0xd] + param_1[1] * param_2;
  local_38 = param_1[2] * param_2 + param_1[0xe];
  fVar2 = param_2 * 0.02;
  local_30 = local_40;
  local_2c = local_3c;
  local_28 = local_38;
  FUN_006bbec0(pfVar1,&local_40,8,param_3 & 0xff | 0xff000000,fVar2,fVar2,0x3ca3d70a,0);
  local_20 = param_2 * param_1[4];
  local_1c = param_1[5] * param_2;
  local_18 = param_2 * param_1[6];
  local_40 = *pfVar1 + local_20;
  local_3c = param_1[0xd] + local_1c;
  local_38 = local_18 + param_1[0xe];
  local_34 = local_24;
  local_30 = local_40;
  local_2c = local_3c;
  local_28 = local_38;
  FUN_006bbec0(pfVar1,&local_40,8,(param_3 & 0xff | 0xffff0000) << 8,fVar2,fVar2,0x3ca3d70a,0);
  local_20 = param_2 * param_1[8];
  local_1c = param_1[9] * param_2;
  local_18 = param_2 * param_1[10];
  local_40 = *pfVar1 + local_20;
  local_3c = param_1[0xd] + local_1c;
  local_38 = local_18 + param_1[0xe];
  local_34 = local_24;
  local_30 = local_40;
  local_2c = local_3c;
  local_28 = local_38;
  FUN_006bbec0(pfVar1,&local_40,8,(param_3 | 0xffffff00) << 0x10,fVar2,fVar2,0x3ca3d70a,0);
  return;
}

