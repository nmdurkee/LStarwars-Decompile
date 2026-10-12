/* Ghidra analysis pseudocode, not original source.
 * ev_58a5325186d3cd5df394779674731c2ac26ad2d4ec877fc6396ce44c5c65b6b5
 * Entry: 0x5cb270; label: FUN_005cb270
 */

/* WARNING: Removing unreachable block (ram,0x005cb627) */
/* WARNING: Removing unreachable block (ram,0x005cb920) */
/* WARNING: Removing unreachable block (ram,0x005cb81b) */
/* WARNING: Removing unreachable block (ram,0x005cb860) */
/* WARNING: Removing unreachable block (ram,0x005cb5b3) */
/* WARNING: Removing unreachable block (ram,0x005cb892) */
/* WARNING: Removing unreachable block (ram,0x005cb83e) */
/* WARNING: Removing unreachable block (ram,0x005cb8c2) */
/* WARNING: Removing unreachable block (ram,0x005cb8d8) */
/* WARNING: Removing unreachable block (ram,0x005cb63d) */
/* WARNING: Removing unreachable block (ram,0x005cb668) */
/* WARNING: Removing unreachable block (ram,0x005cb6e4) */
/* WARNING: Removing unreachable block (ram,0x005cb6a6) */

undefined4 FUN_005cb270(int param_1,undefined4 param_2,int param_3,uint param_4,int param_5)

