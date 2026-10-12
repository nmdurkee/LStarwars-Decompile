/* Ghidra analysis pseudocode, not original source.
 * ev_6d5e80728f20a9db75e52af560e5ebae31a03548301b37a6feef2e83d352f64f
 * Entry: 0x5e9d90; label: FUN_005e9d90
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e9d90(int param_1,int param_2,undefined4 *param_3,int param_4,code *param_5,
                 undefined4 param_6,undefined4 param_7)

{
  float *pfVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  undefined4 *puVar10;
  float *pfVar11;
  int iVar12;
  undefined4 *puVar13;
  int iVar14;
  int local_450;
  int local_448;
  float local_440;
  float local_43c;
  float local_438;
  undefined4 local_434;
  undefined4 local_430;
  float local_42c;
  undefined4 local_428;
  undefined4 local_424;
  float local_420;
  byte *local_41c;
  undefined4 local_418;
  undefined4 local_414;
  undefined4 local_410;
  undefined4 local_40c;
  undefined4 local_408;
  undefined4 local_404;
  int local_400 [256];
  
  iVar14 = DAT_0097387c;
  piVar4 = DAT_00973878;
  if (param_1 == 0) {
    param_1 = DAT_00973880;
  }
  if (*(char *)(param_1 + 6) != '\0') {
    FUN_005e96d0(0,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    return;
  }
  if ((DAT_00973878 != (int *)0x0) && (DAT_0097387c != 0)) {
    _memset(local_400,0,*(int *)(param_2 + 0x168) * 4);
    iVar12 = 0;
    if (*piVar4 != 0) {
      iVar5 = 0;
      piVar9 = piVar4;
      do {
        iVar3 = *(int *)(iVar5 + iVar14);
        if (((-1 < iVar3) && (iVar3 < *(int *)(param_2 + 0x178))) &&
           (uVar6 = (uint)*(byte *)(*(int *)(param_2 + 0x17c) + *(int *)(iVar5 + iVar14)),
           uVar6 != 0xff)) {
          local_400[uVar6] = *piVar9;
        }
        iVar12 = iVar12 + 1;
        iVar5 = iVar12 * 4;
        piVar9 = piVar4 + iVar12;
      } while (piVar4[iVar12] != 0);
    }
  }
  _DAT_0097b9e4 = 0x3f800000;
  _DAT_0097b9e0 = 0x3f800000;
  _DAT_0097b9dc = 0x3f800000;
  iVar14 = *(int *)(param_2 + 0x16c);
  puVar10 = *(undefined4 **)(param_1 + 8);
  uVar6 = *(uint *)(param_2 + 0x168);
  if ((int)(uint)*(ushort *)(param_4 + 4) < (int)*(uint *)(param_2 + 0x168)) {
    uVar6 = (uint)*(ushort *)(param_4 + 4);
  }
  local_42c = 0.0;
  iVar12 = 0;
  local_430 = 0;
  local_434 = 0;
  local_450 = 0;
  local_41c = *(byte **)(param_1 + 0xc);
  puVar13 = param_3;
  if (0 < (int)uVar6) {
    pfVar11 = (float *)&DAT_0097adec;
    local_448 = 0;
    do {
      uVar7 = (uint)*(byte *)(iVar14 + 0x50);
      bVar2 = *local_41c;
      local_41c = local_41c + 1;
      if ((bVar2 & 1) == 0) {
        FUN_005c19d0();
      }
      else {
        local_418 = puVar10[4];
        local_414 = puVar10[5];
        local_410 = puVar10[6];
        local_40c = FUN_006e6b90();
        local_408 = FUN_006e6b90();
        local_404 = FUN_006e6b90();
        thunk_FUN_005b5300(puVar13,&local_40c);
        if ((bVar2 & 0x20) != 0) {
          thunk_FUN_005b5700(puVar13,puVar13,iVar14);
        }
      }
      pfVar1 = pfVar11 + -1;
      if ((bVar2 & 8) == 0) {
        uVar8 = (uint)*(byte *)(local_448 + 0x50 + *(int *)(param_2 + 0x16c));
        *pfVar1 = (float)(&DAT_0097ade8)[uVar8 * 3];
        *pfVar11 = (float)(&DAT_0097adec)[uVar8 * 3];
        pfVar11[1] = (float)(&DAT_0097adf0)[uVar8 * 3];
      }
      else {
        *pfVar1 = (float)puVar10[8];
        *pfVar11 = (float)puVar10[9];
        pfVar11[1] = (float)puVar10[10];
        thunk_FUN_005b4c30(puVar13,pfVar1);
        *pfVar1 = (float)(&DAT_0097ade8)[uVar7 * 3] * *pfVar1;
        *pfVar11 = (float)(&DAT_0097adec)[uVar7 * 3] * *pfVar11;
        pfVar11[1] = (float)(&DAT_0097adf0)[uVar7 * 3] * pfVar11[1];
      }
      if ((bVar2 & 0x10) != 0) {
        if ((((float)(&DAT_0097ade8)[uVar7 * 3] == 0.0) ||
            ((float)(&DAT_0097adec)[uVar7 * 3] == 0.0)) ||
           ((float)(&DAT_0097adf0)[uVar7 * 3] == 0.0)) {
          local_438 = 0.0;
          local_43c = 0.0;
          local_440 = 0.0;
          pfVar11[1] = 0.0;
          *pfVar11 = 0.0;
          *pfVar1 = 0.0;
        }
        else {
          local_440 = 1.0 / (float)(&DAT_0097ade8)[uVar7 * 3];
          local_43c = 1.0 / (float)(&DAT_0097adec)[uVar7 * 3];
          local_438 = 1.0 / (float)(&DAT_0097adf0)[uVar7 * 3];
          *pfVar1 = *pfVar1 * local_440;
          *pfVar11 = *pfVar11 * local_43c;
          pfVar11[1] = local_438 * pfVar11[1];
        }
        thunk_FUN_005b4a50(puVar13,&local_440);
      }
      if ((bVar2 & 2) != 0) {
        local_434 = *puVar10;
        local_430 = puVar10[1];
        local_420 = (float)puVar10[2];
        local_42c = -local_420;
        local_428 = local_434;
        local_424 = local_430;
        FUN_005b4900(puVar13,&local_428);
      }
      puVar13[2] = -(float)puVar13[2];
      puVar13[6] = -(float)puVar13[6];
      puVar13[8] = -(float)puVar13[8];
      puVar13[9] = -(float)puVar13[9];
      puVar13[0xb] = -(float)puVar13[0xb];
      puVar13[0xe] = -(float)puVar13[0xe];
      if (param_5 != (code *)0x0) {
        (*param_5)(puVar13,param_7,&local_434,&local_434,param_6,0);
        param_5 = (code *)0x0;
      }
      if (uVar7 == 0xff) {
        if ((bVar2 & 0x40) != 0) {
          pfVar11[1] = 1.0;
          *pfVar11 = 1.0;
          *pfVar1 = 1.0;
        }
      }
      else {
        FUN_005c0500(puVar13,puVar13,param_3 + uVar7 * 0x10);
      }
      if ((DAT_00973874 != (code *)0x0) && (local_400[local_450] != 0)) {
        (*DAT_00973874)(puVar13,local_400[local_450],0);
      }
      local_448 = local_448 + 0x60;
      iVar14 = iVar14 + 0x60;
      iVar12 = local_450 + 1;
      puVar13 = puVar13 + 0x10;
      puVar10 = puVar10 + 0xc;
      pfVar11 = pfVar11 + 3;
      local_450 = iVar12;
    } while (iVar12 < (int)uVar6);
  }
  if (iVar12 < *(int *)(param_2 + 0x168)) {
    do {
      iVar12 = iVar12 + 1;
      *puVar13 = _DAT_008065c0;
      puVar13[1] = _DAT_008065c4;
      puVar13[2] = _DAT_008065c8;
      puVar13[3] = _DAT_008065cc;
      puVar13[4] = _DAT_008065d0;
      puVar13[5] = _DAT_008065d4;
      puVar13[6] = _DAT_008065d8;
      puVar13[7] = _DAT_008065dc;
      puVar13[8] = _DAT_008065e0;
      puVar13[9] = _DAT_008065e4;
      puVar13[10] = _DAT_008065e8;
      puVar13[0xb] = _DAT_008065ec;
      puVar13[0xc] = _DAT_008065f0;
      puVar13[0xd] = _DAT_008065f4;
      puVar13[0xe] = _DAT_008065f8;
      puVar13[0xf] = _DAT_008065fc;
      puVar13 = puVar13 + 0x10;
    } while (iVar12 < *(int *)(param_2 + 0x168));
  }
  DAT_00973874 = (code *)0x0;
  DAT_00973878 = (int *)0x0;
  DAT_0097387c = 0;
  return;
}

