/* Ghidra pseudocode, not original source.
 * ev_84daf39e48317c5610d39db166d0a8d3fb26fedafe51c8456603b097e41224df
 * Entry: 0x5ff840; label: FUN_005ff840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005ff840(undefined4 *param_1,undefined4 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  float10 fVar7;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c [4];
  float local_4c;
  float local_48;
  float local_44;
  float local_3c;
  float local_38;
  float local_34;
  undefined4 local_2c;
  undefined4 local_28;
  float local_1c;
  undefined1 local_18 [12];
  float local_c;
  float local_8;
  float local_4;
  
  if (param_1 != (undefined4 *)0x0) {
    _DAT_0080e9d8 = *param_1;
    _DAT_0080e9dc = param_1[1];
    _DAT_0080e9e0 = param_1[2];
  }
  if (param_2 != (undefined4 *)0x0) {
    _DAT_0080e9c8 = *param_2;
    _DAT_0080e9cc = param_2[1];
    _DAT_0080e9d0 = param_2[2];
    _DAT_0080e9d4 = param_2[3];
  }
  FUN_005b3470(local_18,&DAT_0080e9d8,&DAT_009736e8);
  FUN_005b3d80(&local_74,local_18,&DAT_0080e9bc,0x3f000000);
  FUN_005b3200(&local_74,&local_74,&DAT_009736e8);
  FUN_005b3b30(&local_74,&local_74);
  FUN_005b3b30(&local_68,&DAT_0080e9d8);
  local_c = -DAT_00973708;
  local_8 = -DAT_0097370c;
  local_4 = -DAT_00973710;
  fVar7 = (float10)FUN_005b39e0(&local_c,&local_68);
  local_1c = (float)fVar7;
  pfVar5 = (float *)&DAT_00806680;
  pfVar6 = local_5c;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar6 = *pfVar5;
    pfVar5 = pfVar5 + 1;
    pfVar6 = pfVar6 + 1;
  }
  fVar7 = (float10)FUN_005c0240(local_74 * local_74 + local_6c * local_6c);
  local_48 = (float)fVar7;
  if (local_48 <= 1.1754944e-38) {
    local_34 = 0.0;
    local_48 = 0.0;
    local_44 = -local_70;
  }
  else {
    local_5c[0] = local_6c / local_48;
    local_4c = (local_74 * local_70) / local_48;
    local_3c = -local_74;
    local_5c[1] = 0.0;
    local_5c[2] = local_74 / local_48;
    local_44 = (-local_70 * local_6c) / local_48;
    local_34 = local_6c;
  }
  local_38 = local_70;
  local_2c = 0x3f000000;
  local_28 = 0x3f000000;
  if (local_1c < 0.0) {
    fVar1 = local_1c * local_1c * local_1c * local_1c;
    fVar1 = fVar1 * fVar1;
    fVar1 = fVar1 * fVar1;
    fVar1 = fVar1 * fVar1;
    fVar3 = 1.0 - fVar1;
    fVar2 = local_68 * fVar1;
    if (local_60 * local_3c + local_4c * local_64 + local_5c[0] * local_68 < 0.0) {
      local_5c[0] = fVar3 * local_5c[0] - fVar2;
      local_4c = fVar3 * local_4c - local_64 * fVar1;
      local_3c = fVar3 * local_3c - local_60 * fVar1;
    }
    else {
      local_5c[0] = fVar3 * local_5c[0] + fVar2;
      local_4c = fVar3 * local_4c + local_64 * fVar1;
      local_3c = fVar3 * local_3c + local_60 * fVar1;
    }
    if (local_60 * local_70 + local_48 * local_64 + local_5c[1] * local_68 < 0.0) {
      local_5c[1] = fVar3 * local_5c[1] - fVar2;
      local_48 = fVar3 * local_48 - local_64 * fVar1;
      local_38 = fVar3 * local_70 - local_60 * fVar1;
    }
    else {
      local_5c[1] = fVar3 * local_5c[1] + fVar2;
      local_48 = local_64 * fVar1 + fVar3 * local_48;
      local_38 = fVar3 * local_70 + local_60 * fVar1;
    }
  }
  FUN_005b37b0(local_18,local_18);
  FUN_005fcc10(local_18,local_5c,&DAT_0080e9c8);
  return 1;
}

