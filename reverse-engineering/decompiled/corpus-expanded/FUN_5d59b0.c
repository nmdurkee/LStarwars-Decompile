/* Ghidra pseudocode, not original source.
 * ev_8bfd975316f8cf2b7f750252451c539d63e4b7da44e3fbde714e6599bb2e7713
 * Entry: 0x5d59b0; label: FUN_005d59b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d59b0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,float param_4,
                 byte param_5,float *param_6)

{
  float fVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  float *local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac [16];
  undefined1 local_6c [8];
  float local_64;
  undefined1 local_60 [12];
  undefined1 local_54 [12];
  undefined1 local_48 [12];
  undefined1 local_3c [12];
  undefined1 local_30 [12];
  undefined1 local_24 [12];
  undefined1 local_18 [12];
  byte local_c [8];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_110;
  local_110 = param_6;
  if (param_4 == 0.0) {
    param_4 = DAT_00973734;
  }
  if ((param_3 == (undefined4 *)0x0) || (param_3 == &DAT_00806680)) {
    puVar7 = &DAT_0080b708;
    puVar8 = local_ac;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
  }
  else {
    FUN_005b5430(local_ac,param_3,&DAT_0080b708);
  }
  local_10c = *param_1;
  local_108 = param_1[1];
  local_104 = param_1[2];
  local_100 = *param_2;
  local_fc = param_2[1];
  local_f8 = param_2[2];
  local_f4 = *param_1;
  local_f0 = param_1[1];
  local_ec = param_2[2];
  local_e8 = *param_2;
  local_e4 = param_2[1];
  local_e0 = param_1[2];
  local_dc = *param_1;
  local_d8 = param_2[1];
  local_d4 = param_1[2];
  local_d0 = *param_1;
  local_cc = param_2[1];
  local_c8 = param_2[2];
  local_c4 = *param_2;
  local_c0 = param_1[1];
  local_bc = param_1[2];
  local_b8 = *param_2;
  local_b4 = param_1[1];
  local_b0 = param_2[2];
  FUN_005b30a0(local_6c,&local_10c,local_ac);
  FUN_005b30a0(local_60,&local_100,local_ac);
  FUN_005b30a0(local_54,&local_f4,local_ac);
  FUN_005b30a0(local_48,&local_e8,local_ac);
  FUN_005b30a0(local_3c,&local_dc,local_ac);
  FUN_005b30a0(local_30,&local_d0,local_ac);
  FUN_005b30a0(local_24,&local_c4,local_ac);
  FUN_005b30a0(local_18,&local_b8,local_ac);
  *local_110 = 3.4028235e+38;
  local_c[0] = 0;
  local_c[1] = 0;
  local_c[2] = 0;
  local_c[3] = 0;
  local_c[4] = 0;
  local_c[5] = 0;
  local_c[6] = 0;
  local_c[7] = 0;
  iVar6 = 0;
  pfVar5 = &local_64;
  fVar3 = DAT_00973730;
  fVar1 = DAT_00966378;
  fVar4 = DAT_0097313c;
  do {
    if (*pfVar5 < *local_110) {
      *local_110 = *pfVar5;
      fVar3 = DAT_00973730;
      fVar1 = DAT_00966378;
      fVar4 = DAT_0097313c;
    }
    if ((*pfVar5 < fVar3) && ((param_5 & 2) == 0)) {
      local_c[iVar6] = local_c[iVar6] | 0x20;
    }
    if (param_4 < *pfVar5) {
      local_c[iVar6] = local_c[iVar6] | 0x10;
    }
    pfVar2 = (float *)-*pfVar5;
    if (pfVar5[-2] < (float)pfVar2 * fVar1) {
      local_c[iVar6] = local_c[iVar6] | 1;
    }
    if (*pfVar5 * fVar1 < pfVar5[-2]) {
      local_c[iVar6] = local_c[iVar6] | 2;
    }
    if (pfVar5[-1] < fVar4 * (float)pfVar2) {
      local_c[iVar6] = local_c[iVar6] | 8;
    }
    if (*pfVar5 * fVar4 < pfVar5[-1]) {
      local_c[iVar6] = local_c[iVar6] | 4;
    }
    iVar6 = iVar6 + 1;
    pfVar5 = pfVar5 + 3;
  } while (iVar6 < 8);
  local_110 = pfVar2;
  if ((byte)((byte)local_c._0_4_ &
            local_c[7] & local_c[6] & SUB41(local_c._4_4_,1) & (byte)local_c._4_4_ & local_c[3] &
            local_c[2] & SUB41(local_c._0_4_,1)) == 0) {
    if (((((((local_c[7] != 0 || local_c[6] != 0) || SUB41(local_c._4_4_,1) != 0) ||
           (byte)local_c._4_4_ != 0) || local_c[3] != 0) || local_c[2] != 0) ||
        SUB41(local_c._0_4_,1) != 0) || (byte)local_c._0_4_ != 0) {
      if ((param_5 & 1) != 0) {
        __security_check_cookie(local_4 ^ (uint)&local_110);
        return;
      }
      local_c[0] = 0;
      local_c[1] = 0;
      local_c[2] = 0;
      local_c[3] = 0;
      local_c[4] = 0;
      local_c[5] = 0;
      local_c[6] = 0;
      local_c[7] = 0;
      iVar6 = 0;
      pfVar5 = &local_64;
      do {
        if ((*pfVar5 < fVar3) && ((param_5 & 2) == 0)) {
          local_c[iVar6] = local_c[iVar6] | 0x20;
        }
        if (param_4 < *pfVar5) {
          local_c[iVar6] = local_c[iVar6] | 0x10;
        }
        fVar1 = *pfVar5;
        if (pfVar5[-2] < -fVar1 * _DAT_00966270) {
          local_c[iVar6] = local_c[iVar6] | 1;
        }
        if (*pfVar5 * _DAT_00966270 < pfVar5[-2]) {
          local_c[iVar6] = local_c[iVar6] | 2;
        }
        if (pfVar5[-1] < _DAT_0096dce4 * -fVar1) {
          local_c[iVar6] = local_c[iVar6] | 8;
        }
        if (*pfVar5 * _DAT_0096dce4 < pfVar5[-1]) {
          local_c[iVar6] = local_c[iVar6] | 4;
        }
        if ((pfVar5[3] < fVar3) && ((param_5 & 2) == 0)) {
          local_c[iVar6 + 1] = local_c[iVar6 + 1] | 0x20;
        }
        if (param_4 < pfVar5[3]) {
          local_c[iVar6 + 1] = local_c[iVar6 + 1] | 0x10;
        }
        fVar1 = pfVar5[3];
        if (pfVar5[1] < -fVar1 * _DAT_00966270) {
          local_c[iVar6 + 1] = local_c[iVar6 + 1] | 1;
        }
        if (pfVar5[3] * _DAT_00966270 < pfVar5[1]) {
          local_c[iVar6 + 1] = local_c[iVar6 + 1] | 2;
        }
        if (pfVar5[2] < _DAT_0096dce4 * -fVar1) {
          local_c[iVar6 + 1] = local_c[iVar6 + 1] | 8;
        }
        if (pfVar5[3] * _DAT_0096dce4 < pfVar5[2]) {
          local_c[iVar6 + 1] = local_c[iVar6 + 1] | 4;
        }
        if ((pfVar5[6] < fVar3) && ((param_5 & 2) == 0)) {
          local_c[iVar6 + 2] = local_c[iVar6 + 2] | 0x20;
        }
        if (param_4 < pfVar5[6]) {
          local_c[iVar6 + 2] = local_c[iVar6 + 2] | 0x10;
        }
        fVar1 = pfVar5[6];
        if (pfVar5[4] < -fVar1 * _DAT_00966270) {
          local_c[iVar6 + 2] = local_c[iVar6 + 2] | 1;
        }
        if (pfVar5[6] * _DAT_00966270 < pfVar5[4]) {
          local_c[iVar6 + 2] = local_c[iVar6 + 2] | 2;
        }
        if (pfVar5[5] < _DAT_0096dce4 * -fVar1) {
          local_c[iVar6 + 2] = local_c[iVar6 + 2] | 8;
        }
        if (pfVar5[6] * _DAT_0096dce4 < pfVar5[5]) {
          local_c[iVar6 + 2] = local_c[iVar6 + 2] | 4;
        }
        if ((pfVar5[9] < fVar3) && ((param_5 & 2) == 0)) {
          local_c[iVar6 + 3] = local_c[iVar6 + 3] | 0x20;
        }
        if (param_4 < pfVar5[9]) {
          local_c[iVar6 + 3] = local_c[iVar6 + 3] | 0x10;
        }
        local_110 = (float *)-pfVar5[9];
        if (pfVar5[7] < (float)local_110 * _DAT_00966270) {
          local_c[iVar6 + 3] = local_c[iVar6 + 3] | 1;
        }
        if (pfVar5[9] * _DAT_00966270 < pfVar5[7]) {
          local_c[iVar6 + 3] = local_c[iVar6 + 3] | 2;
        }
        if (pfVar5[8] < _DAT_0096dce4 * (float)local_110) {
          local_c[iVar6 + 3] = local_c[iVar6 + 3] | 8;
        }
        if (pfVar5[9] * _DAT_0096dce4 < pfVar5[8]) {
          local_c[iVar6 + 3] = local_c[iVar6 + 3] | 4;
        }
        iVar6 = iVar6 + 4;
        pfVar5 = pfVar5 + 0xc;
      } while (iVar6 < 8);
    }
    __security_check_cookie(local_4 ^ (uint)&local_110);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)&local_110);
  return;
}

