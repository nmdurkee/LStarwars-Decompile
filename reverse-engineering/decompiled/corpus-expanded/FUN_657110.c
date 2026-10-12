/* Ghidra pseudocode, not original source.
 * ev_dfc36d2b541ec0d46ba2179b7939a25d003ccbe30d4bab0c10c333595f465d14
 * Entry: 0x657110; label: FUN_00657110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00657110(int param_1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  short *psVar9;
  short sVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  float *pfVar14;
  float10 fVar15;
  float10 fVar16;
  float10 extraout_ST1;
  float local_28;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c [3];
  
  fVar5 = _DAT_0296205c;
  if (param_1 == 1) {
    fVar5 = _DAT_02962060;
  }
  piVar1 = &DAT_0292fbfc + param_1;
  piVar13 = (int *)*piVar1;
  do {
  } while (DAT_02962058 != 0);
  DAT_02962058 = 1;
  if (piVar13 != (int *)0x0) {
    fVar15 = (float10)1e+10;
    fVar16 = (float10)128.0;
    while ((float)piVar13[1] <= fVar5) {
      *piVar1 = piVar13[4];
      iVar8 = piVar13[2];
      piVar13[4] = 0;
      if (iVar8 == 5) {
        iVar8 = *(int *)(DAT_0296209c + (short)piVar13[7] * 4);
        iVar6 = (piVar13[5] + 1) * 0x20 + *piVar13;
        fVar2 = *(float *)(iVar6 + 0x14);
        fVar3 = (float)piVar13[6];
        fVar4 = *(float *)(iVar8 + 0xa0) * (float)piVar13[6];
        fVar4 = fVar4 + fVar4;
        fVar4 = -(float)piVar13[10] * (*(float *)(iVar6 + 0x14) + fVar4) - fVar4;
        *(float *)(iVar6 + 0x14) = fVar4;
        fVar2 = *(float *)(iVar6 + 4) - ((float)piVar13[6] * fVar4 - fVar2 * fVar3);
        *(float *)(iVar6 + 4) = fVar2;
        iVar6 = FUN_00653840(*(undefined4 *)(iVar8 + 0xa0),*(undefined4 *)(iVar6 + 0x14),
                             fVar2 - (float)piVar13[9],&local_1c,&local_18);
        if (iVar6 != 0) {
          if (local_1c <= local_18) {
            local_28 = local_18;
          }
          else {
            local_28 = local_1c;
          }
          if (local_28 < *(float *)(iVar8 + 0xa4)) {
            if (local_1c <= local_18) {
              local_28 = local_18;
            }
            else {
              local_28 = local_1c;
            }
            local_28 = local_28 - (float)piVar13[6];
            fVar2 = local_18;
            if (local_18 < local_1c) {
              fVar2 = local_1c;
            }
            piVar13[6] = (int)fVar2;
            if (local_28 < 0.02 == (local_28 == 0.02)) {
              piVar13[1] = (int)(local_28 + (float)piVar13[1]);
              FUN_006551d0(piVar13,piVar1);
              fVar16 = (float10)128.0;
              fVar15 = (float10)1e+10;
              goto LAB_00657503;
            }
          }
        }
        fVar16 = (float10)128.0;
        fVar15 = (float10)1e+10;
        DAT_02947b70 = DAT_02947b70 + -1;
        *(int **)(DAT_02923198 + DAT_02947b70 * 4) = piVar13;
        *piVar13 = 0;
      }
      else if (iVar8 == 6) {
        local_c[0] = 1.0;
        local_c[1] = 0.0;
        local_c[2] = 0.0;
        pfVar14 = (float *)((piVar13[5] + 1) * 0x20 + *piVar13);
        FUN_005b3620(local_c,local_c,(int)(short)piVar13[8]);
        fVar4 = -(((float)piVar13[10] + 1.0) * (pfVar14[6] * local_c[2] + local_c[0] * pfVar14[4]));
        fVar2 = pfVar14[4];
        fVar3 = (float)piVar13[6];
        local_10 = pfVar14[6] * (float)piVar13[6];
        pfVar14[4] = pfVar14[4] + fVar4 * local_c[0];
        local_14 = fVar4 * local_c[2] + pfVar14[6];
        pfVar14[6] = local_14;
        local_14 = local_14 * (float)piVar13[6];
        *pfVar14 = *pfVar14 - (pfVar14[4] * (float)piVar13[6] - fVar2 * fVar3);
        pfVar14[2] = pfVar14[2] - (local_14 - local_10);
        fVar16 = (float10)128.0;
        fVar15 = (float10)1e+10;
        DAT_02947b70 = DAT_02947b70 + -1;
        *(int **)(DAT_02923198 + DAT_02947b70 * 4) = piVar13;
        *piVar13 = 0;
      }
      else {
        if (iVar8 == 3) {
          DAT_02948e98 = DAT_02948e98 + -1;
          *(int *)(DAT_02921200 + DAT_02948e98 * 4) = *piVar13;
          iVar8 = 0;
          do {
            *(float *)(iVar8 + 0x2c + *piVar13) = (float)fVar15;
            iVar6 = iVar8 + 0x100;
            *(float *)(iVar8 + 0x3c + *piVar13) = (float)fVar16;
            *(float *)(iVar8 + 0x4c + *piVar13) = (float)fVar15;
            *(float *)(iVar8 + 0x5c + *piVar13) = (float)fVar16;
            *(float *)(iVar8 + 0x6c + *piVar13) = (float)fVar15;
            *(float *)(iVar8 + 0x7c + *piVar13) = (float)fVar16;
            *(float *)(iVar8 + 0x8c + *piVar13) = (float)fVar15;
            *(float *)(iVar8 + 0x9c + *piVar13) = (float)fVar16;
            *(float *)(iVar8 + 0xac + *piVar13) = (float)fVar15;
            *(float *)(iVar8 + 0xbc + *piVar13) = (float)fVar16;
            *(float *)(iVar8 + 0xcc + *piVar13) = (float)fVar15;
            *(float *)(iVar8 + 0xdc + *piVar13) = (float)fVar16;
            *(float *)(iVar8 + 0xec + *piVar13) = (float)fVar15;
            *(float *)(iVar8 + 0xfc + *piVar13) = (float)fVar16;
            *(float *)(iVar8 + 0x10c + *piVar13) = (float)fVar15;
            *(float *)(iVar8 + 0x11c + *piVar13) = (float)fVar16;
            iVar8 = iVar6;
          } while (iVar6 < 0x400);
          DAT_02947b70 = DAT_02947b70 + -1;
          *(int **)(DAT_02923198 + DAT_02947b70 * 4) = piVar13;
        }
        else {
          if (iVar8 != 8) {
            if (iVar8 == 2) {
              FUN_005ffea0(piVar13,1);
              piVar13[2] = 3;
            }
            else {
              if (iVar8 != 9) {
                if ((iVar8 == 0) || (iVar8 == 7)) {
                  iVar8 = 0;
                  if (0 < DAT_008108e8 + DAT_008108ec) {
                    piVar11 = DAT_02961fec;
                    do {
                      if (*piVar11 == *piVar13) {
                        FUN_00654ea0(DAT_02961fec + iVar8 * 0x19,
                                     &DAT_0292fd30 +
                                     *(char *)(DAT_02961fec[iVar8 * 0x19 + 1] + 0x2f1));
                        DAT_02961fec[iVar8 * 0x19] = 0;
                        DAT_02961fec[iVar8 * 0x19 + 1] = 0;
                        DAT_02961fec[iVar8 * 0x19 + 2] = 0;
                        break;
                      }
                      iVar8 = iVar8 + 1;
                      piVar11 = piVar11 + 0x19;
                    } while (iVar8 < DAT_008108e8 + DAT_008108ec);
                  }
                  piVar13[1] = (int)((float)piVar13[1] + 0.1);
                  if (piVar13[2] == 0) {
                    piVar13[2] = 2;
                    FUN_006551d0(piVar13,piVar1);
                    fVar16 = (float10)128.0;
                    fVar15 = (float10)1e+10;
                  }
                  else {
                    if (piVar13[2] == 7) {
                      piVar13[2] = 9;
                    }
                    FUN_006551d0(piVar13,piVar1);
                    fVar16 = (float10)128.0;
                    fVar15 = (float10)1e+10;
                  }
                }
                else if (iVar8 == 1) {
                  iVar8 = piVar13[3];
                  iVar6 = *(int *)(DAT_0296209c + *(short *)(iVar8 + 0x182) * 4);
                  iVar7 = 0;
                  iVar12 = 0;
                  if (0 < *(short *)(iVar8 + 0x180)) {
                    piVar11 = (int *)(iVar8 + 0x100);
                    do {
                      iVar12 = iVar7;
                      if (*piVar11 == *piVar13) break;
                      iVar7 = iVar7 + 1;
                      piVar11 = piVar11 + 1;
                      iVar12 = 0;
                    } while (iVar7 < *(short *)(piVar13[3] + 0x180));
                  }
                  if (iVar12 < *(short *)(iVar8 + 0x180) + -1) {
                    iVar8 = iVar12 * 4 + 0x100;
                    iVar7 = iVar12;
                    do {
                      *(undefined4 *)(iVar8 + piVar13[3]) = *(undefined4 *)(iVar8 + 4 + piVar13[3]);
                      iVar7 = iVar7 + 1;
                      iVar8 = iVar8 + 4;
                    } while (iVar7 < *(short *)(piVar13[3] + 0x180) + -1);
                  }
                  *(undefined4 *)(piVar13[3] + 0xfc + *(short *)(piVar13[3] + 0x180) * 4) = 0;
                  *(short *)(piVar13[3] + 0x180) = *(short *)(piVar13[3] + 0x180) + -1;
                  *(short *)(piVar13[3] + 0x18c) = *(short *)(piVar13[3] + 0x18c) + -1;
                  *(short *)(piVar13[3] + 0x188) = *(short *)(piVar13[3] + 0x188) + -1;
                  iVar8 = piVar13[3];
                  if (*(short *)(iVar8 + 0x180) < 1) {
                    *(undefined2 *)(iVar8 + 0x186) = 0;
                    *(undefined2 *)(piVar13[3] + 0x18e) = 0;
                  }
                  else {
                    if (*(char *)(iVar6 + 0x2e) == '\a') {
                      sVar10 = -0xc;
                      *(short *)(iVar8 + 0x186) = *(short *)(iVar8 + 0x186) + -0xc;
                      *(short *)(piVar13[3] + 0x18e) = *(short *)(piVar13[3] + 0x18e) + -0xc;
                      iVar8 = (iVar12 * 3 + 3) * 4;
                    }
                    else {
                      sVar10 = -0x20;
                      *(short *)(iVar8 + 0x186) = *(short *)(iVar8 + 0x186) + -0x20;
                      *(short *)(piVar13[3] + 0x18e) = *(short *)(piVar13[3] + 0x18e) + -0x20;
                      iVar8 = (iVar12 + 1) * 0x20;
                    }
                    if (iVar8 < *(short *)(piVar13[3] + 0x18a)) {
                      psVar9 = (short *)(piVar13[3] + 0x18a);
                      *psVar9 = *psVar9 + sVar10;
                    }
                  }
                  sVar10 = *(short *)(piVar13[3] + 0x180);
                  if (sVar10 < 1) {
                    psVar9 = (short *)(iVar6 + 0x3d0);
                    iVar8 = 8;
                    do {
                      if ((*psVar9 != -1) && (*psVar9 * 0x330 + DAT_029620a4 == piVar13[3])) {
                        *(undefined2 *)(piVar13[3] + 0x182) = 0;
                        *(undefined2 *)(piVar13[3] + 0x32a) = 0xffff;
                        DAT_029211e8 = DAT_029211e8 + -1;
                        *(short *)(DAT_02962084 + DAT_029211e8 * 2) = *psVar9;
                        *psVar9 = -1;
                      }
                      psVar9 = psVar9 + 1;
                      iVar8 = iVar8 + -1;
                    } while (iVar8 != 0);
                    *(undefined4 *)(piVar13[3] + 0x100) = 0;
                  }
                  else {
                    FUN_005ffea0(piVar13[3] + 0x100,(int)sVar10);
                    fVar16 = (float10)128.0;
                    fVar15 = (float10)1e+10;
                  }
                  if (iVar12 == 0) {
                    iVar8 = 0;
                    if (0 < DAT_008108e8 + DAT_008108ec) {
                      piVar11 = DAT_02961fec;
                      do {
                        if (*piVar11 == *piVar13) {
                          DAT_02961fec[iVar8 * 0x19] = *(int *)(piVar13[3] + 0x100);
                          if (*(short *)(piVar13[3] + 0x180) == 0) {
                            fVar15 = (float10)FUN_00654ea0(DAT_02961fec + iVar8 * 0x19,
                                                           &DAT_0292fd30 + *(char *)(iVar6 + 0x2f1))
                            ;
                            DAT_02961fec[iVar8 * 0x19 + 1] = 0;
                            DAT_02961fec[iVar8 * 0x19 + 2] = 0;
                            fVar16 = extraout_ST1;
                          }
                          break;
                        }
                        iVar8 = iVar8 + 1;
                        piVar11 = piVar11 + 0x19;
                      } while (iVar8 < DAT_008108e8 + DAT_008108ec);
                    }
                  }
                  local_10 = (float)piVar13[1] + 0.1;
                  piVar13[1] = (int)local_10;
                  piVar13[2] = (-(uint)(*(char *)(iVar6 + 0x2e) != '\a') & 0xfffffff9) + 9;
                  iVar8 = *piVar1;
                  piVar11 = piVar1;
                  while ((iVar8 != 0 && (iVar6 = *piVar11, *(float *)(iVar6 + 4) < local_10))) {
                    iVar8 = *(int *)(iVar6 + 0x10);
                    piVar11 = (int *)(iVar6 + 0x10);
                  }
                  piVar13[4] = *piVar11;
                  *piVar11 = (int)piVar13;
                }
                goto LAB_00657503;
              }
              FUN_005ffea0(piVar13,1);
              piVar13[2] = 8;
            }
            piVar13[1] = (int)((float)piVar13[1] + 0.1);
            FUN_006551d0(piVar13,piVar1);
            fVar16 = (float10)128.0;
            fVar15 = (float10)1e+10;
            goto LAB_00657503;
          }
          DAT_02947d84 = DAT_02947d84 + -1;
          *(int *)(DAT_029211fc + DAT_02947d84 * 4) = *piVar13;
          iVar8 = 0;
          do {
            *(float *)(iVar8 + 0x2c + *piVar13) = (float)fVar15;
            iVar6 = iVar8 + 0xc0;
            *(float *)(iVar8 + 0x3c + *piVar13) = (float)fVar16;
            *(float *)(iVar8 + 0x4c + *piVar13) = (float)fVar15;
            *(float *)(iVar8 + 0x5c + *piVar13) = (float)fVar16;
            *(float *)(iVar8 + 0x6c + *piVar13) = (float)fVar15;
            *(float *)(iVar8 + 0x7c + *piVar13) = (float)fVar16;
            *(float *)(iVar8 + 0x8c + *piVar13) = (float)fVar15;
            *(float *)(iVar8 + 0x9c + *piVar13) = (float)fVar16;
            *(float *)(iVar8 + 0xac + *piVar13) = (float)fVar15;
            *(float *)(iVar8 + 0xbc + *piVar13) = (float)fVar16;
            *(float *)(iVar8 + 0xcc + *piVar13) = (float)fVar15;
            *(float *)(iVar8 + 0xdc + *piVar13) = (float)fVar16;
            iVar8 = iVar6;
          } while (iVar6 < 0x180);
          DAT_02947b70 = DAT_02947b70 + -1;
          *(int **)(DAT_02923198 + DAT_02947b70 * 4) = piVar13;
        }
        *piVar13 = 0;
      }
LAB_00657503:
      piVar13 = (int *)*piVar1;
      if (piVar13 == (int *)0x0) {
        DAT_02962058 = 0;
        return;
      }
    }
  }
  DAT_02962058 = 0;
  return;
}

