/* Ghidra pseudocode, not original source.
 * ev_1545e5b34141c1614daa034024a98821bd7642306100b3a505193274c33334db
 * Entry: 0x4e24d0; label: FUN_004e24d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e24d0(int param_1)

{
  byte bVar1;
  float *pfVar2;
  byte bVar3;
  undefined2 uVar4;
  ushort uVar5;
  float fVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float fVar11;
  int iVar12;
  float *pfVar13;
  byte *pbVar14;
  uint uVar15;
  bool bVar16;
  float10 fVar17;
  char cStack_4a;
  char cStack_49;
  int iStack_44;
  int iStack_40;
  uint uStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  float fStack_10;
  float fStack_c;
  undefined4 uStack_8;
  float fStack_4;
  
  if (DAT_0095df30 != 0) {
    fStack_c = *(float *)(PTR_DAT_008021b4 + 0x110);
    uStack_8 = *(undefined4 *)(PTR_DAT_008021b4 + 0x114);
    fStack_4 = *(float *)(PTR_DAT_008021b4 + 0x118);
    fStack_18 = *(float *)(PTR_DAT_008021b4 + 0x11c);
    uStack_14 = *(undefined4 *)(PTR_DAT_008021b4 + 0x120);
    fStack_10 = *(float *)(PTR_DAT_008021b4 + 0x124);
    iStack_40 = 0;
    if (0 < DAT_0095df38) {
      do {
        fStack_28 = DAT_0093b0d4;
        pfVar13 = (float *)(iStack_40 * 0x54 + *(int *)(param_1 + 0x5040));
        fVar11 = pfVar13[8];
        if (((uint)fVar11 & 4) != 0) {
          fVar6 = pfVar13[0xb] - _DAT_00925018;
          fStack_30 = DAT_0093b0cc;
          fStack_2c = DAT_0093b0d0;
          iVar12 = 0;
          pfVar13[0xb] = fVar6;
          fStack_38 = 0.0;
          uStack_3c = 0;
          if (fVar6 <= 0.0) {
            uStack_3c = (uint)(((uint)fVar11 & 1) != 0);
            if (((uint)pfVar13[6] & 0x2000000) == 0) {
              fVar6 = 1.0;
            }
            else {
              fVar6 = 0.5;
            }
            pfVar13[0xb] = fVar6;
          }
          pfVar2 = (float *)pfVar13[0xe];
          cStack_4a = '\0';
          *pfVar13 = *pfVar2;
          cStack_49 = '\0';
          pfVar13[1] = pfVar2[2];
          fStack_24 = pfVar13[0x11] - fStack_18;
          fStack_1c = pfVar13[0x13] - fStack_10;
          fVar6 = fStack_c * fStack_24 + fStack_4 * fStack_1c;
          if (fVar6 < 0.1 == (fVar6 == 0.1)) {
            fVar11 = (float)((uint)fVar11 | 1);
          }
          else {
            fVar11 = (float)((uint)fVar11 & 0xfffffffe);
          }
          fVar6 = pfVar13[6];
          pfVar13[8] = fVar11;
          if ((((uint)fVar6 >> 4 ^ (uint)fVar6) & 0xf0) == 0) {
            fVar6 = (float)((uint)fVar6 & 0xffffefff);
          }
          else {
            fVar6 = (float)((uint)fVar6 | 0x1000);
          }
          pfVar13[6] = fVar6;
          if (DAT_0095df2c != 0) {
            uVar7 = (uint)fVar6 >> 4 & 0xf;
            if ((uVar7 == 3) || (uVar7 == 2)) {
              pfVar13[6] = (float)((uint)fVar6 & 0xffffff1f | 0x10);
            }
            iVar8 = FUN_005a9ab0();
            if ((iVar8 != 0) &&
               (fVar17 = (float10)FUN_005becc0(pfVar2,iVar8 + 0x80,0), fVar17 < (float10)40.0)) {
              pfVar13[6] = (float)((uint)pfVar13[6] & 0xffffff0f);
            }
          }
          pbVar14 = (byte *)pfVar13[0x10];
          uVar7 = (uint)pfVar13[6] >> 4 & 0xf;
          if (uVar7 == 0) {
            bVar1 = *(byte *)(pfVar13 + 7);
            iVar12 = FUN_0054fa60();
            iVar8 = 0;
            fVar11 = fStack_38;
            if (bVar1 != 0) {
              do {
                if ((iVar8 == iVar12 / ((int)(0xffff / (ulonglong)(longlong)(int)(uint)bVar1) + 1))
                   && (uStack_3c != 0)) {
                  fVar11 = (float)FUN_005a9b30(param_1,pfVar13,pbVar14,&iStack_44,iStack_40);
                }
                pbVar14[1] = pbVar14[1] & 0xf7 | 4;
                iVar9 = FUN_0054fa60();
                fStack_34 = (_DAT_00805d30 / 65535.0) * (float)iVar9;
                uVar5 = FUN_00550070(*(undefined2 *)(pbVar14 + 4),*(undefined2 *)(pbVar14 + 6),
                                     fStack_34);
                *(ushort *)(pbVar14 + 4) = uVar5;
                if ((int)((uint)uVar5 - (uint)*(ushort *)(pbVar14 + 6)) < 0x16d) {
                  iVar9 = FUN_0054fa60();
                  if (fVar11 == 0.0) {
                    *(short *)(pbVar14 + 6) = (short)iVar9;
                  }
                  else {
                    *(short *)(pbVar14 + 6) =
                         ((short)(iVar9 / 0x49) - (short)(iVar9 / -0x6e000000)) + (short)iStack_44;
                  }
                }
                fStack_30 = *(float *)(pbVar14 + 0x14) + fStack_30;
                iVar8 = iVar8 + 1;
                fStack_28 = *(float *)(pbVar14 + 0x1c) + fStack_28;
                pbVar14 = pbVar14 + 0x20;
              } while (iVar8 < (int)(uint)*(byte *)(pfVar13 + 7));
            }
LAB_005aa6fa:
            fStack_38 = pfVar13[9] - _DAT_00925018;
            pfVar13[9] = fStack_38;
            bVar16 = fStack_38 <= 0.0;
LAB_005aa717:
            if (bVar16) {
              FUN_005a9820();
            }
          }
          else {
            if (uVar7 != 1) {
              uVar15 = (uint)*(byte *)(pfVar13 + 7);
              if (uVar7 != 2) {
                iVar12 = FUN_0054fa60();
                iVar8 = 0;
                if (uVar15 != 0) {
                  do {
                    if ((iVar8 == iVar12 / ((int)(0xffff / (ulonglong)(longlong)(int)uVar15) + 1))
                       && (uStack_3c != 0)) {
                      fStack_38 = (float)FUN_005a9b30(param_1,pfVar13,pbVar14,&iStack_44,iStack_40);
                    }
                    iVar9 = (int)pfVar13[0x10] + (uint)*pbVar14 * 0x20;
                    fStack_24 = *(float *)(pbVar14 + 0x14) - (*(float *)(iVar9 + 0xc) + *pfVar13);
                    fStack_1c = *(float *)(pbVar14 + 0x1c) - (*(float *)(iVar9 + 0x10) + pfVar13[1])
                    ;
                    fVar11 = fStack_24 * fStack_24 + fStack_1c * fStack_1c;
                    if (fVar11 < 0.040000003 != (fVar11 == 0.040000003)) {
                      iVar9 = FUN_0054fa60();
                      *pbVar14 = (byte)(iVar9 / ((int)(0xffff / (ulonglong)
                                                                (longlong)
                                                                (int)(uint)*(byte *)(pfVar13 + 7)) +
                                                1));
                      iVar9 = FUN_0054fa60();
                      pbVar14[1] = pbVar14[1] ^
                                   (((((char)(iVar9 / 0x5556) + (char)(iVar9 >> 0x1f)) -
                                     (char)((longlong)iVar9 * 0x2fffa001 >> 0x3f)) + '\x01') *
                                    '\x10' ^ pbVar14[1]) & 0x30;
                    }
                    iVar9 = (uint)*pbVar14 * 0x20 + (int)pfVar13[0x10];
                    fStack_24 = (*(float *)(iVar9 + 0xc) + *pfVar13) - *(float *)(pbVar14 + 0x14);
                    fStack_1c = (*(float *)(iVar9 + 0x10) + pfVar13[1]) - *(float *)(pbVar14 + 0x1c)
                    ;
                    uVar4 = FUN_005be2d0(fStack_24,fStack_1c);
                    *(undefined2 *)(pbVar14 + 6) = uVar4;
                    iVar9 = FUN_0054fa60();
                    fStack_34 = (_DAT_00805d30 / 65535.0) * (float)iVar9;
                    uVar4 = FUN_00550070(*(undefined2 *)(pbVar14 + 4),*(undefined2 *)(pbVar14 + 6),
                                         fStack_34);
                    *(undefined2 *)(pbVar14 + 4) = uVar4;
                    if ((pbVar14[1] & 0x40) == 0) {
                      FUN_005a9750();
                      FUN_005a97c0();
                    }
                    else {
                      iVar9 = FUN_0054fa60();
                      fStack_34 = (_DAT_00805d30 / 65535.0) * (float)iVar9;
                      uVar5 = FUN_00550070(*(undefined2 *)(pbVar14 + 4),*(undefined2 *)(pbVar14 + 6)
                                           ,fStack_34);
                      *(ushort *)(pbVar14 + 4) = uVar5;
                      if ((int)((uint)uVar5 - (uint)*(ushort *)(pbVar14 + 6)) < 0x16d) {
                        iVar9 = FUN_0054fa60();
                        if (fStack_38 != 0.0) {
                          iVar9 = iVar9 / 0x49 + iStack_44;
                        }
                        *(short *)(pbVar14 + 6) = (short)iVar9;
                      }
                    }
                    fStack_30 = *(float *)(pbVar14 + 0x14) + fStack_30;
                    iVar8 = iVar8 + 1;
                    fStack_28 = *(float *)(pbVar14 + 0x1c) + fStack_28;
                    pbVar14 = pbVar14 + 0x20;
                  } while (iVar8 < (int)(uint)*(byte *)(pfVar13 + 7));
                }
                goto LAB_005aa6fa;
              }
              iVar12 = FUN_0054fa60();
              iVar8 = 0;
              fVar11 = fStack_38;
              if (uVar15 != 0) {
                do {
                  if ((iVar8 == iVar12 / ((int)(0xffff / (ulonglong)(longlong)(int)uVar15) + 1)) &&
                     (uStack_3c != 0)) {
                    fVar11 = (float)FUN_005a9b30(param_1,pfVar13,pbVar14,&iStack_44,iStack_40);
                  }
                  if ((pbVar14[1] & 0x40) == 0) {
                    iVar9 = FUN_005a96f0();
                    if (iVar9 != 0) {
                      cStack_4a = cStack_4a + '\x01';
                    }
                  }
                  else {
                    cStack_4a = cStack_4a + '\x01';
                    iVar9 = FUN_0054fa60();
                    fStack_34 = (_DAT_00805d30 / 65535.0) * (float)iVar9;
                    uVar5 = FUN_00550070(*(undefined2 *)(pbVar14 + 4),*(undefined2 *)(pbVar14 + 6),
                                         fStack_34);
                    *(ushort *)(pbVar14 + 4) = uVar5;
                    if ((int)((uint)uVar5 - (uint)*(ushort *)(pbVar14 + 6)) < 0x16d) {
                      iVar9 = FUN_0054fa60();
                      if (fVar11 != 0.0) {
                        iVar9 = iVar9 / 0x49 + iStack_44;
                      }
                      *(short *)(pbVar14 + 6) = (short)iVar9;
                    }
                  }
                  if ((pbVar14[1] & 0x40) == 0) {
                    iVar9 = (uint)*pbVar14 * 0x20 + (int)pfVar13[0x10];
                    fStack_24 = (*(float *)(iVar9 + 0xc) + *pfVar13) - *(float *)(pbVar14 + 0x14);
                    fStack_1c = (*(float *)(iVar9 + 0x10) + pfVar13[1]) - *(float *)(pbVar14 + 0x1c)
                    ;
                    uVar4 = FUN_005be2d0(fStack_24,fStack_1c);
                    *(undefined2 *)(pbVar14 + 6) = uVar4;
                    iVar9 = FUN_0054fa60();
                    fStack_34 = (_DAT_00805d30 / 65535.0) * (float)iVar9;
                    uVar4 = FUN_00550070(*(undefined2 *)(pbVar14 + 4),*(undefined2 *)(pbVar14 + 6),
                                         fStack_34);
                    *(undefined2 *)(pbVar14 + 4) = uVar4;
                    if ((pbVar14[1] & 0x40) == 0) {
                      FUN_005a9750();
                      FUN_005a97c0();
                    }
                  }
                  fStack_30 = *(float *)(pbVar14 + 0x14) + fStack_30;
                  iVar8 = iVar8 + 1;
                  fStack_28 = *(float *)(pbVar14 + 0x1c) + fStack_28;
                  pbVar14 = pbVar14 + 0x20;
                } while (iVar8 < (int)(uint)*(byte *)(pfVar13 + 7));
              }
              bVar16 = cStack_4a == *(char *)(pfVar13 + 7);
              goto LAB_005aa717;
            }
            iVar8 = FUN_0054fa60();
            bVar1 = *(byte *)(pfVar13 + 7);
            if (((uint)pfVar13[6] & 0x1000) != 0) {
              fVar11 = (float)((uint)pfVar13[6] & 0xffffefff);
              pfVar13[6] = fVar11;
              if (pfVar13[0xf] != 0.0) {
                fVar11 = (float)(((uint)fVar11 >> 3 ^ (uint)fVar11) & 0x70000 ^ (uint)fVar11);
                pfVar13[6] = fVar11;
                iVar9 = *(int *)((int)pfVar13[0xf] + 8);
                uVar7 = (uint)fVar11 >> 0x10 & 7;
                fStack_24 = *(float *)(iVar9 + uVar7 * 0xc) - *pfVar13;
                fStack_1c = *(float *)(iVar9 + uVar7 * 0xc + 8) - pfVar13[1];
                uVar4 = FUN_005be2d0(fStack_24,fStack_1c);
                *(undefined2 *)(pfVar13 + 5) = uVar4;
                if (DAT_0095df2c == 0) {
                  pfVar13[6] = (float)((uint)pfVar13[6] & 0xfffffff1 | 1);
                }
                else {
                  pfVar13[6] = (float)((uint)pfVar13[6] & 0xfffffff4 | 4);
                }
                FUN_005a8960();
                pbVar14 = (byte *)pfVar13[0x10];
                iVar9 = 0;
                if (*(char *)(pfVar13 + 7) != '\0') {
                  do {
                    *pbVar14 = (byte)iVar9;
                    iVar9 = iVar9 + 1;
                    pbVar14 = pbVar14 + 0x20;
                  } while (iVar9 < (int)(uint)*(byte *)(pfVar13 + 7));
                }
              }
            }
            if (*(char *)(pfVar13 + 7) != '\0') {
              iVar9 = 0;
              do {
                if ((iVar9 == iVar8 / ((int)(0xffff / (ulonglong)(longlong)(int)(uint)bVar1) + 1))
                   && (uStack_3c != 0)) {
                  iVar12 = FUN_005a9b30(param_1,pfVar13,pbVar14,&iStack_44,iStack_40);
                }
                if ((pbVar14[1] & 0x40) == 0) {
                  iVar10 = FUN_005a96f0();
                  if (iVar10 != 0) {
                    cStack_4a = cStack_4a + '\x01';
                  }
                }
                else {
                  cStack_4a = cStack_4a + '\x01';
                  iVar10 = FUN_0054fa60();
                  fStack_34 = (_DAT_00805d30 / 65535.0) * (float)iVar10;
                  uVar5 = FUN_00550070(*(undefined2 *)(pbVar14 + 4),*(undefined2 *)(pbVar14 + 6),
                                       fStack_34);
                  *(ushort *)(pbVar14 + 4) = uVar5;
                  if ((int)((uint)uVar5 - (uint)*(ushort *)(pbVar14 + 6)) < 0x16d) {
                    iVar10 = FUN_0054fa60();
                    if (iVar12 != 0) {
                      iVar10 = iVar10 / 0x49 + iStack_44;
                    }
                    *(short *)(pbVar14 + 6) = (short)iVar10;
                  }
                }
                if ((pbVar14[1] & 0x40) == 0) {
                  iVar10 = (uint)*pbVar14 * 0x20 + (int)pfVar13[0x10];
                  fStack_24 = (*(float *)(iVar10 + 0xc) + *pfVar13) - *(float *)(pbVar14 + 0x14);
                  fStack_1c = (*(float *)(iVar10 + 0x10) + pfVar13[1]) - *(float *)(pbVar14 + 0x1c);
                  uVar4 = FUN_005be2d0(fStack_24,fStack_1c);
                  *(undefined2 *)(pbVar14 + 6) = uVar4;
                  iVar10 = FUN_0054fa60();
                  fStack_34 = (_DAT_00805d30 / 65535.0) * (float)iVar10;
                  uVar4 = FUN_00550070(*(undefined2 *)(pbVar14 + 4),*(undefined2 *)(pbVar14 + 6),
                                       fStack_34);
                  *(undefined2 *)(pbVar14 + 4) = uVar4;
                }
                bVar3 = pbVar14[1];
                if ((char)bVar3 < '\0') {
LAB_005aa552:
                  cStack_49 = cStack_49 + '\x01';
                }
                else if (((bVar3 & 0x40) != 0) &&
                        (uVar7 = (int)(short)(*(short *)(pbVar14 + 4) - *(short *)(pfVar13 + 5)) >>
                                 0x1f,
                        (int)(((int)(short)(*(short *)(pbVar14 + 4) - *(short *)(pfVar13 + 5)) ^
                              uVar7) - uVar7) < 0x16d)) {
                  pbVar14[1] = bVar3 | 0x80;
                  goto LAB_005aa552;
                }
                if ((pbVar14[1] & 0x40) == 0) {
                  FUN_005a9750();
                  fStack_34 = 1.0 / (float)pbVar14[3];
                  if (fStack_34 < *(float *)(pbVar14 + 8) != (fStack_34 == *(float *)(pbVar14 + 8)))
                  {
                    bVar3 = pbVar14[1];
                    bVar3 = ((bVar3 & 0xfc) + 4 ^ bVar3) & 0xc ^ bVar3;
                    pbVar14[1] = bVar3;
                    if (0xc < (bVar3 & 0xc)) {
                      pbVar14[1] = bVar3 & 0xf3;
                    }
                    pbVar14[8] = 0;
                    pbVar14[9] = 0;
                    pbVar14[10] = 0;
                    pbVar14[0xb] = 0;
                  }
                  *(float *)(pbVar14 + 8) = *(float *)(pbVar14 + 8) + _DAT_00925018;
                }
                fStack_30 = *(float *)(pbVar14 + 0x14) + fStack_30;
                iVar9 = iVar9 + 1;
                fStack_28 = *(float *)(pbVar14 + 0x1c) + fStack_28;
                pbVar14 = pbVar14 + 0x20;
              } while (iVar9 < (int)(uint)*(byte *)(pfVar13 + 7));
            }
            if (cStack_49 == *(char *)(pfVar13 + 7)) {
              bVar16 = cStack_4a == *(char *)(pfVar13 + 7);
              goto LAB_005aa717;
            }
          }
          fStack_34 = (float)(uint)*(byte *)(pfVar13 + 7);
          fStack_30 = fStack_30 / (float)(int)fStack_34;
          pfVar13[0x11] = fStack_30;
          fStack_28 = fStack_28 / (float)(int)fStack_34;
          pfVar13[0x12] = fStack_2c;
          pfVar13[0x13] = fStack_28;
          if ((0.0 < pfVar13[10]) && (DAT_0095df2c == 0)) {
            fStack_34 = pfVar13[10] - _DAT_00925018;
            pfVar13[10] = fStack_34;
            if (fStack_34 < 0.0 != (fStack_34 == 0.0)) {
              FUN_0054fa60();
              FUN_005a99e0();
            }
          }
          fVar11 = pfVar13[6];
          pfVar13[6] = (float)(((int)fVar11 << 4 ^ (uint)fVar11) & 0xf00 ^ (uint)fVar11);
        }
        iStack_40 = iStack_40 + 1;
      } while (iStack_40 < DAT_0095df38);
    }
  }
  return;
}

