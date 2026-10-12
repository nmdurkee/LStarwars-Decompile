/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5cc550; label: FUN_005cc550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x005ccbfb) */
/* WARNING: Removing unreachable block (ram,0x005ccbbe) */
/* WARNING: Removing unreachable block (ram,0x005cccb0) */
/* WARNING: Removing unreachable block (ram,0x005cc91e) */
/* WARNING: Removing unreachable block (ram,0x005ccc2d) */
/* WARNING: Removing unreachable block (ram,0x005ccbdd) */
/* WARNING: Removing unreachable block (ram,0x005ccc52) */
/* WARNING: Removing unreachable block (ram,0x005ccc68) */
/* WARNING: Removing unreachable block (ram,0x005cc934) */
/* WARNING: Removing unreachable block (ram,0x005cc95f) */
/* WARNING: Removing unreachable block (ram,0x005cc9db) */
/* WARNING: Removing unreachable block (ram,0x005cc99d) */

undefined4
FUN_005cc550(int param_1,float param_2,int param_3,float param_4,uint param_5,int param_6,
            float *param_7)

{
  float fVar1;
  byte bVar2;
  ushort uVar3;
  float *pfVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  sbyte sVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  byte *pbVar13;
  uint uVar14;
  int iVar15;
  float *pfVar16;
  uint *puVar17;
  float10 fVar18;
  float10 fVar19;
  float10 extraout_ST0;
  float10 fVar20;
  float10 extraout_ST1;
  float10 fVar21;
  float fVar22;
  float fVar25;
  float fVar26;
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  float fVar27;
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  int local_88;
  float local_84;
  int local_80;
  ushort *local_7c;
  float *local_74;
  float *local_60;
  float local_40 [4];
  float local_30 [4];
  undefined1 local_20 [16];
  
  pbVar7 = *(byte **)(param_1 + 0x34);
  iVar5 = *(ushort *)(param_1 + 6) - 1;
  local_60 = param_7;
  fVar18 = (float10)(((float)iVar5 * (param_2 - (float)*(ushort *)(param_1 + 0xe))) /
                    (float)(int)(*(ushort *)(param_1 + 10) - 1));
  if (fVar18 < (float10)0) {
    fVar18 = (float10)(float)(float10)0;
  }
  fVar19 = (float10)*(ushort *)(param_1 + 6);
  if (fVar19 < fVar18 != (fVar19 == fVar18)) {
    fVar18 = (float10)iVar5;
  }
  local_74 = *(float **)(param_3 + 8);
  uVar6 = FUN_006e6b90();
  local_7c = *(ushort **)(param_1 + 0x2c);
  pfVar16 = *(float **)(param_1 + 0x24);
  uVar10 = uVar6 & 3;
  uVar11 = (uint)*(ushort *)(param_1 + 8);
  fVar1 = (float)(extraout_ST1 - (float10)(int)uVar6);
  iVar5 = *(int *)(param_1 + 0x28) + -0x20;
  puVar17 = (uint *)(((int)(uVar6 + ((int)uVar6 >> 0x1f & 3U)) >> 2) * uVar11 +
                    *(int *)(param_1 + 0x30));
  local_84 = (float)param_5;
  if ((int)(uint)*(ushort *)(param_1 + 4) < (int)param_5) {
    local_84 = (float)(uint)*(ushort *)(param_1 + 4);
  }
  pbVar13 = pbVar7 + param_6;
  pbVar12 = (byte *)(*(int *)(param_3 + 0xc) + param_6);
  if (param_6 != 0) {
    local_60 = (float *)0x0;
  }
  for (; pbVar7 < pbVar13; pbVar7 = pbVar7 + 1) {
    iVar15 = 0;
    do {
      if (((&DAT_0076426c)[iVar15] & *pbVar7) != 0) {
        if (*local_7c < 0x10) {
          puVar17 = (uint *)((int)puVar17 + (uint)(byte)(&DAT_00764270)[*local_7c]);
          pfVar16 = pfVar16 + 2;
        }
        if (local_7c[1] < 0x10) {
          puVar17 = (uint *)((int)puVar17 + (uint)(byte)(&DAT_00764270)[local_7c[1]]);
          pfVar16 = pfVar16 + 2;
        }
        if (local_7c[2] < 0x10) {
          puVar17 = (uint *)((int)puVar17 + (uint)(byte)(&DAT_00764270)[local_7c[2]]);
          pfVar16 = pfVar16 + 2;
        }
      }
      local_7c = local_7c + 3;
      local_74 = local_74 + 4;
      iVar15 = iVar15 + 1;
    } while (iVar15 < 3);
  }
  pbVar13 = pbVar13 + (int)local_84;
  fVar19 = extraout_ST0;
  do {
    if (pbVar13 <= pbVar7) {
      return 0;
    }
    bVar2 = *pbVar7;
    *pbVar12 = *pbVar12 | bVar2;
    pbVar12 = pbVar12 + 1;
    local_80 = 0;
    do {
      pfVar4 = local_60;
      fVar21 = (float10)(1.0 - param_4);
      if (((&DAT_0076426c)[local_80] & bVar2) == 0) {
        fVar20 = (float10)*local_74 * fVar21;
        if (local_80 == 0) {
          *local_74 = (float)fVar20;
          local_74[1] = (float)((float10)local_74[1] * fVar21);
          local_74[2] = (float)((float10)local_74[2] * fVar21);
          if (local_60 != (float *)0x0) {
            local_60 = (float *)0x0;
            pfVar4[2] = (float)fVar19;
            pfVar4[1] = (float)fVar19;
            *pfVar4 = (float)fVar19;
          }
          local_7c = local_7c + 3;
          local_74 = local_74 + 4;
        }
        else if (local_80 == 1) {
          *local_74 = (float)fVar20;
          local_7c = local_7c + 3;
          local_74[1] = (float)((float10)local_74[1] * fVar21);
          local_74[2] = (float)((float10)local_74[2] * fVar21);
          local_74[3] = (float)(fVar21 * (float10)local_74[3] + fVar18);
          fVar22 = *local_74;
          fVar25 = local_74[1];
          fVar26 = local_74[2];
          fVar27 = local_74[3];
          auVar23._0_4_ = fVar26 * fVar26 + fVar22 * fVar22;
          auVar23._4_4_ = fVar27 * fVar27 + fVar25 * fVar25;
          auVar23._8_4_ = fVar22 * fVar22 + fVar26 * fVar26;
          auVar23._12_4_ = fVar25 * fVar25 + fVar27 * fVar27;
          auVar28._0_4_ = auVar23._4_4_ + auVar23._0_4_;
          auVar28._4_4_ = auVar23._0_4_ + auVar23._4_4_;
          auVar28._8_4_ = auVar23._12_4_ + auVar23._8_4_;
          auVar28._12_4_ = auVar23._8_4_ + auVar23._12_4_;
          auVar24 = rsqrtps(auVar23,auVar28);
          *local_74 = auVar24._0_4_ * fVar22;
          local_74[1] = auVar24._4_4_ * fVar25;
          local_74[2] = auVar24._8_4_ * fVar26;
          local_74[3] = auVar24._12_4_ * fVar27;
          local_74 = local_74 + 4;
        }
        else {
          local_7c = local_7c + 3;
          *local_74 = (float)(fVar20 + fVar18);
          local_74[1] = (float)((float10)local_74[1] * fVar21 + fVar18);
          local_74[2] = (float)((float10)local_74[2] * fVar21 + fVar18);
          local_74 = local_74 + 4;
        }
      }
      else if (local_80 == 1) {
        local_84 = 0.0;
        do {
          uVar6 = (uint)*local_7c;
          local_7c = local_7c + 1;
          if (uVar6 == 6) {
            uVar6 = *(uint *)((int)puVar17 + uVar11);
            uVar8 = *puVar17 >> 8;
            sVar9 = (char)uVar10 * '\x06';
            fVar22 = (float)(uVar6 & 0xff);
            fVar25 = (float)(*puVar17 & 0xff);
            *(float *)((int)local_30 + (int)local_84) =
                 ((float)(uVar8 >> sVar9 & 0x3f) * 0.01587302 * (fVar22 - fVar25) + fVar25) *
                 *pfVar16 + pfVar16[1];
            if (uVar10 < 3) {
              fVar26 = (fVar22 - fVar25) * (float)(uVar8 >> (sVar9 + 6U & 0x1f) & 0x3f) * 0.01587302
              ;
              fVar22 = fVar25;
            }
            else {
              fVar26 = ((float)*(byte *)((int)puVar17 + uVar11 * 2) - fVar22) *
                       (float)(uVar6 >> 8 & 0x3f) * 0.01587302;
            }
            puVar17 = puVar17 + 1;
            *(float *)((int)local_40 + (int)local_84) = (fVar26 + fVar22) * *pfVar16 + pfVar16[1];
LAB_005cc9f9:
            pfVar16 = pfVar16 + 2;
          }
          else {
            if (uVar6 == 7) {
              FUN_005ca5a0(puVar17,uVar10,uVar11,pfVar16,(int)local_30 + (int)local_84,
                           (int)local_40 + (int)local_84);
              puVar17 = puVar17 + 2;
              goto LAB_005cc9f9;
            }
            fVar22 = (float)*(ushort *)(iVar5 + uVar6 * 2) * *(float *)(param_1 + 0x20) +
                     *(float *)(param_1 + 0x1c);
            *(float *)((int)local_30 + (int)local_84) = fVar22;
            *(float *)((int)local_40 + (int)local_84) = fVar22;
          }
          local_84 = (float)((int)local_84 + 4);
        } while ((int)local_84 < 0xc);
        fVar18 = (float10)FUN_005c0240(1.0 - (local_30[2] * local_30[2] +
                                             local_30[0] * local_30[0] + local_30[1] * local_30[1]))
        ;
        local_30[3] = (float)fVar18;
        fVar18 = (float10)FUN_005c0240(1.0 - (local_40[2] * local_40[2] +
                                             local_40[0] * local_40[0] + local_40[1] * local_40[1]))
        ;
        local_40[3] = (float)fVar18;
        FUN_005b83b0(local_30,local_40);
        fVar22 = (local_40[0] - local_30[0]) * fVar1 + local_30[0];
        fVar25 = (local_40[1] - local_30[1]) * fVar1 + local_30[1];
        fVar26 = (local_40[2] - local_30[2]) * fVar1 + local_30[2];
        fVar27 = (local_40[3] - local_30[3]) * fVar1 + local_30[3];
        auVar29._0_4_ = fVar26 * fVar26 + fVar22 * fVar22;
        auVar29._4_4_ = fVar27 * fVar27 + fVar25 * fVar25;
        auVar29._8_4_ = fVar22 * fVar22 + fVar26 * fVar26;
        auVar29._12_4_ = fVar25 * fVar25 + fVar27 * fVar27;
        auVar24._4_4_ = auVar29._0_4_ + auVar29._4_4_;
        auVar24._0_4_ = auVar29._4_4_ + auVar29._0_4_;
        auVar24._8_4_ = auVar29._12_4_ + auVar29._8_4_;
        auVar24._12_4_ = auVar29._8_4_ + auVar29._12_4_;
        auVar24 = rsqrtps(auVar29,auVar24);
        local_20._0_4_ = auVar24._0_4_ * fVar22;
        local_20._4_4_ = auVar24._4_4_ * fVar25;
        local_20._8_4_ = auVar24._8_4_ * fVar26;
        local_20._12_4_ = auVar24._12_4_ * fVar27;
        FUN_005b8cf0(local_74,local_74,local_20,param_4);
        fVar18 = (float10)param_4;
        fVar19 = (float10)0;
        local_74 = local_74 + 4;
      }
      else {
        local_88 = 0;
        pfVar4 = local_74;
        do {
          local_74 = pfVar4;
          pfVar4 = local_60;
          uVar3 = *local_7c;
          local_7c = local_7c + 1;
          if (uVar3 == 6) {
            uVar8 = *puVar17 & 0xff;
            uVar14 = *(uint *)((int)puVar17 + uVar11) & 0xff;
            uVar6 = *puVar17 >> 8;
            sVar9 = (char)uVar10 * '\x06';
            fVar22 = (float)(uVar6 >> sVar9 & 0x3f) * 0.01587302;
            if (uVar10 < 3) {
              fVar25 = (float)uVar8;
              fVar25 = (fVar22 + fVar1 * ((float)(uVar6 >> (sVar9 + 6U & 0x1f) & 0x3f) * 0.01587302
                                         - fVar22)) * ((float)uVar14 - fVar25) + fVar25;
            }
            else {
              fVar26 = (float)uVar14;
              fVar25 = (float)uVar8;
              fVar25 = fVar25 + fVar22 * (fVar26 - fVar25);
              fVar25 = fVar25 + fVar1 * ((((float)*(byte *)((int)puVar17 + uVar11 * 2) - fVar26) *
                                          (float)(*(uint *)((int)puVar17 + uVar11) >> 8 & 0x3f) *
                                          0.01587302 + fVar26) - fVar25);
            }
            puVar17 = puVar17 + 1;
            local_84 = fVar25 * *pfVar16 + pfVar16[1];
            pfVar16 = pfVar16 + 2;
            fVar19 = (float10)0;
          }
          else {
            local_84 = (float)*(ushort *)(iVar5 + (uint)uVar3 * 2) * *(float *)(param_1 + 0x20) +
                       *(float *)(param_1 + 0x1c);
          }
          fVar22 = *local_74;
          if (local_60 != (float *)0x0) {
            if (local_88 == 0) {
              *local_60 = local_84;
            }
            else if (local_88 == 1) {
              local_60[1] = local_84;
            }
            else {
              local_60 = (float *)0x0;
              pfVar4[2] = -local_84;
            }
          }
          local_88 = local_88 + 1;
          *local_74 = (float)((float10)(local_84 - fVar22) * fVar18 + (float10)*local_74);
          pfVar4 = local_74 + 1;
        } while (local_88 < 3);
        local_74 = local_74 + 2;
      }
      local_80 = local_80 + 1;
    } while (local_80 < 3);
    pbVar7 = pbVar7 + 1;
  } while( true );
}

