/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x433160; label: FUN_00433160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00433160(undefined4 *param_1)

{
  undefined *puVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  uint uVar6;
  int *piVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  float10 extraout_ST0;
  float10 fVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  float fVar14;
  undefined4 uVar15;
  uint local_78;
  uint local_74;
  float local_70;
  float local_6c;
  undefined4 *local_68;
  undefined4 local_64;
  float local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined4 local_40 [16];
  
  fVar14 = *(float *)(DAT_0093d7f0 + 0x22c) * _DAT_00925018 * 1.1;
  local_70 = (float)param_1[0x40] / (float)param_1[0x41];
  iVar3 = FUN_006e6b90();
  puVar1 = PTR_DAT_008021b4;
  iVar3 = iVar3 * 0x34;
  piVar7 = (int *)(&DAT_00876690 + iVar3);
  puVar8 = (undefined4 *)(PTR_DAT_008021b4 + 0x68);
  local_68 = puVar8;
  if (*piVar7 == 0) {
    local_58 = param_1[0xc];
    local_54 = param_1[0xd];
    local_50 = param_1[0xe];
    iVar4 = FUN_006e6b90();
    local_6c = (float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff];
    local_70 = ABS(local_6c);
    iVar4 = FUN_006e6b90();
    local_6c = (float)(int)ROUND(((float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] + 1.0) * 196608.0);
    uVar9 = (uint)local_6c & 0xffff;
    uVar2 = FUN_00550070(*(undefined2 *)(param_1 + 0x4e),0xd556,0x41200000);
    *(undefined2 *)(param_1 + 0x4e) = uVar2;
    uVar2 = FUN_00550070(*(undefined2 *)((int)param_1 + 0x13a),
                         *(short *)(DAT_0093d7f0 + 0x27a) + 0x4000,0x41200000);
    *(undefined2 *)((int)param_1 + 0x13a) = uVar2;
    uVar2 = FUN_00550070(*(undefined2 *)(param_1 + 0x4f),uVar9,0x41200000);
    *(undefined2 *)(param_1 + 0x4f) = uVar2;
    FUN_005506f0(0,&local_58,0x40400000,0);
    local_64 = DAT_0080250c;
    local_60 = (float)DAT_00802510;
    local_5c = DAT_00802514;
    local_6c = (float)(int)ROUND(2730.0 - (1.0 - local_70) * 5461.0);
    FUN_005b3620(&local_64,&local_64,(uint)local_6c & 0xffff);
    local_6c = *(float *)(DAT_0093d7f0 + 0x22c) / _DAT_00925018;
    FUN_005b3830(&local_64,&local_64,local_6c);
    local_60 = 1.0 / (float)(&DAT_029899a0)
                            [(int)(*(ushort *)(param_1 + 0x4e) + 0x4000) >> 1 & 0x7fff];
    local_6c = _DAT_00925018 * 1.8;
    fVar11 = (float10)FUN_0054fad0(local_58,*puVar8,local_6c);
    local_4c = (float)fVar11;
    local_6c = _DAT_00925018 * 1.8;
    fVar11 = (float10)FUN_0054fad0(local_54,*(undefined4 *)(puVar1 + 0x6c),local_6c);
    local_48 = (float)fVar11;
    local_6c = _DAT_00925018 * 1.8;
    fVar11 = (float10)FUN_0054fad0(local_50,*(undefined4 *)(puVar1 + 0x70),local_6c);
    local_44 = (float)fVar11;
    FUN_005b37d0(&local_4c,&local_4c,&local_64);
    FUN_005b44e0(local_40);
    FUN_005b4dd0(local_40,*(undefined2 *)(param_1 + 0x4e));
    FUN_005b5060(local_40,*(undefined2 *)((int)param_1 + 0x13a));
    FUN_005b5240(local_40,*(undefined2 *)(param_1 + 0x4f));
    FUN_005b4900(local_40,&local_4c);
    uVar9 = (uint)*(ushort *)(param_1 + 0x4f);
    puVar8 = local_40;
    puVar10 = param_1;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar10 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar10 = puVar10 + 1;
    }
    uVar6 = (uint)*(ushort *)(param_1 + 0x4e);
    uVar15 = 0;
    uVar13 = 5;
    pfVar5 = &local_4c;
    uVar12 = *(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x780);
    fVar14 = _DAT_00925018;
  }
  else {
    local_58 = *(undefined4 *)(&DAT_008766a0 + iVar3);
    local_54 = *(undefined4 *)(&DAT_008766a4 + iVar3);
    local_50 = *(undefined4 *)(&DAT_008766a8 + iVar3);
    FUN_005518a0(piVar7,fVar14);
    FUN_00550a20(*piVar7,*(undefined4 *)(&DAT_008766ac + iVar3),&local_4c,&local_78,&local_74,1);
    uVar9 = local_78 + 0x8000;
    if (fVar14 < 0.0) {
      local_74 = -local_74 & 0xffff;
      uVar9 = local_78 + 0x10000;
    }
    local_78 = uVar9;
    iVar4 = FUN_006e6b90();
    local_70 = (float)(int)ROUND(-((1.0 - ((float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] + 1.0) * 0.5)
                                  * 5461.0));
    uVar9 = (uint)local_70 & 0xffff;
    iVar4 = FUN_006e6b90();
    local_70 = (float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff];
    local_6c = ABS(local_70);
    iVar4 = FUN_006e6b90();
    local_70 = (float)((int)ROUND((extraout_ST0 +
                                  (float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff]) *
                                  (float10)196608.0) & 0xffff);
    uVar2 = FUN_00550070(*(undefined2 *)(param_1 + 0x4e),uVar9 - local_74,0x41200000);
    *(undefined2 *)(param_1 + 0x4e) = uVar2;
    local_6c = (float)(int)ROUND((1.0 - local_6c) * 5461.0 - 2730.0);
    uVar2 = FUN_00550070(*(undefined2 *)((int)param_1 + 0x13a),(short)local_78 - local_6c._0_2_,
                         0x41200000);
    *(undefined2 *)((int)param_1 + 0x13a) = uVar2;
    uVar2 = FUN_00550070(*(undefined2 *)(param_1 + 0x4f),(int)local_70 + local_78,0x41200000);
    *(undefined2 *)(param_1 + 0x4f) = uVar2;
    FUN_005506f0(0,&DAT_008766a0 + iVar3,0x40400000,0);
    FUN_005b44e0(local_40);
    FUN_005b4dd0(local_40,*(undefined2 *)(param_1 + 0x4e));
    FUN_005b5060(local_40,*(undefined2 *)((int)param_1 + 0x13a));
    FUN_005b5240(local_40,*(undefined2 *)(param_1 + 0x4f));
    FUN_005b4900(local_40,&DAT_008766a0 + iVar3);
    puVar8 = local_40;
    puVar10 = param_1;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar10 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar10 = puVar10 + 1;
    }
    FUN_005b3800(&local_64,&DAT_008766a0 + iVar3,&local_58);
    local_6c = 1.0 / _DAT_00925018;
    FUN_005b3830(&local_64,&local_64,local_6c);
    param_1[0x20] = local_64;
    param_1[0x21] = local_60;
    uVar15 = 0;
    param_1[0x22] = local_5c;
    uVar13 = 5;
    fVar14 = _DAT_00925018;
    uVar9 = local_74;
    uVar6 = local_78;
    iVar4 = FUN_006e6b90(5,_DAT_00925018,local_74,local_78,0);
    pfVar5 = (float *)(&DAT_008766a0 + iVar4 * 0x34);
    uVar12 = *(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x780);
  }
  FUN_00684be0(uVar12,pfVar5,uVar13,fVar14,uVar9,uVar6,uVar15);
  puVar8 = local_68;
  iVar4 = *(int *)(&DAT_008766b4 + iVar3);
  if (iVar4 != 0) {
    if (((*(uint *)(iVar4 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar4 + 0x1fc) & 0x1000) != 0)) {
      *(uint *)(iVar4 + 0xef0) = *(uint *)(iVar4 + 0xef0) | 0x400000;
      *(uint *)(*(int *)(&DAT_008766b4 + iVar3) + 0x1fc) =
           *(uint *)(*(int *)(&DAT_008766b4 + iVar3) + 0x1fc) | 0x20;
      *(uint *)(*(int *)(&DAT_008766b4 + iVar3) + 0xef4) =
           *(uint *)(*(int *)(&DAT_008766b4 + iVar3) + 0xef4) | 0x20;
      fVar11 = (float10)FUN_0054fad0(*(undefined4 *)(&DAT_008766b8 + iVar3),*local_68,_DAT_00925018)
      ;
      *(float *)(&DAT_008766b8 + iVar3) = (float)fVar11;
      local_68 = (undefined4 *)((float)puVar8[1] - 2.0);
      fVar11 = (float10)FUN_0054fad0(*(undefined4 *)(&DAT_008766bc + iVar3),local_68,
                                     _DAT_00925018 * 1.5);
      *(float *)(&DAT_008766bc + iVar3) = (float)fVar11;
      fVar11 = (float10)FUN_0054fad0(*(undefined4 *)(&DAT_008766c0 + iVar3),puVar8[2],_DAT_00925018)
      ;
      iVar4 = *(int *)(&DAT_008766b4 + iVar3);
      *(float *)(&DAT_008766c0 + iVar3) = (float)fVar11;
      *(undefined4 *)(iVar4 + 0x5c) = *(undefined4 *)(&DAT_008766b8 + iVar3);
      *(undefined4 *)(iVar4 + 0x60) = *(undefined4 *)(&DAT_008766bc + iVar3);
      *(undefined4 *)(iVar4 + 100) = *(undefined4 *)(&DAT_008766c0 + iVar3);
      iVar4 = *(int *)(&DAT_008766b4 + iVar3);
      *(undefined4 *)(iVar4 + 0x10bc) = *(undefined4 *)(iVar4 + 0x5c);
      *(undefined4 *)(iVar4 + 0x10c0) = *(undefined4 *)(iVar4 + 0x60);
      *(undefined4 *)(iVar4 + 0x10c4) = *(undefined4 *)(iVar4 + 100);
      iVar4 = *(int *)(&DAT_008766b4 + iVar3);
      *(undefined4 *)(iVar4 + 0x68) = local_64;
      *(float *)(iVar4 + 0x6c) = local_60;
      *(undefined4 *)(iVar4 + 0x70) = local_5c;
      iVar4 = *(int *)(&DAT_008766b4 + iVar3);
      fVar11 = (float10)FUN_005b9ef0(&DAT_00802538);
      local_68 = (undefined4 *)(int)ROUND(fVar11 * (float10)2730.0);
      *(short *)(iVar4 + 0x278) = *(short *)(iVar4 + 0x278) + (short)local_68;
      iVar4 = *(int *)(&DAT_008766b4 + iVar3);
      fVar11 = (float10)FUN_005b9ef0(&DAT_00802538);
      local_68 = (undefined4 *)(int)ROUND(fVar11 * (float10)2730.0);
      *(short *)(iVar4 + 0x27a) = *(short *)(iVar4 + 0x27a) + (short)local_68;
      iVar4 = *(int *)(&DAT_008766b4 + iVar3);
      fVar11 = (float10)FUN_005b9ef0(&DAT_00802538);
      local_68._0_2_ = (short)(int)ROUND(fVar11 * (float10)2730.0);
      *(short *)(iVar4 + 0x27c) = *(short *)(iVar4 + 0x27c) + (short)local_68;
      *(undefined4 *)(*(int *)(&DAT_008766b4 + iVar3) + 0x628) = 0x3f800000;
      *(undefined4 *)(*(int *)(&DAT_008766b4 + iVar3) + 0x62c) = 0x3f800000;
      *(undefined4 *)(*(int *)(&DAT_008766b4 + iVar3) + 0x630) = 0x3f800000;
      *(undefined4 *)(*(int *)(&DAT_008766b4 + iVar3) + 0x634) = 0x3f800000;
      *(undefined4 *)(*(int *)(&DAT_008766b4 + iVar3) + 0x638) = 0x3f800000;
      *(undefined4 *)(*(int *)(&DAT_008766b4 + iVar3) + 0x63c) = 0x3f800000;
      return;
    }
    if (iVar4 != 0) {
      *(undefined4 *)(&DAT_008766b4 + iVar3) = 0;
    }
  }
  return;
}