{
  float fVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  sbyte sVar8;
  uint uVar9;
  byte *pbVar10;
  uint uVar11;
  float *pfVar12;
  uint uVar13;
  float *pfVar14;
  int iVar15;
  uint *puVar16;
  float10 extraout_ST0;
  float10 fVar17;
  float10 extraout_ST1;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  float fVar24;
  int local_74;
  float *local_68;
  int local_64;
  ushort *local_60;
  uint local_54;
  int local_4c;
  float local_30 [4];
  float local_20 [7];
  
  pbVar10 = *(byte **)(param_1 + 0x34);
  *(undefined1 *)(param_3 + 6) = 1;
  pfVar12 = *(float **)(param_3 + 8);
  uVar4 = FUN_006e6b90();
  uVar9 = (uint)*(ushort *)(param_1 + 8);
  pfVar14 = *(float **)(param_1 + 0x24);
  local_60 = *(ushort **)(param_1 + 0x2c);
  iVar15 = *(int *)(param_1 + 0x28) + -0x20;
  fVar1 = (float)(extraout_ST0 - (float10)(int)uVar4);
  puVar16 = (uint *)(((int)(uVar4 + ((int)uVar4 >> 0x1f & 3U)) >> 2) * uVar9 +
                    *(int *)(param_1 + 0x30));
  uVar4 = uVar4 & 3;
  local_54 = param_4;
  if ((int)(uint)*(ushort *)(param_1 + 4) < (int)param_4) {
    local_54 = (uint)*(ushort *)(param_1 + 4);
  }
  pbVar5 = pbVar10 + param_5;
  pbVar6 = (byte *)(*(int *)(param_3 + 0xc) + param_5);
  for (; pbVar10 < pbVar5; pbVar10 = pbVar10 + 1) {
    local_4c = 0;
    do {
      local_68 = (float *)0x3;
      if (local_4c == 1) {
        local_68 = (float *)0x4;
      }
      if (((&DAT_0076426c)[local_4c] & *pbVar10) == 0) {
        local_60 = local_60 + (int)local_68;
      }
      else if (local_68 != (float *)0x0) {
        local_64 = (int)local_68;
        do {
          uVar3 = *local_60;
          local_60 = local_60 + 1;
          if (uVar3 < 0x10) {
            puVar16 = (uint *)((int)puVar16 + (uint)(byte)(&DAT_00764270)[uVar3]);
            pfVar14 = pfVar14 + 2;
          }
          local_64 = local_64 + -1;
        } while (local_64 != 0);
      }
      local_4c = local_4c + 1;
      pfVar12 = pfVar12 + 4;
    } while (local_4c < 3);
  }
  pbVar5 = pbVar5 + local_54;
  fVar24 = fVar1;
  fVar17 = extraout_ST1;
  local_68 = pfVar12;
  do {
    if (pbVar5 <= pbVar10) {
      return 0;
    }
    bVar2 = *pbVar10;
    *pbVar6 = bVar2;
    pbVar6 = pbVar6 + 1;
    local_4c = 0;
    do {
      if (((&DAT_0076426c)[local_4c] & bVar2) == 0) {
        if (local_4c == 0) {
          local_60 = local_60 + 3;
          local_68[2] = (float)fVar17;
          local_68[1] = (float)fVar17;
          *local_68 = (float)fVar17;
          local_68 = local_68 + 4;
        }
        else if (local_4c == 1) {
          local_60 = local_60 + 4;
          local_68[2] = (float)fVar17;
          local_68[1] = (float)fVar17;
          *local_68 = (float)fVar17;
          local_68[3] = 1.0;
          local_68 = local_68 + 4;
        }
        else {
          local_60 = local_60 + 3;
          local_68[2] = 1.0;
          local_68[1] = 1.0;
          *local_68 = 1.0;
          local_68 = local_68 + 4;
        }
      }
      else if (local_4c == 1) {
        local_54 = 0;
        do {
          uVar3 = *local_60;
          local_60 = local_60 + 1;
          uVar11 = (uint)uVar3;
          if (uVar11 == 6) {
            uVar11 = *(uint *)((int)puVar16 + uVar9);
            uVar7 = *puVar16 >> 8;
            sVar8 = (char)uVar4 * '\x06';
            fVar18 = (float)(uVar11 & 0xff);
            fVar19 = (float)(*puVar16 & 0xff);
            *(float *)((int)local_20 + local_54) =
                 ((float)(uVar7 >> sVar8 & 0x3f) * 0.01587302 * (fVar18 - fVar19) + fVar19) *
                 *pfVar14 + pfVar14[1];
            if (uVar4 < 3) {
              fVar20 = (fVar18 - fVar19) * (float)(uVar7 >> (sVar8 + 6U & 0x1f) & 0x3f) * 0.01587302
              ;
              fVar18 = fVar19;
            }
            else {
              fVar20 = ((float)*(byte *)((int)puVar16 + uVar9 * 2) - fVar18) *
                       (float)(uVar11 >> 8 & 0x3f) * 0.01587302;
            }
            puVar16 = puVar16 + 1;
            *(float *)((int)local_30 + local_54) = (fVar20 + fVar18) * *pfVar14 + pfVar14[1];
LAB_005cb706:
            pfVar14 = pfVar14 + 2;
          }
          else {
            if (uVar11 == 7) {
              FUN_005ca5a0(puVar16,uVar4,uVar9,pfVar14,(int)local_20 + local_54,
                           (int)local_30 + local_54);
              fVar17 = (float10)0;
              puVar16 = puVar16 + 2;
              goto LAB_005cb706;
            }
            if (uVar11 == 9) {
              *(float *)((int)local_20 + local_54) =
                   (float)*(ushort *)((int)puVar16 + uVar4 * 2) * *pfVar14 + pfVar14[1];
              if (uVar4 < 3) {
                uVar3 = *(ushort *)((int)puVar16 + uVar4 * 2 + 2);
              }
              else {
                uVar3 = *(ushort *)((int)puVar16 + uVar9);
              }
              puVar16 = puVar16 + 2;
              *(float *)((int)local_30 + local_54) = (float)uVar3 * *pfVar14 + pfVar14[1];
              goto LAB_005cb706;
            }
            fVar18 = (float)*(ushort *)(iVar15 + uVar11 * 2) * *(float *)(param_1 + 0x20) +
                     *(float *)(param_1 + 0x1c);
            *(float *)((int)local_20 + local_54) = fVar18;
            *(float *)((int)local_30 + local_54) = fVar18;
          }
          local_54 = local_54 + 4;
        } while ((int)local_54 < 0x10);
        fVar18 = (local_30[0] - local_20[0]) * fVar24 + local_20[0];
        fVar19 = (local_30[1] - local_20[1]) * fVar24 + local_20[1];
        fVar20 = (local_30[2] - local_20[2]) * fVar24 + local_20[2];
        fVar21 = (local_30[3] - local_20[3]) * fVar24 + local_20[3];
        auVar22._0_4_ = fVar20 * fVar20 + fVar18 * fVar18;
        auVar22._4_4_ = fVar21 * fVar21 + fVar19 * fVar19;
        auVar22._8_4_ = fVar18 * fVar18 + fVar20 * fVar20;
        auVar22._12_4_ = fVar19 * fVar19 + fVar21 * fVar21;
        auVar23._4_4_ = auVar22._0_4_ + auVar22._4_4_;
        auVar23._0_4_ = auVar22._4_4_ + auVar22._0_4_;
        auVar23._8_4_ = auVar22._12_4_ + auVar22._8_4_;
        auVar23._12_4_ = auVar22._8_4_ + auVar22._12_4_;
        auVar23 = rsqrtps(auVar22,auVar23);
        *local_68 = auVar23._0_4_ * fVar18;
        local_68[1] = auVar23._4_4_ * fVar19;
        local_68[2] = auVar23._8_4_ * fVar20;
        local_68[3] = auVar23._12_4_ * fVar21;
        local_68 = local_68 + 4;
      }
      else {
        local_74 = 3;
        pfVar12 = local_68;
        do {
          local_68 = pfVar12;
          uVar3 = *local_60;
          local_60 = local_60 + 1;
          if (uVar3 == 6) {
            uVar7 = *puVar16 & 0xff;
            uVar13 = *(uint *)((int)puVar16 + uVar9) & 0xff;
            uVar11 = *puVar16 >> 8;
            sVar8 = (char)uVar4 * '\x06';
            fVar18 = (float)(uVar11 >> sVar8 & 0x3f) * 0.01587302;
            if (uVar4 < 3) {
              fVar19 = (float)uVar7;
              *local_68 = ((fVar18 + fVar1 * ((float)(uVar11 >> (sVar8 + 6U & 0x1f) & 0x3f) *
                                              0.01587302 - fVar18)) * ((float)uVar13 - fVar19) +
                          fVar19) * *pfVar14 + pfVar14[1];
            }
            else {
              fVar19 = (float)uVar13;
              fVar20 = (float)uVar7;
              fVar20 = fVar20 + fVar18 * (fVar19 - fVar20);
              *local_68 = (fVar20 + fVar1 * ((((float)*(byte *)((int)puVar16 + uVar9 * 2) - fVar19)
                                              * (float)(*(uint *)((int)puVar16 + uVar9) >> 8 & 0x3f)
                                                * 0.01587302 + fVar19) - fVar20)) * *pfVar14 +
                          pfVar14[1];
            }
            puVar16 = puVar16 + 1;
            pfVar14 = pfVar14 + 2;
          }
          else {
            *local_68 = (float)*(ushort *)(iVar15 + (uint)uVar3 * 2) * *(float *)(param_1 + 0x20) +
                        *(float *)(param_1 + 0x1c);
          }
          local_74 = local_74 + -1;
          pfVar12 = local_68 + 1;
        } while (local_74 != 0);
        local_68 = local_68 + 2;
      }
      local_4c = local_4c + 1;
    } while (local_4c < 3);
    pbVar10 = pbVar10 + 1;
  } while( true );
}

