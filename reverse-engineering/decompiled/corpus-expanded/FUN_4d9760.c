/* Ghidra pseudocode, not original source.
 * ev_39fbc79f0f4753fe71d498de82ca90498367aadd8f8860e7e5955d3b79e5f355
 * Entry: 0x4d9760; label: FUN_004d9760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004d9760(undefined4 *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined1 **ppuVar7;
  undefined4 *puVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  float local_174;
  float local_170;
  float local_16c;
  float local_168;
  undefined4 local_164;
  double local_160;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  float local_148 [3];
  undefined1 local_13c [4];
  undefined4 local_138;
  undefined4 local_130;
  float local_12c;
  undefined4 local_128;
  undefined1 local_124 [12];
  undefined1 *local_118 [5];
  float local_104;
  float local_100;
  undefined4 local_fc;
  undefined *local_f4;
  undefined4 local_ec;
  code *local_d8;
  code *local_d4;
  float local_8c;
  undefined4 local_74;
  undefined1 local_50 [76];
  
  if (param_1[0x20] == 0) {
    return 0;
  }
  iVar5 = param_1[0x24];
  if (((iVar5 == 0) || ((*(byte *)(iVar5 + 0x1fc) & 1) == 0)) || (*(char *)(iVar5 + 0x28b) != '\0'))
  {
    _memset(param_1,0,0xa0);
    return 0;
  }
  if (0.0 < *(float *)(DAT_00882a6c + 0xb000)) goto LAB_004d9e41;
  local_170 = (float)param_1[0x14] - (float)param_1[0xc];
  local_16c = (float)param_1[0x15] - (float)param_1[0xd];
  local_168 = (float)param_1[0x16] - (float)param_1[0xe];
  local_160 = (double)CONCAT44(local_160._4_4_,
                               local_170 * local_170 + local_16c * local_16c + local_168 * local_168
                              );
  local_174 = local_168 * (float)param_1[10] +
              local_170 * (float)param_1[8] + (float)param_1[9] * local_16c;
  fVar1 = (float)param_1[0x21];
  if (NAN(fVar1) || 1.0 < fVar1 == (fVar1 == 1.0)) {
    while( true ) {
      if ((1.0 <= local_160._0_4_) && (0.0 <= local_174)) goto LAB_004d98fa;
      fVar1 = (float)param_1[0x21] + _DAT_007f15e0;
      param_1[0x21] = fVar1;
      if (1.0 < fVar1) break;
      FUN_0040eff0(param_1[0x20],param_1 + 0x14,fVar1);
      local_170 = (float)param_1[0x14] - (float)param_1[0xc];
      local_16c = (float)param_1[0x15] - (float)param_1[0xd];
      local_168 = (float)param_1[0x16] - (float)param_1[0xe];
      local_160 = (double)CONCAT44(local_160._4_4_,
                                   local_170 * local_170 + local_16c * local_16c +
                                   local_168 * local_168);
      local_174 = local_168 * (float)param_1[10] +
                  local_170 * (float)param_1[8] + (float)param_1[9] * local_16c;
    }
    param_1[0x21] = 0x3f800000;
  }
LAB_004d98fa:
  fVar9 = (float10)FUN_005c0240(local_160._0_4_);
  fVar1 = (float)fVar9;
  fVar2 = (float)param_1[0x21];
  if (NAN(fVar2) || 1.0 < fVar2 == (fVar2 == 1.0)) {
    if (fVar1 != 0.0) {
      fVar3 = (float)param_1[0x1f];
      fVar2 = *(float *)(DAT_00882a6c + 0xb004) / *(float *)(DAT_00882a6c + 0xb00c);
      if (1.0 < fVar2) {
        fVar2 = 1.0;
      }
      if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b090) && (DAT_00882a70 == 1)) {
        fVar3 = fVar3 / 0.995;
        if (0.01 <= fVar2) {
          fVar2 = (fVar2 - 0.01) * fVar3;
          goto LAB_004d9a6c;
        }
        fVar2 = (fVar3 * fVar2) / 0.01;
      }
      else {
        fVar2 = fVar2 * fVar3;
LAB_004d9a6c:
        fVar2 = fVar3 * 1.5 - fVar2;
      }
      local_160 = (double)CONCAT44(local_160._4_4_,fVar2);
      fVar2 = fVar2 / fVar1;
      param_1[0x10] = fVar2 * local_170;
      param_1[0x11] = local_16c * fVar2;
      param_1[0x12] = fVar2 * local_168;
      local_170 = _DAT_00925018 * (float)param_1[0x10];
      local_16c = (float)param_1[0x11] * _DAT_00925018;
      local_168 = _DAT_00925018 * (float)param_1[0x12];
      param_1[0xc] = local_170 + (float)param_1[0xc];
      param_1[0xd] = (float)param_1[0xd] + local_16c;
      param_1[0xe] = (float)param_1[0xe] + local_168;
      FUN_004d94f0(&local_170,fVar1 / 5.0,0);
      param_1[0x18] = local_170;
      param_1[0x19] = local_16c;
      param_1[0x1a] = local_168;
      param_1[0x1b] = local_164;
    }
  }
  else {
    local_170 = _DAT_00925018 * (float)param_1[0x10];
    local_16c = (float)param_1[0x11] * _DAT_00925018;
    local_168 = _DAT_00925018 * (float)param_1[0x12];
    param_1[0xc] = (float)param_1[0xc] + local_170;
    param_1[0xd] = (float)param_1[0xd] + local_16c;
    param_1[0xe] = (float)param_1[0xe] + local_168;
    FUN_004d94f0(&local_170,fVar1 / 5.0,0);
    param_1[0x18] = local_170;
    param_1[0x19] = local_16c;
    param_1[0x1a] = local_168;
    param_1[0x1b] = local_164;
  }
  if ((((*(int *)(param_2 + 0x128) == DAT_0087b08c) && (param_1[0x24] != 0)) &&
      (*(short *)(param_1 + 0x22) == DAT_007f1b1c)) &&
     (iVar5 = FUN_005cfac0(&DAT_00881cc8), iVar5 != 0)) {
    *(float *)(param_1[0x24] + 0x1090) = *(float *)(param_1[0x24] + 0x1090) - _DAT_00925018;
    iVar4 = DAT_0093d810;
    iVar5 = param_1[0x24];
    if (*(float *)(iVar5 + 0x1090) < 0.0) {
      local_130 = *(undefined4 *)(iVar5 + 0x5c);
      local_12c = *(float *)(iVar5 + 0x60) + 1.0;
      local_128 = *(undefined4 *)(iVar5 + 100);
      if (DAT_0093d810 != 0) {
        fVar9 = (float10)FUN_005b3c50(DAT_0093d810 + 0x80,iVar5 + 0x80,local_124);
        if (_DAT_007ffe28 * 4.0 * _DAT_007ffe28 < (float)fVar9) {
          local_160 = (double)_DAT_007ffe24;
          fVar10 = (float10)FUN_005b9dd0();
          fVar11 = (float10)local_160;
          local_148[0] = (float)(fVar11 - (fVar11 + fVar11) * fVar10);
          local_148[1] = 0.0;
          local_148[2] = _DAT_007ffe28;
          FUN_005b3620(local_148,local_148,*(undefined2 *)(iVar4 + 0x696));
          FUN_005b37d0(local_148,local_148,DAT_0093d810 + 0x80);
          local_154 = 0;
          local_150 = 0;
          local_14c = _DAT_007fc024;
          FUN_005b3620(&local_154,&local_154,*(undefined2 *)(iVar4 + 0x696));
          FUN_0049f630(local_13c,&local_130,local_148,&local_154,_DAT_007ffd10,_DAT_007ffd14);
          if (_DAT_007ffe20 * _DAT_007ffe20 < (float)fVar9) {
            local_138 = 0;
            FUN_005b3b30(local_13c,local_13c);
            FUN_005b3830(local_13c,local_13c,_DAT_007ffe20);
            FUN_005b37d0(local_148,&local_130,local_13c);
            local_154 = 0;
            local_150 = 0;
            local_14c = 0;
            FUN_0049f630(local_13c,&local_130,local_148,&local_154,_DAT_007ffd10,_DAT_007ffd14);
          }
        }
        FUN_005b4500(local_50,&local_130);
        puVar6 = &DAT_00810210;
        ppuVar7 = local_118;
        for (iVar5 = 0x32; iVar5 != 0; iVar5 = iVar5 + -1) {
          *ppuVar7 = (undefined1 *)*puVar6;
          puVar6 = puVar6 + 1;
          ppuVar7 = ppuVar7 + 1;
        }
        local_118[0] = local_50;
        local_118[2] = local_13c;
        fVar9 = (float10)FUN_005d02e0(&DAT_00881cc8);
        local_104 = (float)fVar9;
        local_f4 = &DAT_00881cc8;
        local_ec = 0x29a;
        local_d8 = FUN_0042cf20;
        local_fc = _DAT_007ffd14;
        local_d4 = FUN_004d9710;
        local_8c = _DAT_00925018;
        local_74 = 0x40a00000;
        local_100 = local_104;
        FUN_0064d270(local_118);
        fVar9 = (float10)FUN_005b9dd0();
        fVar10 = (float10)_DAT_007ffd0c;
        *(float *)(param_1[0x24] + 0x1090) =
             (float)(((float10)_DAT_007ffd08 - fVar10) + (fVar10 + fVar10) * fVar9);
      }
    }
  }
LAB_004d9e41:
  param_1[0xf] = 0x3f800000;
  if (param_1[0x24] != 0) {
    puVar6 = param_1;
    puVar8 = (undefined4 *)(param_1[0x24] + 0xc04);
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    iVar5 = param_1[0x24];
    *(undefined4 *)(iVar5 + 0x5c) = *(undefined4 *)(iVar5 + 0xc34);
    *(undefined4 *)(iVar5 + 0x60) = *(undefined4 *)(iVar5 + 0xc38);
    *(undefined4 *)(iVar5 + 100) = *(undefined4 *)(iVar5 + 0xc3c);
    iVar5 = param_1[0x24];
    *(undefined4 *)(iVar5 + 0x10bc) = *(undefined4 *)(iVar5 + 0x5c);
    *(undefined4 *)(iVar5 + 0x10c0) = *(undefined4 *)(iVar5 + 0x60);
    *(undefined4 *)(iVar5 + 0x10c4) = *(undefined4 *)(iVar5 + 100);
  }
  return 1;
}

