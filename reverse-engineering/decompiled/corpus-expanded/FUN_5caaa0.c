/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5caaa0; label: FUN_005caaa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x005cae52) */
/* WARNING: Removing unreachable block (ram,0x005cb207) */
/* WARNING: Removing unreachable block (ram,0x005cb102) */
/* WARNING: Removing unreachable block (ram,0x005cb147) */
/* WARNING: Removing unreachable block (ram,0x005cade8) */
/* WARNING: Removing unreachable block (ram,0x005cb179) */
/* WARNING: Removing unreachable block (ram,0x005cb125) */
/* WARNING: Removing unreachable block (ram,0x005cb1a9) */
/* WARNING: Removing unreachable block (ram,0x005cb1bf) */
/* WARNING: Removing unreachable block (ram,0x005cae68) */
/* WARNING: Removing unreachable block (ram,0x005cae93) */
/* WARNING: Removing unreachable block (ram,0x005caf0f) */
/* WARNING: Removing unreachable block (ram,0x005caed1) */

undefined4 FUN_005caaa0(int param_1,undefined4 param_2,int param_3,uint param_4,int param_5)

{
  float fVar1;
  byte bVar2;
  ushort uVar3;
  float *pfVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  sbyte sVar9;
  uint uVar10;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  float *pfVar14;
  int iVar15;
  uint *puVar16;
  float10 extraout_ST0;
  float10 fVar17;
  float10 extraout_ST1;
  float fVar18;
  float fVar21;
  float fVar22;
  float fVar23;
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  int local_84;
  uint local_78;
  float *local_70;
  ushort *local_6c;
  int local_58;
  float local_40 [4];
  float local_30 [4];
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  pbVar11 = *(byte **)(param_1 + 0x34);
  *(undefined1 *)(param_3 + 6) = 1;
  local_70 = *(float **)(param_3 + 8);
  uVar5 = FUN_006e6b90();
  uVar10 = (uint)*(ushort *)(param_1 + 8);
  pfVar14 = *(float **)(param_1 + 0x24);
  local_6c = *(ushort **)(param_1 + 0x2c);
  iVar15 = *(int *)(param_1 + 0x28) + -0x20;
  fVar1 = (float)(extraout_ST0 - (float10)(int)uVar5);
  puVar16 = (uint *)(((int)(uVar5 + ((int)uVar5 >> 0x1f & 3U)) >> 2) * uVar10 +
                    *(int *)(param_1 + 0x30));
  uVar5 = uVar5 & 3;
  local_78 = param_4;
  if ((int)(uint)*(ushort *)(param_1 + 4) < (int)param_4) {
    local_78 = (uint)*(ushort *)(param_1 + 4);
  }
  pbVar6 = pbVar11 + param_5;
  pbVar7 = (byte *)(*(int *)(param_3 + 0xc) + param_5);
  for (; pbVar11 < pbVar6; pbVar11 = pbVar11 + 1) {
    local_58 = 0;
    do {
      if (((&DAT_0076426c)[local_58] & *pbVar11) != 0) {
        if (*local_6c < 0x10) {
          puVar16 = (uint *)((int)puVar16 + (uint)(byte)(&DAT_00764270)[*local_6c]);
          pfVar14 = pfVar14 + 2;
        }
        if (local_6c[1] < 0x10) {
          puVar16 = (uint *)((int)puVar16 + (uint)(byte)(&DAT_00764270)[local_6c[1]]);
          pfVar14 = pfVar14 + 2;
        }
        if (local_6c[2] < 0x10) {
          puVar16 = (uint *)((int)puVar16 + (uint)(byte)(&DAT_00764270)[local_6c[2]]);
          pfVar14 = pfVar14 + 2;
        }
      }
      local_6c = local_6c + 3;
      local_70 = local_70 + 4;
      local_58 = local_58 + 1;
    } while (local_58 < 3);
  }
  pbVar6 = pbVar6 + local_78;
  fVar17 = extraout_ST1;
  do {
    if (pbVar6 <= pbVar11) {
      return 0;
    }
    bVar2 = *pbVar11;
    *pbVar7 = bVar2;
    pbVar7 = pbVar7 + 1;
    local_58 = 0;
    do {
      if (((&DAT_0076426c)[local_58] & bVar2) == 0) {
        if (local_58 == 0) {
          local_6c = local_6c + 3;
          local_70[2] = (float)fVar17;
          local_70[1] = (float)fVar17;
          *local_70 = (float)fVar17;
          local_70 = local_70 + 4;
        }
        else if (local_58 == 1) {
          local_6c = local_6c + 3;
          local_70[2] = (float)fVar17;
          local_70[1] = (float)fVar17;
          *local_70 = (float)fVar17;
          local_70[3] = 1.0;
          local_70 = local_70 + 4;
        }
        else {
          local_6c = local_6c + 3;
          local_70[2] = 1.0;
          local_70[1] = 1.0;
          *local_70 = 1.0;
          local_70 = local_70 + 4;
        }
      }
      else if (local_58 == 1) {
        local_78 = 0;
        do {
          uVar3 = *local_6c;
          local_6c = local_6c + 1;
          uVar12 = (uint)uVar3;
          if (uVar12 == 6) {
            uVar12 = *(uint *)((int)puVar16 + uVar10);
            uVar8 = *puVar16 >> 8;
            sVar9 = (char)uVar5 * '\x06';
            fVar18 = (float)(uVar12 & 0xff);
            fVar21 = (float)(*puVar16 & 0xff);
            *(float *)((int)local_30 + local_78) =
                 ((float)(uVar8 >> sVar9 & 0x3f) * 0.01587302 * (fVar18 - fVar21) + fVar21) *
                 *pfVar14 + pfVar14[1];
            if (uVar5 < 3) {
              fVar22 = (fVar18 - fVar21) * (float)(uVar8 >> (sVar9 + 6U & 0x1f) & 0x3f) * 0.01587302
              ;
              fVar18 = fVar21;
            }
            else {
              fVar22 = ((float)*(byte *)((int)puVar16 + uVar10 * 2) - fVar18) *
                       (float)(uVar12 >> 8 & 0x3f) * 0.01587302;
            }
            puVar16 = puVar16 + 1;
            *(float *)((int)local_40 + local_78) = (fVar22 + fVar18) * *pfVar14 + pfVar14[1];
LAB_005caf31:
            pfVar14 = pfVar14 + 2;
          }
          else {
            if (uVar12 == 7) {
              FUN_005ca5a0(puVar16,uVar5,uVar10,pfVar14,(int)local_30 + local_78,
                           (int)local_40 + local_78);
              puVar16 = puVar16 + 2;
              goto LAB_005caf31;
            }
            if (uVar12 == 9) {
              *(float *)((int)local_30 + local_78) =
                   (float)*(ushort *)((int)puVar16 + uVar5 * 2) * *pfVar14 + pfVar14[1];
              if (uVar5 < 3) {
                uVar3 = *(ushort *)((int)puVar16 + uVar5 * 2 + 2);
              }
              else {
                uVar3 = *(ushort *)((int)puVar16 + uVar10);
              }
              puVar16 = puVar16 + 2;
              *(float *)((int)local_40 + local_78) = (float)uVar3 * *pfVar14 + pfVar14[1];
              goto LAB_005caf31;
            }
            fVar18 = (float)*(ushort *)(iVar15 + uVar12 * 2) * *(float *)(param_1 + 0x20) +
                     *(float *)(param_1 + 0x1c);
            *(float *)((int)local_30 + local_78) = fVar18;
            *(float *)((int)local_40 + local_78) = fVar18;
          }
          local_78 = local_78 + 4;
        } while ((int)local_78 < 0xc);
        fVar17 = (float10)FUN_005c0240(1.0 - (local_30[2] * local_30[2] +
                                             local_30[0] * local_30[0] + local_30[1] * local_30[1]))
        ;
        local_30[3] = (float)fVar17;
        fVar17 = (float10)FUN_005c0240(1.0 - (local_40[2] * local_40[2] +
                                             local_40[0] * local_40[0] + local_40[1] * local_40[1]))
        ;
        local_40[3] = (float)fVar17;
        fVar17 = (float10)0;
        fStack_1c = local_40[2] * local_30[2] + local_40[0] * local_30[0];
        fStack_14 = local_40[0] * local_30[0] + local_40[2] * local_30[2];
        fStack_18 = local_40[1] * local_30[1] + local_40[3] * local_30[3];
        local_20 = local_40[3] * local_30[3] + local_40[1] * local_30[1] + fStack_1c;
        if ((float10)local_20 < fVar17) {
          local_40[0] = 0.0 - local_40[0];
          local_40[1] = 0.0 - local_40[1];
          local_40[2] = 0.0 - local_40[2];
          local_40[3] = 0.0 - local_40[3];
        }
        fVar18 = (local_40[0] - local_30[0]) * fVar1 + local_30[0];
        fVar21 = (local_40[1] - local_30[1]) * fVar1 + local_30[1];
        fVar22 = (local_40[2] - local_30[2]) * fVar1 + local_30[2];
        fVar23 = (local_40[3] - local_30[3]) * fVar1 + local_30[3];
        auVar19._0_4_ = fVar22 * fVar22 + fVar18 * fVar18;
        auVar19._4_4_ = fVar23 * fVar23 + fVar21 * fVar21;
        auVar19._8_4_ = fVar18 * fVar18 + fVar22 * fVar22;
        auVar19._12_4_ = fVar21 * fVar21 + fVar23 * fVar23;
        auVar20._4_4_ = auVar19._0_4_ + auVar19._4_4_;
        auVar20._0_4_ = auVar19._4_4_ + auVar19._0_4_;
        auVar20._8_4_ = auVar19._12_4_ + auVar19._8_4_;
        auVar20._12_4_ = auVar19._8_4_ + auVar19._12_4_;
        auVar20 = rsqrtps(auVar19,auVar20);
        *local_70 = auVar20._0_4_ * fVar18;
        local_70[1] = auVar20._4_4_ * fVar21;
        local_70[2] = auVar20._8_4_ * fVar22;
        local_70[3] = auVar20._12_4_ * fVar23;
        local_70 = local_70 + 4;
      }
      else {
        local_84 = 3;
        pfVar4 = local_70;
        do {
          local_70 = pfVar4;
          uVar3 = *local_6c;
          local_6c = local_6c + 1;
          if (uVar3 == 6) {
            uVar8 = *puVar16 & 0xff;
            uVar13 = *(uint *)((int)puVar16 + uVar10) & 0xff;
            uVar12 = *puVar16 >> 8;
            sVar9 = (char)uVar5 * '\x06';
            fVar18 = (float)(uVar12 >> sVar9 & 0x3f) * 0.01587302;
            if (uVar5 < 3) {
              fVar21 = (float)uVar8;
              *local_70 = ((fVar18 + fVar1 * ((float)(uVar12 >> (sVar9 + 6U & 0x1f) & 0x3f) *
                                              0.01587302 - fVar18)) * ((float)uVar13 - fVar21) +
                          fVar21) * *pfVar14 + pfVar14[1];
            }
            else {
              fVar21 = (float)uVar13;
              fVar22 = (float)uVar8;
              fVar22 = fVar22 + fVar18 * (fVar21 - fVar22);
              *local_70 = (fVar22 + fVar1 * ((((float)*(byte *)((int)puVar16 + uVar10 * 2) - fVar21)
                                              * (float)(*(uint *)((int)puVar16 + uVar10) >> 8 & 0x3f
                                                       ) * 0.01587302 + fVar21) - fVar22)) *
                          *pfVar14 + pfVar14[1];
            }
            puVar16 = puVar16 + 1;
            pfVar14 = pfVar14 + 2;
          }
          else {
            *local_70 = (float)*(ushort *)(iVar15 + (uint)uVar3 * 2) * *(float *)(param_1 + 0x20) +
                        *(float *)(param_1 + 0x1c);
          }
          local_84 = local_84 + -1;
          pfVar4 = local_70 + 1;
        } while (local_84 != 0);
        local_70 = local_70 + 2;
      }
      local_58 = local_58 + 1;
    } while (local_58 < 3);
    pbVar11 = pbVar11 + 1;
  } while( true );
}

