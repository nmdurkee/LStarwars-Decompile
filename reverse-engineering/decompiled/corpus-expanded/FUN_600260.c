/* Ghidra pseudocode, not original source.
 * ev_64f3679a1f1e131a29792e896f5cd05cb4870e5bb22e267d9bfafa2e72f365ab
 * Entry: 0x600260; label: FUN_00600260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x0060037b) */
/* WARNING: Removing unreachable block (ram,0x006002ea) */
/* WARNING: Removing unreachable block (ram,0x00600337) */
/* WARNING: Removing unreachable block (ram,0x006003c0) */

void FUN_00600260(int param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  float *pfVar10;
  int iVar11;
  float10 fVar12;
  float10 extraout_ST0;
  float10 fVar13;
  float10 extraout_ST0_00;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar18;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  int local_14;
  uint local_8;
  
  iVar11 = 0;
  if (*(int *)(param_1 + 0x2a8) == 0) {
    if (DAT_008108fc <= DAT_02924b44) {
      FUN_005f74a0();
      return;
    }
    *(undefined4 *)(param_1 + 0x2a8) = *(undefined4 *)(DAT_02962090 + DAT_02924b44 * 4);
    DAT_02924b44 = DAT_02924b44 + 1;
  }
  iVar9 = *(int *)(param_1 + 0x2a8);
  *(undefined4 *)(iVar9 + 0x10) = *(undefined4 *)(param_1 + 0xa0);
  local_8 = (uint)(longlong)ROUND(*(float *)(param_1 + 0x298));
  *(float *)(iVar9 + 0x28) = (float)(local_8 & 0x1ff) * 0.003921569;
  local_8 = (uint)(longlong)ROUND(*(float *)(param_1 + 0x29c));
  *(float *)(iVar9 + 0x2c) = (float)(local_8 & 0x1ff) * 0.003921569;
  local_8 = (uint)(longlong)ROUND(*(float *)(param_1 + 0x2a0));
  *(float *)(iVar9 + 0x30) = (float)(local_8 & 0x1ff) * 0.003921569;
  local_8 = (uint)(longlong)ROUND(*(float *)(param_1 + 0x2a4));
  local_14 = 0;
  *(float *)(iVar9 + 0x34) = (float)(local_8 & 0x1ff) * 0.003921569;
  fVar17 = (float10)0;
  do {
    iVar9 = 0;
    pfVar10 = (float *)(param_1 + 0x158);
    local_1c = (float)fVar17;
    local_20 = (float)fVar17;
    fVar2 = (float)local_14 * 0.015625;
    do {
      if ((pfVar10[-2] < fVar2 != (pfVar10[-2] == fVar2)) && (fVar2 <= *pfVar10)) {
        fVar16 = (float10)(fVar2 - *(float *)(param_1 + 0x150 + iVar9 * 8));
        if (fVar16 == fVar17) {
          fVar16 = (float10)*(float *)(param_1 + 0x154 + iVar9 * 8);
        }
        else {
          pfVar10 = (float *)(param_1 + 0x154 + iVar9 * 8);
          fVar16 = ((float10)*(float *)(param_1 + 0x15c + iVar9 * 8) - (float10)*pfVar10) *
                   (fVar16 / (float10)(*(float *)(param_1 + 0x158 + iVar9 * 8) -
                                      *(float *)(param_1 + 0x150 + iVar9 * 8))) + (float10)*pfVar10;
        }
        break;
      }
      iVar9 = iVar9 + 1;
      pfVar10 = pfVar10 + 2;
      fVar16 = fVar17;
    } while (iVar9 < 7);
    local_28 = (float)fVar16;
    iVar9 = 0;
    pfVar10 = (float *)(param_1 + 0x198);
    do {
      if ((pfVar10[-2] < fVar2 != (pfVar10[-2] == fVar2)) && (fVar2 <= *pfVar10)) {
        fVar16 = (float10)(fVar2 - *(float *)(param_1 + 400 + iVar9 * 8));
        if (fVar16 == fVar17) {
          fVar16 = (float10)*(float *)(param_1 + 0x194 + iVar9 * 8);
        }
        else {
          pfVar10 = (float *)(param_1 + 0x194 + iVar9 * 8);
          fVar16 = ((float10)*(float *)(param_1 + 0x19c + iVar9 * 8) - (float10)*pfVar10) *
                   (fVar16 / (float10)(*(float *)(param_1 + 0x198 + iVar9 * 8) -
                                      *(float *)(param_1 + 400 + iVar9 * 8))) + (float10)*pfVar10;
        }
        break;
      }
      iVar9 = iVar9 + 1;
      pfVar10 = pfVar10 + 2;
      fVar16 = fVar17;
    } while (iVar9 < 7);
    local_24 = (float)fVar16;
    iVar9 = 0;
    pfVar10 = (float *)(param_1 + 0x1e0);
    do {
      if ((pfVar10[-2] < fVar2 != (pfVar10[-2] == fVar2)) && (fVar2 <= *pfVar10)) {
        fVar16 = (float10)(fVar2 - *(float *)(param_1 + 0x1d8 + iVar9 * 8));
        if (fVar16 == fVar17) {
          fVar16 = (float10)*(float *)(param_1 + 0x1dc + iVar9 * 8);
        }
        else {
          pfVar10 = (float *)(param_1 + 0x1dc + iVar9 * 8);
          fVar16 = ((float10)*(float *)(param_1 + 0x1e4 + iVar9 * 8) - (float10)*pfVar10) *
                   (fVar16 / (float10)(*(float *)(param_1 + 0x1e0 + iVar9 * 8) -
                                      *(float *)(param_1 + 0x1d8 + iVar9 * 8))) + (float10)*pfVar10;
        }
        break;
      }
      iVar9 = iVar9 + 1;
      pfVar10 = pfVar10 + 2;
      fVar16 = fVar17;
    } while (iVar9 < 7);
    local_2c = (float)fVar16;
    iVar9 = FUN_006e6b90();
    fVar4 = (float)(&DAT_029899a0)[iVar9 >> 1 & 0x7fff] * *(float *)(param_1 + 0xb4);
    iVar9 = FUN_006e6b90();
    fVar5 = (float)(&DAT_029899a0)[iVar9 >> 1 & 0x7fff] * *(float *)(param_1 + 0xbc);
    pfVar1 = (float *)(*(int *)(param_1 + 0x2a8) + 0x4c + iVar11);
    fVar12 = (float10)(float)((float10)local_2c - extraout_ST1);
    iVar9 = FUN_006e6b90();
    uVar6 = iVar9 >> 1 & 0x7fff;
    fVar13 = (float10)(float)(&DAT_029899a0)[uVar6] * (float10)local_28 * (float10)0.25;
    fVar16 = extraout_ST0;
    iVar9 = FUN_006e6b90();
    uVar7 = iVar9 >> 1 & 0x7fff;
    fVar14 = (float10)(float)(&DAT_029899a0)[uVar7] * (float10)local_24 * (float10)0.25;
    fVar15 = (float10)local_24 * (float10)0.25 * (float10)(float)(&DAT_029899a0)[uVar6];
    fVar18 = (float10)(float)(&DAT_029899a0)[uVar7] * extraout_ST0_00;
    fVar2 = (float)(&DAT_029899a0)[uVar7];
    fVar3 = (float)(&DAT_029899a0)[uVar6];
    *pfVar1 = (float)((float10)(float)((float10)fVar4 + (fVar15 - fVar18)) * fVar12);
    iVar9 = 0;
    pfVar10 = (float *)(param_1 + 200);
    pfVar1[1] = (float)((float10)(float)((float10)fVar5 - (fVar14 + fVar16)) * fVar12);
    pfVar1[2] = (float)extraout_ST1_00;
    fVar15 = (float10)(float)((float10)fVar4 - (fVar18 + fVar15));
    pfVar1[3] = (float)(fVar15 * fVar12);
    fVar16 = (float10)(float)((float10)fVar5 + ((float10)(double)fVar14 - fVar16));
    pfVar1[4] = (float)(fVar16 * fVar12);
    pfVar1[5] = (float)extraout_ST1_00;
    pfVar1[6] = (float)(((float10)(fVar2 * local_28 * 0.5) + fVar15) * fVar12);
    pfVar1[7] = (float)(((float10)(local_28 * 0.5 * fVar3) + fVar16) * fVar12);
    pfVar1[8] = (float)extraout_ST1_00;
    do {
      if (((float10)pfVar10[-2] < fVar13 != ((float10)pfVar10[-2] == fVar13)) &&
         (fVar13 <= (float10)*pfVar10)) {
        fVar16 = (float10)(float)(fVar13 - (float10)*(float *)(param_1 + 0xc0 + iVar9 * 8));
        if (fVar16 == extraout_ST1_00) {
          local_20 = (float)*(byte *)(param_1 + 0xc4 + iVar9 * 8);
          local_1c = (float)*(byte *)(param_1 + 0xc5 + iVar9 * 8);
          fVar16 = (float10)*(byte *)(param_1 + 0xc6 + iVar9 * 8);
        }
        else {
          uVar6 = (uint)*(byte *)(param_1 + 0xc4 + iVar9 * 8);
          fVar16 = fVar16 / (float10)(*(float *)(param_1 + 200 + iVar9 * 8) -
                                     *(float *)(param_1 + 0xc0 + iVar9 * 8));
          uVar7 = (uint)*(byte *)(param_1 + 0xc5 + iVar9 * 8);
          uVar8 = (uint)*(byte *)(param_1 + 0xc6 + iVar9 * 8);
          local_20 = (float)((float10)(int)(*(byte *)(param_1 + 0xcc + iVar9 * 8) - uVar6) * fVar16
                            + (float10)uVar6);
          local_1c = (float)((float10)(int)(*(byte *)(param_1 + 0xcd + iVar9 * 8) - uVar7) * fVar16
                            + (float10)uVar7);
          fVar16 = fVar16 * (float10)(int)(*(byte *)(param_1 + 0xce + iVar9 * 8) - uVar8) +
                   (float10)uVar8;
        }
        break;
      }
      iVar9 = iVar9 + 1;
      pfVar10 = pfVar10 + 2;
      fVar16 = fVar17;
    } while (iVar9 < 7);
    local_18 = (float)fVar16;
    iVar9 = 0;
    pfVar10 = (float *)(param_1 + 0x108);
    do {
      if (((float10)pfVar10[-2] < fVar13 != ((float10)pfVar10[-2] == fVar13)) &&
         (fVar13 <= (float10)*pfVar10)) {
        fVar17 = (float10)(float)(fVar13 - (float10)*(float *)(param_1 + 0x100 + iVar9 * 8));
        if (fVar17 == extraout_ST1_00) {
          fVar17 = (float10)*(float *)(param_1 + 0x104 + iVar9 * 8);
        }
        else {
          pfVar10 = (float *)(param_1 + 0x104 + iVar9 * 8);
          fVar17 = ((float10)*(float *)(param_1 + 0x10c + iVar9 * 8) - (float10)*pfVar10) *
                   (fVar17 / (float10)(*(float *)(param_1 + 0x108 + iVar9 * 8) -
                                      *(float *)(param_1 + 0x100 + iVar9 * 8))) + (float10)*pfVar10;
        }
        break;
      }
      iVar9 = iVar9 + 1;
      pfVar10 = pfVar10 + 2;
    } while (iVar9 < 7);
    local_30 = (float)fVar17;
    local_30 = local_30 + local_30;
    if (255.0 <= local_30) {
      local_30 = 255.0;
    }
    local_14 = local_14 + 1;
    iVar11 = iVar11 + 0x28;
    local_8 = (uint)(longlong)ROUND(local_30);
    uVar6 = local_8 << 8;
    local_8 = (uint)(longlong)ROUND(local_20);
    uVar6 = uVar6 | local_8;
    local_8 = (uint)(longlong)ROUND(local_1c);
    uVar6 = uVar6 << 8 | local_8;
    local_8 = (uint)(longlong)ROUND(local_18);
    pfVar1[9] = (float)(uVar6 << 8 | local_8);
    fVar17 = extraout_ST1_00;
    if (0x9ff < iVar11) {
      return;
    }
  } while( true );
}

