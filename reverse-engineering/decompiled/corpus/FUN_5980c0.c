/* Ghidra analysis pseudocode, not original source.
 * ev_2b6ca283a8ac7011eb105309a135b5adaaf9bfbb0074228736b4018ed27e76f8
 * Entry: 0x5980c0; label: FUN_005980c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005980c0(int param_1,int param_2)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  float *pfVar8;
  undefined4 *puVar9;
  float *pfVar10;
  undefined4 *puVar11;
  float **ppfVar12;
  float local_1b0 [4];
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  float local_180;
  float local_17c;
  float local_178;
  float local_16c;
  undefined4 local_168;
  float local_164;
  undefined4 local_160 [4];
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined1 local_11c [12];
  float *local_110 [3];
  int local_104;
  float local_fc;
  float local_f8;
  undefined4 local_f4;
  int local_ec;
  undefined4 local_e4;
  code *local_d4;
  undefined1 *local_cc;
  undefined4 local_84;
  int local_7c;
  undefined4 local_6c;
  undefined4 local_48 [12];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar5 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x108);
  if ((iVar5 != -1) && (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar5 * 4) != 0)) {
    if (DAT_008051cc == 0) {
      pfVar8 = (float *)(iVar5 * 0x40 + 0x804 + param_1);
      pfVar10 = local_1b0;
      for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
        *pfVar10 = *pfVar8;
        pfVar8 = pfVar8 + 1;
        pfVar10 = pfVar10 + 1;
      }
    }
    else {
      if (DAT_008051d0 == 0) {
        fVar1 = *(float *)(param_1 + 0x748);
        uVar2 = *(undefined4 *)(param_1 + 0x74c);
        pfVar8 = (float *)&DAT_00806680;
        pfVar10 = local_1b0;
        for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
          *pfVar10 = *pfVar8;
          pfVar8 = pfVar8 + 1;
          pfVar10 = pfVar10 + 1;
        }
        local_1b0[2] = *(float *)(param_1 + 0x750);
        local_1a0 = *(undefined4 *)(param_1 + 0x754);
        local_19c = *(undefined4 *)(param_1 + 0x758);
        local_198 = *(undefined4 *)(param_1 + 0x75c);
        local_190 = *(undefined4 *)(param_1 + 0x760);
        local_18c = *(undefined4 *)(param_1 + 0x764);
        local_188 = *(undefined4 *)(param_1 + 0x768);
        local_1b0[0] = fVar1;
        local_1b0[1] = (float)uVar2;
      }
      else {
        FUN_005b4670(local_1b0,*(undefined2 *)(param_1 + 0x7a6));
      }
      FUN_005b4f70(local_1b0,*(undefined2 *)(param_1 + 0x27a));
      FUN_005b4900(local_1b0,iVar5 * 0x40 + 0x834 + param_1);
    }
    iVar5 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x109);
    if ((iVar5 != -1) && (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar5 * 4) != 0)) {
      if (DAT_008051cc == 0) {
        pfVar8 = local_1b0;
        pfVar10 = (float *)local_48;
        for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
          *pfVar10 = *pfVar8;
          pfVar8 = pfVar8 + 1;
          pfVar10 = pfVar10 + 1;
        }
        local_10 = 0;
        local_14 = 0;
        local_18 = 0;
        puVar9 = (undefined4 *)(iVar5 * 0x40 + 0x804 + param_1);
        puVar11 = local_160;
        for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar11 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar11 = puVar11 + 1;
        }
        local_128 = 0;
        local_12c = 0;
        local_130 = 0;
        FUN_00550690(local_1b0,local_48,local_160,0x3f000000);
      }
      iVar7 = iVar5 * 0x40 + param_1;
      local_180 = (*(float *)(iVar5 * 0x40 + 0x834 + param_1) + local_180) * 0.5;
      local_17c = (*(float *)(iVar7 + 0x838) + local_17c) * 0.5;
      local_178 = (*(float *)(iVar7 + 0x83c) + local_178) * 0.5;
    }
    fVar4 = local_178;
    fVar3 = local_17c;
    fVar1 = local_180;
    if (DAT_008051cc == 0) {
      local_160[1] = *(undefined4 *)(param_1 + 0x74c);
      local_160[0] = *(undefined4 *)(param_1 + 0x748);
      local_160[2] = *(undefined4 *)(param_1 + 0x750);
      local_150 = *(undefined4 *)(param_1 + 0x754);
      local_14c = *(undefined4 *)(param_1 + 0x758);
      local_148 = *(undefined4 *)(param_1 + 0x75c);
      local_140 = *(undefined4 *)(param_1 + 0x760);
      local_13c = *(undefined4 *)(param_1 + 0x764);
      local_138 = *(undefined4 *)(param_1 + 0x768);
      FUN_005b5700(local_1b0,local_160,local_1b0);
      local_180 = fVar1;
      local_17c = fVar3;
      local_178 = fVar4;
    }
    else {
      local_180 = fVar1;
      local_17c = fVar3;
      local_178 = fVar4;
      if (DAT_008051d0 != 0) {
        FUN_005b3620(local_11c,param_1 + 0x748,*(undefined2 *)(param_1 + 0x27a));
        FUN_005b4900(local_1b0,local_11c);
      }
    }
    puVar9 = &DAT_00810210;
    ppfVar12 = local_110;
    for (iVar5 = 0x32; iVar5 != 0; iVar5 = iVar5 + -1) {
      *ppfVar12 = (float *)*puVar9;
      puVar9 = puVar9 + 1;
      ppfVar12 = ppfVar12 + 1;
    }
    local_110[0] = local_1b0;
    local_164 = _DAT_008051b4;
    if ((param_2 != 0) && (local_164 = _DAT_008051c0, param_2 == 1)) {
      local_164 = _DAT_008051bc;
    }
    local_16c = local_164 * (float)(&DAT_029899a0)[*(ushort *)(param_1 + 0x58) >> 1];
    local_164 = local_164 *
                (float)(&DAT_029899a0)[(int)(*(ushort *)(param_1 + 0x58) + 0x4000) >> 1 & 0x7fff];
    local_168 = _DAT_008051b8;
    if (param_2 == 2) {
      local_168 = _DAT_008051c4;
    }
    local_110[2] = &local_16c;
    iVar5 = *(int *)(param_1 + 0x798);
    local_ec = *(int *)(iVar5 + 0xa4) + 0x30;
    local_fc = *(float *)(iVar5 + 0xa8) * 0.5;
    local_e4 = 0x8011;
    if ((*(byte *)(iVar5 + 0x9c) & 4) == 0) {
      local_e4 = 0x8111;
    }
    local_84 = _DAT_00925018;
    local_7c = param_1 + 0x4d8;
    local_f4 = _DAT_008051c8;
    local_104 = param_1;
    local_d4 = FUN_00597d00;
    local_6c = 0x40400000;
    local_cc = &LAB_00597d90;
    local_f8 = local_fc;
    iVar5 = FUN_0064d270(local_110);
    if (iVar5 != 0) {
      uVar6 = FUN_0058b720(param_1);
      *(uint *)(iVar5 + 0x218) = uVar6 & 0xffff;
      *(undefined4 *)(iVar5 + 0x218) = *(undefined4 *)(param_1 + 0x798);
      *(short *)(iVar5 + 0x13a) = *(short *)(param_1 + 0x7a6) + *(short *)(param_1 + 0x5a);
    }
  }
  return;
}

