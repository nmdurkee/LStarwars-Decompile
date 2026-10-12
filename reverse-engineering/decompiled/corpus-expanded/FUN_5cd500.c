/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5cd500; label: FUN_005cd500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x005cdbdb) */
/* WARNING: Removing unreachable block (ram,0x005cdb9e) */
/* WARNING: Removing unreachable block (ram,0x005cdc98) */
/* WARNING: Removing unreachable block (ram,0x005cd8b2) */
/* WARNING: Removing unreachable block (ram,0x005cdc0d) */
/* WARNING: Removing unreachable block (ram,0x005cdbbd) */
/* WARNING: Removing unreachable block (ram,0x005cdc36) */
/* WARNING: Removing unreachable block (ram,0x005cdc4c) */
/* WARNING: Removing unreachable block (ram,0x005cd8c8) */
/* WARNING: Removing unreachable block (ram,0x005cd8f3) */
/* WARNING: Removing unreachable block (ram,0x005cd96b) */
/* WARNING: Removing unreachable block (ram,0x005cd931) */

undefined4
FUN_005cd500(int param_1,float param_2,int param_3,float param_4,uint param_5,int param_6,
            float *param_7)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  ushort uVar4;
  undefined1 auVar5 [16];
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  uint uVar10;
  byte *pbVar11;
  uint uVar12;
  undefined4 uVar13;
  sbyte sVar14;
  uint uVar15;
  uint uVar16;
  byte *pbVar17;
  int iVar18;
  uint uVar19;
  byte *pbVar20;
  float *pfVar21;
  float *pfVar22;
  uint *puVar23;
  float10 fVar24;
  float10 fVar25;
  float10 extraout_ST0;
  float10 fVar26;
  float10 extraout_ST1;
  float10 fVar27;
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  int local_b4;
  int local_ac;
  float local_a8;
  ushort *local_a4;
  uint *local_a0;
  float *local_98;
  float *local_88;
  float local_68 [7];
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float local_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float local_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  pbVar20 = *(byte **)(param_1 + 0x34);
  iVar9 = *(ushort *)(param_1 + 6) - 1;
  local_88 = param_7;
  fVar24 = (float10)(((float)iVar9 * (param_2 - (float)*(ushort *)(param_1 + 0xe))) /
                    (float)(int)(*(ushort *)(param_1 + 10) - 1));
  if (fVar24 < (float10)0) {
    fVar24 = (float10)(float)(float10)0;
  }
  fVar25 = (float10)*(ushort *)(param_1 + 6);
  if (fVar25 < fVar24 != (fVar25 == fVar24)) {
    fVar24 = (float10)iVar9;
  }
  local_98 = *(float **)(param_3 + 8);
  uVar10 = FUN_006e6b90();
  local_a4 = *(ushort **)(param_1 + 0x2c);
  pfVar22 = *(float **)(param_1 + 0x24);
  uVar15 = uVar10 & 3;
  uVar16 = (uint)*(ushort *)(param_1 + 8);
  fVar1 = (float)(extraout_ST1 - (float10)(int)uVar10);
  iVar9 = *(int *)(param_1 + 0x28) + -0x20;
  puVar23 = (uint *)(((int)(uVar10 + ((int)uVar10 >> 0x1f & 3U)) >> 2) * uVar16 +
                    *(int *)(param_1 + 0x30));
  local_a8 = (float)param_5;
  if ((int)(uint)*(ushort *)(param_1 + 4) < (int)param_5) {
    local_a8 = (float)(uint)*(ushort *)(param_1 + 4);
  }
  pbVar11 = pbVar20 + param_6;
  pbVar17 = (byte *)(*(int *)(param_3 + 0xc) + param_6);
  if (param_6 != 0) {
    local_88 = (float *)0x0;
  }
  if (pbVar20 < pbVar11) {
    local_98 = local_98 + ((int)pbVar11 - (int)pbVar20) * 0xc;
    do {
      iVar18 = 0;
      do {
        if (((&DAT_0076426c)[iVar18] & *pbVar20) != 0) {
          if (*local_a4 < 0x10) {
            puVar23 = (uint *)((int)puVar23 + (uint)(byte)(&DAT_00764270)[*local_a4]);
            pfVar22 = pfVar22 + 2;
          }
          if (local_a4[1] < 0x10) {
            puVar23 = (uint *)((int)puVar23 + (uint)(byte)(&DAT_00764270)[local_a4[1]]);
            pfVar22 = pfVar22 + 2;
          }
          if (local_a4[2] < 0x10) {
            puVar23 = (uint *)((int)puVar23 + (uint)(byte)(&DAT_00764270)[local_a4[2]]);
            pfVar22 = pfVar22 + 2;
          }
        }
        local_a4 = local_a4 + 3;
        iVar18 = iVar18 + 1;
      } while (iVar18 < 3);
      pbVar20 = pbVar20 + 1;
    } while (pbVar20 < pbVar11);
  }
  pbVar11 = pbVar11 + (int)local_a8;
  local_a0 = puVar23;
  fVar25 = extraout_ST0;
  do {
    if (pbVar11 <= pbVar20) {
      return 0;
    }
    bVar3 = *pbVar20;
    *pbVar17 = *pbVar17 | bVar3;
    pbVar17 = pbVar17 + 1;
    local_ac = 0;
    do {
      fVar27 = (float10)(1.0 - param_4);
      if (((&DAT_0076426c)[local_ac] & bVar3) == 0) {
        fVar26 = (float10)*local_98 * fVar27;
        if (local_ac == 0) {
          *local_98 = (float)fVar26;
          local_98[1] = (float)((float10)local_98[1] * fVar27);
          local_98[2] = (float)((float10)local_98[2] * fVar27);
          if (local_88 == (float *)0x0) {
LAB_005cd81f:
            local_a4 = local_a4 + 3;
            local_98 = local_98 + 4;
          }
          else {
            local_88[2] = (float)fVar25;
            local_a4 = local_a4 + 3;
            local_88[1] = (float)fVar25;
            *local_88 = (float)fVar25;
            local_88 = (float *)0x0;
            local_98 = local_98 + 4;
          }
        }
        else {
          if (local_ac != 1) {
            *local_98 = (float)(fVar26 + fVar24);
            local_98[1] = (float)((float10)local_98[1] * fVar27 + fVar24);
            local_98[2] = (float)((float10)local_98[2] * fVar27 + fVar24);
            goto LAB_005cd81f;
          }
          *local_98 = (float)fVar26;
          local_a4 = local_a4 + 3;
          local_98[1] = (float)((float10)local_98[1] * fVar27);
          local_98[2] = (float)((float10)local_98[2] * fVar27);
          local_98[3] = (float)(fVar27 * (float10)local_98[3] + fVar24);
          fVar2 = *local_98;
          fVar6 = local_98[1];
          fVar7 = local_98[2];
          fVar8 = local_98[3];
          auVar28._0_4_ = fVar7 * fVar7 + fVar2 * fVar2;
          auVar28._4_4_ = fVar8 * fVar8 + fVar6 * fVar6;
          auVar28._8_4_ = fVar2 * fVar2 + fVar7 * fVar7;
          auVar28._12_4_ = fVar6 * fVar6 + fVar8 * fVar8;
          auVar5._4_4_ = auVar28._0_4_ + auVar28._4_4_;
          auVar5._0_4_ = auVar28._4_4_ + auVar28._0_4_;
          auVar5._8_4_ = auVar28._12_4_ + auVar28._8_4_;
          auVar5._12_4_ = auVar28._8_4_ + auVar28._12_4_;
          auVar29 = rsqrtps(auVar28,auVar5);
          *local_98 = auVar29._0_4_ * fVar2;
          local_98[1] = auVar29._4_4_ * fVar6;
          local_98[2] = auVar29._8_4_ * fVar7;
          local_98[3] = auVar29._12_4_ * fVar8;
          local_98 = local_98 + 4;
        }
      }
      else if (local_ac == 1) {
        local_a0 = (uint *)0x0;
        pfVar21 = pfVar22;
        do {
          uVar4 = *local_a4;
          local_a4 = local_a4 + 1;
          if (uVar4 == 6) {
            uVar10 = *(uint *)((int)puVar23 + uVar16);
            uVar12 = *puVar23 >> 8;
            sVar14 = (char)uVar15 * '\x06';
            fVar2 = (float)(uVar10 & 0xff);
            fVar6 = (float)(*puVar23 & 0xff);
            *(float *)((int)local_68 + (int)local_a0 + 0xc) =
                 ((float)(uVar12 >> sVar14 & 0x3f) * 0.01587302 * (fVar2 - fVar6) + fVar6) *
                 *pfVar21 + pfVar21[1];
            if (uVar15 < 3) {
              fVar7 = (fVar2 - fVar6) * (float)(uVar12 >> (sVar14 + 6U & 0x1f) & 0x3f) * 0.01587302;
              fVar2 = fVar6;
            }
            else {
              fVar7 = ((float)*(byte *)((int)puVar23 + uVar16 * 2) - fVar2) *
                      (float)(uVar10 >> 8 & 0x3f) * 0.01587302;
            }
            puVar23 = puVar23 + 1;
            pfVar22 = pfVar21 + 2;
            fVar2 = (fVar7 + fVar2) * *pfVar21 + pfVar21[1];
          }
          else {
            fVar2 = (float)*(ushort *)(iVar9 + (uint)uVar4 * 2) * *(float *)(param_1 + 0x20) +
                    *(float *)(param_1 + 0x1c);
            *(float *)((int)local_68 + (int)local_a0 + 0xc) = fVar2;
            pfVar22 = pfVar21;
          }
          *(float *)((int)local_68 + (int)local_a0) = fVar2;
          local_a0 = (uint *)((int)local_a0 + 4);
          pfVar21 = pfVar22;
        } while ((int)local_a0 < 0xc);
        uVar13 = FUN_006e6b90();
        uVar13 = FUN_006e6b90(uVar13);
        uVar13 = FUN_006e6b90(uVar13);
        FUN_005b7d60(&local_40,uVar13);
        uVar13 = FUN_006e6b90();
        uVar13 = FUN_006e6b90(uVar13);
        uVar13 = FUN_006e6b90(uVar13);
        FUN_005b7d60(local_68 + 6,uVar13);
        fStack_1c = fStack_48 * fStack_38 + local_68[6] * local_40;
        fStack_14 = local_68[6] * local_40 + fStack_48 * fStack_38;
        fStack_18 = fStack_4c * fStack_3c + fStack_44 * fStack_34;
        local_20 = fStack_44 * fStack_34 + fStack_4c * fStack_3c + fStack_1c;
        if (local_20 < 0.0) {
          local_68[6] = 0.0 - local_68[6];
          fStack_4c = 0.0 - fStack_4c;
          fStack_48 = 0.0 - fStack_48;
          fStack_44 = 0.0 - fStack_44;
        }
        local_30 = (local_68[6] - local_40) * fVar1 + local_40;
        fStack_2c = (fStack_4c - fStack_3c) * fVar1 + fStack_3c;
        fStack_28 = (fStack_48 - fStack_38) * fVar1 + fStack_38;
        fStack_24 = (fStack_44 - fStack_34) * fVar1 + fStack_34;
        auVar30._0_4_ = fStack_28 * fStack_28 + local_30 * local_30;
        auVar30._4_4_ = fStack_24 * fStack_24 + fStack_2c * fStack_2c;
        auVar30._8_4_ = local_30 * local_30 + fStack_28 * fStack_28;
        auVar30._12_4_ = fStack_2c * fStack_2c + fStack_24 * fStack_24;
        auVar29._4_4_ = auVar30._0_4_ + auVar30._4_4_;
        auVar29._0_4_ = auVar30._4_4_ + auVar30._0_4_;
        auVar29._8_4_ = auVar30._12_4_ + auVar30._8_4_;
        auVar29._12_4_ = auVar30._8_4_ + auVar30._12_4_;
        auVar29 = rsqrtps(auVar30,auVar29);
        local_30 = auVar29._0_4_ * local_30;
        fStack_2c = auVar29._4_4_ * fStack_2c;
        fStack_28 = auVar29._8_4_ * fStack_28;
        fStack_24 = auVar29._12_4_ * fStack_24;
        FUN_005b8cf0(local_98,local_98,&local_30,param_4);
        fVar24 = (float10)param_4;
        local_98 = local_98 + 4;
        fVar25 = (float10)0;
        local_a0 = puVar23;
      }
      else {
        local_b4 = 0;
        pfVar21 = local_98;
        do {
          local_98 = pfVar21;
          pfVar21 = local_88;
          uVar4 = *local_a4;
          local_a4 = local_a4 + 1;
          if (uVar4 == 6) {
            uVar12 = *puVar23 & 0xff;
            uVar19 = *(uint *)((int)puVar23 + uVar16) & 0xff;
            uVar10 = *puVar23 >> 8;
            sVar14 = (char)uVar15 * '\x06';
            fVar2 = (float)(uVar10 >> sVar14 & 0x3f) * 0.01587302;
            if (uVar15 < 3) {
              fVar6 = (float)uVar12;
              fVar6 = (fVar2 + fVar1 * ((float)(uVar10 >> (sVar14 + 6U & 0x1f) & 0x3f) * 0.01587302
                                       - fVar2)) * ((float)uVar19 - fVar6) + fVar6;
            }
            else {
              fVar7 = (float)uVar19;
              fVar6 = (float)uVar12;
              fVar6 = fVar6 + fVar2 * (fVar7 - fVar6);
              fVar6 = fVar6 + fVar1 * ((((float)*(byte *)((int)local_a0 + uVar16 * 2) - fVar7) *
                                        (float)(*(uint *)((int)puVar23 + uVar16) >> 8 & 0x3f) *
                                        0.01587302 + fVar7) - fVar6);
            }
            puVar23 = local_a0 + 1;
            local_a8 = fVar6 * *pfVar22 + pfVar22[1];
            pfVar22 = pfVar22 + 2;
            fVar25 = (float10)0;
            local_a0 = puVar23;
          }
          else {
            local_a8 = (float)*(ushort *)(iVar9 + (uint)uVar4 * 2) * *(float *)(param_1 + 0x20) +
                       *(float *)(param_1 + 0x1c);
          }
          fVar2 = *local_98;
          if (local_88 != (float *)0x0) {
            if (local_b4 == 0) {
              *local_88 = local_a8;
            }
            else if (local_b4 == 1) {
              local_88[1] = local_a8;
            }
            else {
              local_88 = (float *)0x0;
              pfVar21[2] = -local_a8;
            }
          }
          local_b4 = local_b4 + 1;
          *local_98 = (float)((float10)(local_a8 - fVar2) * fVar24 + (float10)*local_98);
          pfVar21 = local_98 + 1;
        } while (local_b4 < 3);
        local_98 = local_98 + 2;
      }
      local_ac = local_ac + 1;
    } while (local_ac < 3);
    pbVar20 = pbVar20 + 1;
  } while( true );
}

