/* Ghidra pseudocode, not original source.
 * ev_d2141175d7fdb31f80696454dffb563fb6f914ee7c013e44c78745164b884694
 * Entry: 0x6256a0; label: FUN_006256a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006256a0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  char cVar1;
  uint uVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float local_150;
  float local_14c;
  float local_148;
  float local_144;
  float local_140;
  float local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  float local_120;
  double local_11c;
  undefined4 local_114 [4];
  undefined1 local_104;
  undefined1 auStack_103 [255];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_150;
  local_144 = (float)param_3;
  local_140 = (float)param_4;
  *(int *)(param_2 + 0x20) = param_4;
  local_148 = (float)param_5;
  local_114[2] = 0xff00000;
  local_114[3] = 0xffffffff;
  local_114[0] = 0xff000000;
  local_114[1] = 0xffffffff;
  *(int *)(param_2 + 0x1c) = param_3;
  iVar4 = FUN_0061e850();
  if (((iVar4 == 0) || (DAT_02912e8c != 0)) && ((*(uint *)(param_2 + 0x4c) & 8) == 0)) {
    *(uint *)(param_2 + 0x4c) = *(uint *)(param_2 + 0x4c) & 0xffffffef;
  }
  else {
    *(uint *)(param_2 + 0x4c) = *(uint *)(param_2 + 0x4c) | 0x10;
  }
  if (DAT_02912eb8 == 0) {
    FUN_005d0fb0(DAT_02912b38);
  }
  cVar1 = *(char *)(param_2 + 0x10);
  if (cVar1 == '\x01') {
    if (DAT_02912eb8 == 0) {
      uVar5 = 0xff000060;
      goto LAB_006257ac;
    }
  }
  else if (cVar1 == '\x02') {
    if (DAT_02912eb8 == 0) {
      uVar5 = 0xff006000;
      goto LAB_006257ac;
    }
  }
  else if (cVar1 == '\x03') {
    if (DAT_02912eb8 == 0) {
      uVar5 = 0xff600000;
      goto LAB_006257ac;
    }
  }
  else if (DAT_02912eb8 == 0) {
    uVar5 = *(undefined4 *)(param_2 + 0x28 + (*(byte *)(param_2 + 0x11) & 1) * 4);
LAB_006257ac:
    FUN_005d1060(DAT_02912b38,uVar5);
  }
  fVar7 = (float10)FUN_005d0e80(DAT_02912b38);
  local_13c = (float)(((float10)1 / (float10)_DAT_0080f564) * fVar7 * (float10)1.25);
  fVar7 = (float10)FUN_005d0e80(DAT_02912b38);
  local_11c = (double)(fVar7 * (float10)0.125);
  fVar8 = (float10)FUN_005d0eb0(DAT_02912b38);
  fVar7 = (float10)1;
  local_120 = (float)((fVar8 + (float10)local_11c) * (fVar7 / (float10)_DAT_0080f564));
  fVar9 = (float10)local_13c;
  fVar8 = fVar9 - (float10)2.0;
  local_11c = (double)fVar8;
  local_150 = (float)((float10)*(int *)(param_2 + 0x6c) * fVar8);
  if ((*(byte *)(param_2 + 0x4c) & 1) != 0) {
    fVar7 = (float10)FUN_005d0d60(DAT_02912b38,&DAT_02900b70);
    local_14c = (float)(((float10)1 / (float10)_DAT_0080f560) * fVar7);
    fVar3 = (local_148 - *(float *)(param_2 + 0x54)) - 4.0;
    if (local_14c < fVar3) {
      local_14c = fVar3;
    }
    FUN_006187a0(local_144,local_140,local_148,local_13c);
    if (DAT_02912eb8 == 0) {
      local_148 = local_13c - 4.0;
      uVar5 = FUN_006e6b90(0xffffffff,DAT_02900c70);
      uVar5 = FUN_006e6b90(uVar5);
      local_148 = local_140 + 2.0;
      uVar5 = FUN_006e6b90(uVar5);
      local_148 = (float)((float10)local_144 + (float10)*(float *)(param_2 + 0x54) + extraout_ST1);
      uVar5 = FUN_006e6b90(uVar5);
      FUN_005db880(uVar5);
    }
    local_14c = 0.0;
    if (0 < *(int *)(param_2 + 0x6c)) {
      do {
        fVar3 = local_14c;
        local_148 = ((float)(int)local_14c + 0.5) * (float)local_11c + local_144;
        if (DAT_02912eb8 == 0) {
          uVar5 = FUN_006e6b90();
          local_148 = local_140 + local_13c;
          uVar6 = FUN_006e6b90(0xff000000,DAT_02900c70);
          uVar6 = FUN_006e6b90(uVar5,uVar6);
          FUN_005db5b0(uVar5,uVar6);
        }
        local_14c = (float)((int)fVar3 + 1);
      } while ((int)local_14c < *(int *)(param_2 + 0x6c));
    }
    if (DAT_02912eb8 == 0) {
      local_148 = local_144 + *(float *)(param_2 + 0x54);
      uVar5 = FUN_006e6b90();
      local_148 = local_140 + local_13c;
      uVar6 = FUN_006e6b90(local_114[(*(uint *)(param_2 + 0x4c) >> 2 & 1) + 2],DAT_02900c70);
      uVar6 = FUN_006e6b90(uVar5,uVar6);
      FUN_005db5b0(uVar5,uVar6);
    }
    local_14c = local_120 + local_140;
    fVar3 = local_144 - local_150;
    local_150 = local_150 + local_144;
    FUN_00618550(DAT_02912b38,local_150,local_14c,0x10,fVar3,*(undefined4 *)(param_2 + 0x54),
                 *(undefined4 *)(param_2 + 0x24));
    local_150 = local_144 + *(float *)(param_2 + 0x54) + 2.0;
    FUN_006183e0(DAT_02912b38,local_150,local_14c,&DAT_02900b70);
    FUN_004f1f40(&local_104,&DAT_02900b70,DAT_0080f59c + 1);
    auStack_103[DAT_0080f59c] = 0;
    fVar7 = (float10)FUN_005d0d60(DAT_02912b38,&local_104);
    local_150 = (float)(((float10)1 / (float10)_DAT_0080f560) * fVar7);
    if (DAT_02912eb8 == 0) {
      local_150 = local_144 + *(float *)(param_2 + 0x54) + 2.0 + local_150;
      uVar5 = FUN_006e6b90();
      local_150 = local_140 + local_13c;
      uVar6 = FUN_006e6b90(0xff000000,DAT_02900c70);
      uVar6 = FUN_006e6b90(uVar5,uVar6);
      FUN_005db5b0(uVar5,uVar6);
    }
    goto LAB_0062614d;
  }
  local_14c = (float)fVar8;
  *(float *)(param_2 + 0x58) = local_14c;
  fVar8 = (float10)local_148;
  fVar10 = (float10)local_144;
  *(float *)(param_2 + 0x5c) = (float)((fVar10 + fVar8) - ((float10)local_14c + fVar7));
  fVar11 = (float10)local_140;
  *(float *)(param_2 + 0x60) = (float)(fVar11 + fVar7);
  if (param_1 != 0) {
    if (param_1 != DAT_02912eac) {
      param_1 = FUN_0061f050();
      fVar8 = extraout_ST0;
      fVar10 = extraout_ST1_00;
    }
    if (param_1 != 0) {
      FUN_006187a0((float)fVar10,(float)fVar11,(float)fVar8,(float)fVar9);
      fVar9 = (float10)local_13c;
      fVar10 = (float10)local_144;
      fVar11 = (float10)local_140;
    }
  }
  local_148 = (float)(fVar11 + fVar9);
  local_14c = (float)(fVar10 + (float10)*(float *)(param_2 + 0x54));
  FUN_00618720(local_14c,(float)fVar11,local_14c,local_148);
  local_14c = 0.0;
  if (0 < *(int *)(param_2 + 0x6c)) {
    do {
      fVar3 = local_14c;
      local_14c = ((float)(int)local_14c + 0.5) * (float)local_11c + local_144;
      if (DAT_02912eb8 == 0) {
        uVar5 = FUN_006e6b90();
        uVar6 = FUN_006e6b90(0xff000000,DAT_02900c70);
        uVar6 = FUN_006e6b90(uVar5,uVar6);
        FUN_005db5b0(uVar5,uVar6);
      }
      local_14c = (float)((int)fVar3 + 1);
    } while ((int)local_14c < *(int *)(param_2 + 0x6c));
  }
  local_14c = local_120 + local_140;
  fVar3 = local_144 - local_150;
  local_150 = local_150 + local_144;
  FUN_00618550(DAT_02912b38,local_150,local_14c,0x10,fVar3,*(undefined4 *)(param_2 + 0x54),
               *(undefined4 *)(param_2 + 0x24));
  local_150 = *(float *)(param_2 + 0x5c) - 1.0;
  fVar3 = local_144 + *(float *)(param_2 + 0x54);
  FUN_00618550(DAT_02912b38,local_150,local_14c,0x20,fVar3,local_150 - fVar3,
               *(undefined4 *)(param_2 + 100));
  if ((*(uint *)(param_2 + 0x4c) & 0x1c0) == 0xc0) {
    if (DAT_02912eb8 == 0) {
      uVar5 = FUN_006e6b90(*(undefined4 *)(param_2 + 0x50),DAT_02900c70);
      uVar5 = FUN_006e6b90(uVar5);
      uVar5 = FUN_006e6b90(uVar5);
      uVar5 = FUN_006e6b90(uVar5);
      FUN_005db880(uVar5);
      goto LAB_00625e2a;
    }
  }
  else {
LAB_00625e2a:
    if (DAT_02912eb8 == 0) {
      uVar5 = FUN_006e6b90(0xff000000,(&DAT_02900c70)[DAT_02912e94]);
      uVar5 = FUN_006e6b90(uVar5);
      uVar5 = FUN_006e6b90(uVar5);
      uVar5 = FUN_006e6b90(uVar5);
      FUN_005dbbf0(uVar5);
    }
  }
  uVar2 = *(uint *)(param_2 + 0x4c);
  if ((uVar2 & 0x1c0) == 0x40) {
    local_150 = *(float *)(param_2 + 0x5c) + *(float *)(param_2 + 0x58) * 0.1;
    uVar5 = FUN_006e6b90();
    local_150 = (float)((float10)*(float *)(param_2 + 0x60) + extraout_ST1_01);
    local_138 = uVar5;
    local_134 = FUN_006e6b90();
    local_150 = *(float *)(param_2 + 0x5c) + *(float *)(param_2 + 0x58) * 0.9;
    local_130 = FUN_006e6b90();
    local_150 = *(float *)(param_2 + 0x58) * 0.5 + *(float *)(param_2 + 0x60);
    local_12c = FUN_006e6b90();
    local_150 = (float)(extraout_ST0_00 + (float10)*(float *)(param_2 + 0x60));
    local_128 = uVar5;
    local_124 = FUN_006e6b90();
    if (DAT_02912eb8 == 0) {
      FUN_005dc2f0(&local_138,0,3,local_114[uVar2 >> 4 & 1],DAT_02900c70);
    }
  }
  uVar2 = *(uint *)(param_2 + 0x4c);
  if ((uVar2 & 0x1c0) == 0x80) {
    local_150 = *(float *)(param_2 + 0x5c) + *(float *)(param_2 + 0x58) * 0.1;
    local_138 = FUN_006e6b90();
    local_150 = *(float *)(param_2 + 0x58) * 0.45 + *(float *)(param_2 + 0x60);
    uVar5 = FUN_006e6b90();
    local_150 = *(float *)(param_2 + 0x58) * 0.5 + *(float *)(param_2 + 0x5c);
    local_134 = uVar5;
    local_130 = FUN_006e6b90();
    local_150 = (float)(extraout_ST0_01 + (float10)*(float *)(param_2 + 0x60));
    local_12c = FUN_006e6b90();
    local_150 = *(float *)(param_2 + 0x58) * 0.9 + *(float *)(param_2 + 0x5c);
    local_128 = FUN_006e6b90();
    local_124 = uVar5;
    if (DAT_02912eb8 == 0) {
      FUN_005dc2f0(&local_138,0,3,local_114[uVar2 >> 4 & 1],DAT_02900c70);
    }
    local_150 = *(float *)(param_2 + 0x58) * 0.1 + *(float *)(param_2 + 0x5c);
    local_138 = FUN_006e6b90();
    local_150 = *(float *)(param_2 + 0x58) * 0.55 + *(float *)(param_2 + 0x60);
    uVar5 = FUN_006e6b90();
    local_150 = *(float *)(param_2 + 0x58) * 0.5 + *(float *)(param_2 + 0x5c);
    local_134 = uVar5;
    local_130 = FUN_006e6b90();
    local_150 = *(float *)(param_2 + 0x60) + *(float *)(param_2 + 0x58) * 0.9;
    local_12c = FUN_006e6b90();
    local_150 = (float)(extraout_ST0_02 + (float10)*(float *)(param_2 + 0x5c));
    local_128 = FUN_006e6b90();
    local_124 = uVar5;
    if (DAT_02912eb8 == 0) {
      FUN_005dc2f0(&local_138,0,3,local_114[*(uint *)(param_2 + 0x4c) >> 4 & 1],DAT_02900c70);
    }
  }
LAB_0062614d:
  FUN_006e6b90();
  __security_check_cookie(local_4 ^ (uint)&local_150);
  return;
}

