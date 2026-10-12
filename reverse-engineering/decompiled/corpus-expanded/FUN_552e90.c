/* Ghidra pseudocode, not original source.
 * ev_9398ef22b4c43c044c1b187060a2935e0b1d1dc3bbb9f543c9cb1dd758ae788c
 * Entry: 0x552e90; label: FUN_00552e90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00552e90(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,undefined4 param_9,int param_10,int param_11,
                 undefined4 param_12,float param_13)

{
  undefined4 uVar1;
  short sVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  char cVar9;
  undefined4 *puVar10;
  bool bVar11;
  int local_140;
  int local_13c;
  uint local_134;
  uint local_130;
  float local_118;
  float fStack_114;
  float fStack_110;
  float local_10c;
  float fStack_108;
  float fStack_104;
  undefined4 local_100 [12];
  float local_d0;
  float local_cc;
  float local_c8;
  undefined4 local_c0 [12];
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_80 [12];
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 auStack_40 [64];
  
  iVar7 = DAT_0093b0fc;
  sVar2 = DAT_0093b0f8;
  DAT_0093b0fc = 0;
  DAT_0093b0f8 = 0;
  if (param_2 == 0) {
    local_13c = DAT_00802540;
    if (DAT_00802540 == -1) {
      DAT_0093b0f8 = 0;
      DAT_0093b0fc = 0;
      return;
    }
    if (DAT_0093b0e8 == 0) {
      DAT_0093b0f8 = 0;
      DAT_0093b0fc = 0;
      return;
    }
    local_140 = DAT_0093b0ec;
    if (DAT_0093b0ec == 0) {
      DAT_0093b0f8 = 0;
      DAT_0093b0fc = 0;
      return;
    }
    local_134 = DAT_0093b0f0;
    local_130 = DAT_0093b0f4;
    uVar1 = _DAT_00802544;
  }
  else {
    local_13c = (int)*(short *)(param_2 + 0x1064);
    local_140 = *(int *)(param_2 + 0x50);
    local_134 = (uint)*(byte *)(param_2 + 0x1082);
    local_130 = (uint)*(byte *)(param_2 + 0x107b);
    uVar1 = *(undefined4 *)(param_2 + 0x1014);
  }
  DAT_00802540 = 0xffffffff;
  _DAT_00802544 = 0x49f42400;
  DAT_0093b0e8 = 0;
  DAT_0093b0ec = 0;
  DAT_0093b0f0 = 0;
  DAT_0093b0f4 = 0;
  if (param_1 == 0) {
    param_1 = FUN_0055f450();
  }
  if (param_3 == -1) {
    if (param_4 == 0) {
      return;
    }
    iVar6 = FUN_005cfac0(param_4);
    bVar11 = iVar6 == 0;
  }
  else {
    bVar11 = *(char *)(*(int *)(param_1 + 0x2ac0) + 0xe + param_3 * 0x10) == '\0';
  }
  if (((!bVar11) && (param_5 != -1)) && (*(int *)(local_140 + 0x14 + param_5 * 4) != 0)) {
    if (iVar7 == 0) {
      puVar8 = (undefined4 *)(param_5 * 0x40 + param_7);
      puVar10 = local_100;
      for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
      }
    }
    else {
      FUN_005b4500(local_100,param_5 * 0x40 + 0x30 + param_7);
    }
    if ((param_6 != -1) && (*(int *)(local_140 + 0x14 + param_6 * 4) != 0)) {
      if (iVar7 == 0) {
        puVar8 = local_100;
        puVar10 = local_80;
        for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar10 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar10 = puVar10 + 1;
        }
        local_48 = 0;
        local_4c = 0;
        local_50 = 0;
        puVar8 = (undefined4 *)(param_6 * 0x40 + param_7);
        puVar10 = local_c0;
        for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar10 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar10 = puVar10 + 1;
        }
        local_88 = 0;
        local_8c = 0;
        local_90 = 0;
        FUN_00550690(local_100,local_80,local_c0,0x3f000000);
      }
      iVar7 = param_7 + param_6 * 0x40;
      local_d0 = (*(float *)(param_7 + 0x30 + param_6 * 0x40) + local_d0) * 0.5;
      local_cc = (*(float *)(iVar7 + 0x34) + local_cc) * 0.5;
      local_c8 = (*(float *)(iVar7 + 0x38) + local_c8) * 0.5;
    }
    if (sVar2 != 0) {
      FUN_005b5240(local_100,sVar2);
    }
    if (((param_3 != -1) && (param_3 == *(short *)(PTR_DAT_00803e00 + 4))) &&
       (DAT_0093b100 != (code *)0x0)) {
      (*DAT_0093b100)(local_13c,local_134,&local_10c,&local_118);
      if (((local_10c != 1.0) || (fStack_108 != 1.0)) || (fStack_104 != 1.0)) {
        FUN_005b4c30(local_100,&local_10c);
      }
      if (((local_118 != 0.0) || (fStack_114 != 0.0)) || (fStack_110 != 0.0)) {
        FUN_005b4960(local_100,&local_118);
      }
    }
    fVar5 = local_c8;
    fVar4 = local_cc;
    fVar3 = local_d0;
    if (param_10 != 0) {
      FUN_005b5700(local_100,param_10,local_100);
    }
    local_d0 = fVar3;
    local_cc = fVar4;
    local_c8 = fVar5;
    if (param_11 != 0) {
      FUN_005b4900(local_100,param_11);
    }
    cVar9 = '\0';
    if ((param_3 != -1) &&
       (param_4 = param_3 * 0x10 + *(int *)(param_1 + 0x2ac0), DAT_00951bb8 != 0)) {
      cVar9 = *(char *)(DAT_00951bb8 + 1 + param_3 * 8);
    }
    if (param_13 != 1.0) {
      FUN_005b4b30(local_100,param_13);
    }
    if (cVar9 == '\0') {
      FUN_005f33b0(param_4,local_100);
    }
    else {
      FUN_005ff7a0(param_4,local_100,param_12);
    }
    if ((param_8 != 0) &&
       (iVar7 = FUN_00550490(local_100,local_130,uVar1,
                             *(undefined4 *)(*(int *)(param_1 + 0x128) + 0xc0),auStack_40),
       iVar7 != 0)) {
      FUN_005d4690(0);
      if (cVar9 != '\0') {
        FUN_005ff7a0(param_4,auStack_40,param_12);
        FUN_005d46b0();
        return;
      }
      FUN_005f33b0(param_4,auStack_40);
      FUN_005d46b0();
    }
  }
  return;
}

