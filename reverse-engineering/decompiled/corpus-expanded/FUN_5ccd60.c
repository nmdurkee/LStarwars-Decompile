/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5ccd60; label: FUN_005ccd60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x005cd365) */
/* WARNING: Removing unreachable block (ram,0x005cd328) */
/* WARNING: Removing unreachable block (ram,0x005cd41a) */
/* WARNING: Removing unreachable block (ram,0x005cd1c9) */
/* WARNING: Removing unreachable block (ram,0x005cd397) */
/* WARNING: Removing unreachable block (ram,0x005cd347) */
/* WARNING: Removing unreachable block (ram,0x005cd3bc) */
/* WARNING: Removing unreachable block (ram,0x005cd3d2) */
/* WARNING: Removing unreachable block (ram,0x005cd1df) */
/* WARNING: Removing unreachable block (ram,0x005cd20a) */
/* WARNING: Removing unreachable block (ram,0x005cd282) */
/* WARNING: Removing unreachable block (ram,0x005cd248) */

undefined4
FUN_005ccd60(int param_1,float param_2,int param_3,float param_4,uint param_5,int param_6,
            float *param_7)

{
  byte *pbVar1;
  float fVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  float *pfVar10;
  sbyte sVar11;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  uint uVar15;
  int iVar16;
  float *pfVar17;
  uint *puVar18;
  float10 fVar19;
  float10 fVar20;
  float10 extraout_ST0;
  float10 fVar21;
  float10 extraout_ST1;
  float10 fVar22;
  float fVar23;
  float fVar26;
  float fVar27;
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  float fVar28;
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  float local_8c;
  int local_84;
  int local_7c;
  ushort *local_78;
  float *local_74;
  float *local_6c;
  uint local_64;
  float local_40 [4];
  float local_30 [4];
  undefined1 local_20 [16];
  
  pbVar14 = *(byte **)(param_1 + 0x34);
  iVar5 = *(ushort *)(param_1 + 6) - 1;
  local_74 = param_7;
  fVar19 = (float10)(((float)iVar5 * (param_2 - (float)*(ushort *)(param_1 + 0xe))) /
                    (float)(int)(*(ushort *)(param_1 + 10) - 1));
  if (fVar19 < (float10)0) {
    fVar19 = (float10)(float)(float10)0;
  }
  fVar20 = (float10)*(ushort *)(param_1 + 6);
  if (fVar20 < fVar19 != (fVar20 == fVar19)) {
    fVar19 = (float10)iVar5;
  }
  local_6c = *(float **)(param_3 + 8);
  uVar6 = FUN_006e6b90();
  local_78 = *(ushort **)(param_1 + 0x2c);
  pfVar17 = *(float **)(param_1 + 0x24);
  uVar12 = uVar6 & 3;
  uVar13 = (uint)*(ushort *)(param_1 + 8);
  fVar2 = (float)(extraout_ST1 - (float10)(int)uVar6);
  iVar5 = *(int *)(param_1 + 0x28) + -0x20;
  puVar18 = (uint *)(((int)(uVar6 + ((int)uVar6 >> 0x1f & 3U)) >> 2) * uVar13 +
                    *(int *)(param_1 + 0x30));
  local_64 = param_5;
  if ((int)(uint)*(ushort *)(param_1 + 4) < (int)param_5) {
    local_64 = (uint)*(ushort *)(param_1 + 4);
  }
  pbVar1 = pbVar14 + param_6;
  pbVar7 = (byte *)(*(int *)(param_3 + 0xc) + param_6);
  if (param_6 != 0) {
    local_74 = (float *)0x0;
  }
  for (; pbVar14 < pbVar1; pbVar14 = pbVar14 + 1) {
    iVar16 = 0;
    do {
      iVar8 = 3;
      if (iVar16 == 1) {
        iVar8 = 4;
      }
      if (((&DAT_0076426c)[iVar16] & *pbVar14) == 0) {
        local_78 = local_78 + iVar8;
      }
      else {
        for (; iVar8 != 0; iVar8 = iVar8 + -1) {
          uVar4 = *local_78;
          local_78 = local_78 + 1;
          if (uVar4 < 0x10) {
            puVar18 = (uint *)((int)puVar18 + (uint)(byte)(&DAT_00764270)[uVar4]);
            pfVar17 = pfVar17 + 2;
          }
        }
      }
      iVar16 = iVar16 + 1;
      local_6c = local_6c + 4;
    } while (iVar16 < 3);
  }
  fVar20 = extraout_ST0;
  pfVar10 = local_74;
  do {
    if (pbVar1 + local_64 <= pbVar14) {
      return 0;
    }
    bVar3 = *pbVar14;
    *pbVar7 = *pbVar7 | bVar3;
    pbVar7 = pbVar7 + 1;
    local_7c = 0;
    do {
      fVar22 = (float10)(1.0 - param_4);
      if (((&DAT_0076426c)[local_7c] & bVar3) == 0) {
        fVar21 = (float10)*local_6c * fVar22;
        if (local_7c == 0) {
          *local_6c = (float)fVar21;
          local_6c[1] = (float)((float10)local_6c[1] * fVar22);
          local_6c[2] = (float)((float10)local_6c[2] * fVar22);
          if (pfVar10 == (float *)0x0) {
LAB_005cd064:
            local_78 = local_78 + 3;
            local_6c = local_6c + 4;
          }
          else {
            pfVar10[2] = (float)fVar20;
            pfVar10[1] = (float)fVar20;
            *pfVar10 = (float)fVar20;
            local_74 = (float *)0x0;
            pfVar10 = local_74;
            local_78 = local_78 + 3;
            local_6c = local_6c + 4;
          }
        }
        else {
          if (local_7c != 1) {
            *local_6c = (float)(fVar21 + fVar19);
            local_6c[1] = (float)((float10)local_6c[1] * fVar22 + fVar19);
            local_6c[2] = (float)((float10)local_6c[2] * fVar22 + fVar19);
            goto LAB_005cd064;
          }
          *local_6c = (float)fVar21;
          local_78 = local_78 + 4;
          local_6c[1] = (float)((float10)local_6c[1] * fVar22);
          local_6c[2] = (float)((float10)local_6c[2] * fVar22);
          local_6c[3] = (float)(fVar22 * (float10)local_6c[3] + fVar19);
          fVar23 = *local_6c;
          fVar26 = local_6c[1];
          fVar27 = local_6c[2];
          fVar28 = local_6c[3];
          auVar24._0_4_ = fVar27 * fVar27 + fVar23 * fVar23;
          auVar24._4_4_ = fVar28 * fVar28 + fVar26 * fVar26;
          auVar24._8_4_ = fVar23 * fVar23 + fVar27 * fVar27;
          auVar24._12_4_ = fVar26 * fVar26 + fVar28 * fVar28;
          auVar29._0_4_ = auVar24._4_4_ + auVar24._0_4_;
          auVar29._4_4_ = auVar24._0_4_ + auVar24._4_4_;
          auVar29._8_4_ = auVar24._12_4_ + auVar24._8_4_;
          auVar29._12_4_ = auVar24._8_4_ + auVar24._12_4_;
          auVar25 = rsqrtps(auVar24,auVar29);
          *local_6c = auVar25._0_4_ * fVar23;
          local_6c[1] = auVar25._4_4_ * fVar26;
          local_6c[2] = auVar25._8_4_ * fVar27;
          local_6c[3] = auVar25._12_4_ * fVar28;
          local_6c = local_6c + 4;
        }
      }
      else if (local_7c == 1) {
        local_8c = 0.0;
        pfVar10 = pfVar17;
        do {
          uVar6 = (uint)*local_78;
          local_78 = local_78 + 1;
          if (uVar6 == 6) {
            uVar6 = *(uint *)((int)puVar18 + uVar13);
            uVar9 = *puVar18 >> 8;
            sVar11 = (char)uVar12 * '\x06';
            fVar23 = (float)(uVar6 & 0xff);
            fVar26 = (float)(*puVar18 & 0xff);
            *(float *)((int)local_30 + (int)local_8c) =
                 ((float)(uVar9 >> sVar11 & 0x3f) * 0.01587302 * (fVar23 - fVar26) + fVar26) *
                 *pfVar10 + pfVar10[1];
            if (uVar12 < 3) {
              fVar27 = (fVar23 - fVar26) *
                       (float)(uVar9 >> (sVar11 + 6U & 0x1f) & 0x3f) * 0.01587302;
              fVar23 = fVar26;
            }
            else {
              fVar27 = ((float)*(byte *)((int)puVar18 + uVar13 * 2) - fVar23) *
                       (float)(uVar6 >> 8 & 0x3f) * 0.01587302;
            }
            puVar18 = puVar18 + 1;
            pfVar17 = pfVar10 + 2;
            *(float *)((int)local_40 + (int)local_8c) = (fVar27 + fVar23) * *pfVar10 + pfVar10[1];
          }
          else if (uVar6 == 7) {
            FUN_005ca5a0(puVar18,uVar12,uVar13,pfVar10,(int)local_30 + (int)local_8c,
                         (int)local_40 + (int)local_8c);
            fVar19 = (float10)param_4;
            puVar18 = puVar18 + 2;
            pfVar17 = pfVar10 + 2;
          }
          else {
            fVar23 = (float)*(ushort *)(iVar5 + uVar6 * 2) * *(float *)(param_1 + 0x20) +
                     *(float *)(param_1 + 0x1c);
            *(float *)((int)local_30 + (int)local_8c) = fVar23;
            *(float *)((int)local_40 + (int)local_8c) = fVar23;
            pfVar17 = pfVar10;
          }
          local_8c = (float)((int)local_8c + 4);
          pfVar10 = pfVar17;
        } while ((int)local_8c < 0x10);
        fVar23 = (local_40[0] - local_30[0]) * fVar2 + local_30[0];
        fVar26 = (local_40[1] - local_30[1]) * fVar2 + local_30[1];
        fVar27 = (local_40[2] - local_30[2]) * fVar2 + local_30[2];
        fVar28 = (local_40[3] - local_30[3]) * fVar2 + local_30[3];
        auVar30._0_4_ = fVar27 * fVar27 + fVar23 * fVar23;
        auVar30._4_4_ = fVar28 * fVar28 + fVar26 * fVar26;
        auVar30._8_4_ = fVar23 * fVar23 + fVar27 * fVar27;
        auVar30._12_4_ = fVar26 * fVar26 + fVar28 * fVar28;
        auVar25._4_4_ = auVar30._0_4_ + auVar30._4_4_;
        auVar25._0_4_ = auVar30._4_4_ + auVar30._0_4_;
        auVar25._8_4_ = auVar30._12_4_ + auVar30._8_4_;
        auVar25._12_4_ = auVar30._8_4_ + auVar30._12_4_;
        auVar25 = rsqrtps(auVar30,auVar25);
        local_20._0_4_ = auVar25._0_4_ * fVar23;
        local_20._4_4_ = auVar25._4_4_ * fVar26;
        local_20._8_4_ = auVar25._8_4_ * fVar27;
        local_20._12_4_ = auVar25._12_4_ * fVar28;
        FUN_005b8cf0(local_20,local_6c,local_20,(float)fVar19);
        fVar20 = (float10)0;
        local_6c = local_6c + 4;
        fVar19 = (float10)param_4;
        pfVar10 = local_74;
      }
      else {
        local_84 = 0;
        pfVar10 = local_6c;
        do {
          local_6c = pfVar10;
          pfVar10 = local_74;
          uVar4 = *local_78;
          local_78 = local_78 + 1;
          if (uVar4 == 6) {
            uVar9 = *puVar18 & 0xff;
            uVar15 = *(uint *)((int)puVar18 + uVar13) & 0xff;
            uVar6 = *puVar18 >> 8;
            sVar11 = (char)uVar12 * '\x06';
            fVar23 = (float)(uVar6 >> sVar11 & 0x3f) * 0.01587302;
            if (uVar12 < 3) {
              fVar26 = (float)uVar9;
              fVar26 = (fVar23 + fVar2 * ((float)(uVar6 >> (sVar11 + 6U & 0x1f) & 0x3f) * 0.01587302
                                         - fVar23)) * ((float)uVar15 - fVar26) + fVar26;
            }
            else {
              fVar27 = (float)uVar15;
              fVar26 = (float)uVar9;
              fVar26 = fVar26 + fVar23 * (fVar27 - fVar26);
              fVar26 = fVar26 + fVar2 * ((((float)*(byte *)((int)puVar18 + uVar13 * 2) - fVar27) *
                                          (float)(*(uint *)((int)puVar18 + uVar13) >> 8 & 0x3f) *
                                          0.01587302 + fVar27) - fVar26);
            }
            puVar18 = puVar18 + 1;
            local_8c = fVar26 * *pfVar17 + pfVar17[1];
            pfVar17 = pfVar17 + 2;
            fVar20 = (float10)0;
          }
          else {
            local_8c = (float)*(ushort *)(iVar5 + (uint)uVar4 * 2) * *(float *)(param_1 + 0x20) +
                       *(float *)(param_1 + 0x1c);
          }
          fVar23 = *local_6c;
          if (local_74 != (float *)0x0) {
            if (local_84 == 0) {
              *local_74 = local_8c;
            }
            else if (local_84 == 1) {
              local_74[1] = local_8c;
            }
            else {
              local_74 = (float *)0x0;
              pfVar10[2] = -local_8c;
            }
          }
          local_84 = local_84 + 1;
          *local_6c = (float)((float10)(local_8c - fVar23) * fVar19 + (float10)*local_6c);
          pfVar10 = local_6c + 1;
        } while (local_84 < 3);
        local_6c = local_6c + 2;
        pfVar10 = local_74;
      }
      local_7c = local_7c + 1;
    } while (local_7c < 3);
    pbVar14 = pbVar14 + 1;
  } while( true );
}

