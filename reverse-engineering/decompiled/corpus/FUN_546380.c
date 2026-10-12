/* Ghidra analysis pseudocode, not original source.
 * ev_177857cb78ddb8ad13dc6718881af1dfaef05e8a3811f551bff9ab7ba98e27a8
 * Entry: 0x546380; label: FUN_00546380
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00546380(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  float *pfVar13;
  short *psVar14;
  float10 extraout_ST0;
  float10 fVar15;
  float10 fVar16;
  float10 extraout_ST0_00;
  float10 fVar17;
  float10 fVar18;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float10 extraout_ST1_02;
  float10 extraout_ST1_03;
  float10 extraout_ST1_04;
  float local_64;
  float local_60;
  int local_5c;
  int local_58;
  float local_54;
  int local_48;
  undefined4 local_28 [9];
  
  iVar10 = DAT_02983a44;
  psVar14 = DAT_00924850;
  _DAT_02983a40 = _DAT_02983a40 + 0x1f5;
  DAT_02983a48 = DAT_02983a48 + 0x85;
  iVar12 = DAT_02983a44 + 0x179;
  DAT_02983a44 = iVar12;
  iVar9 = FUN_006e6b90();
  fVar5 = (float)(&DAT_029899a0)[iVar9 >> 1 & 0x7fff] * 0.75 +
          (float)(&DAT_029899a0)[iVar10 + 0x4179 >> 1 & 0x7fff] * 0.15;
  iVar10 = FUN_006e6b90();
  bVar8 = false;
  local_48 = 0;
  fVar1 = (float)((float10)(float)(&DAT_029899a0)[iVar10 >> 1 & 0x7fff] * extraout_ST1 -
                 extraout_ST0 * (float10)(float)(&DAT_029899a0)[iVar12 >> 1 & 0x7fff]);
  if (0 < DAT_0092484c) {
    do {
      if (*psVar14 != 0) {
        if (*(float *)(psVar14 + 0x1c) <=
            (*(float *)(psVar14 + 0xc) - DAT_00973720) * (*(float *)(psVar14 + 0xc) - DAT_00973720)
            + (*(float *)(psVar14 + 8) - DAT_00973718) * (*(float *)(psVar14 + 8) - DAT_00973718) +
              (*(float *)(psVar14 + 10) - DAT_0097371c) * (*(float *)(psVar14 + 10) - DAT_0097371c))
        {
          *(undefined1 *)((int)psVar14 + 0x1d) = 0;
        }
        else {
          *(undefined1 *)((int)psVar14 + 0x1d) = 1;
          if (((char)psVar14[0xe] != '\0') && (0.0 < *(float *)(psVar14 + 0x10))) {
            if (psVar14[1] != 0) {
              iVar10 = 8;
              piVar11 = param_1;
              do {
                if ((*piVar11 == 0) ||
                   (pfVar13 = (float *)*piVar11,
                   *(float *)(psVar14 + 0x14) <=
                   (*(float *)(psVar14 + 0xc) - pfVar13[2]) *
                   (*(float *)(psVar14 + 0xc) - pfVar13[2]) +
                   (*(float *)(psVar14 + 8) - *pfVar13) * (*(float *)(psVar14 + 8) - *pfVar13) +
                   (*(float *)(psVar14 + 10) - pfVar13[1]) * (*(float *)(psVar14 + 10) - pfVar13[1])
                   )) {
                  *(undefined4 *)(((int)local_28 - (int)param_1) + (int)piVar11) = 0;
                }
                else {
                  *(undefined4 *)(((int)local_28 - (int)param_1) + (int)piVar11) = 1;
                  bVar8 = true;
                }
                piVar11 = piVar11 + 1;
                iVar10 = iVar10 + -1;
              } while (iVar10 != 0);
            }
            if ((psVar14[1] == 0) || (!bVar8)) {
              local_58 = 0;
              if (0 < psVar14[0xf]) {
                pfVar13 = (float *)(*(int *)(psVar14 + 6) + 0x10);
                do {
                  fVar17 = (float10)1;
                  iVar10 = FUN_006e6b90();
                  fVar16 = (float10)(float)(&DAT_029899a0)[iVar10 >> 1 & 0x7fff] * fVar17;
                  fVar2 = pfVar13[0xb];
                  iVar10 = FUN_006e6b90();
                  *pfVar13 = (float)(((float10)(float)((float10)fVar5 * (float10)pfVar13[0xb] *
                                                      (extraout_ST0_02 +
                                                      (float10)(float)(&DAT_029899a0)
                                                                      [iVar10 >> 1 & 0x7fff] *
                                                      extraout_ST1_04)) - (float10)*pfVar13) *
                                     fVar17 + (float10)*pfVar13);
                  fVar2 = (float)(((float10)(float)((float10)fVar1 * (float10)fVar2 *
                                                   (fVar16 + extraout_ST1_03)) - (float10)pfVar13[2]
                                  ) * fVar17 + (float10)pfVar13[2]);
                  pfVar13[2] = fVar2;
                  fVar17 = (float10)FUN_005c0240(*pfVar13 * *pfVar13 + fVar2 * fVar2);
                  fVar17 = (float10)(float)((float10)1 - fVar17 * (float10)0.3499999940395355);
                  if (fVar17 < (float10)0.05000000074505806) {
                    fVar17 = (float10)0.05;
                  }
                  *pfVar13 = (float)((float10)*pfVar13 * fVar17);
                  pfVar13[2] = (float)((float10)pfVar13[2] * fVar17);
                  pfVar13[7] = (float)((float10)1 / fVar17);
                  if (fVar17 < (float10)0.19) {
                    fVar17 = (float10)(float)(float10)0.19;
                  }
                  local_58 = local_58 + 1;
                  pfVar13[1] = (float)(((float10)pfVar13[0xb] / (float10)*(float *)(psVar14 + 0x10))
                                      * fVar17);
                  pfVar13 = pfVar13 + 0x10;
                } while (local_58 < psVar14[0xf]);
              }
            }
            else {
              local_58 = 0;
              if (0 < psVar14[0xf]) {
                pfVar13 = (float *)(*(int *)(psVar14 + 6) + 0x38);
                do {
                  fVar16 = (float10)0.20000000298023224;
                  fVar17 = (float10)1;
                  fVar18 = (float10)0.5;
                  local_60 = 1e+06;
                  local_5c = -1;
                  if ((*param_1 != 0) &&
                     (fVar2 = *pfVar13 - ((float *)*param_1)[2],
                     fVar3 = pfVar13[-2] - *(float *)*param_1, fVar2 = fVar3 * fVar3 + fVar2 * fVar2
                     , fVar2 < 1e+06)) {
                    local_5c = 0;
                    local_60 = fVar2;
                  }
                  if (param_1[1] != 0) {
                    pfVar4 = (float *)param_1[1];
                    fVar2 = (*pfVar13 - pfVar4[2]) * (*pfVar13 - pfVar4[2]) +
                            (pfVar13[-2] - *pfVar4) * (pfVar13[-2] - *pfVar4);
                    if (fVar2 < local_60) {
                      local_5c = 1;
                      local_60 = fVar2;
                    }
                  }
                  if (param_1[2] != 0) {
                    pfVar4 = (float *)param_1[2];
                    fVar2 = (*pfVar13 - pfVar4[2]) * (*pfVar13 - pfVar4[2]) +
                            (pfVar13[-2] - *pfVar4) * (pfVar13[-2] - *pfVar4);
                    if (fVar2 < local_60) {
                      local_5c = 2;
                      local_60 = fVar2;
                    }
                  }
                  if (param_1[3] != 0) {
                    pfVar4 = (float *)param_1[3];
                    fVar2 = (*pfVar13 - pfVar4[2]) * (*pfVar13 - pfVar4[2]) +
                            (pfVar13[-2] - *pfVar4) * (pfVar13[-2] - *pfVar4);
                    if (fVar2 < local_60) {
                      local_5c = 3;
                      local_60 = fVar2;
                    }
                  }
                  if (param_1[4] != 0) {
                    pfVar4 = (float *)param_1[4];
                    fVar2 = (*pfVar13 - pfVar4[2]) * (*pfVar13 - pfVar4[2]) +
                            (pfVar13[-2] - *pfVar4) * (pfVar13[-2] - *pfVar4);
                    if (fVar2 < local_60) {
                      local_5c = 4;
                      local_60 = fVar2;
                    }
                  }
                  if (param_1[5] != 0) {
                    pfVar4 = (float *)param_1[5];
                    fVar2 = (*pfVar13 - pfVar4[2]) * (*pfVar13 - pfVar4[2]) +
                            (pfVar13[-2] - *pfVar4) * (pfVar13[-2] - *pfVar4);
                    if (fVar2 < local_60) {
                      local_5c = 5;
                      local_60 = fVar2;
                    }
                  }
                  if (param_1[6] != 0) {
                    pfVar4 = (float *)param_1[6];
                    fVar2 = (*pfVar13 - pfVar4[2]) * (*pfVar13 - pfVar4[2]) +
                            (pfVar13[-2] - *pfVar4) * (pfVar13[-2] - *pfVar4);
                    if (fVar2 < local_60) {
                      local_5c = 6;
                      local_60 = fVar2;
                    }
                  }
                  if ((param_1[7] == 0) ||
                     (pfVar4 = (float *)param_1[7],
                     local_60 <=
                     (*pfVar13 - pfVar4[2]) * (*pfVar13 - pfVar4[2]) +
                     (pfVar13[-2] - *pfVar4) * (pfVar13[-2] - *pfVar4))) {
                    if (local_5c == -1) break;
                  }
                  else {
                    local_5c = 7;
                  }
                  pfVar4 = (float *)param_1[local_5c];
                  fVar15 = (float10)pfVar4[1] - (float10)pfVar13[-1];
                  if (fVar15 <= ((float10)*(float *)(psVar14 + 0x12) * (float10)pfVar13[1]) /
                                (float10)*(float *)(psVar14 + 0x10)) {
                    local_54 = 0.45;
                    if ((float10)0 <= fVar15) {
                      fVar16 = (fVar15 * fVar18 + fVar16) * (float10)pfVar13[1];
                    }
                    else {
                      fVar16 = (float10)pfVar13[1] * fVar16;
                    }
                  }
                  else {
                    local_54 = 0.0;
                    fVar16 = (float10)pfVar13[1] * fVar16;
                  }
                  fVar2 = (float)(fVar16 / (float10)*(float *)(psVar14 + 0x10));
                  fVar3 = pfVar13[-3] * pfVar13[-10];
                  pfVar13[-10] = fVar3;
                  fVar6 = pfVar13[-3] * pfVar13[-8];
                  pfVar13[-8] = fVar6;
                  local_64 = (pfVar13[-2] + fVar2 * fVar3) - *pfVar4;
                  local_60 = (fVar6 * fVar2 + *pfVar13) - pfVar4[2];
                  fVar7 = local_64 * local_64 + local_60 * local_60;
                  if (fVar7 < local_54 * local_54) {
                    if (fVar7 == 0.0) {
                      local_64 = local_54;
                      local_60 = 0.0;
                    }
                    else {
                      fVar17 = (float10)FUN_005c0240(fVar7);
                      local_64 = (float)((float10)local_54 / fVar17) * local_64;
                      local_60 = (float)((float10)local_54 / fVar17) * local_60;
                    }
                    local_64 = (((*(float *)param_1[local_5c] + local_64) - pfVar13[-2]) * 0.3) /
                               fVar2;
                    local_60 = (((((float *)param_1[local_5c])[2] + local_60) - *pfVar13) * 0.3) /
                               fVar2;
                    fVar2 = local_64 * local_64 + local_60 * local_60;
                    if (0.25 < fVar2) {
                      fVar17 = (float10)FUN_005c0240(fVar2);
                      local_64 = (float)((float10)0.5 / fVar17) * local_64;
                      local_60 = (float)((float10)0.5 / fVar17) * local_60;
                    }
                    local_64 = (local_64 - pfVar13[-10]) * *(float *)(psVar14 + 0x24);
                    local_60 = (local_60 - pfVar13[-8]) * *(float *)(psVar14 + 0x24);
                    fVar2 = local_64 * local_64 + local_60 * local_60;
                    if (*(float *)(psVar14 + 0x22) < fVar2) {
                      fVar3 = *(float *)(psVar14 + 0x20);
                      fVar17 = (float10)FUN_005c0240(fVar2);
                      local_64 = (float)((float10)fVar3 / fVar17) * local_64;
                      local_60 = (float)((float10)fVar3 / fVar17) * local_60;
                    }
                    fVar17 = (float10)0.5;
                    fVar16 = (float10)(pfVar13[-10] + local_64);
                    pfVar13[-10] = pfVar13[-10] + local_64;
                    fVar18 = (float10)(pfVar13[-8] + local_60);
                    pfVar13[-8] = pfVar13[-8] + local_60;
                    iVar10 = FUN_006e6b90();
                    fVar15 = (float10)(float)(&DAT_029899a0)[iVar10 >> 1 & 0x7fff] * fVar16;
                    fVar2 = pfVar13[1];
                    iVar10 = FUN_006e6b90();
                    pfVar13[-10] = (float)(((float10)(float)((float10)pfVar13[1] * (float10)fVar5 *
                                                            ((float10)(float)(&DAT_029899a0)
                                                                             [iVar10 >> 1 & 0x7fff]
                                                             * fVar18 + fVar16)) - extraout_ST1_02)
                                           * (float10)0.05000000074505806 + extraout_ST1_02);
                    fVar17 = extraout_ST0_01 +
                             ((float10)(float)((float10)fVar2 * (float10)fVar1 * (fVar15 + fVar17))
                             - extraout_ST0_01) * (float10)0.05000000074505806;
                  }
                  else {
                    iVar10 = FUN_006e6b90();
                    fVar2 = (float)(((float10)(float)((float10)pfVar13[1] * (float10)fVar5 *
                                                     ((float10)(float)(&DAT_029899a0)
                                                                      [iVar10 >> 1 & 0x7fff] *
                                                      fVar17 + extraout_ST1_00)) - (float10)fVar3) *
                                   fVar18);
                    iVar10 = FUN_006e6b90();
                    fVar3 = (float)(((float10)(float)((float10)pfVar13[1] * (float10)fVar1 *
                                                     (extraout_ST0_00 +
                                                     (float10)(float)(&DAT_029899a0)
                                                                     [iVar10 >> 1 & 0x7fff] *
                                                     extraout_ST1_01)) - (float10)fVar6) * fVar17);
                    fVar6 = fVar2 * fVar2 + fVar3 * fVar3;
                    if (fVar6 <= 0.000144) {
                      pfVar13[-10] = pfVar13[-10] + fVar2;
                      fVar17 = (float10)pfVar13[-8] + (float10)fVar3;
                    }
                    else {
                      fVar17 = (float10)FUN_005c0240(fVar6);
                      pfVar13[-10] = pfVar13[-10] +
                                     (float)((float10)0.012000000104308128 / fVar17) * fVar2;
                      fVar17 = (float10)pfVar13[-8] +
                               (float10)((float)((float10)0.012000000104308128 / fVar17) * fVar3);
                    }
                  }
                  pfVar13[-8] = (float)fVar17;
                  fVar17 = (float10)FUN_005c0240(pfVar13[-10] * pfVar13[-10] +
                                                 pfVar13[-8] * pfVar13[-8]);
                  fVar17 = (float10)(float)((float10)1 - fVar17 * (float10)0.3499999940395355);
                  if (fVar17 < (float10)0.05000000074505806) {
                    fVar17 = (float10)0.05;
                  }
                  pfVar13[-10] = (float)((float10)pfVar13[-10] * fVar17);
                  pfVar13[-8] = (float)((float10)pfVar13[-8] * fVar17);
                  pfVar13[-3] = (float)((float10)1 / fVar17);
                  if (fVar17 < (float10)0.19) {
                    fVar17 = (float10)(float)(float10)0.19;
                  }
                  local_58 = local_58 + 1;
                  pfVar13[-9] = (float)(((float10)pfVar13[1] / (float10)*(float *)(psVar14 + 0x10))
                                       * fVar17);
                  pfVar13 = pfVar13 + 0x10;
                } while (local_58 < psVar14[0xf]);
              }
            }
          }
        }
      }
      local_48 = local_48 + 1;
      psVar14 = psVar14 + 0x26;
    } while (local_48 < DAT_0092484c);
  }
  return;
}

