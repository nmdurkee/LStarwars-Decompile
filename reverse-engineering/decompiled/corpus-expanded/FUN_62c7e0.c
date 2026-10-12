/* Ghidra pseudocode, not original source.
 * ev_be89c5742567956971c64ab2441aea6b3f78c2cf42a7c801ad7bb364f9087e2c
 * Entry: 0x62c7e0; label: FUN_0062c7e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062c7e0(short *param_1,undefined4 param_2,float *param_3,int param_4,int param_5,
                 short *param_6,int param_7,float param_8,code *param_9,int param_10)

{
  float fVar1;
  float fVar2;
  char cVar3;
  short sVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  bool bVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  float *pfVar12;
  int iVar13;
  undefined4 *puVar14;
  int iVar15;
  int iVar16;
  int local_12c;
  int *local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  int local_114;
  float fStack_110;
  undefined1 auStack_10c [12];
  undefined4 local_100;
  undefined4 local_fc [47];
  int aiStack_40 [16];
  
  if (param_7 != 0) {
    return;
  }
  if (param_6 == (short *)0x0) {
    return;
  }
  cVar3 = *(char *)((int)param_3 + 0x31);
  if (cVar3 != '\0') {
    if (((-1 < *(short *)(param_3 + 0xd)) &&
        (local_114 = (int)*(short *)(param_3 + 0xd), local_114 < *(int *)(DAT_029130e4 + 8))) &&
       (*(int *)(*(int *)(param_1 + 6) + local_114 * 4) != 0)) {
      fVar1 = param_3[5];
      goto LAB_0062c896;
    }
    if (cVar3 != '\0') {
      if (((-1 < *(short *)((int)param_3 + 0x32)) &&
          (local_114 = (int)*(short *)((int)param_3 + 0x32), local_114 < *(int *)(DAT_029130e4 + 8))
          ) && (*(int *)(*(int *)(param_1 + 6) + local_114 * 4) != 0)) {
        fVar1 = param_3[4];
        goto LAB_0062c896;
      }
      if (cVar3 != '\0') {
        return;
      }
    }
  }
  if (*(short *)((int)param_3 + 0x36) < 0) {
    return;
  }
  local_114 = (int)*(short *)((int)param_3 + 0x36);
  if (*(int *)(DAT_029130e4 + 8) <= local_114) {
    return;
  }
  if (*(int *)(*(int *)(param_1 + 6) + local_114 * 4) == 0) {
    return;
  }
  fVar1 = *param_3;
LAB_0062c896:
  sVar4 = *param_6;
  do {
    if (sVar4 == -1) {
      return;
    }
    if ((*param_1 == sVar4) && (local_114 == param_6[2])) {
      if (param_5 == 0) {
        uVar9 = *(uint *)(param_6 + 10);
        if ((uVar9 & 0x3000000) == 0) goto LAB_0062c981;
      }
      else {
        uVar9 = *(uint *)(param_6 + 10);
        if (((((uVar9 & 0x400) == 0) || (*(char *)(param_5 + 0x280) != -1)) &&
            ((((uVar9 & 0x10) == 0 || ((*(byte *)(param_5 + 0x281) & 2) != 0)) &&
             (((uVar9 & 0x40) == 0 || (*(char *)(param_5 + 0x286) == '\0')))))) &&
           ((((uVar9 & 0x20) == 0 || (*(char *)(param_5 + 0x286) != '\0')) &&
            (((-1 < (char)uVar9 || (*(char *)(param_5 + 0x287) != '\0')) &&
             (((uVar9 & 0x3000000) == 0 ||
              ((*(char *)(param_5 + 0x288) != '\0' && ((*(byte *)(param_5 + 0x281) & 2) != 0))))))))
           )) {
LAB_0062c981:
          bVar7 = false;
          if ((uVar9 & 4) == 0) {
            if ((uVar9 & 8) == 0) {
              pfVar12 = (float *)(param_6 + 4);
              iVar13 = 2;
              do {
                if (1.0 < *pfVar12) {
                  fVar2 = param_3[0xc];
                  if (((uint)fVar2 & 8) == 0) {
                    if (fVar1 <= *pfVar12) {
                      if (((((uint)fVar2 & 2) != 0) && (fVar1 < param_3[1])) &&
                         (param_3[1] <= *pfVar12)) goto LAB_0062cac2;
                    }
                    else if ((param_3[1] <= *pfVar12) ||
                            ((((uint)fVar2 & 2) != 0 && (fVar1 < param_3[1])))) {
LAB_0062cac2:
                      bVar7 = true;
                    }
                  }
                  else if (((fVar1 < *pfVar12) || ((((uint)fVar2 & 2) != 0 && (param_3[1] < fVar1)))
                           ) && (*pfVar12 < param_3[1] != (*pfVar12 == param_3[1])))
                  goto LAB_0062cac2;
                }
                pfVar12 = pfVar12 + 1;
                iVar13 = iVar13 + -1;
              } while (iVar13 != 0);
              if (bVar7) goto LAB_0062cae1;
            }
            else {
              if ((1.0 < *(float *)(param_6 + 6)) &&
                 (*(float *)(param_6 + 6) < *(float *)(param_6 + 4))) {
                if (*(float *)(param_6 + 4) < fVar1 == (*(float *)(param_6 + 4) == fVar1)) {
                  fVar2 = *(float *)(param_6 + 6);
joined_r0x0062ca20:
                  if (fVar2 < fVar1) goto LAB_0062c945;
                }
                goto LAB_0062cae1;
              }
              if (*(float *)(param_6 + 4) < fVar1 != (*(float *)(param_6 + 4) == fVar1)) {
                if (*(float *)(param_6 + 6) <= 1.0) goto LAB_0062cae1;
                if (*(float *)(param_6 + 4) < *(float *)(param_6 + 6)) {
                  fVar2 = *(float *)(param_6 + 6);
                  goto joined_r0x0062ca20;
                }
              }
            }
          }
          else {
LAB_0062cae1:
            local_120 = 0;
            local_11c = 0;
            iVar13 = 0;
            local_118 = 0;
            iVar15 = 0;
            puVar14 = (undefined4 *)(param_4 + 0x30);
            local_124 = (int *)(param_1 + 10);
            local_12c = 0;
            puVar8 = &local_100;
            do {
              if ((((uint)(ushort)param_6[0xc] & 1 << ((byte)iVar15 & 0x1f)) != 0) &&
                 (*local_124 != 0)) {
                uVar5 = puVar14[1];
                *puVar8 = *puVar14;
                uVar6 = puVar14[2];
                puVar8[1] = uVar5;
                aiStack_40[iVar13] = iVar15;
                puVar8[2] = uVar6;
                if ((iVar13 == 0) || ((*(uint *)(param_6 + 10) & 0x800) != 0)) {
                  FUN_005b37d0(&local_120,&local_120,puVar14);
                  iVar13 = local_12c;
                }
                iVar13 = iVar13 + 1;
                puVar8 = puVar8 + 3;
                local_12c = iVar13;
              }
              local_124 = local_124 + 1;
              iVar15 = iVar15 + 1;
              puVar14 = puVar14 + 0x10;
            } while (iVar15 < 0x10);
            if ((0 < iVar13) && ((*(uint *)(param_6 + 10) & 0x800) != 0)) {
              FUN_005b3830(&local_120,&local_120,1.0 / (float)local_12c);
              iVar13 = local_12c;
            }
            uVar9 = *(uint *)(param_6 + 10);
            iVar15 = iVar13;
            if ((uVar9 & 0x1000) == 0) {
LAB_0062cc18:
              if (param_5 != 0) {
                if (iVar15 == 0) {
                  local_100 = *(undefined4 *)(param_5 + 0x5c);
                  local_fc[0] = *(undefined4 *)(param_5 + 0x60);
                  local_fc[1] = *(undefined4 *)(param_5 + 100);
                  local_120 = *(undefined4 *)(param_5 + 0x5c);
                  local_11c = *(undefined4 *)(param_5 + 0x60);
                  local_118 = *(undefined4 *)(param_5 + 100);
                  iVar15 = 1;
                  if (((uVar9 & 0x2000) == 0) || (*(float *)(param_5 + 0x21c) == 2e+06)) {
                    if (((uVar9 & 0x4000) != 0) && (*(float *)(param_5 + 0x220) != 2e+06)) {
                      local_11c = *(undefined4 *)(param_5 + 0x220);
                    }
                  }
                  else {
                    local_11c = *(undefined4 *)(param_5 + 0x21c);
                  }
                }
                else if (((uVar9 & 0x2000) == 0) || (*(float *)(param_5 + 0x21c) == 2e+06)) {
                  if (((uVar9 & 0x4000) != 0) && (*(float *)(param_5 + 0x220) != 2e+06)) {
                    iVar16 = 0;
                    if (3 < iVar13) {
                      iVar11 = (iVar13 - 4U >> 2) + 1;
                      iVar16 = iVar11 * 4;
                      puVar8 = local_fc + 3;
                      do {
                        iVar11 = iVar11 + -1;
                        puVar8[-3] = *(undefined4 *)(param_5 + 0x220);
                        *puVar8 = *(undefined4 *)(param_5 + 0x220);
                        puVar8[3] = *(undefined4 *)(param_5 + 0x220);
                        puVar8[6] = *(undefined4 *)(param_5 + 0x220);
                        puVar8 = puVar8 + 0xc;
                      } while (iVar11 != 0);
                    }
                    if (iVar16 < iVar13) {
                      iVar11 = iVar13 - iVar16;
                      puVar8 = local_fc + iVar16 * 3;
                      do {
                        iVar11 = iVar11 + -1;
                        *puVar8 = *(undefined4 *)(param_5 + 0x220);
                        puVar8 = puVar8 + 3;
                      } while (iVar11 != 0);
                    }
                  }
                }
                else {
                  iVar16 = 0;
                  if (3 < iVar13) {
                    iVar11 = (iVar13 - 4U >> 2) + 1;
                    iVar16 = iVar11 * 4;
                    puVar8 = local_fc + 3;
                    do {
                      iVar11 = iVar11 + -1;
                      puVar8[-3] = *(undefined4 *)(param_5 + 0x21c);
                      *puVar8 = *(undefined4 *)(param_5 + 0x21c);
                      puVar8[3] = *(undefined4 *)(param_5 + 0x21c);
                      puVar8[6] = *(undefined4 *)(param_5 + 0x21c);
                      puVar8 = puVar8 + 0xc;
                    } while (iVar11 != 0);
                  }
                  if (iVar16 < iVar13) {
                    iVar11 = iVar13 - iVar16;
                    puVar8 = local_fc + iVar16 * 3;
                    do {
                      iVar11 = iVar11 + -1;
                      *puVar8 = *(undefined4 *)(param_5 + 0x21c);
                      puVar8 = puVar8 + 3;
                    } while (iVar11 != 0);
                  }
                }
              }
            }
            else if (param_5 != 0) {
              local_120 = *(undefined4 *)(param_5 + 0x5c);
              iVar13 = 0;
              iVar15 = 1;
              local_11c = *(undefined4 *)(param_5 + 0x17c);
              local_12c = 0;
              local_118 = *(undefined4 *)(param_5 + 100);
              goto LAB_0062cc18;
            }
            if (param_9 != (code *)0x0) {
              if ((iVar13 == 0) && ((uVar9 & 0x3000000) != 0)) {
                (*param_9)(param_5 + 0x5c,param_5,uVar9 & 0x1000000,1);
              }
              else if ((0 < iVar15) && (((uVar9 & 0x3000000) != 0 && (iVar16 = 0, 0 < iVar13)))) {
                do {
                  if (*(int *)(*(int *)(param_5 + 0x50) + 0x14 + aiStack_40[iVar16] * 4) != 0) {
                    (*param_9)(aiStack_40[iVar16] * 0x40 + param_4,param_5,
                               *(uint *)(param_6 + 10) & 0x1000000,0);
                    iVar13 = local_12c;
                  }
                  iVar16 = iVar16 + 1;
                } while (iVar16 < iVar13);
              }
            }
            if (param_5 != 0) {
              if (*(byte *)(param_6 + 3) != 0) {
                *(byte *)(param_5 + 0x289) = *(byte *)(param_5 + 0x289) | *(byte *)(param_6 + 3);
              }
              if (*(byte *)((int)param_6 + 7) != 0) {
                *(byte *)(param_5 + 0x289) =
                     *(byte *)(param_5 + 0x289) & ~*(byte *)((int)param_6 + 7);
              }
            }
            if (iVar15 < 1) {
LAB_0062ceba:
              if (param_5 == 0) goto LAB_0062cf31;
              uVar9 = *(uint *)(param_6 + 10);
              if ((uVar9 & 0x100000) == 0) {
                if ((uVar9 & 0x40000) != 0) {
                  fVar2 = *(float *)(param_5 + 0x22c);
                  goto LAB_0062cee8;
                }
LAB_0062ceff:
                if ((uVar9 & 0x200000) == 0) {
                  if ((uVar9 & 0x80000) == 0) goto LAB_0062cf31;
                  fVar2 = *(float *)(param_5 + 0x22c);
                }
                else {
                  fVar2 = *(float *)(param_5 + 0x228);
                }
                if (fVar2 <= *(float *)(param_6 + 0x18)) goto LAB_0062cf31;
              }
              else {
                fVar2 = *(float *)(param_5 + 0x228);
LAB_0062cee8:
                if (*(float *)(param_6 + 0x16) <= fVar2) goto LAB_0062ceff;
              }
            }
            else {
              if (param_5 != 0) {
                if ((((*(uint *)(param_6 + 10) & 0x40) != 0) && (*(char *)(param_5 + 0x286) != '\0')
                    ) || (((*(uint *)(param_6 + 10) & 0x20) != 0 &&
                          (*(char *)(param_5 + 0x286) == '\0')))) goto LAB_0062c945;
                goto LAB_0062ceba;
              }
LAB_0062cf31:
              if (((iVar15 != 0) && (sVar4 = param_6[1], sVar4 != -1)) &&
                 ((int)sVar4 < *(int *)(param_10 + 4))) {
                uVar9 = *(uint *)(param_6 + 10);
                if ((uVar9 & 1) == 0) {
                  if ((((uVar9 & 0x1000) == 0) && ((uVar9 & 0x800) == 0)) && (local_12c != 0)) {
                    if (0 < iVar15) {
                      puVar8 = &local_100;
                      do {
                        FUN_0062c560(param_10,(int)param_6[1],puVar8);
                        puVar8 = puVar8 + 3;
                        iVar15 = iVar15 + -1;
                      } while (iVar15 != 0);
                    }
                  }
                  else {
                    FUN_0062c560(param_10,(int)sVar4,&local_120);
                  }
                }
                else {
                  if (*(float *)(param_6 + 8) <= 0.0) {
                    uVar9 = (uint)*(byte *)((int)param_6 + 0x1b);
                  }
                  else if ((uVar9 & 0x800000) == 0) {
                    uVar9 = FUN_0062c300(*(undefined4 *)(param_6 + 8),param_8);
                  }
                  else {
                    uVar9 = FUN_0062c350(*(undefined4 *)(param_6 + 8));
                  }
                  if ((int)uVar9 < 0) {
                    uVar9 = 1;
                  }
                  else if ((int)uVar9 < 1) goto LAB_0062d276;
                  if (((char)param_6[0xd] == '\0') ||
                     (uVar10 = FUN_005b9e30(),
                     uVar10 >> 0x10 <= (uint)*(byte *)(param_6 + 0xd) * 0x100)) {
                    uVar10 = *(uint *)(param_6 + 10);
                    if ((uVar10 & 0x1000) == 0) {
                      if ((uVar10 & 0x800) == 0) {
                        if (local_12c == 0) {
                          if (((uVar10 & 0x400000) == 0) || (param_5 == 0)) {
                            FUN_0062c680(param_10,(int)param_6[1],&local_120,uVar9,0,0);
                          }
                          else {
                            FUN_0062c760(param_10,(int)param_6[1],&local_120,uVar9,param_5 + 0x68);
                          }
                        }
                        else if (0 < local_12c) {
                          puVar8 = &local_100;
                          local_124 = (int *)param_4;
                          do {
                            if (((*(uint *)(param_6 + 10) & 0x400000) == 0) || (param_5 == 0)) {
                              if ((*(uint *)(param_6 + 10) & 0x4000000) == 0) {
                                FUN_0062c680(param_10,(int)param_6[1],puVar8,uVar9,0,0);
                              }
                              else {
                                FUN_0062c6d0(param_10,(int)param_6[1],puVar8,uVar9,local_124);
                              }
                            }
                            else {
                              FUN_005b3800(auStack_10c,param_5 + 0x5c,param_5 + 0x8c);
                              fStack_110 = 1.0 / param_8;
                              FUN_005b3830(auStack_10c,auStack_10c,fStack_110);
                              FUN_0062c760(param_10,(int)param_6[1],puVar8,uVar9,auStack_10c);
                            }
                            local_124 = (int *)((int)local_124 + 0x40);
                            puVar8 = puVar8 + 3;
                            local_12c = local_12c + -1;
                          } while (local_12c != 0);
                        }
                      }
                      else if (((uVar10 & 0x400000) == 0) || (param_5 == 0)) {
                        FUN_0062c680(param_10,(int)param_6[1],&local_120,uVar9,0,0);
                      }
                      else {
                        FUN_0062c760(param_10,(int)param_6[1],&local_120,uVar9,param_5 + 0x68);
                      }
                    }
                    else if (((uVar10 & 0x400000) == 0) || (param_5 == 0)) {
                      FUN_0062c680(param_10,(int)param_6[1],&local_120,uVar9,0,0);
                    }
                    else {
                      FUN_0062c760(param_10,(int)param_6[1],&local_120,uVar9,param_5 + 0x68);
                    }
                  }
                }
              }
            }
LAB_0062d276:
            FUN_006dea60();
            if (((DAT_029a99b0 != (code *)0x0) && (param_5 != 0)) &&
               (sVar4 = param_6[0x14], sVar4 != -1)) {
              if ((*(uint *)(param_6 + 10) & 0x8000) == 0) {
                (*DAT_029a99b0)((int)sVar4,0);
              }
              else {
                (*DAT_029a99b0)((int)sVar4,param_5 + 0x80);
              }
            }
          }
        }
      }
    }
LAB_0062c945:
    param_6 = param_6 + 0x1a;
    sVar4 = *param_6;
  } while( true );
}

