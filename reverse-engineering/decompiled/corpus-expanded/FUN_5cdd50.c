/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5cdd50; label: FUN_005cdd50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x005ce198) */
/* WARNING: Removing unreachable block (ram,0x005ce182) */
/* WARNING: Removing unreachable block (ram,0x005ce0ee) */
/* WARNING: Removing unreachable block (ram,0x005ce1e1) */
/* WARNING: Removing unreachable block (ram,0x005ce10d) */
/* WARNING: Removing unreachable block (ram,0x005ce12b) */
/* WARNING: Removing unreachable block (ram,0x005ce15d) */

undefined4
FUN_005cdd50(int param_1,float param_2,int param_3,float param_4,uint param_5,int param_6,
            float *param_7)

{
  byte *pbVar1;
  float fVar2;
  byte bVar3;
  ushort uVar4;
  float fVar5;
  float fVar6;
  float10 fVar7;
  float10 fVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  sbyte sVar13;
  uint uVar14;
  byte *pbVar15;
  int iVar16;
  uint *puVar17;
  uint uVar18;
  float *pfVar19;
  uint uVar20;
  float *pfVar21;
  float10 fVar22;
  float10 fVar23;
  float10 extraout_ST0;
  float10 fVar24;
  float10 fVar25;
  float10 fVar26;
  float10 fVar27;
  float10 fVar28;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  ushort *local_38;
  byte *local_34;
  float *local_30;
  float *local_28;
  uint local_18;
  int local_10;
  int local_c;
  
  fVar2 = 1.0 - param_4;
  if ((*(byte *)(param_1 + 0x13) & 1) != 0) {
    if ((*(byte *)(param_1 + 0x13) & 2) != 0) {
      uVar9 = FUN_005ccd60(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      return uVar9;
    }
    uVar9 = FUN_005cc550(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    return uVar9;
  }
  if (*(char *)(param_3 + 6) != '\0') {
    uVar9 = FUN_005cd500(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    return uVar9;
  }
  iVar10 = *(ushort *)(param_1 + 6) - 1;
  local_34 = *(byte **)(param_1 + 0x34);
  fVar22 = (float10)(((float)iVar10 * (param_2 - (float)*(ushort *)(param_1 + 0xe))) /
                    (float)(int)(*(ushort *)(param_1 + 10) - 1));
  if (fVar22 < (float10)0) {
    fVar22 = (float10)(float)(float10)0;
  }
  fVar23 = (float10)*(ushort *)(param_1 + 6);
  if (fVar23 < fVar22 != (fVar23 == fVar22)) {
    fVar22 = (float10)iVar10;
  }
  local_30 = *(float **)(param_3 + 8);
  uVar11 = FUN_006e6b90();
  local_38 = *(ushort **)(param_1 + 0x2c);
  local_28 = *(float **)(param_1 + 0x24);
  uVar14 = (uint)*(ushort *)(param_1 + 8);
  iVar10 = *(int *)(param_1 + 0x28);
  puVar17 = (uint *)(((int)(uVar11 + ((int)uVar11 >> 0x1f & 3U)) >> 2) * uVar14 +
                    *(int *)(param_1 + 0x30));
  param_4 = (float)param_5;
  if ((int)(uint)*(ushort *)(param_1 + 4) < (int)param_5) {
    param_4 = (float)(uint)*(ushort *)(param_1 + 4);
  }
  pbVar1 = local_34 + param_6;
  pbVar15 = (byte *)(*(int *)(param_3 + 0xc) + param_6);
  if (param_6 != 0) {
    param_7 = (float *)0x0;
  }
  for (; local_34 < pbVar1; local_34 = local_34 + 1) {
    iVar16 = 0;
    do {
      if (((&DAT_0076426c)[iVar16] & *local_34) != 0) {
        if (*local_38 < 0x10) {
          puVar17 = (uint *)((int)puVar17 + (uint)(byte)(&DAT_00764270)[*local_38]);
          local_28 = local_28 + 2;
        }
        if (local_38[1] < 0x10) {
          puVar17 = (uint *)((int)puVar17 + (uint)(byte)(&DAT_00764270)[local_38[1]]);
          local_28 = local_28 + 2;
        }
        if (local_38[2] < 0x10) {
          puVar17 = (uint *)((int)puVar17 + (uint)(byte)(&DAT_00764270)[local_38[2]]);
          local_28 = local_28 + 2;
        }
      }
      local_38 = local_38 + 3;
      local_30 = local_30 + 4;
      iVar16 = iVar16 + 1;
    } while (iVar16 < 3);
  }
  if (local_34 < pbVar1 + (int)param_4) {
    fVar24 = (float10)fVar2;
    fVar25 = (float10)(float)(extraout_ST1 - (float10)(int)uVar11);
    fVar26 = (float10)0.015873020514845848;
    pfVar21 = param_7;
    fVar23 = extraout_ST0;
    do {
      bVar3 = *local_34;
      *pbVar15 = *pbVar15 | bVar3;
      pbVar15 = pbVar15 + 1;
      local_c = 0;
      do {
        if (((&DAT_0076426c)[local_c] & bVar3) == 0) {
          if (local_c == 2) {
            pfVar19 = local_30 + 4;
            local_38 = local_38 + 3;
            *local_30 = (float)((float10)*local_30 * fVar24 + fVar22);
            local_30[1] = (float)(fVar24 * (float10)local_30[1] + fVar22);
            local_30[2] = (float)((float10)local_30[2] * fVar24 + fVar22);
          }
          else {
            *local_30 = (float)((float10)*local_30 * fVar24);
            local_30[1] = (float)(fVar24 * (float10)local_30[1]);
            local_30[2] = (float)((float10)local_30[2] * fVar24);
            if (pfVar21 != (float *)0x0) {
              param_7 = (float *)0x0;
              pfVar21[2] = (float)fVar23;
              pfVar21[1] = (float)fVar23;
              *pfVar21 = (float)fVar23;
              pfVar21 = (float *)0x0;
            }
            pfVar19 = local_30 + 4;
            local_38 = local_38 + 3;
          }
        }
        else {
          local_10 = 0;
          pfVar21 = local_30;
          do {
            local_30 = pfVar21;
            pfVar21 = param_7;
            uVar4 = *local_38;
            local_38 = local_38 + 1;
            if (uVar4 == 6) {
              uVar18 = *puVar17 & 0xff;
              uVar12 = *puVar17 >> 8;
              sVar13 = (char)(uVar11 & 3) * '\x06';
              uVar20 = *(uint *)(uVar14 + (int)puVar17) & 0xff;
              fVar2 = (float)((float10)(uVar12 >> sVar13 & 0x3f) * fVar26);
              if ((uVar11 & 3) < 3) {
                fVar27 = (float10)fVar2;
                fVar23 = (float10)uVar18;
                fVar23 = (float10)(float)(fVar27 + fVar25 * ((float10)(float)((float10)(uVar12 >> (
                                                  sVar13 + 6U & 0x1f) & 0x3f) * fVar26) - fVar27)) *
                         ((float10)uVar20 - fVar23) + fVar23;
              }
              else {
                fVar5 = (float)uVar20;
                fVar6 = (float)uVar18;
                fVar23 = (float10)(fVar6 + fVar2 * (fVar5 - fVar6));
                fVar23 = fVar23 + fVar25 * ((float10)(((float)*(byte *)((int)puVar17 + uVar14 * 2) -
                                                      fVar5) * (float)((float10)(*(uint *)(uVar14 + 
                                                  (int)puVar17) >> 8 & 0x3f) * fVar26) + fVar5) -
                                           fVar23);
              }
              fVar23 = fVar23 * (float10)*local_28 + (float10)local_28[1];
              puVar17 = puVar17 + 1;
              local_28 = local_28 + 2;
            }
            else {
              fVar23 = (float10)*(ushort *)(iVar10 + -0x20 + (uint)uVar4 * 2) *
                       (float10)*(float *)(param_1 + 0x20) + (float10)*(float *)(param_1 + 0x1c);
            }
            fVar23 = (float10)(float)fVar23;
            fVar28 = (float10)(float)(fVar23 - (float10)*local_30);
            fVar27 = fVar25;
            fVar7 = fVar24;
            fVar8 = fVar26;
            if ((local_c == 1) &&
               (((float10)3.1415927410125732 < fVar28 || (fVar28 < (float10)-3.1415927410125732))))
            {
              local_18 = FUN_006e6b90();
              local_18 = local_18 & 0xffff;
              if (0x7fff < local_18) {
                local_18 = local_18 - 0x10000;
              }
              fVar28 = (float10)((float)(int)local_18 * 9.58738e-05);
              fVar23 = extraout_ST0_00;
              fVar27 = extraout_ST1_00;
              fVar7 = fVar25;
              fVar8 = fVar24;
              fVar22 = fVar26;
            }
            fVar26 = fVar8;
            fVar24 = fVar7;
            fVar25 = fVar27;
            if (param_7 != (float *)0x0) {
              if (local_10 == 0) {
                *param_7 = (float)fVar23;
              }
              else if (local_10 == 1) {
                param_7[1] = (float)fVar23;
              }
              else {
                param_7 = (float *)0x0;
                pfVar21[2] = (float)-fVar23;
              }
            }
            local_10 = local_10 + 1;
            *local_30 = (float)(fVar28 * fVar22 + (float10)*local_30);
            pfVar21 = local_30 + 1;
          } while (local_10 < 3);
          fVar23 = (float10)0;
          pfVar19 = local_30 + 2;
          pfVar21 = param_7;
        }
        local_c = local_c + 1;
        local_30 = pfVar19;
      } while (local_c < 3);
      local_34 = local_34 + 1;
    } while (local_34 < pbVar1 + (int)param_4);
    return 0;
  }
  return 0;
}

