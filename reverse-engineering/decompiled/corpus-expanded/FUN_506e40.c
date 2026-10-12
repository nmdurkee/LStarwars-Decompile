/* Ghidra pseudocode, not original source.
 * ev_9d34c938d292037f498e462893e532f4f6f058923093d2cacbd29fd836aaae04
 * Entry: 0x506e40; label: FUN_00506e40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_00506e40(int param_1,undefined4 param_2,int param_3,int param_4)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  float fVar6;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar7;
  float10 extraout_ST1;
  float local_4150;
  float local_414c;
  float local_4148;
  int local_4144;
  float local_4140;
  float local_413c;
  float local_4138;
  float local_4130;
  float local_412c;
  float local_4128;
  float local_4120;
  float local_411c;
  float local_4118;
  undefined4 local_4114;
  undefined1 local_4110 [4];
  undefined1 local_410c [4];
  undefined1 local_4108 [4];
  undefined1 local_4104 [4];
  undefined1 local_4100 [48];
  float local_40d0;
  float local_40cc;
  float local_40c8;
  undefined1 local_40c0 [64];
  undefined1 local_4080 [64];
  undefined1 local_4040 [64];
  undefined1 local_4000 [48];
  float local_3fd0;
  float local_3fcc;
  float local_3fc8;
  undefined4 uStack_4;
  
  uStack_4 = 0x506e4a;
  local_4150 = 0.0;
  local_414c = 0.0;
  local_4148 = 0.0;
  if (**(int **)(param_1 + 0x50) < 0x414e4934) {
    return;
  }
  if (0x414e4935 < **(int **)(param_1 + 0x50)) {
    return;
  }
  piVar2 = *(int **)(in_ECX + 4);
  FUN_00501300(param_4,piVar2);
  if ((short)piVar2[2] == 0) {
    return;
  }
  iVar5 = *piVar2;
  if (iVar5 == 0) {
    return;
  }
  FUN_00500e50(param_1,param_2,local_4000,0);
  if ((*(byte *)(param_1 + 0x58) & 4) != 0) {
    FUN_005b4960(local_4000,param_1 + 0x40);
  }
  if (param_3 != 0) {
    FUN_005b5430(local_4000,local_4000,param_3);
  }
  local_4140 = local_3fd0;
  local_413c = local_3fcc;
  local_4138 = local_3fc8;
  iVar3 = FUN_006e6b90();
  local_4144 = FUN_006e6b90();
  fVar7 = extraout_ST0;
  if (*(short *)((int)piVar2 + 0xe) != 0) {
    if (iVar3 != 0) {
      iVar3 = **(int **)(*(int *)(param_4 + 0x58) + 0x18) + -100 +
              (uint)*(ushort *)(piVar2 + 2) * 100;
      iVar4 = **(int **)(param_4 + 0xa4) + -0x18 + (uint)*(ushort *)(piVar2 + 2) * 0x18;
      FUN_00503050(iVar3,*(undefined4 *)(iVar4 + 0xc),local_40c0,&local_414c,local_4110,local_410c,
                   local_4108,local_4104,&local_4150);
      if (local_414c == 0.0) {
        return;
      }
      FUN_005f38c0(iVar5,*(undefined4 *)(iVar3 + 0x48),*(undefined4 *)(iVar4 + 0xc),0,0,local_4000);
      FUN_005019c0(iVar5,*(ushort *)((int)piVar2 + 0x12) - 1,local_4040);
      FUN_005c0500(local_4100,local_4040,local_4040 + (uint)*(ushort *)((int)piVar2 + 0x12) * 0x40);
      FUN_005c0500(local_4100,local_4100,local_40c0);
      local_4120 = local_40d0 - local_4140;
      local_411c = local_40cc - local_413c;
      local_4118 = local_40c8 - local_4138;
      local_4114 = 0;
      FUN_005b59a0(local_4080,local_4100);
      FUN_005c0490(&local_4130,&local_4120,local_4080);
      FUN_005b3b30(&local_4130,&local_4130);
      if (local_4128 <= 0.1) {
        local_414c = 0.0;
        local_4150 = 0.0;
      }
      else {
        local_4150 = local_4130 * 0.5;
        local_414c = local_412c * 0.5;
      }
    }
    iVar3 = *(int *)(*(int *)(iVar5 + 0xc) + -4 + (uint)*(ushort *)((int)piVar2 + 0xe) * 4);
    if (0.24 < local_4150) {
      local_4150 = 0.24;
    }
    if (local_4150 < -0.24) {
      local_4150 = -0.24;
    }
    local_4150 = ABS(local_4150);
    iVar4 = FUN_006e6b90();
    fVar6 = (((float)(&DAT_029899a0)[0x4000 - iVar4 >> 1 & 0x7fff] - 0.7) * 0.18) / 0.3;
    if (fVar6 < local_414c) {
      local_414c = fVar6;
    }
    if (local_414c < -fVar6) {
      local_414c = -fVar6;
    }
    local_4150 = (float)((extraout_ST0_00 - (float10)*(float *)(iVar3 + 0x80)) * (float10)0.125);
    *(float *)(iVar3 + 0x80) = local_4150 + *(float *)(iVar3 + 0x80);
    local_414c = (float)((-(float10)local_414c - (float10)*(float *)(iVar3 + 0x84)) * (float10)0.125
                        ) + *(float *)(iVar3 + 0x84);
    *(float *)(iVar3 + 0x84) = local_414c;
    fVar6 = (float)1;
    fVar7 = extraout_ST1;
    if (local_414c < -0.15) goto LAB_00507258;
  }
  fVar6 = local_4148;
LAB_00507258:
  uVar1 = *(ushort *)(piVar2 + 3);
  if (uVar1 != 0) {
    if (local_4144 == 0) {
      local_4148 = (float)piVar2[1] - *(float *)(param_4 + 0xe4) * 10.0;
      piVar2[1] = (int)local_4148;
      if ((float10)local_4148 < fVar7) {
        piVar2[1] = (int)(float)fVar7;
      }
    }
    else {
      local_4148 = *(float *)(param_4 + 0xe4) * 30.0 + (float)piVar2[1];
      piVar2[1] = (int)local_4148;
      if (3.0 < local_4148) {
        piVar2[1] = 0x40400000;
      }
    }
    iVar3 = FUN_006e6b90();
    if (iVar3 < (int)fVar6) {
      iVar3 = (int)fVar6;
    }
    iVar4 = *(int *)(*(int *)(iVar5 + 0xc) + -4 + (uint)*(ushort *)((int)piVar2 + 10) * 4);
    iVar5 = (uint)uVar1 * 0x20 + *(int *)(iVar5 + 100);
    if (iVar3 < *(short *)(iVar5 + -0x14)) {
      *(undefined2 *)(iVar4 + 0x74) = *(undefined2 *)(*(int *)(iVar5 + -0x18) + iVar3 * 2);
      FUN_005e4b00(iVar4);
      return;
    }
  }
  return;
}

