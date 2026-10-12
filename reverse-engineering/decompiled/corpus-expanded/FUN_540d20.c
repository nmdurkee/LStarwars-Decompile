/* Ghidra pseudocode, not original source.
 * ev_d41a9e73f582863d0d1c8c52ad55b427a61509ce0f65a786388b60a63b819da3
 * Entry: 0x540d20; label: FUN_00540d20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00540d20(int *param_1,int param_2,float *param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined1 *puVar10;
  uint uVar11;
  float *pfVar12;
  uint uVar13;
  float *pfVar14;
  int iVar15;
  float *pfVar16;
  uint uVar17;
  float *pfVar18;
  int iVar19;
  float *pfVar20;
  uint uVar21;
  float10 fVar22;
  float local_1b0;
  float local_1ac;
  float local_1a8;
  undefined1 *local_1a4;
  uint local_1a0;
  float local_19c;
  float local_198;
  float local_194;
  float local_190;
  float local_18c;
  float local_188;
  float local_184;
  int local_180 [4];
  undefined1 local_170 [16];
  float afStack_160 [4];
  undefined1 local_150 [16];
  undefined1 local_140 [16];
  undefined1 local_130 [16];
  undefined1 local_120 [16];
  float afStack_110 [4];
  float afStack_100 [16];
  float local_c0 [4];
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a0;
  float local_9c;
  float local_98;
  float local_80;
  float local_7c;
  float local_78;
  float local_70;
  float local_6c;
  float local_68;
  float local_60;
  float local_5c;
  float local_58;
  
  FUN_005b44e0(param_3);
  if (*(char *)(param_2 + 1) != -1) {
    if ((param_5 == 4) || (param_5 == 5)) {
      local_1a0 = 3;
      uVar17 = 3;
      uVar21 = 0;
    }
    else {
      uVar17 = 2;
      uVar21 = 1;
      local_1a0 = 2;
    }
    iVar19 = *(char *)(param_2 + 1) * 0x13c + *param_1;
    iVar15 = (int)*(short *)(param_2 + 2) % param_4;
    local_180[1] = *(short *)(param_2 + 2) - iVar15;
    uVar11 = local_180[1] + param_4;
    local_180[2] = uVar11;
    local_180[3] = uVar11 + param_4;
    local_180[0] = local_180[1] - param_4;
    if (local_180[1] - param_4 < 0) {
      local_180[0] = 0;
    }
    uVar13 = (uint)*(ushort *)(iVar19 + 0x30);
    if ((int)uVar13 < (int)uVar11) {
      local_180[2] = uVar13;
    }
    if ((int)uVar13 < (int)(uVar11 + param_4)) {
      local_180[3] = uVar13;
    }
    if (uVar21 <= uVar17) {
      iVar1 = *(int *)(iVar19 + 0x34);
      uVar11 = uVar21;
      do {
        afStack_160[uVar11] = (float)(local_180[uVar11] * 0x80 + iVar1);
        uVar11 = uVar11 + 1;
      } while ((int)uVar11 <= (int)uVar17);
    }
    local_19c = (float)uVar21;
    if (uVar21 <= local_1a0) {
      local_1a4 = local_150 + uVar21 * 0x10;
      pfVar20 = afStack_100 + uVar21 * 0x10;
      do {
        local_19c = (float)uVar21;
        FUN_005b44e0(pfVar20);
        iVar1 = *(int *)(*(int *)(iVar19 + 4) + 8);
        iVar2 = *(int *)(*(int *)(iVar19 + 8) + 8);
        iVar3 = *(int *)(*(int *)(iVar19 + 0xc) + 8);
        iVar4 = *(int *)(*(int *)(iVar19 + 0x10) + 8);
        iVar5 = local_180[uVar21] * 0xc;
        pfVar14 = (float *)(iVar2 + iVar5);
        pfVar12 = (float *)(iVar1 + iVar5);
        pfVar16 = (float *)(iVar3 + iVar5);
        pfVar18 = (float *)(iVar4 + iVar5);
        local_198 = (*(float *)(iVar3 + iVar5) - *(float *)(iVar4 + iVar5)) +
                    (*(float *)(iVar2 + iVar5) - *(float *)(iVar1 + iVar5));
        local_194 = (pfVar14[1] - pfVar12[1]) + (pfVar16[1] - pfVar18[1]);
        local_190 = (pfVar16[2] - pfVar18[2]) + (pfVar14[2] - pfVar12[2]);
        local_1b0 = (*pfVar14 - *pfVar16) + (*pfVar12 - *pfVar18);
        local_1ac = (pfVar14[1] - pfVar16[1]) + (pfVar12[1] - pfVar18[1]);
        local_1a8 = (pfVar14[2] - pfVar16[2]) + (pfVar12[2] - pfVar18[2]);
        fVar22 = (float10)FUN_005bec80(&local_198);
        fVar6 = local_19c;
        afStack_110[(int)local_19c] = (float)fVar22;
        fVar22 = (float10)FUN_005bec80(&local_1b0);
        afStack_160[(int)fVar6] = (float)fVar22;
        FUN_005b3b30(&local_198,&local_198);
        FUN_005b3b30(&local_1b0,&local_1b0);
        FUN_005b3920(&local_18c,&local_198,&local_1b0);
        FUN_005b3b30(&local_18c,&local_18c);
        FUN_005b3920(&local_1b0,&local_18c,&local_198);
        FUN_005b3b30(&local_1b0,&local_1b0);
        puVar10 = local_1a4;
        *pfVar20 = local_198;
        pfVar20[1] = local_194;
        pfVar20[2] = local_190;
        pfVar20[4] = local_1b0;
        pfVar20[5] = local_1ac;
        pfVar20[6] = local_1a8;
        pfVar20[8] = local_18c;
        pfVar20[9] = local_188;
        pfVar20[10] = local_184;
        FUN_005b7ea0(pfVar20,local_1a4);
        uVar21 = (int)fVar6 + 1;
        local_1a4 = puVar10 + 0x10;
        pfVar20 = pfVar20 + 0x10;
        local_19c = (float)uVar21;
      } while ((int)uVar21 <= (int)local_1a0);
    }
    pfVar20 = *(float **)(*(int *)(iVar19 + 4) + 8);
    pfVar12 = *(float **)(*(int *)(iVar19 + 8) + 8);
    pfVar14 = *(float **)(*(int *)(iVar19 + 0xc) + 8);
    pfVar16 = *(float **)(*(int *)(iVar19 + 0x10) + 8);
    local_198 = (*pfVar14 - *pfVar16) + (*pfVar12 - *pfVar20);
    local_194 = (pfVar12[1] - pfVar20[1]) + (pfVar14[1] - pfVar16[1]);
    local_190 = (pfVar14[2] - pfVar16[2]) + (pfVar12[2] - pfVar20[2]);
    local_1b0 = (*pfVar12 - *pfVar14) + (*pfVar20 - *pfVar16);
    local_1ac = (pfVar12[1] - pfVar14[1]) + (pfVar20[1] - pfVar16[1]);
    local_1a8 = (pfVar12[2] - pfVar14[2]) + (pfVar20[2] - pfVar16[2]);
    fVar22 = (float10)FUN_005bec80(&local_198);
    local_1a4 = (undefined1 *)(float)fVar22;
    fVar22 = (float10)FUN_005bec80(&local_1b0);
    local_19c = (float)fVar22;
    fVar6 = (*(float *)(param_2 + 4) + (float)iVar15) / (float)param_4;
    if ((*(ushort *)(iVar19 + 0x68) & 0x200) == 0) {
      *(undefined4 *)(iVar19 + 0xa0) = *(undefined4 *)(iVar19 + 0xa4);
      *(undefined4 *)(iVar19 + 0x9c) = *(undefined4 *)(iVar19 + 0xa4);
    }
    else {
      fVar8 = (afStack_110[1] / (float)local_1a4) * (1.0 - fVar6) +
              (afStack_110[2] / (float)local_1a4) * fVar6;
      if (fVar8 < 1.0 == (fVar8 == 1.0)) {
        fVar7 = (1.0 - *(float *)(iVar19 + 0xa4)) * (1.0 - 1.0 / fVar8) + *(float *)(iVar19 + 0xa4);
      }
      else {
        fVar7 = *(float *)(iVar19 + 0xa4) * fVar8;
      }
      *(float *)(iVar19 + 0x9c) = fVar7;
      fVar7 = (afStack_160[2] / local_19c) * fVar6 + (afStack_160[1] / local_19c) * (1.0 - fVar6);
      if (fVar7 < 1.0 == (fVar7 == 1.0)) {
        fVar9 = *(float *)(iVar19 + 0xa4) + (1.0 - 1.0 / fVar7) * (1.0 - *(float *)(iVar19 + 0xa4));
      }
      else {
        fVar9 = *(float *)(iVar19 + 0xa4) * fVar7;
      }
      *(float *)(iVar19 + 0xa0) = fVar9;
      if (1.0 < fVar8) {
        *(float *)(iVar19 + 0x88) = *(float *)(iVar19 + 0x80) / fVar8;
      }
      if (1.0 < fVar7) {
        *(float *)(iVar19 + 0x8c) = *(float *)(iVar19 + 0x84) / fVar7;
      }
    }
    if (param_5 == 1) {
      pfVar20 = param_3 + 4;
      pfVar12 = param_3 + 8;
      *param_3 = local_c0[0] + fVar6 * (local_80 - local_c0[0]);
      param_3[1] = local_c0[1] + fVar6 * (local_7c - local_c0[1]);
      param_3[2] = local_c0[2] + fVar6 * (local_78 - local_c0[2]);
      *pfVar20 = local_b0 + fVar6 * (local_70 - local_b0);
      param_3[5] = local_ac + fVar6 * (local_6c - local_ac);
      param_3[6] = local_a8 + fVar6 * (local_68 - local_a8);
      *pfVar12 = local_a0 + fVar6 * (local_60 - local_a0);
      param_3[9] = local_9c + fVar6 * (local_5c - local_9c);
      param_3[10] = local_98 + (local_58 - local_98) * fVar6;
      FUN_005b3b30(param_3,param_3);
      FUN_005b3b30(pfVar20,pfVar20);
      FUN_005b3b30(pfVar12,pfVar12);
      return;
    }
    if (param_5 == 2) {
      FUN_005b8410(local_170,local_140,local_130,fVar6);
      FUN_005b8040(local_170,param_3);
      return;
    }
    if (param_5 == 3) {
      FUN_005b87a0(local_170,local_140,local_130,fVar6);
      FUN_005b8040(local_170,param_3);
      return;
    }
    if (param_5 == 4) {
      FUN_005b8520(local_170,local_150,local_140,local_130,local_120,fVar6);
      FUN_005b8040(local_170,param_3);
      return;
    }
    if (param_5 == 5) {
      FUN_005b86c0(local_170,local_150,local_140,local_130,local_120,fVar6);
      FUN_005b8040(local_170,param_3);
      return;
    }
    pfVar20 = local_c0;
    for (iVar15 = 0x10; iVar15 != 0; iVar15 = iVar15 + -1) {
      *param_3 = *pfVar20;
      pfVar20 = pfVar20 + 1;
      param_3 = param_3 + 1;
    }
  }
  return;
}

