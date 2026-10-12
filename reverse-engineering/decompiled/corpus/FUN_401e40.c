/* Ghidra analysis pseudocode, not original source.
 * ev_4eb19e57a9d3b9beba017312b3b21652588e9c732adfcebbbddaeb757a53089f
 * Entry: 0x401e40; label: FUN_00401e40
 */

void FUN_00401e40(int *param_1)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  byte bVar9;
  uint uVar10;
  int extraout_ECX;
  ushort uVar11;
  int *piVar12;
  int iVar13;
  bool bVar14;
  float10 fVar15;
  int *local_40;
  int local_3c;
  int *local_38;
  int local_34;
  int local_30;
  int local_2c;
  float local_28;
  int local_24;
  uint local_1c;
  uint local_18;
  undefined1 local_c [12];
  
  local_1c = 0;
  local_18 = 0;
  if ((param_1 != (int *)0x0) && (DAT_0093d810 != 0)) {
    local_2c = 0;
    piVar12 = param_1;
    do {
      bVar14 = false;
      if ((*(byte *)(piVar12 + 0x84) & 1) != 0) {
        bVar2 = false;
        if ((*piVar12 != 0) && ((*(byte *)(*piVar12 + 10) & 2) != 0)) {
          bVar2 = true;
        }
        iVar13 = 0;
        local_38 = piVar12;
        bVar3 = false;
        if ((char)piVar12[0x83] != '\0') {
          do {
            bVar14 = bVar3;
            local_38 = local_38 + 1;
            cVar1 = *(char *)((int)piVar12 + iVar13 + 0x204);
            if (cVar1 != -1) {
              bVar14 = true;
            }
            piVar8 = (int *)*local_38;
            bVar9 = (byte)iVar13;
            if (piVar8 == (int *)0x0) {
              *(ushort *)((int)piVar12 + 0x20e) =
                   *(ushort *)((int)piVar12 + 0x20e) & ~(ushort)(1 << (bVar9 & 0x1f));
              cVar1 = *(char *)((int)piVar12 + iVar13 + 0x204);
              if (cVar1 != -1) {
                *(undefined1 *)(cVar1 + 0x4280 + (int)param_1) = 0xff;
                *(undefined1 *)(*(char *)((int)piVar12 + iVar13 + 0x204) + 0x42c0 + (int)param_1) =
                     0xff;
                *(undefined1 *)((int)piVar12 + iVar13 + 0x204) = 0xff;
              }
            }
            else {
              uVar10 = (uint)*(byte *)((int)piVar8 + 6);
              if (uVar10 == DAT_007faaa4) {
                iVar7 = *piVar8;
                if ((*(char *)(DAT_0093d810 + 0x7b5) == 'J') &&
                   (*(int *)(DAT_0093d810 + 0x798) == iVar7)) {
                  *(ushort *)((int)piVar12 + 0x20e) =
                       *(ushort *)((int)piVar12 + 0x20e) | (ushort)(1 << (bVar9 & 0x1f));
                }
                else if ((DAT_0093d814 == 0) ||
                        ((*(char *)(DAT_0093d814 + 0x7b5) != 'J' ||
                         (*(int *)(DAT_0093d814 + 0x798) != iVar7)))) {
                  if ((((uint)*(ushort *)((int)piVar12 + 0x20e) & 1 << (bVar9 & 0x1f)) != 0) &&
                     (iVar5 = FUN_00490b70(iVar7), iVar5 == 0)) {
                    *(ushort *)((int)piVar12 + 0x20e) =
                         *(ushort *)((int)piVar12 + 0x20e) & ~(ushort)(1 << (bVar9 & 0x1f));
                  }
                }
                else {
                  *(ushort *)((int)piVar12 + 0x20e) =
                       *(ushort *)((int)piVar12 + 0x20e) | (ushort)(1 << (bVar9 & 0x1f));
                }
                iVar5 = FUN_00490b70(iVar7);
                if ((iVar5 != 0) && (cVar1 = *(char *)((int)piVar12 + iVar13 + 0x204), cVar1 != -1))
                {
                  iVar5 = (int)cVar1;
                  iVar6 = iVar5 * 0x10d8 + DAT_0093d504;
                  uVar10 = *(uint *)(iVar6 + 0x1fc);
                  if (((uVar10 & 1) == 0) ||
                     (((uVar10 & 0x1000) == 0 ||
                      (iVar7 = FUN_00401e10(iVar6,iVar7), iVar5 = extraout_ECX, iVar7 == 0)))) {
                    *(undefined1 *)(iVar5 + 0x4280 + (int)param_1) = 0xff;
                    *(undefined1 *)
                     (*(char *)((int)piVar12 + iVar13 + 0x204) + 0x42c0 + (int)param_1) = 0xff;
                    *(undefined1 *)((int)piVar12 + iVar13 + 0x204) = 0xff;
                  }
                }
              }
              else if (uVar10 == DAT_00802644) {
                iVar7 = *piVar8;
                if (DAT_0093d810 == *(int *)(iVar7 + 0x38)) goto LAB_00402001;
                if ((DAT_0093d814 == 0) || (DAT_0093d814 != *(int *)(iVar7 + 0x38))) {
                  uVar11 = *(ushort *)((int)piVar12 + 0x20e);
                  if (((uint)uVar11 & 1 << (bVar9 & 0x1f)) == 0) {
                    if (((*(uint *)(iVar7 + 0x94) & 2) == 0) || ((*(uint *)(iVar7 + 0x94) & 1) == 0)
                       ) {
joined_r0x004025af:
                      if (cVar1 != -1) {
                        *(undefined1 *)(cVar1 + 0x4280 + (int)param_1) = 0xff;
                        *(undefined1 *)
                         (*(char *)((int)piVar12 + iVar13 + 0x204) + 0x42c0 + (int)param_1) = 0xff;
                        *(undefined1 *)((int)piVar12 + iVar13 + 0x204) = 0xff;
                      }
                    }
                  }
                  else if ((*(int *)(iVar7 + 0x34) != 0) &&
                          (((iVar7 = *(int *)(*(int *)(iVar7 + 0x34) + 0xc), iVar7 == 0 ||
                            (iVar7 == 3)) || (iVar7 == 4)))) {
LAB_00402066:
                    *(ushort *)((int)piVar12 + 0x20e) = ~(ushort)(1 << (bVar9 & 0x1f)) & uVar11;
                  }
                }
                else {
LAB_00402021:
                  *(ushort *)((int)piVar12 + 0x20e) =
                       *(ushort *)((int)piVar12 + 0x20e) | (ushort)(1 << (bVar9 & 0x1f));
                }
              }
              else if (uVar10 == DAT_008025d4) {
                iVar7 = *piVar8;
                if (((*(byte *)(iVar7 + 0xac) & 6) == 0) &&
                   (((((*(byte *)(iVar7 + 0xac) & 8) == 0 || (DAT_0087baf0 != 0)) &&
                     (*(float *)(iVar7 + 0x70) != 1.0)) && ((*(byte *)(iVar7 + 0x84) & 0x20) == 0)))
                   ) {
                  if ((*(char *)(DAT_0093d810 + 0x7b5) == '(') &&
                     (*(int *)(DAT_0093d810 + 0x798) == iVar7)) goto LAB_00402021;
                  if ((DAT_0093d814 != 0) &&
                     ((*(char *)(DAT_0093d814 + 0x7b5) == '(' &&
                      (*(int *)(DAT_0093d814 + 0x798) == iVar7)))) goto LAB_00402001;
                  if ((((uint)*(ushort *)((int)piVar12 + 0x20e) & 1 << (bVar9 & 0x1f)) != 0) &&
                     (*(char *)(iVar7 + 0x89) == -1)) {
                    *(ushort *)((int)piVar12 + 0x20e) =
                         ~(ushort)(1 << (bVar9 & 0x1f)) & *(ushort *)((int)piVar12 + 0x20e);
                  }
                }
                else {
LAB_004025e1:
                  *(ushort *)((int)piVar12 + 0x20e) =
                       *(ushort *)((int)piVar12 + 0x20e) & ~(ushort)(1 << (bVar9 & 0x1f));
                }
              }
              else {
                if (uVar10 == DAT_007f8cc4) {
                  iVar7 = *piVar8;
                  iVar5 = FUN_004678f0(DAT_0093d810,iVar7);
                  if (iVar5 != 0) goto LAB_00402001;
                  iVar5 = FUN_004678f0(DAT_0093d814,iVar7);
                  uVar10 = 1 << (bVar9 & 0x1f);
                  uVar11 = (ushort)uVar10;
                  if (iVar5 == 0) {
                    if ((*(ushort *)((int)piVar12 + 0x20e) & uVar10) == 0) {
                      iVar7 = FUN_00467890(iVar7);
                      if ((iVar7 != 0) &&
                         (cVar1 = *(char *)((int)piVar12 + iVar13 + 0x204), cVar1 != -1)) {
                        *(undefined1 *)(cVar1 + 0x4280 + (int)param_1) = 0xff;
                        *(undefined1 *)
                         (*(char *)((int)piVar12 + iVar13 + 0x204) + 0x42c0 + (int)param_1) = 0xff;
                        *(undefined1 *)((int)piVar12 + iVar13 + 0x204) = 0xff;
                      }
                    }
                    else {
                      *(ushort *)((int)piVar12 + 0x20e) =
                           ~(ushort)(1 << (bVar9 & 0x1f)) & *(ushort *)((int)piVar12 + 0x20e);
                    }
                    goto LAB_0040207e;
                  }
                }
                else {
                  if (uVar10 != DAT_00802460) goto LAB_004025e1;
                  iVar7 = *piVar8;
                  if (cVar1 == -1) {
                    iVar5 = 0;
                  }
                  else {
                    iVar5 = cVar1 * 0x10d8 + DAT_0093d504;
                  }
                  if ((*(char *)(DAT_0093d810 + 0x7b5) == DAT_00802874) &&
                     (*(int *)(DAT_0093d810 + 0x798) == iVar7)) goto LAB_00402021;
                  if ((DAT_0093d814 == 0) ||
                     ((*(char *)(DAT_0093d814 + 0x7b5) != DAT_00802874 ||
                      (*(int *)(DAT_0093d814 + 0x798) != iVar7)))) {
                    uVar11 = *(ushort *)((int)piVar12 + 0x20e);
                    if (((uint)uVar11 & 1 << (bVar9 & 0x1f)) != 0) goto LAB_00402066;
                    iVar7 = FUN_0054d410(iVar7,iVar5,0);
                    if (iVar7 != 0) {
                      cVar1 = *(char *)((int)piVar12 + iVar13 + 0x204);
                      goto joined_r0x004025af;
                    }
                    goto LAB_0040207e;
                  }
LAB_00402001:
                  uVar11 = (ushort)(1 << (bVar9 & 0x1f));
                }
                *(ushort *)((int)piVar12 + 0x20e) = *(ushort *)((int)piVar12 + 0x20e) | uVar11;
              }
            }
LAB_0040207e:
            iVar13 = iVar13 + 1;
            bVar3 = bVar14;
          } while (iVar13 < (int)(uint)*(byte *)(piVar12 + 0x83));
        }
        local_30 = (DAT_0093d814 != 0) + 1;
        if (((*(short *)((int)piVar12 + 0x20e) == 0) && ((*(byte *)(piVar12 + 0x84) & 2) == 0)) ||
           (bVar2)) {
          if ((bVar14) && ((char)piVar12[0x83] != '\0')) {
            piVar8 = piVar12 + 0x81;
            do {
              if ((char)*piVar8 != -1) {
                *(undefined1 *)((char)*piVar8 + 0x4280 + (int)param_1) = 0xff;
                *(undefined1 *)((char)*piVar8 + 0x42c0 + (int)param_1) = 0xff;
                *(char *)piVar8 = -1;
              }
              piVar8 = (int *)((int)piVar8 + 1);
            } while ((int)((-0x204 - (int)piVar12) + (int)piVar8) <
                     (int)(uint)*(byte *)(piVar12 + 0x83));
          }
        }
        else {
          if (((bVar14) && (*(short *)((int)piVar12 + 0x20e) == 0)) && ((char)piVar12[0x83] != '\0')
             ) {
            piVar8 = piVar12 + 0x81;
            do {
              cVar1 = (char)*piVar8;
              if ((cVar1 != -1) && (*(int **)(cVar1 * 0x10d8 + 0x10d4 + DAT_0093d504) != piVar12)) {
                *(undefined1 *)(cVar1 + 0x4280 + (int)param_1) = 0xff;
                *(undefined1 *)((char)*piVar8 + 0x42c0 + (int)param_1) = 0xff;
                *(char *)piVar8 = -1;
              }
              piVar8 = (int *)((int)piVar8 + 1);
            } while ((int)((-0x204 - (int)piVar12) + (int)piVar8) <
                     (int)(uint)*(byte *)(piVar12 + 0x83));
          }
          local_3c = 0;
          if ((char)piVar12[0x83] != '\0') {
            local_40 = piVar12 + 0x12;
            local_38 = piVar12;
            do {
              local_38 = local_38 + 1;
              if ((int)(uint)*(byte *)(piVar12 + 0x83) <= local_30) break;
              if (((uint)*(ushort *)((int)piVar12 + 0x20e) & 1 << ((byte)local_3c & 0x1f)) == 0) {
                if (*(char *)(local_3c + 0x204 + (int)piVar12) == -1) {
                  iVar13 = FUN_00401d60();
                  if (iVar13 != 0) {
                    local_28 = 1e+09;
                    uVar11 = *(ushort *)(*local_40 + 0x14);
                    local_24 = -1;
                    if (uVar11 != 0) {
                      iVar13 = local_40[-1];
                      uVar10 = (uint)*(byte *)(iVar13 + 0x14);
                      iVar7 = 0;
                      if (uVar10 != 0) {
                        iVar5 = 0;
                        do {
                          uVar4 = __allshl();
                          if ((uVar4 & uVar11) != 0) {
                            iVar6 = *(int *)(iVar13 + 0x88);
                            local_1c = local_1c | *(uint *)(iVar6 + 0x18 + iVar5);
                            local_18 = local_18 | *(uint *)(iVar6 + 0x1c + iVar5);
                          }
                          iVar7 = iVar7 + 1;
                          iVar5 = iVar5 + 0x28;
                        } while (iVar7 < (int)uVar10);
                      }
                    }
                    iVar13 = 0;
                    if (0 < DAT_0093d500) {
                      local_34 = 0;
                      iVar7 = DAT_0093d504;
                      do {
                        if (*(char *)((int)param_1 + iVar13 + 0x42c0) == -1) {
                          uVar10 = *(uint *)(iVar7 + 0x1fc);
                          if ((((((((uVar10 & 1) != 0) && ((uVar10 & 0x1000) != 0)) &&
                                 (*(char *)(iVar7 + 0x28b) == '\0')) &&
                                ((-1 < (char)uVar10 && ((*(byte *)(iVar7 + 0xef3) & 1) == 0)))) &&
                               ((local_1c == 0 && local_18 == 0 ||
                                ((*(uint *)(iVar7 + 0x3f8) & local_1c) != 0 ||
                                 (*(uint *)(iVar7 + 0x3fc) & local_18) != 0)))) &&
                              ((*(uint *)(iVar7 + 0xef4) & 0x40000) != 0)) &&
                             ((*(short *)((int)piVar12 + 0x20e) != 0 ||
                              (*(int **)(iVar7 + 0x10d4) == piVar12)))) {
                            if (DAT_0093b2a4 == 0) {
                              piVar8 = (int *)*local_38;
                              uVar10 = (uint)*(byte *)((int)piVar8 + 6);
                              if ((uVar10 != DAT_007faaa4) ||
                                 ((*(uint *)(local_34 + 0xef0 + DAT_0093d504) & 0x800000) != 0)) {
                                if (uVar10 == DAT_007f8cc4) {
                                  iVar5 = *piVar8;
                                  if ((*(byte *)(iVar5 + 0x74) & 0x10) != 0) {
                                    iVar6 = FUN_0055bc80(iVar7,1);
                                    if (iVar6 == 0) goto LAB_004026a2;
                                    if ((*(byte *)(iVar5 + 0x74) & 0x10) != 0) goto LAB_00402665;
                                  }
                                  iVar5 = FUN_0055bc80(iVar7,0);
                                  bVar14 = iVar5 == 0;
                                }
                                else if (uVar10 == DAT_00802644) {
                                  bVar14 = *(char *)(*piVar8 + 0x91) == '\a';
                                }
                                else {
                                  if (uVar10 != DAT_00802460) goto LAB_00402665;
                                  bVar14 = (*(byte *)(iVar7 + 0x4bc) & 8) == 0;
                                }
                                if (!bVar14) goto LAB_00402665;
                              }
                            }
                            else {
LAB_00402665:
                              fVar15 = (float10)FUN_005b3c50(local_40 + -5,iVar7 + 0x414,local_c);
                              if ((float)fVar15 < local_28) {
                                local_28 = (float)fVar15;
                                local_24 = iVar13;
                              }
                            }
                          }
                        }
LAB_004026a2:
                        local_34 = local_34 + 0x10d8;
                        iVar13 = iVar13 + 1;
                        iVar7 = iVar7 + 0x10d8;
                      } while (iVar13 < DAT_0093d500);
                      if (local_24 != -1) {
                        *(char *)(local_3c + 0x204 + (int)piVar12) = (char)local_24;
                        *(undefined1 *)(local_24 + 0x4280 + (int)param_1) = (undefined1)local_2c;
                        *(byte *)((int)param_1 + local_24 + 0x42c0) = (byte)local_3c;
                      }
                    }
                  }
                  goto LAB_004026ed;
                }
LAB_004026f7:
                local_30 = local_30 + 1;
              }
              else {
LAB_004026ed:
                if (*(char *)(local_3c + 0x204 + (int)piVar12) != -1) goto LAB_004026f7;
              }
              local_40 = local_40 + 0xf;
              local_3c = local_3c + 1;
            } while (local_3c < (int)(uint)*(byte *)(piVar12 + 0x83));
          }
        }
        *(ushort *)(piVar12 + 0x84) = *(ushort *)(piVar12 + 0x84) & 0xfffd;
      }
      local_2c = local_2c + 1;
      piVar12 = piVar12 + 0x85;
    } while (local_2c < 0x20);
  }
  return;
}

