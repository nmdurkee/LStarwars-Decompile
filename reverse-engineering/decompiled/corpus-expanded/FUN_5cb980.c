/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5cb980; label: FUN_005cb980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x005cbf67) */
/* WARNING: Removing unreachable block (ram,0x005cbf26) */
/* WARNING: Removing unreachable block (ram,0x005cc02f) */
/* WARNING: Removing unreachable block (ram,0x005cbc7c) */
/* WARNING: Removing unreachable block (ram,0x005cbf99) */
/* WARNING: Removing unreachable block (ram,0x005cbf49) */
/* WARNING: Removing unreachable block (ram,0x005cbfcd) */
/* WARNING: Removing unreachable block (ram,0x005cbfe3) */
/* WARNING: Removing unreachable block (ram,0x005cbc92) */
/* WARNING: Removing unreachable block (ram,0x005cbcbd) */
/* WARNING: Removing unreachable block (ram,0x005cbd35) */
/* WARNING: Removing unreachable block (ram,0x005cbcfb) */

undefined4 FUN_005cb980(int param_1,undefined4 param_2,int param_3,uint param_4,int param_5)

{
  float fVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  undefined4 uVar7;
  sbyte sVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  uint uVar12;
  byte *pbVar13;
  int iVar14;
  ushort *puVar15;
  float *pfVar16;
  float *pfVar17;
  int iVar18;
  uint *puVar19;
  float10 extraout_ST0;
  float10 fVar20;
  float10 extraout_ST1;
  float fVar21;
  float fVar24;
  float fVar25;
  float fVar26;
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  int local_9c;
  float *local_94;
  int local_8c;
  uint *local_84;
  uint local_80;
  float local_58 [7];
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
  
  pbVar11 = *(byte **)(param_1 + 0x34);
  *(undefined1 *)(param_3 + 6) = 1;
  local_94 = *(float **)(param_3 + 8);
  uVar4 = FUN_006e6b90();
  puVar15 = *(ushort **)(param_1 + 0x2c);
  pfVar17 = *(float **)(param_1 + 0x24);
  uVar9 = uVar4 & 3;
  uVar10 = (uint)*(ushort *)(param_1 + 8);
  iVar18 = *(int *)(param_1 + 0x28) + -0x20;
  fVar1 = (float)(extraout_ST0 - (float10)(int)uVar4);
  puVar19 = (uint *)(((int)(uVar4 + ((int)uVar4 >> 0x1f & 3U)) >> 2) * uVar10 +
                    *(int *)(param_1 + 0x30));
  local_80 = param_4;
  if ((int)(uint)*(ushort *)(param_1 + 4) < (int)param_4) {
    local_80 = (uint)*(ushort *)(param_1 + 4);
  }
  pbVar5 = pbVar11 + param_5;
  pbVar13 = (byte *)(*(int *)(param_3 + 0xc) + param_5);
  for (; pbVar11 < pbVar5; pbVar11 = pbVar11 + 1) {
    iVar14 = 0;
    do {
      if (((&DAT_0076426c)[iVar14] & *pbVar11) != 0) {
        if (*puVar15 < 0x10) {
          puVar19 = (uint *)((int)puVar19 + (uint)(byte)(&DAT_00764270)[*puVar15]);
          pfVar17 = pfVar17 + 2;
        }
        if (puVar15[1] < 0x10) {
          puVar19 = (uint *)((int)puVar19 + (uint)(byte)(&DAT_00764270)[puVar15[1]]);
          pfVar17 = pfVar17 + 2;
        }
        if (puVar15[2] < 0x10) {
          puVar19 = (uint *)((int)puVar19 + (uint)(byte)(&DAT_00764270)[puVar15[2]]);
          pfVar17 = pfVar17 + 2;
        }
      }
      local_94 = local_94 + 4;
      puVar15 = puVar15 + 3;
      iVar14 = iVar14 + 1;
    } while (iVar14 < 3);
  }
  pbVar5 = pbVar5 + local_80;
  fVar20 = extraout_ST1;
  local_84 = puVar19;
  for (; pbVar11 < pbVar5; pbVar11 = pbVar11 + 1) {
    bVar2 = *pbVar11;
    *pbVar13 = bVar2;
    pbVar13 = pbVar13 + 1;
    local_80 = 0;
    do {
      if (((&DAT_0076426c)[local_80] & bVar2) == 0) {
        if (local_80 == 0) {
          local_94[2] = (float)fVar20;
          puVar15 = puVar15 + 3;
          local_94[1] = (float)fVar20;
          *local_94 = (float)fVar20;
          local_94 = local_94 + 4;
        }
        else if (local_80 == 1) {
          local_94[2] = (float)fVar20;
          puVar15 = puVar15 + 3;
          local_94[1] = (float)fVar20;
          *local_94 = (float)fVar20;
          local_94[3] = 1.0;
          local_94 = local_94 + 4;
        }
        else {
          local_94[2] = 1.0;
          puVar15 = puVar15 + 3;
          local_94[1] = 1.0;
          *local_94 = 1.0;
          local_94 = local_94 + 4;
        }
      }
      else if (local_80 == 1) {
        local_8c = 0;
        local_84 = (uint *)0x0;
        pfVar16 = pfVar17;
        do {
          uVar3 = *puVar15;
          puVar15 = puVar15 + 1;
          if (uVar3 == 6) {
            uVar4 = *(uint *)((int)puVar19 + uVar10);
            uVar6 = *puVar19 >> 8;
            sVar8 = (char)uVar9 * '\x06';
            fVar21 = (float)(uVar4 & 0xff);
            fVar24 = (float)(*puVar19 & 0xff);
            *(float *)((int)local_58 + (int)local_84) =
                 ((float)(uVar6 >> sVar8 & 0x3f) * 0.01587302 * (fVar21 - fVar24) + fVar24) *
                 *pfVar16 + pfVar16[1];
            if (uVar9 < 3) {
              fVar25 = (fVar21 - fVar24) * (float)(uVar6 >> (sVar8 + 6U & 0x1f) & 0x3f) * 0.01587302
              ;
              fVar21 = fVar24;
            }
            else {
              fVar25 = ((float)*(byte *)((int)puVar19 + uVar10 * 2) - fVar21) *
                       (float)(uVar4 >> 8 & 0x3f) * 0.01587302;
            }
            puVar19 = puVar19 + 1;
            pfVar17 = pfVar16 + 2;
            fVar21 = (fVar25 + fVar21) * *pfVar16 + pfVar16[1];
          }
          else {
            local_8c = local_8c + 1;
            fVar21 = (float)*(ushort *)(iVar18 + (uint)uVar3 * 2) * *(float *)(param_1 + 0x20) +
                     *(float *)(param_1 + 0x1c);
            *(float *)((int)local_58 + (int)local_84) = fVar21;
            pfVar17 = pfVar16;
          }
          *(float *)((int)local_58 + (int)local_84 + 0xc) = fVar21;
          local_84 = (uint *)((int)local_84 + 4);
          pfVar16 = pfVar17;
        } while ((int)local_84 < 0xc);
        uVar7 = FUN_006e6b90();
        uVar7 = FUN_006e6b90(uVar7);
        uVar7 = FUN_006e6b90(uVar7);
        if (local_8c == 3) {
          FUN_005b7d60(local_94,uVar7);
        }
        else {
          FUN_005b7d60(&local_30,uVar7);
          uVar7 = FUN_006e6b90();
          uVar7 = FUN_006e6b90(uVar7);
          uVar7 = FUN_006e6b90(uVar7);
          FUN_005b7d60(local_58 + 6,uVar7);
          fStack_1c = fStack_38 * fStack_28 + local_58[6] * local_30;
          fStack_14 = local_58[6] * local_30 + fStack_38 * fStack_28;
          fStack_18 = fStack_3c * fStack_2c + fStack_34 * fStack_24;
          local_20 = fStack_34 * fStack_24 + fStack_3c * fStack_2c + fStack_1c;
          if (local_20 < 0.0) {
            local_58[6] = 0.0 - local_58[6];
            fStack_3c = 0.0 - fStack_3c;
            fStack_38 = 0.0 - fStack_38;
            fStack_34 = 0.0 - fStack_34;
          }
          fVar21 = (local_58[6] - local_30) * fVar1 + local_30;
          fVar24 = (fStack_3c - fStack_2c) * fVar1 + fStack_2c;
          fVar25 = (fStack_38 - fStack_28) * fVar1 + fStack_28;
          fVar26 = (fStack_34 - fStack_24) * fVar1 + fStack_24;
          auVar22._0_4_ = fVar25 * fVar25 + fVar21 * fVar21;
          auVar22._4_4_ = fVar26 * fVar26 + fVar24 * fVar24;
          auVar22._8_4_ = fVar21 * fVar21 + fVar25 * fVar25;
          auVar22._12_4_ = fVar24 * fVar24 + fVar26 * fVar26;
          auVar23._4_4_ = auVar22._0_4_ + auVar22._4_4_;
          auVar23._0_4_ = auVar22._4_4_ + auVar22._0_4_;
          auVar23._8_4_ = auVar22._12_4_ + auVar22._8_4_;
          auVar23._12_4_ = auVar22._8_4_ + auVar22._12_4_;
          auVar23 = rsqrtps(auVar22,auVar23);
          *local_94 = auVar23._0_4_ * fVar21;
          local_94[1] = auVar23._4_4_ * fVar24;
          local_94[2] = auVar23._8_4_ * fVar25;
          local_94[3] = auVar23._12_4_ * fVar26;
        }
        fVar20 = (float10)0;
        local_94 = local_94 + 4;
        local_84 = puVar19;
      }
      else {
        local_9c = 3;
        pfVar16 = local_94;
        do {
          local_94 = pfVar16;
          uVar3 = *puVar15;
          puVar15 = puVar15 + 1;
          if (uVar3 == 6) {
            uVar6 = *puVar19 & 0xff;
            uVar12 = *(uint *)((int)puVar19 + uVar10) & 0xff;
            uVar4 = *puVar19 >> 8;
            sVar8 = (char)uVar9 * '\x06';
            fVar21 = (float)(uVar4 >> sVar8 & 0x3f) * 0.01587302;
            if (uVar9 < 3) {
              fVar24 = (float)uVar6;
              *local_94 = ((fVar21 + fVar1 * ((float)(uVar4 >> (sVar8 + 6U & 0x1f) & 0x3f) *
                                              0.01587302 - fVar21)) * ((float)uVar12 - fVar24) +
                          fVar24) * *pfVar17 + pfVar17[1];
            }
            else {
              fVar24 = (float)uVar12;
              fVar25 = (float)uVar6;
              fVar25 = fVar25 + fVar21 * (fVar24 - fVar25);
              *local_94 = (fVar25 + fVar1 * ((((float)*(byte *)((int)local_84 + uVar10 * 2) - fVar24
                                              ) * (float)(*(uint *)((int)puVar19 + uVar10) >> 8 &
                                                         0x3f) * 0.01587302 + fVar24) - fVar25)) *
                          *pfVar17 + pfVar17[1];
            }
            puVar19 = local_84 + 1;
            pfVar17 = pfVar17 + 2;
            local_84 = puVar19;
          }
          else {
            *local_94 = (float)*(ushort *)(iVar18 + (uint)uVar3 * 2) * *(float *)(param_1 + 0x20) +
                        *(float *)(param_1 + 0x1c);
          }
          local_9c = local_9c + -1;
          pfVar16 = local_94 + 1;
        } while (local_9c != 0);
        local_94 = local_94 + 2;
      }
      local_80 = local_80 + 1;
    } while ((int)local_80 < 3);
  }
  return 0;
}

