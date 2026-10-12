
/* WARNING: Removing unreachable block (ram,0x005cc457) */
/* WARNING: Removing unreachable block (ram,0x005cc441) */
/* WARNING: Removing unreachable block (ram,0x005cc3ad) */
/* WARNING: Removing unreachable block (ram,0x005cc49f) */
/* WARNING: Removing unreachable block (ram,0x005cc3cc) */
/* WARNING: Removing unreachable block (ram,0x005cc3ea) */
/* WARNING: Removing unreachable block (ram,0x005cc41c) */

undefined4 FUN_005cc0d0(int param_1,undefined4 param_2,int param_3,uint param_4,int param_5)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  sbyte sVar11;
  uint uVar12;
  ushort *puVar13;
  byte *pbVar14;
  uint uVar15;
  byte *pbVar16;
  byte *pbVar17;
  uint *puVar18;
  uint uVar19;
  float *pfVar20;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float *local_38;
  float *local_34;
  uint local_2c;
  int local_18;
  int local_14;
  
  if ((*(byte *)(param_1 + 0x13) & 1) == 0) {
    if (DAT_009737de == '\0') {
      *(undefined1 *)(param_3 + 6) = 0;
      pbVar17 = *(byte **)(param_1 + 0x34);
      pfVar20 = *(float **)(param_3 + 8);
      uVar8 = FUN_006e6b90();
      local_38 = *(float **)(param_1 + 0x24);
      iVar3 = *(int *)(param_1 + 0x28);
      uVar12 = (uint)*(ushort *)(param_1 + 8);
      puVar18 = (uint *)(((int)(uVar8 + ((int)uVar8 >> 0x1f & 3U)) >> 2) * uVar12 +
                        *(int *)(param_1 + 0x30));
      puVar13 = *(ushort **)(param_1 + 0x2c);
      local_2c = param_4;
      if ((int)(uint)*(ushort *)(param_1 + 4) < (int)param_4) {
        local_2c = (uint)*(ushort *)(param_1 + 4);
      }
      pbVar16 = (byte *)(*(int *)(param_3 + 0xc) + param_5);
      pbVar14 = pbVar17 + param_5;
      for (; pbVar17 < pbVar14; pbVar17 = pbVar17 + 1) {
        iVar9 = 0;
        do {
          if (((&DAT_0076426c)[iVar9] & *pbVar17) != 0) {
            if (*puVar13 < 0x10) {
              puVar18 = puVar18 + 1;
              local_38 = local_38 + 2;
            }
            if (puVar13[1] < 0x10) {
              puVar18 = puVar18 + 1;
              local_38 = local_38 + 2;
            }
            if (puVar13[2] < 0x10) {
              puVar18 = puVar18 + 1;
              local_38 = local_38 + 2;
            }
          }
          pfVar20 = pfVar20 + 4;
          puVar13 = puVar13 + 3;
          iVar9 = iVar9 + 1;
        } while (iVar9 < 3);
      }
      for (; pbVar17 < pbVar14 + local_2c; pbVar17 = pbVar17 + 1) {
        bVar1 = *pbVar17;
        *pbVar16 = bVar1;
        pbVar16 = pbVar16 + 1;
        local_14 = 0;
        local_34 = pfVar20;
        do {
          if (((&DAT_0076426c)[local_14] & bVar1) == 0) {
            if (local_14 == 2) {
              pfVar20 = local_34 + 4;
              local_34[2] = 1.0;
              puVar13 = puVar13 + 3;
              local_34[1] = 1.0;
              *local_34 = 1.0;
            }
            else {
              pfVar20 = local_34 + 4;
              local_34[2] = (float)extraout_ST1;
              puVar13 = puVar13 + 3;
              local_34[1] = (float)extraout_ST1;
              *local_34 = (float)extraout_ST1;
            }
          }
          else {
            local_18 = 3;
            pfVar20 = local_34;
            do {
              local_34 = pfVar20;
              uVar2 = *puVar13;
              puVar13 = puVar13 + 1;
              if (uVar2 == 6) {
                uVar19 = *puVar18 & 0xff;
                uVar15 = *puVar18 >> 8;
                sVar11 = (char)(uVar8 & 3) * '\x06';
                uVar10 = *(uint *)((int)puVar18 + uVar12) & 0xff;
                fVar5 = (float)(uVar15 >> sVar11 & 0x3f) * 0.01587302;
                if ((uVar8 & 3) < 3) {
                  fVar4 = (float)uVar19;
                  fVar4 = (fVar5 + (float)(extraout_ST0 - (float10)(int)uVar8) *
                                   ((float)(uVar15 >> (sVar11 + 6U & 0x1f) & 0x3f) * 0.01587302 -
                                   fVar5)) * ((float)uVar10 - fVar4) + fVar4;
                }
                else {
                  fVar6 = (float)uVar10;
                  fVar4 = (float)uVar19;
                  fVar4 = fVar4 + fVar5 * (fVar6 - fVar4);
                  fVar4 = fVar4 + (float)(extraout_ST0 - (float10)(int)uVar8) *
                                  ((((float)*(byte *)((int)puVar18 + uVar12 * 2) - fVar6) *
                                    (float)(*(uint *)((int)puVar18 + uVar12) >> 8 & 0x3f) *
                                    0.01587302 + fVar6) - fVar4);
                }
                fVar5 = fVar4 * *local_38 + local_38[1];
                puVar18 = puVar18 + 1;
                local_38 = local_38 + 2;
              }
              else {
                fVar5 = (float)*(ushort *)(iVar3 + -0x20 + (uint)uVar2 * 2) *
                        *(float *)(param_1 + 0x20) + *(float *)(param_1 + 0x1c);
              }
              *local_34 = fVar5;
              local_18 = local_18 + -1;
              pfVar20 = local_34 + 1;
            } while (local_18 != 0);
            pfVar20 = local_34 + 2;
          }
          local_14 = local_14 + 1;
          local_34 = pfVar20;
        } while (local_14 < 3);
      }
      return 0;
    }
    uVar7 = FUN_005cb980(param_1,param_2,param_3,param_4,param_5);
    return uVar7;
  }
  if ((*(byte *)(param_1 + 0x13) & 2) == 0) {
    uVar7 = FUN_005caaa0(param_1,param_2,param_3,param_4,param_5);
    return uVar7;
  }
  uVar7 = FUN_005cb270();
  return uVar7;
}

