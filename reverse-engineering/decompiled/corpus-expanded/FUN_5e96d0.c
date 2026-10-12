/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5e96d0; label: FUN_005e96d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e96d0(int param_1,int param_2,int param_3,int param_4,int param_5,code *param_6,
                 undefined4 param_7,undefined4 param_8)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  float *pfVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  float *local_470;
  undefined4 *local_46c;
  undefined4 *local_468;
  byte *local_460;
  float *local_45c;
  int local_458;
  undefined4 local_440;
  undefined4 local_43c;
  float local_438;
  float local_434;
  float local_430;
  float local_42c;
  undefined4 *local_428;
  byte *local_424;
  undefined1 local_420 [16];
  int local_410 [259];
  
  uVar10 = *(uint *)(param_3 + 0x168);
  if ((int)(uint)*(ushort *)(param_5 + 4) < (int)*(uint *)(param_3 + 0x168)) {
    uVar10 = (uint)*(ushort *)(param_5 + 4);
  }
  iVar2 = FUN_006de8d0((uVar10 + 1) * 0x10);
  iVar3 = FUN_006de8d0(uVar10 * 0xc);
  if ((iVar2 == 0) || (iVar3 == 0)) {
    FUN_005c12e0();
  }
  local_468 = (undefined4 *)(iVar2 + 0xfU & 0xfffffff0);
  if (param_2 == 0) {
    param_2 = DAT_00973880;
  }
  local_428 = local_468;
  if ((DAT_00973878 != (int *)0x0) && (DAT_0097387c != 0)) {
    _memset(local_410,0,*(int *)(param_3 + 0x168) * 4);
    iVar2 = 0;
    if (*DAT_00973878 != 0) {
      iVar4 = 0;
      piVar7 = DAT_00973878;
      do {
        if (((-1 < *(int *)(iVar4 + DAT_0097387c)) &&
            (*(int *)(iVar4 + DAT_0097387c) < *(int *)(param_3 + 0x178))) &&
           (uVar5 = (uint)*(byte *)(*(int *)(param_3 + 0x17c) + *(int *)(iVar4 + DAT_0097387c)),
           uVar5 != 0xff)) {
          local_410[uVar5] = *piVar7;
        }
        iVar2 = iVar2 + 1;
        iVar4 = iVar2 * 4;
        piVar7 = DAT_00973878 + iVar2;
      } while (DAT_00973878[iVar2] != 0);
    }
  }
  if (param_1 == 0) {
    local_42c = 1.0;
    local_430 = 1.0;
    local_434 = 1.0;
    local_468[0x3fc] = 0;
    local_468[0x3fd] = 0;
    local_468[0x3fe] = 0;
    local_468[0x3ff] = 0x3f800000;
  }
  else {
    pfVar6 = (float *)FUN_005b4b90(local_420,param_1);
    local_434 = *pfVar6;
    local_430 = pfVar6[1];
    local_42c = pfVar6[2];
    FUN_005b7ea0(param_1,local_468 + 0x3fc);
  }
  puVar8 = *(undefined4 **)(param_2 + 8);
  local_438 = 0.0;
  local_43c = 0;
  local_440 = 0;
  local_458 = 0;
  iVar2 = param_4;
  if (0 < (int)uVar10) {
    local_470 = (float *)(iVar3 + 4);
    local_46c = (undefined4 *)(param_4 + 0x30);
    local_460 = (byte *)(*(int *)(param_3 + 0x16c) + 0x50);
    local_424 = *(byte **)(param_2 + 0xc);
    do {
      uVar5 = (uint)*local_460;
      bVar1 = *local_424;
      local_424 = local_424 + 1;
      if ((bVar1 & 1) == 0) {
        *local_468 = 0;
        local_468[1] = 0;
        local_468[2] = 0;
        local_468[3] = 0x3f800000;
      }
      else {
        *local_468 = puVar8[4];
        local_468[1] = puVar8[5];
        local_468[2] = puVar8[6];
        local_468[3] = puVar8[7];
      }
      if (uVar5 == 0xff) {
        local_45c = (float *)(iVar3 + 0xbf4);
      }
      else {
        FUN_005c1880(local_468);
        local_45c = &local_434;
      }
      FUN_005b8040(local_468,iVar2);
      if ((bVar1 & 8) == 0) {
        local_470[-1] = *local_45c;
        *local_470 = local_45c[1];
        local_470[1] = local_45c[2];
      }
      else {
        local_470[-1] = (float)puVar8[8] * *local_45c;
        *local_470 = local_45c[1] * (float)puVar8[9];
        local_470[1] = local_45c[2] * (float)puVar8[10];
        thunk_FUN_005b4c30(iVar2,local_470 + -1);
      }
      if ((bVar1 & 0x10) != 0) {
        local_470[1] = 1.0;
        *local_470 = 1.0;
        local_470[-1] = 1.0;
      }
      if ((bVar1 & 2) == 0) {
        if (uVar5 == 0xff) {
          if (param_1 != 0) {
            *local_46c = *(undefined4 *)(param_1 + 0x30);
            local_46c[1] = *(undefined4 *)(param_1 + 0x34);
            local_46c[2] = *(undefined4 *)(param_1 + 0x38);
            local_46c[3] = *(undefined4 *)(param_1 + 0x3c);
          }
          goto LAB_005e9a8e;
        }
        iVar4 = uVar5 * 0x40 + param_4;
        *local_46c = *(undefined4 *)(uVar5 * 0x40 + 0x30 + param_4);
        local_46c[1] = *(undefined4 *)(iVar4 + 0x34);
        local_46c[2] = *(undefined4 *)(iVar4 + 0x38);
        local_46c[3] = *(undefined4 *)(iVar4 + 0x3c);
      }
      else {
        local_440 = *puVar8;
        local_43c = puVar8[1];
        local_438 = -(float)puVar8[2];
        if (uVar5 == 0xff) {
          if (param_1 == 0) {
            *local_46c = *puVar8;
            local_46c[1] = puVar8[1];
            local_46c[2] = puVar8[2];
          }
          else {
            FUN_005b30a0(local_46c,puVar8,param_1);
          }
LAB_005e9a8e:
          if (param_6 != (code *)0x0) {
            (*param_6)(iVar2,param_8,&local_440,&local_440,param_7,0);
            param_6 = (code *)0x0;
          }
          if ((bVar1 & 0x40) != 0) {
            local_470[1] = 1.0;
            *local_470 = 1.0;
            local_470[-1] = 1.0;
          }
        }
        else {
          FUN_005b30a0(local_46c,puVar8,uVar5 * 0x40 + param_4);
        }
      }
      if ((DAT_00973874 != (code *)0x0) && (local_410[local_458] != 0)) {
        (*DAT_00973874)(iVar2,local_410[local_458],local_468);
      }
      local_46c = local_46c + 0x10;
      local_468 = local_468 + 4;
      local_460 = local_460 + 0x60;
      local_458 = local_458 + 1;
      local_470 = local_470 + 3;
      iVar2 = iVar2 + 0x40;
      puVar8 = puVar8 + 0xc;
    } while (local_458 < (int)uVar10);
  }
  puVar8 = (undefined4 *)(iVar2 + uVar10 * -0x40);
  iVar2 = 0;
  if (3 < (int)uVar10) {
    iVar3 = (uVar10 - 4 >> 2) + 1;
    iVar2 = iVar3 * 4;
    puVar9 = puVar8;
    do {
      puVar8 = puVar9 + 0x40;
      iVar3 = iVar3 + -1;
      puVar9[2] = -(float)puVar9[2];
      puVar9[6] = -(float)puVar9[6];
      puVar9[8] = -(float)puVar9[8];
      puVar9[9] = -(float)puVar9[9];
      puVar9[0xb] = -(float)puVar9[0xb];
      puVar9[0xe] = -(float)puVar9[0xe];
      puVar9[0x12] = -(float)puVar9[0x12];
      puVar9[0x16] = -(float)puVar9[0x16];
      puVar9[0x18] = -(float)puVar9[0x18];
      puVar9[0x19] = -(float)puVar9[0x19];
      puVar9[0x1b] = -(float)puVar9[0x1b];
      puVar9[0x1e] = -(float)puVar9[0x1e];
      puVar9[0x22] = -(float)puVar9[0x22];
      puVar9[0x26] = -(float)puVar9[0x26];
      puVar9[0x28] = -(float)puVar9[0x28];
      puVar9[0x29] = -(float)puVar9[0x29];
      puVar9[0x2b] = -(float)puVar9[0x2b];
      puVar9[0x2e] = -(float)puVar9[0x2e];
      puVar9[0x32] = -(float)puVar9[0x32];
      puVar9[0x36] = -(float)puVar9[0x36];
      puVar9[0x38] = -(float)puVar9[0x38];
      puVar9[0x39] = -(float)puVar9[0x39];
      puVar9[0x3b] = -(float)puVar9[0x3b];
      puVar9[0x3e] = -(float)puVar9[0x3e];
      puVar9 = puVar8;
    } while (iVar3 != 0);
  }
  if (iVar2 < (int)uVar10) {
    iVar3 = uVar10 - iVar2;
    iVar2 = iVar2 + iVar3;
    puVar9 = puVar8;
    do {
      puVar8 = puVar9 + 0x10;
      iVar3 = iVar3 + -1;
      puVar9[2] = -(float)puVar9[2];
      puVar9[6] = -(float)puVar9[6];
      puVar9[8] = -(float)puVar9[8];
      puVar9[9] = -(float)puVar9[9];
      puVar9[0xb] = -(float)puVar9[0xb];
      puVar9[0xe] = -(float)puVar9[0xe];
      puVar9 = puVar8;
    } while (iVar3 != 0);
  }
  if (iVar2 < *(int *)(param_3 + 0x168)) {
    do {
      iVar2 = iVar2 + 1;
      *puVar8 = _DAT_008065c0;
      puVar8[1] = _DAT_008065c4;
      puVar8[2] = _DAT_008065c8;
      puVar8[3] = _DAT_008065cc;
      puVar8[4] = _DAT_008065d0;
      puVar8[5] = _DAT_008065d4;
      puVar8[6] = _DAT_008065d8;
      puVar8[7] = _DAT_008065dc;
      puVar8[8] = _DAT_008065e0;
      puVar8[9] = _DAT_008065e4;
      puVar8[10] = _DAT_008065e8;
      puVar8[0xb] = _DAT_008065ec;
      puVar8[0xc] = _DAT_008065f0;
      puVar8[0xd] = _DAT_008065f4;
      puVar8[0xe] = _DAT_008065f8;
      puVar8[0xf] = _DAT_008065fc;
      puVar8 = puVar8 + 0x10;
    } while (iVar2 < *(int *)(param_3 + 0x168));
  }
  DAT_00973874 = (code *)0x0;
  DAT_00973878 = (int *)0x0;
  DAT_0097387c = 0;
  FUN_006de960();
  FUN_006de960();
  return;
}

