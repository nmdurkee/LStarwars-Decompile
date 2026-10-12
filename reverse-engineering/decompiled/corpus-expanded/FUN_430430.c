/* Ghidra pseudocode, not original source.
 * ev_e7751f4f01b1073429001044a4e8501ad85e4023b91c3e954e91fa81cbba79ed
 * Entry: 0x430430; label: FUN_00430430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00430430(void)

{
  float fVar1;
  char cVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined2 uVar8;
  byte *pbVar9;
  uint uVar10;
  char *pcVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  uint *puVar16;
  undefined8 uVar17;
  int local_8;
  
  iVar14 = DAT_0093d504;
  iVar12 = DAT_0093d500;
  _DAT_00876848 = 0;
  _DAT_0087684c = 0;
  _DAT_00876850 = 0;
  _DAT_00876854 = 0;
  if (0 < DAT_0093d500) {
    pbVar9 = (byte *)(DAT_0093d504 + 0x378);
    iVar15 = DAT_0093d500;
    do {
      if ((((*(uint *)(pbVar9 + -0x17c) & 0x1000) != 0) && (pbVar9[-0xed] == 0)) && (*pbVar9 != 0))
      {
        (&DAT_00876847)[*pbVar9] = (&DAT_00876847)[*pbVar9] + '\x01';
      }
      pbVar9 = pbVar9 + 0x10d8;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
  }
  local_8 = 0;
  if (0 < iVar12) {
    do {
      uVar10 = *(uint *)(iVar14 + 0x1fc);
      if ((uVar10 & 1) != 0) {
        uVar4 = *(uint *)(iVar14 + 0x1f8);
        if ((uVar4 & 0x40000) == 0) {
          if ((uVar10 & 0x1000) == 0) {
            if (*(byte *)(iVar14 + 0x400) == 0xff) {
              if (*(char *)(iVar14 + 0x406) == '\x01') {
                fVar1 = *(float *)(iVar14 + 0x4c8) - _DAT_00925018;
                *(float *)(iVar14 + 0x4c8) = fVar1;
                if (fVar1 < 0.0 != (fVar1 == 0.0)) {
                  *(undefined4 *)(iVar14 + 0x4c8) = 0;
                  *(uint *)(iVar14 + 0x1fc) = uVar10 | 0x1000;
                  *(undefined1 *)(iVar14 + 0x406) = 2;
                }
              }
              else if (*(char *)(iVar14 + 0x406) != '\x03') {
                if ((uVar4 & 0x4000) != 0) goto LAB_00430eec;
                iVar12 = *(int *)(iVar14 + 0x40c);
                if (iVar12 != 0) {
                  iVar15 = 0;
                  pcVar11 = (char *)(iVar12 + 0x81);
                  do {
                    if (*pcVar11 != '\0') {
                      iVar15 = 0;
                      if (*(char *)(iVar12 + 7) != '\0') {
                        iVar12 = 0xc;
                        do {
                          piVar13 = (int *)(*(int *)(iVar14 + 0x40c) + iVar12);
                          if (*piVar13 == iVar14) {
                            *piVar13 = 0;
                          }
                          iVar15 = iVar15 + 1;
                          iVar12 = iVar12 + 4;
                        } while (iVar15 < (int)(uint)*(byte *)(*(int *)(iVar14 + 0x40c) + 7));
                      }
                      goto LAB_004305b6;
                    }
                    iVar15 = iVar15 + 1;
                    pcVar11 = pcVar11 + 0x34;
                  } while (iVar15 < 4);
                  FUN_005181e0(iVar12);
                }
LAB_004305b6:
                FUN_004d22f0(iVar14 + 0xcc4);
                FUN_0055cad0(iVar14,1);
              }
            }
            else {
              iVar12 = *(int *)(PTR_DAT_00802c54 + 0x2ae8);
              iVar15 = (uint)*(byte *)(iVar14 + 0x400) * 0xa4 + *(int *)(iVar12 + 0x18);
              if (*(char *)(iVar14 + 0x406) == '\0') {
                cVar2 = *(char *)(iVar15 + 0x87);
                if (cVar2 == '\0') {
                  if (DAT_008668c8._1_1_ < *(byte *)(iVar15 + 0x84)) {
LAB_00430d6e:
                    *(undefined1 *)(iVar14 + 0x406) = 4;
                  }
                  else {
                    FUN_0041c120(iVar14,iVar12);
                  }
                }
                else if (cVar2 == '\x01') {
                  if (*(int *)(iVar15 + 0x74) == 0) {
                    *(undefined1 *)(iVar15 + 0x87) = 0;
                  }
                  else if ((DAT_0093d810 != 0) &&
                          (uVar10 = 1 << ((byte)(*(int *)(iVar15 + 0x74) - *(int *)(iVar12 + 0x38)
                                                >> 6) & 0x1f),
                          (uVar10 & *(uint *)(DAT_0093d810 + 0x2b0)) != 0 ||
                          ((int)uVar10 >> 0x1f & *(uint *)(DAT_0093d810 + 0x2b4)) != 0)) {
                    if (DAT_008668c8._1_1_ < *(byte *)(iVar15 + 0x84)) {
                      *(undefined1 *)(iVar14 + 0x406) = 4;
                    }
                    else if (((*(byte *)(iVar15 + 0x50) < 2) || (*(float *)(iVar15 + 0x90) <= 0.0))
                            || (*(byte *)(iVar14 + 0x410) == 0)) {
                      FUN_0041c120(iVar14,iVar12);
                    }
                    else {
                      fVar1 = *(float *)(iVar15 + 0x90);
                      *(undefined1 *)(iVar14 + 0x406) = 1;
                      *(float *)(iVar14 + 0x4c8) = (float)*(byte *)(iVar14 + 0x410) * fVar1;
                    }
                  }
                }
                else if ((cVar2 == '\x02') && (*(byte *)(iVar15 + 0x84) <= DAT_008668c8._1_1_)) {
                  FUN_0052cc90(iVar12,iVar14,iVar14 + 0x2c8,iVar14 + 0x2c8,_DAT_00925018);
                }
              }
              else if ((*(char *)(iVar14 + 0x406) == '\x01') &&
                      ((iVar5 = *(int *)(iVar14 + 0x40c), iVar5 == 0 ||
                       ((*(byte *)(iVar5 + 0x50) & 2) != 0)))) {
                if ((*(char *)(iVar15 + 0x87) == '\x01') &&
                   (((DAT_0093d810 == 0 ||
                     (uVar10 = 1 << ((byte)(*(int *)(iVar15 + 0x74) - *(int *)(iVar12 + 0x38) >> 6)
                                    & 0x1f),
                     (uVar10 & *(uint *)(DAT_0093d810 + 0x2b0)) == 0 &&
                     ((int)uVar10 >> 0x1f & *(uint *)(DAT_0093d810 + 0x2b4)) == 0)) ||
                    (DAT_008668c8._1_1_ < *(byte *)(iVar15 + 0x84))))) {
                  if ((1 < *(byte *)(iVar15 + 0x50)) && (0.0 < *(float *)(iVar15 + 0x90))) {
                    *(float *)(iVar14 + 0x4c8) =
                         (float)*(byte *)(iVar14 + 0x410) * *(float *)(iVar15 + 0x90);
                  }
                }
                else {
                  fVar1 = *(float *)(iVar14 + 0x4c8) - _DAT_00925018;
                  *(float *)(iVar14 + 0x4c8) = fVar1;
                  if (fVar1 < 0.0 != (fVar1 == 0.0)) {
                    if (iVar5 == 0) {
                      *(undefined4 *)(iVar14 + 0x4c8) = 0;
                      if (*(short *)(iVar14 + 0x1064) == DAT_007f18b8) {
                        FUN_0041c120(iVar14,*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8));
                        FUN_004302e0(iVar14,0x40400000,0);
                      }
                      else {
                        FUN_0041c120(iVar14,*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8));
                      }
                    }
                    else {
                      uVar6 = *(undefined4 *)(iVar14 + 0x36c);
                      uVar7 = *(undefined4 *)(iVar14 + 0x478);
                      iVar12 = 0;
                      if (*(char *)(iVar5 + 7) != '\0') {
                        iVar15 = 0xc;
                        do {
                          if (*(int *)(iVar15 + *(int *)(iVar14 + 0x40c)) != 0) {
                            iVar5 = **(int **)(iVar15 + *(int *)(iVar14 + 0x40c));
                            *(undefined4 *)(iVar5 + 0x4c8) = 0;
                            *(undefined4 *)(iVar5 + 0x36c) = uVar6;
                            *(undefined4 *)(iVar5 + 0x478) = uVar7;
                            FUN_0041c120(iVar5,*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8));
                            piVar13 = *(int **)(iVar14 + 0x40c);
                            if (*piVar13 == 0) {
                              *piVar13 = *(int *)(iVar15 + (int)piVar13);
                            }
                          }
                          iVar12 = iVar12 + 1;
                          iVar15 = iVar15 + 4;
                        } while (iVar12 < (int)(uint)*(byte *)(*(int *)(iVar14 + 0x40c) + 7));
                      }
                      puVar16 = (uint *)(*(int *)(iVar14 + 0x40c) + 0x50);
                      *puVar16 = *puVar16 & 0xfffffff7;
                      puVar16 = (uint *)(*(int *)(iVar14 + 0x40c) + 0x50);
                      *puVar16 = *puVar16 & 0xfffffffb;
                    }
                  }
                }
              }
            }
          }
          else if (*(char *)(iVar14 + 0x28b) != '\0') {
            if (*(code **)(iVar14 + 0xea8) != (code *)0x0) {
              (**(code **)(iVar14 + 0xea8))(iVar14);
              *(undefined4 *)(iVar14 + 0xea8) = 0;
            }
            if (*(float *)(iVar14 + 0x1010) <= 0.0) {
              fVar1 = *(float *)(iVar14 + 0x1008) + _DAT_00925018;
              *(float *)(iVar14 + 0x1008) = fVar1;
              if (*(float *)(iVar14 + 0x100c) < fVar1 != (*(float *)(iVar14 + 0x100c) == fVar1)) {
                iVar12 = 0;
                *(undefined4 *)(iVar14 + 0x1008) = *(undefined4 *)(iVar14 + 0x100c);
                if (0 < DAT_0093d500) {
                  puVar16 = (uint *)(DAT_0093d504 + 0x2a8);
                  do {
                    uVar10 = *(uint *)(iVar14 + 0x1ec);
                    puVar16[-0x2e] = puVar16[-0x2e] & ~*(uint *)(iVar14 + 0x1e8);
                    puVar16[-0x2d] = puVar16[-0x2d] & ~uVar10;
                    uVar17 = __allshl();
                    *puVar16 = *puVar16 & ~(uint)uVar17;
                    puVar16[1] = puVar16[1] & ~(uint)((ulonglong)uVar17 >> 0x20);
                    uVar17 = __allshl();
                    puVar16[0x302] = puVar16[0x302] & ~(uint)uVar17;
                    puVar16[0x303] = puVar16[0x303] & ~(uint)((ulonglong)uVar17 >> 0x20);
                    uVar17 = __allshl();
                    puVar16[0x304] = puVar16[0x304] & ~(uint)uVar17;
                    puVar16[0x305] = puVar16[0x305] & ~(uint)((ulonglong)uVar17 >> 0x20);
                    iVar12 = iVar12 + 1;
                    puVar16 = puVar16 + 0x436;
                  } while (iVar12 < DAT_0093d500);
                }
                if ((*(uint *)(iVar14 + 0x1f8) & 0x4000) == 0) {
                  if ((*(uint *)(iVar14 + 0xeec) & 0x100000) == 0) {
                    iVar12 = *(int *)(iVar14 + 0x40c);
                    if (iVar12 != 0) {
                      iVar15 = 0;
                      pcVar11 = (char *)(iVar12 + 0x81);
                      do {
                        if (*pcVar11 != '\0') {
                          iVar15 = 0;
                          if (*(char *)(iVar12 + 7) != '\0') {
                            iVar12 = 0xc;
                            do {
                              piVar13 = (int *)(*(int *)(iVar14 + 0x40c) + iVar12);
                              if (*piVar13 == iVar14) {
                                *piVar13 = 0;
                              }
                              iVar15 = iVar15 + 1;
                              iVar12 = iVar12 + 4;
                            } while (iVar15 < (int)(uint)*(byte *)(*(int *)(iVar14 + 0x40c) + 7));
                          }
                          goto LAB_00430e86;
                        }
                        iVar15 = iVar15 + 1;
                        pcVar11 = pcVar11 + 0x34;
                      } while (iVar15 < 4);
                      FUN_005181e0(iVar12);
                    }
LAB_00430e86:
                    FUN_004d22f0(iVar14 + 0xcc4);
                    FUN_0055cad0(iVar14,1);
                  }
                  else {
LAB_00430e14:
                    *(undefined4 *)(iVar14 + 0x1010) = 0x3f800000;
                  }
                }
                else if ((*(uint *)(iVar14 + 0x1f8) & 0x400) == 0) {
                  *(undefined4 *)(iVar14 + 0x1010) = 0x40000000;
                }
                else {
                  iVar12 = (uint)*(byte *)(iVar14 + 0x400) * 0xa4 +
                           *(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ae8) + 0x18);
                  if ((*(uint *)(iVar14 + 0xeec) >> 0x14 & 1) == 0) {
                    if ((*(char *)(iVar12 + 0x86) == -1) || (*(int *)(iVar14 + 0x478) != 0)) {
                      uVar10 = *(int *)(iVar14 + 0x4c4) + 1;
                    }
                    else {
                      uVar10 = (int)(((int)*(char *)(iVar12 + 0x86) - (int)*(char *)(iVar12 + 0x85))
                                    * (DAT_008668c8._1_1_ - 1)) / 9 + 1 +
                               (int)*(char *)(iVar12 + 0x85);
                    }
                    if (uVar10 <= *(uint *)(iVar14 + 0x4c4)) {
                      *(uint *)(iVar14 + 0x1fc) = *(uint *)(iVar14 + 0x1fc) & 0xffffefff;
                      goto LAB_00430d6e;
                    }
                  }
                  else if ((*(uint *)(iVar14 + 0xeec) >> 0x15 & 1) == 0) {
                    if ((*(short *)(iVar14 + 0x1064) != DAT_007f19bc) ||
                       (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b054)) goto LAB_00430e14;
                    *(undefined4 *)(iVar14 + 0x1010) = 0x40a00000;
                    goto LAB_004308cc;
                  }
                  *(uint *)(iVar14 + 0x1fc) = *(uint *)(iVar14 + 0x1fc) & 0xffffefff;
                  *(undefined1 *)(iVar14 + 0x406) = 1;
                  fVar1 = 1.0 - ((float)DAT_008668c8._1_1_ - 1.0) / 9.0;
                  *(float *)(iVar14 + 0x4c8) = fVar1;
                  *(float *)(iVar14 + 0x4c8) =
                       fVar1 * *(float *)(iVar12 + 0x8c) + *(float *)(iVar12 + 0x88) * (1.0 - fVar1)
                  ;
                }
              }
            }
            else {
              fVar1 = *(float *)(iVar14 + 0x1010) - _DAT_00925018;
              *(float *)(iVar14 + 0x1010) = fVar1;
              if (fVar1 < 0.0 == (fVar1 == 0.0)) {
                if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0a0) &&
                   (iVar12 = FUN_0041a4d0(iVar14), iVar12 != 0)) {
                  *(undefined4 *)(iVar14 + 0x5c) = *(undefined4 *)(iVar12 + 0x5c);
                  *(undefined4 *)(iVar14 + 0x60) = *(undefined4 *)(iVar12 + 0x60);
                  *(undefined4 *)(iVar14 + 100) = *(undefined4 *)(iVar12 + 100);
                }
              }
              else {
                *(undefined4 *)(iVar14 + 0x1010) = 0;
                if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0a0) &&
                   (iVar12 = FUN_0041a4d0(iVar14), iVar12 != 0)) {
                  *(undefined4 *)(iVar14 + 0x8c) = *(undefined4 *)(iVar12 + 0x5c);
                  *(undefined4 *)(iVar14 + 0x90) = *(undefined4 *)(iVar12 + 0x60);
                  uVar6 = *(undefined4 *)(iVar12 + 100);
                  *(undefined4 *)(iVar14 + 0x94) = uVar6;
                  *(undefined4 *)(iVar14 + 0x5c) = *(undefined4 *)(iVar14 + 0x8c);
                  *(undefined4 *)(iVar14 + 0x10bc) = *(undefined4 *)(iVar14 + 0x8c);
                  *(undefined4 *)(iVar14 + 0x60) = *(undefined4 *)(iVar14 + 0x90);
                  *(undefined4 *)(iVar14 + 0x10c0) = *(undefined4 *)(iVar14 + 0x90);
                  *(undefined4 *)(iVar14 + 100) = uVar6;
                  *(undefined4 *)(iVar14 + 0x10c4) = uVar6;
                  FUN_0055d2b0(iVar14);
                  *(undefined4 *)(iVar14 + 0x68) = *(undefined4 *)(iVar12 + 0x68);
                  *(undefined4 *)(iVar14 + 0x6c) = *(undefined4 *)(iVar12 + 0x6c);
                  *(undefined4 *)(iVar14 + 0x70) = *(undefined4 *)(iVar12 + 0x70);
                  uVar8 = *(undefined2 *)(iVar12 + 0x27a);
                  *(undefined2 *)(iVar14 + 0x5a) = uVar8;
                }
                else {
                  FUN_0055cd80(iVar14);
                  FUN_0055d2b0(iVar14);
                  uVar8 = *(undefined2 *)(iVar14 + 0x5a);
                  *(undefined4 *)(iVar14 + 0x70) = 0;
                  *(undefined4 *)(iVar14 + 0x68) = 0;
                  *(undefined4 *)(iVar14 + 0x6c) = 0xbdcccccd;
                }
                uVar10 = *(uint *)(iVar14 + 0x1fc);
                *(undefined2 *)(iVar14 + 0x27a) = uVar8;
                *(undefined2 *)(iVar14 + 0x58) = uVar8;
                FUN_0041af70(iVar14);
                *(undefined1 *)(iVar14 + 0x28b) = 0;
                *(uint *)(iVar14 + 0x1fc) =
                     *(uint *)(iVar14 + 0x1fc) ^
                     ((uVar10 >> 0xd & 1) << 0xd ^ *(uint *)(iVar14 + 0x1fc)) & 0x2000;
                *(undefined1 *)(iVar14 + 0x107f) = *(undefined1 *)(iVar14 + 0x107e);
                uVar3 = *(undefined1 *)(*(int *)(*(int *)(iVar14 + 0x54) + 0x24) + 0xf5);
                *(uint *)(iVar14 + 0xef0) = *(uint *)(iVar14 + 0xef0) | 0x80;
                *(undefined1 *)(iVar14 + 0xe38) = uVar3;
                *(undefined1 *)(iVar14 + 0xe39) = 4;
                *(undefined1 *)(iVar14 + 0x7b5) = 0xff;
                if (*(char *)(iVar14 + 0x280) != -1) {
                  *(undefined4 *)(iVar14 + 0x1000) = 0x40200000;
                }
                FUN_0052f800(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar14,iVar14 + 0x2c8,0xff,1
                            );
                iVar12 = *(int *)(iVar14 + 0xcd4);
                if ((iVar12 != 0) &&
                   ((((*(int *)(iVar12 + 0xcd0) == 0 || (*(int *)(iVar12 + 0xcd0) == iVar14)) &&
                     ((*(uint *)(iVar12 + 0x1fc) & 0x1000) != 0)) &&
                    ((*(char *)(iVar12 + 0x7b5) != '+' && (*(char *)(iVar12 + 0x28b) == '\0')))))) {
                  FUN_004871a0(iVar12,iVar14 + 0x5c);
                  FUN_00488730(iVar14,*(undefined4 *)(iVar14 + 0xcd4),0,1);
                }
                if ((((*(byte *)(iVar14 + 0x1fc) & 0x80) != 0) &&
                    (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234)) && (DAT_009253a4 == 0)) {
                  FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,0,0);
                }
              }
            }
          }
        }
        else if ((((DAT_00951b54 != 0) && ((uVar10 & 0x1000) == 0)) &&
                 ((*(char *)(iVar14 + 0x400) == -1 &&
                  ((*(char *)(iVar14 + 0x406) != '\x01' && (*(char *)(iVar14 + 0x406) != '\x03')))))
                 ) && ((uVar4 & 0x4000) != 0)) {
LAB_00430eec:
          FUN_0052cc90(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar14,iVar14 + 0x2c8,
                       iVar14 + 0x2c8,_DAT_00925018);
        }
      }
LAB_004308cc:
      local_8 = local_8 + 1;
      iVar14 = iVar14 + 0x10d8;
    } while (local_8 < DAT_0093d500);
  }
  return;
}

