/* Ghidra pseudocode, not original source.
 * ev_48ff0e80e492cdbcfd6e19b242aa934bd4f134661b9f943047c850011602a6eb
 * Entry: 0x6baa80; label: FUN_006baa80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006baa80(float *param_1,float param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = param_2;
  local_50 = *param_1 + 0.0;
  local_4c = param_1[1] + 0.0;
  local_48 = param_2 + param_1[2];
  local_44 = local_34;
  if (0 < param_4) {
    iVar1 = (int)(0x10000 / (longlong)param_4);
    local_54 = param_4;
    iVar2 = iVar1;
    local_40 = local_50;
    local_3c = local_4c;
    local_38 = local_48;
    do {
      local_30 = local_50;
      local_2c = local_4c;
      local_28 = local_48;
      local_24 = local_44;
      FUN_005b3620(&local_50,&local_20,iVar2);
      local_50 = *param_1 + local_50;
      local_4c = param_1[1] + local_4c;
      local_48 = param_1[2] + local_48;
      local_44 = local_34;
      local_40 = local_50;
      local_3c = local_4c;
      local_38 = local_48;
      FUN_006ba7d0(&local_30,&local_50,param_3);
      iVar2 = iVar2 + iVar1;
      local_54 = local_54 + -1;
    } while (local_54 != 0);
  }
  return;
}

