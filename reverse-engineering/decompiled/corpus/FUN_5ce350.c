/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5ce350; label: FUN_005ce350
 */

/* WARNING: Removing unreachable block (ram,0x005ce5a4) */
/* WARNING: Removing unreachable block (ram,0x005ce668) */
/* WARNING: Removing unreachable block (ram,0x005ce652) */
/* WARNING: Removing unreachable block (ram,0x005ce5c5) */
/* WARNING: Removing unreachable block (ram,0x005ce5e3) */
/* WARNING: Removing unreachable block (ram,0x005ce6b0) */
/* WARNING: Removing unreachable block (ram,0x005ce617) */

void FUN_005ce350(int param_1,undefined4 param_2,float *param_3,float param_4,char *param_5)

{
  uint *puVar1;
  byte *pbVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float10 fVar9;
  uint uVar10;
  uint uVar11;
  sbyte sVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint *puVar18;
  float *pfVar19;
  float *pfVar20;
  float10 extraout_ST0;
  float10 fVar21;
  float10 extraout_ST1;
  ushort *local_2c;
  int local_20;
  
  uVar17 = (uint)*(ushort *)(param_1 + 0xc);
  uVar10 = FUN_006e6b90();
  uVar13 = (uint)*(ushort *)(param_1 + 8);
  local_2c = *(ushort **)(param_1 + 0x2c);
  param_2 = local_2c + *(ushort *)(param_1 + 4) * uVar17;
  iVar5 = *(int *)(param_1 + 0x28);
  bVar3 = *(byte *)(param_1 + 0x11);
  pfVar19 = *(float **)(param_1 + 0x24);
  puVar18 = (uint *)(((int)(uVar10 + ((int)uVar10 >> 0x1f & 3U)) >> 2) * uVar13 +
                    *(int *)(param_1 + 0x30));
  uVar16 = uVar10 & 3;
  if (0 < (int)param_4) {
    local_20 = (int)param_4;
    do {
      if (uVar17 != 0) {
        param_2 = (ushort *)((int)param_2 + uVar17);
        param_4 = (float)uVar17;
        do {
          uVar4 = *local_2c;
          local_2c = local_2c + 1;
          if (uVar4 < 0x10) {
            puVar18 = (uint *)((int)puVar18 + (uint)(byte)(&DAT_00764270)[uVar4]);
            pfVar19 = pfVar19 + 2;
          }
          param_4 = (float)((int)param_4 - 1);
        } while (param_4 != 0.0);
      }
      local_20 = local_20 + -1;
    } while (local_20 != 0);
  }
  local_20 = 0;
  fVar21 = extraout_ST1;
  if (uVar17 != 0) {
    do {
      uVar4 = *local_2c;
      local_2c = local_2c + 1;
      pfVar20 = pfVar19;
      if (param_5 == (char *)0x0) {
LAB_005ce53f:
        fVar9 = extraout_ST0 - (float10)(int)uVar10;
        if ((*param_2 & 1) != 0) {
          fVar9 = fVar21;
        }
        param_4 = (float)fVar9;
        switch((uint)uVar4) {
        case 6:
          puVar1 = (uint *)((int)puVar18 + uVar13);
          uVar14 = *puVar18 & 0xff;
          uVar15 = *puVar1 & 0xff;
          uVar11 = *puVar18 >> 8;
          sVar12 = (char)uVar16 * '\x06';
          fVar6 = (float)(uVar11 >> sVar12 & 0x3f) * 0.01587302;
          if (uVar16 < 3) {
            fVar7 = (float)uVar14;
            puVar18 = puVar18 + 1;
            pfVar20 = pfVar19 + 2;
            *param_3 = ((fVar6 + param_4 * ((float)(uVar11 >> (sVar12 + 6U & 0x1f) & 0x3f) *
                                            0.01587302 - fVar6)) * ((float)uVar15 - fVar7) + fVar7)
                       * *pfVar19 + pfVar19[1];
          }
          else {
            fVar7 = (float)uVar15;
            fVar8 = (float)uVar14;
            pbVar2 = (byte *)((int)puVar18 + uVar13 * 2);
            fVar8 = fVar8 + fVar6 * (fVar7 - fVar8);
            puVar18 = puVar18 + 1;
            pfVar20 = pfVar19 + 2;
            *param_3 = (fVar8 + param_4 * ((((float)*pbVar2 - fVar7) *
                                            (float)(*puVar1 >> 8 & 0x3f) * 0.01587302 + fVar7) -
                                          fVar8)) * *pfVar19 + pfVar19[1];
          }
          break;
        case 7:
          fVar21 = (float10)FUN_005ca830(puVar18,uVar16,uVar13,param_4,pfVar19);
          *param_3 = (float)fVar21;
          fVar21 = (float10)0;
          puVar18 = puVar18 + 2;
          pfVar20 = pfVar19 + 2;
          break;
        case 8:
          pbVar2 = (byte *)((int)puVar18 + uVar16);
          puVar18 = puVar18 + 1;
          *param_3 = (float)(int)*(short *)(iVar5 + (uint)*pbVar2 * 2);
          break;
        default:
          *param_3 = (float)*(ushort *)(iVar5 + -0x20 + (uint)bVar3 * 2 + (uint)uVar4 * 2) *
                     *(float *)(param_1 + 0x20) + *(float *)(param_1 + 0x1c);
          break;
        case 10:
          *param_3 = (float)((int)*(short *)(iVar5 + 2 + (uint)*(byte *)((int)puVar18 + uVar16) * 2)
                            | (int)*(short *)(iVar5 + (uint)*(byte *)((int)puVar18 + uVar16) * 2) <<
                              0x10);
          puVar18 = puVar18 + 1;
        }
      }
      else {
        if (local_20 == *param_5) {
          param_5 = param_5 + 1;
          goto LAB_005ce53f;
        }
        switch(uVar4) {
        case 6:
          puVar18 = puVar18 + 1;
          pfVar20 = pfVar19 + 2;
          break;
        case 7:
          puVar18 = puVar18 + 2;
          pfVar20 = pfVar19 + 2;
          break;
        case 8:
        case 10:
          puVar18 = puVar18 + 1;
        }
      }
      param_3 = param_3 + 1;
      param_2 = (ushort *)((int)param_2 + 1);
      local_20 = local_20 + 1;
      pfVar19 = pfVar20;
    } while (local_20 < (int)uVar17);
  }
  return;
}

