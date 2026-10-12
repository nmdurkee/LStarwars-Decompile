/* Ghidra pseudocode, not original source.
 * ev_4377ad99129b2c218cc07e3c8fdbc7bfca14166fd1a7528fd51d788f3b01d532
 * Entry: 0x6042e0; label: FUN_006042e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006042e0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,float param_4,
                 int param_5)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined1 local_6c [8];
  float local_64 [22];
  byte local_c [8];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_d0;
  if (DAT_0080e85c == 0) {
    __security_check_cookie(local_4 ^ (uint)&local_d0);
    return;
  }
  if (param_5 != 0) {
    FUN_005f7490();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_4 == 0.0) {
    if (_DAT_0097374c == 0.0) {
      param_4 = DAT_00973734;
    }
    else {
      param_4 = _DAT_0097374c;
    }
  }
  if ((param_3 == (undefined4 *)0x0) || (param_3 == &DAT_00806680)) {
    puVar4 = &DAT_0080b708;
    puVar5 = &DAT_0280c480;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  else {
    FUN_005b5430(&DAT_0280c480,param_3,&DAT_0080b708);
  }
  _DAT_0080e8f0 = param_4;
  _DAT_0080e8f4 = param_4;
  _DAT_0080e8f8 = param_4;
  _DAT_0080e8fc = param_4;
  if (DAT_0297c0d0 == 0) {
    local_c8 = param_1[1];
    local_c4 = param_1[2];
    local_c0 = *param_2;
    local_bc = param_2[1];
    local_b8 = param_2[2];
    local_b4 = *param_1;
    local_b0 = param_1[1];
    local_ac = param_2[2];
    local_a8 = *param_2;
    local_a4 = param_2[1];
    local_a0 = param_1[2];
    local_9c = *param_1;
    local_98 = param_2[1];
    local_94 = param_1[2];
    local_90 = *param_1;
    local_8c = param_2[1];
    local_88 = param_2[2];
    local_84 = *param_2;
    local_80 = param_1[1];
    local_7c = param_1[2];
    local_78 = *param_2;
    local_74 = param_1[1];
    local_70 = param_2[2];
    local_cc = *param_1;
    FUN_00603f10(local_6c,&local_cc,&DAT_0280c480,8);
    local_c[0] = 0;
    local_c[1] = 0;
    local_c[2] = 0;
    local_c[3] = 0;
    local_c[4] = 0;
    local_c[5] = 0;
    local_c[6] = 0;
    local_c[7] = 0;
    iVar2 = 0;
    pfVar3 = local_64;
    do {
      if (*pfVar3 < DAT_00973730) {
        local_c[iVar2] = local_c[iVar2] | 0x20;
      }
      if (param_4 < *pfVar3) {
        local_c[iVar2] = local_c[iVar2] | 0x10;
      }
      fVar1 = *pfVar3;
      if (pfVar3[-2] < -fVar1 * DAT_00966378) {
        local_c[iVar2] = local_c[iVar2] | 1;
      }
      if (*pfVar3 * DAT_00966378 < pfVar3[-2]) {
        local_c[iVar2] = local_c[iVar2] | 2;
      }
      if (pfVar3[-1] < DAT_0097313c * -fVar1) {
        local_c[iVar2] = local_c[iVar2] | 8;
      }
      if (*pfVar3 * DAT_0097313c < pfVar3[-1]) {
        local_c[iVar2] = local_c[iVar2] | 4;
      }
      if (pfVar3[3] < DAT_00973730) {
        local_c[iVar2 + 1] = local_c[iVar2 + 1] | 0x20;
      }
      if (param_4 < pfVar3[3]) {
        local_c[iVar2 + 1] = local_c[iVar2 + 1] | 0x10;
      }
      fVar1 = pfVar3[3];
      if (pfVar3[1] < -fVar1 * DAT_00966378) {
        local_c[iVar2 + 1] = local_c[iVar2 + 1] | 1;
      }
      if (pfVar3[3] * DAT_00966378 < pfVar3[1]) {
        local_c[iVar2 + 1] = local_c[iVar2 + 1] | 2;
      }
      if (pfVar3[2] < DAT_0097313c * -fVar1) {
        local_c[iVar2 + 1] = local_c[iVar2 + 1] | 8;
      }
      if (pfVar3[3] * DAT_0097313c < pfVar3[2]) {
        local_c[iVar2 + 1] = local_c[iVar2 + 1] | 4;
      }
      if (pfVar3[6] < DAT_00973730) {
        local_c[iVar2 + 2] = local_c[iVar2 + 2] | 0x20;
      }
      if (param_4 < pfVar3[6]) {
        local_c[iVar2 + 2] = local_c[iVar2 + 2] | 0x10;
      }
      fVar1 = pfVar3[6];
      if (pfVar3[4] < -fVar1 * DAT_00966378) {
        local_c[iVar2 + 2] = local_c[iVar2 + 2] | 1;
      }
      if (pfVar3[6] * DAT_00966378 < pfVar3[4]) {
        local_c[iVar2 + 2] = local_c[iVar2 + 2] | 2;
      }
      if (pfVar3[5] < DAT_0097313c * -fVar1) {
        local_c[iVar2 + 2] = local_c[iVar2 + 2] | 8;
      }
      if (pfVar3[6] * DAT_0097313c < pfVar3[5]) {
        local_c[iVar2 + 2] = local_c[iVar2 + 2] | 4;
      }
      if (pfVar3[9] < DAT_00973730) {
        local_c[iVar2 + 3] = local_c[iVar2 + 3] | 0x20;
      }
      if (param_4 < pfVar3[9]) {
        local_c[iVar2 + 3] = local_c[iVar2 + 3] | 0x10;
      }
      local_d0 = -pfVar3[9];
      if (pfVar3[7] < local_d0 * DAT_00966378) {
        local_c[iVar2 + 3] = local_c[iVar2 + 3] | 1;
      }
      if (pfVar3[9] * DAT_00966378 < pfVar3[7]) {
        local_c[iVar2 + 3] = local_c[iVar2 + 3] | 2;
      }
      if (pfVar3[8] < DAT_0097313c * local_d0) {
        local_c[iVar2 + 3] = local_c[iVar2 + 3] | 8;
      }
      if (pfVar3[9] * DAT_0097313c < pfVar3[8]) {
        local_c[iVar2 + 3] = local_c[iVar2 + 3] | 4;
      }
      iVar2 = iVar2 + 4;
      pfVar3 = pfVar3 + 0xc;
    } while (iVar2 < 8);
  }
  else {
    _DAT_02854f60 = param_1[1];
    _DAT_02854f70 = param_1[2];
    _DAT_02854f54 = *param_2;
    _DAT_02854f64 = param_2[1];
    _DAT_02854f74 = param_2[2];
    _DAT_02854f58 = *param_1;
    _DAT_02854f68 = param_1[1];
    _DAT_02854f78 = param_2[2];
    _DAT_02854f5c = *param_2;
    _DAT_02854f6c = param_2[1];
    _DAT_02854f7c = param_1[2];
    _DAT_02854f80 = *param_1;
    _DAT_02854f90 = param_2[1];
    _DAT_02854fa0 = param_1[2];
    _DAT_02854f84 = *param_1;
    _DAT_02854f94 = param_2[1];
    _DAT_02854fa4 = param_2[2];
    _DAT_02854f88 = *param_2;
    _DAT_02854f98 = param_1[1];
    _DAT_02854fa8 = param_1[2];
    _DAT_02854f8c = *param_2;
    _DAT_02854f9c = param_1[1];
    _DAT_02854fac = param_2[2];
    _DAT_02854f50 = *param_1;
    FUN_00604110(&DAT_02854fd0,&DAT_02854f50,&DAT_0280c480,8,&DAT_0097c1b0);
  }
  __security_check_cookie(local_4 ^ (uint)&local_d0);
  return;
}

