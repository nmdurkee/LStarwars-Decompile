/* Ghidra analysis pseudocode, not original source.
 * ev_b2f72df0dabe11c9bc7c22be1245d6bb58dcd22f440da2427165c0dad76f7a14
 * Entry: 0x636810; label: FUN_00636810
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00636810(int param_1,float param_2,float *param_3,uint param_4)

{
  float fVar1;
  char cVar2;
  ushort uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  uint uVar10;
  float10 fVar11;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  int local_c;
  char *local_8;
  uint local_4;
  
  iVar6 = (int)param_2;
  *(undefined4 *)((int)param_2 + 0x140) = 0;
  local_8 = (char *)0x0;
  if (param_1 == 0) {
    pfVar9 = (float *)FUN_00547580(_DAT_02913970,0);
  }
  else {
    pfVar9 = (float *)(param_1 + 4);
    _DAT_02913994 = (int *)(param_1 + 0x4f84);
    if ((*_DAT_02913994 != 0) && (param_3 != (float *)0x0)) {
      iVar7 = FUN_006e6b90();
      iVar5 = *(int *)(param_1 + 0x4f90);
      if ((iVar7 < iVar5) &&
         (((-1 < iVar7 && (iVar8 = FUN_006e6b90(), iVar8 < *(int *)(param_1 + 0x4f94))) &&
          (-1 < iVar8)))) {
        local_8 = *(char **)(*(int *)(param_1 + 0x4fa4) + (iVar5 * iVar8 + iVar7) * 4);
        local_c = 0;
        pfVar9 = (float *)FUN_00636780(pfVar9);
      }
    }
  }
  if ((int)param_4 < 0) {
    local_4 = 0;
  }
  else {
    local_4 = param_4 >> 4 & 1;
    param_4 = param_4 & 0xf;
  }
  if (pfVar9 != (float *)0x0) {
    do {
      cVar2 = *(char *)(pfVar9 + 0x16);
      param_2 = 1.0;
      if (cVar2 == '\0') break;
      if (*(char *)((int)pfVar9 + 0x7a) == -1) {
        if ((((int)param_4 < 0) || (cVar2 == '\a')) ||
           ((uVar10 = 1 << ((byte)param_4 & 0x1f), (uVar10 & *(ushort *)(pfVar9 + 0x18)) == 0 &&
            ((((uVar3 = *(ushort *)((int)pfVar9 + 0x5e), uVar3 == 0 || (cVar2 != '\x05')) ||
              ((param_4 != 0xffffffff && ((uVar10 & uVar3) != 0)))) &&
             ((local_4 == 0 || (uVar3 != 0)))))))) {
          if ((*(byte *)((int)pfVar9 + 0x59) & 1) == 0) {
            switch(cVar2) {
            case '\x01':
              if (param_3 == (float *)0x0) {
                fVar1 = 0.0;
              }
              else {
                fVar1 = (param_3[2] - pfVar9[2]) * (param_3[2] - pfVar9[2]) +
                        (*param_3 - *pfVar9) * (*param_3 - *pfVar9) +
                        (param_3[1] - pfVar9[1]) * (param_3[1] - pfVar9[1]);
              }
              param_2 = 1.0;
              if (fVar1 < pfVar9[0x10] * pfVar9[0x10]) {
                if (pfVar9[0xf] < pfVar9[0x10]) {
                  fVar11 = (float10)FUN_005c0240(fVar1);
                  fVar1 = (float)fVar11;
                  if ((1.0 < (fVar1 - pfVar9[0xf]) / (pfVar9[0x10] - pfVar9[0xf])) ||
                     (param_2 = 0.0, 0.0 <= (fVar1 - pfVar9[0xf]) / (pfVar9[0x10] - pfVar9[0xf]))) {
                    if ((fVar1 - pfVar9[0xf]) / (pfVar9[0x10] - pfVar9[0xf]) <= 1.0) {
                      param_2 = (fVar1 - pfVar9[0xf]) / (pfVar9[0x10] - pfVar9[0xf]);
                    }
                    else {
                      param_2 = 1.0;
                    }
                  }
                  param_2 = 1.0 - param_2;
                }
                if ((*(char *)((int)pfVar9 + 0x79) == -1) && (*(char *)((int)pfVar9 + 0x7a) == -1))
                {
                  param_2 = *(float *)(PTR_DAT_0080fe0c + *(char *)((int)pfVar9 + 0x7b) * 4) *
                            param_2;
                }
                if ((param_2 != 0.0) &&
                   (*(float *)(iVar6 + 0x2c) < param_2 != (*(float *)(iVar6 + 0x2c) == param_2)))
                goto LAB_00636ab4;
              }
              break;
            case '\x02':
            case '\x03':
            case '\x04':
            case '\x06':
            case '\b':
              if (param_3 == (float *)0x0) {
                fVar1 = 0.0;
              }
              else {
                fVar1 = (param_3[1] - pfVar9[1]) * (param_3[1] - pfVar9[1]) +
                        (*param_3 - *pfVar9) * (*param_3 - *pfVar9) +
                        (param_3[2] - pfVar9[2]) * (param_3[2] - pfVar9[2]);
              }
              if (fVar1 < pfVar9[0x10] * pfVar9[0x10]) {
                if (pfVar9[0xf] < pfVar9[0x10]) {
                  fVar11 = (float10)FUN_005c0240(fVar1);
                  fVar1 = (float)fVar11;
                  if ((1.0 < (fVar1 - pfVar9[0xf]) / (pfVar9[0x10] - pfVar9[0xf])) ||
                     (param_2 = 0.0, 0.0 <= (fVar1 - pfVar9[0xf]) / (pfVar9[0x10] - pfVar9[0xf]))) {
                    if ((fVar1 - pfVar9[0xf]) / (pfVar9[0x10] - pfVar9[0xf]) <= 1.0) {
                      param_2 = (fVar1 - pfVar9[0xf]) / (pfVar9[0x10] - pfVar9[0xf]);
                    }
                    else {
                      param_2 = 1.0;
                    }
                  }
                  param_2 = 1.0 - param_2;
                }
                if ((*(char *)((int)pfVar9 + 0x79) == -1) && (*(char *)((int)pfVar9 + 0x7a) == -1))
                {
                  param_2 = *(float *)(PTR_DAT_0080fe0c + *(char *)((int)pfVar9 + 0x7b) * 4) *
                            param_2;
                }
                if (((param_2 != 0.0) &&
                    (*(float *)(iVar6 + 0x14) < param_2 != (*(float *)(iVar6 + 0x14) == param_2)))
                   && ((pfVar9[6] != 0.0 || ((pfVar9[7] != 0.0 || (pfVar9[8] != 0.0)))))) {
                  FUN_00636160(param_2);
                }
                fVar11 = (float10)param_2;
                if (param_3 != (float *)0x0) {
                  if ((*(byte *)((int)pfVar9 + 0x59) & 4) != 0) {
                    *(float *)(iVar6 + 0x134) =
                         (float)((float10)pfVar9[3] * fVar11 + (float10)*(float *)(iVar6 + 0x134));
                    *(float *)(iVar6 + 0x138) =
                         (float)((float10)pfVar9[4] * fVar11 + (float10)*(float *)(iVar6 + 0x138));
                    *(float *)(iVar6 + 0x13c) =
                         (float)((float10)pfVar9[5] * fVar11 + (float10)*(float *)(iVar6 + 0x13c));
                    *(float *)(iVar6 + 0x140) = (float)(fVar11 + (float10)*(float *)(iVar6 + 0x140))
                    ;
                    if (16.0 < pfVar9[0x1b]) {
                      uVar10 = FUN_006e6b90();
                      *(float *)(iVar6 + 0x134) =
                           (float)((float10)(float)(&DAT_029899a0)
                                                   [((int)uVar10 >> 4) * DAT_02913990 >> 1 & 0x7fff]
                                   * extraout_ST0 * (float10)(uVar10 & 0xf) * (float10)_DAT_0080fe1c
                                  + (float10)*(float *)(iVar6 + 0x134));
                      uVar10 = FUN_006e6b90();
                      *(float *)(iVar6 + 0x138) =
                           (float)((float10)(float)(&DAT_029899a0)
                                                   [((int)uVar10 >> 4) * DAT_02913990 + 0x4000 >> 1
                                                    & 0x7fff] * extraout_ST0_00 *
                                   (float10)(uVar10 & 0xf) * (float10)_DAT_0080fe1c +
                                  (float10)*(float *)(iVar6 + 0x138));
                      uVar10 = FUN_006e6b90();
                      *(float *)(iVar6 + 0x13c) =
                           (float)((float10)(float)(&DAT_029899a0)
                                                   [((int)uVar10 >> 4) * DAT_02913990 + 0x4000 >> 1
                                                    & 0x7fff] * extraout_ST0_01 *
                                   (float10)(uVar10 & 0xf) * (float10)_DAT_0080fe1c +
                                  (float10)*(float *)(iVar6 + 0x13c));
                      fVar11 = extraout_ST0_01;
                    }
                  }
                  if ((*(byte *)((int)pfVar9 + 0x59) & 2) != 0) {
                    if (pfVar9 == *(float **)(iVar6 + 0x4c)) {
                      *(float *)(iVar6 + 0x5c) = (float)fVar11;
                      if (*(char *)(pfVar9 + 0x16) == '\x04') {
                        FUN_005b3830(iVar6 + 0x50,pfVar9 + 3,0xbf800000);
                      }
                      else {
                        FUN_005b3800(iVar6 + 0x50,param_3,pfVar9);
                      }
                    }
                    else if (((float10)0 != fVar11) && ((float10)*(float *)(iVar6 + 0x5c) < fVar11))
                    {
                      *(float **)(iVar6 + 0x4c) = pfVar9;
                      uVar4 = *(undefined2 *)((int)pfVar9 + 0x6a);
                      *(float *)(iVar6 + 0x5c) = (float)fVar11;
                      *(undefined2 *)(iVar6 + 0x74) = uVar4;
                      if (*(char *)(pfVar9 + 0x16) == '\x04') {
                        FUN_005b3830(iVar6 + 0x50,pfVar9 + 3,0xbf800000);
                        *(undefined4 *)(iVar6 + 0x70) = 0x3f800000;
                      }
                      else {
                        FUN_005b3800(iVar6 + 0x50,param_3,pfVar9);
                        *(undefined4 *)(iVar6 + 0x70) = 0x3f800000;
                      }
                    }
                  }
                }
              }
              else if (*(float **)(iVar6 + 0x4c) == pfVar9) {
                *(undefined4 *)(iVar6 + 0x5c) = 0x33d6bf95;
              }
              break;
            case '\x05':
              param_2 = 2.0;
LAB_00636ab4:
              FUN_00636160(param_2);
              break;
            case '\a':
              if ((param_3 != (float *)0x0) &&
                 (fVar1 = (param_3[2] - pfVar9[2]) * (param_3[2] - pfVar9[2]) +
                          (*param_3 - *pfVar9) * (*param_3 - *pfVar9) +
                          (param_3[1] - pfVar9[1]) * (param_3[1] - pfVar9[1]),
                 fVar1 < pfVar9[0x10] * pfVar9[0x10])) {
                if (pfVar9[0xf] < pfVar9[0x10]) {
                  fVar11 = (float10)FUN_005c0240(fVar1);
                  fVar1 = (float)fVar11;
                  if ((1.0 < (fVar1 - pfVar9[0xf]) / (pfVar9[0x10] - pfVar9[0xf])) ||
                     (param_2 = 0.0, 0.0 <= (fVar1 - pfVar9[0xf]) / (pfVar9[0x10] - pfVar9[0xf]))) {
                    if ((fVar1 - pfVar9[0xf]) / (pfVar9[0x10] - pfVar9[0xf]) <= 1.0) {
                      param_2 = (fVar1 - pfVar9[0xf]) / (pfVar9[0x10] - pfVar9[0xf]);
                    }
                    else {
                      param_2 = 1.0;
                    }
                  }
                  param_2 = 1.0 - param_2;
                }
                if ((*(char *)((int)pfVar9 + 0x79) == -1) && (*(char *)((int)pfVar9 + 0x7a) == -1))
                {
                  param_2 = *(float *)(PTR_DAT_0080fe0c + *(char *)((int)pfVar9 + 0x7b) * 4) *
                            param_2;
                }
                if ((param_2 != 0.0) && (*(int *)(iVar6 + 0x48) < 3)) {
                  *(float **)(iVar6 + 0x30 + *(int *)(iVar6 + 0x48) * 4) = pfVar9;
                  *(float *)(iVar6 + 0x3c + *(int *)(iVar6 + 0x48) * 4) = param_2;
                  *(int *)(iVar6 + 0x48) = *(int *)(iVar6 + 0x48) + 1;
                }
              }
            }
          }
          goto switchD_0063699d_default;
        }
        pfVar9 = (float *)FUN_00636780(pfVar9);
      }
      else {
switchD_0063699d_default:
        if (param_1 == 0) {
          pfVar9 = (float *)FUN_00547580(_DAT_02913970,pfVar9);
        }
        else if (local_8 == (char *)0x0) {
          pfVar9 = pfVar9 + 0x23;
        }
        else if (local_c < *local_8) {
          local_c = local_c + 1;
          pfVar9 = (float *)(local_8[local_c] * 0x8c + 4 + param_1);
        }
        else {
          pfVar9 = (float *)0x0;
        }
      }
    } while (pfVar9 != (float *)0x0);
    if (*(float *)(iVar6 + 0x140) != 0.0) {
      FUN_005b3b30(iVar6 + 0x134,iVar6 + 0x134);
    }
  }
  return;
}

