/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5a9d40; label: FUN_005a9d40
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a9d40(int param_1)

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
  char local_4a;
  char local_49;
  int local_44;
  int local_40;
  uint local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_1c;
  float local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  undefined4 local_8;
  float local_4;
  
  if (DAT_0095df30 != 0) {
    local_c = *(float *)(PTR_DAT_008021b4 + 0x110);
    local_8 = *(undefined4 *)(PTR_DAT_008021b4 + 0x114);
    local_4 = *(float *)(PTR_DAT_008021b4 + 0x118);
    local_18 = *(float *)(PTR_DAT_008021b4 + 0x11c);
    local_14 = *(undefined4 *)(PTR_DAT_008021b4 + 0x120);
    local_10 = *(float *)(PTR_DAT_008021b4 + 0x124);
    local_40 = 0;
    if (0 < DAT_0095df38) {
      do {
        local_28 = DAT_0093b0d4;
        pfVar13 = (float *)(local_40 * 0x54 + *(int *)(param_1 + 0x5040));
        fVar11 = pfVar13[8];
        if (((uint)fVar11 & 4) != 0) {
          fVar6 = pfVar13[0xb] - _DAT_00925018;
          local_30 = DAT_0093b0cc;
          local_2c = DAT_0093b0d0;
          iVar12 = 0;
          pfVar13[0xb] = fVar6;
          local_38 = 0.0;
          local_3c = 0;
          if (fVar6 <= 0.0) {
            local_3c = (uint)(((uint)fVar11 & 1) != 0);
            if (((uint)pfVar13[6] & 0x2000000) == 0) {
              fVar6 = 1.0;
            }
            else {
              fVar6 = 0.5;
            }
            pfVar13[0xb] = fVar6;
          }
          pfVar2 = (float *)pfVar13[0xe];
          local_4a = '\0';
          *pfVar13 = *pfVar2;
          local_49 = '\0';
          pfVar13[1] = pfVar2[2];
          local_24 = pfVar13[0x11] - local_18;
          local_1c = pfVar13[0x13] - local_10;
          fVar6 = local_c * local_24 + local_4 * local_1c;
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
            fVar11 = local_38;
            if (bVar1 != 0) {
              do {
                if ((iVar8 == iVar12 / ((int)(0xffff / (ulonglong)(longlong)(int)(uint)bVar1) + 1))
                   && (local_3c != 0)) {
                  fVar11 = (float)FUN_005a9b30(param_1,pfVar13,pbVar14,&local_44,local_40);
                }
                pbVar14[1] = pbVar14[1] & 0xf7 | 4;
                iVar9 = FUN_0054fa60();
                local_34 = (_DAT_00805d30 / 65535.0) * (float)iVar9;
                uVar5 = FUN_00550070(*(undefined2 *)(pbVar14 + 4),*(undefined2 *)(pbVar14 + 6),
                                     local_34);
                *(ushort *)(pbVar14 + 4) = uVar5;
                if ((int)((uint)uVar5 - (uint)*(ushort *)(pbVar14 + 6)) < 0x16d) {
                  iVar9 = FUN_0054fa60();
                  if (fVar11 == 0.0) {
                    *(short *)(pbVar14 + 6) = (short)iVar9;
                  }
                  else {
                    *(short *)(pbVar14 + 6) =
                         ((short)(iVar9 / 0x49) - (short)(iVar9 / -0x6e000000)) + (short)local_44;
                  }
                }
                local_30 = *(float *)(pbVar14 + 0x14) + local_30;
                iVar8 = iVar8 + 1;
                local_28 = *(float *)(pbVar14 + 0x1c) + local_28;
                pbVar14 = pbVar14 + 0x20;
              } while (iVar8 < (int)(uint)*(byte *)(pfVar13 + 7));
            }
LAB_005aa6fa:
            local_38 = pfVar13[9] - _DAT_00925018;
            pfVar13[9] = local_38;
            bVar16 = local_38 <= 0.0;
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
                       && (local_3c != 0)) {
                      local_38 = (float)FUN_005a9b30(param_1,pfVar13,pbVar14,&local_44,local_40);
                    }
                    iVar9 = (int)pfVar13[0x10] + (uint)*pbVar14 * 0x20;
                    local_24 = *(float *)(pbVar14 + 0x14) - (*(float *)(iVar9 + 0xc) + *pfVar13);
                    local_1c = *(float *)(pbVar14 + 0x1c) - (*(float *)(iVar9 + 0x10) + pfVar13[1]);
                    fVar11 = local_24 * local_24 + local_1c * local_1c;
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
                    local_24 = (*(float *)(iVar9 + 0xc) + *pfVar13) - *(float *)(pbVar14 + 0x14);
                    local_1c = (*(float *)(iVar9 + 0x10) + pfVar13[1]) - *(float *)(pbVar14 + 0x1c);
                    uVar4 = FUN_005be2d0(local_24,local_1c);
                    *(undefined2 *)(pbVar14 + 6) = uVar4;
                    iVar9 = FUN_0054fa60();
                    local_34 = (_DAT_00805d30 / 65535.0) * (float)iVar9;
                    uVar4 = FUN_00550070(*(undefined2 *)(pbVar14 + 4),*(undefined2 *)(pbVar14 + 6),
                                         local_34);
                    *(undefined2 *)(pbVar14 + 4) = uVar4;
                    if ((pbVar14[1] & 0x40) == 0) {
                      FUN_005a9750();
                      FUN_005a97c0();
                    }
                    else {
                      iVar9 = FUN_0054fa60();
                      local_34 = (_DAT_00805d30 / 65535.0) * (float)iVar9;
                      uVar5 = FUN_00550070(*(undefined2 *)(pbVar14 + 4),*(undefined2 *)(pbVar14 + 6)
                                           ,local_34);
                      *(ushort *)(pbVar14 + 4) = uVar5;
                      if ((int)((uint)uVar5 - (uint)*(ushort *)(pbVar14 + 6)) < 0x16d) {
                        iVar9 = FUN_0054fa60();
                        if (local_38 != 0.0) {
                          iVar9 = iVar9 / 0x49 + local_44;
                        }
                        *(short *)(pbVar14 + 6) = (short)iVar9;
                      }
                    }
                    local_30 = *(float *)(pbVar14 + 0x14) + local_30;
                    iVar8 = iVar8 + 1;
                    local_28 = *(float *)(pbVar14 + 0x1c) + local_28;
                    pbVar14 = pbVar14 + 0x20;
                  } while (iVar8 < (int)(uint)*(byte *)(pfVar13 + 7));
                }
                goto LAB_005aa6fa;
              }
              iVar12 = FUN_0054fa60();
              iVar8 = 0;
              fVar11 = local_38;
              if (uVar15 != 0) {
                do {
                  if ((iVar8 == iVar12 / ((int)(0xffff / (ulonglong)(longlong)(int)uVar15) + 1)) &&
                     (local_3c != 0)) {
                    fVar11 = (float)FUN_005a9b30(param_1,pfVar13,pbVar14,&local_44,local_40);
                  }
                  if ((pbVar14[1] & 0x40) == 0) {
                    iVar9 = FUN_005a96f0();
                    if (iVar9 != 0) {
                      local_4a = local_4a + '\x01';
                    }
                  }
                  else {
                    local_4a = local_4a + '\x01';
                    iVar9 = FUN_0054fa60();
                    local_34 = (_DAT_00805d30 / 65535.0) * (float)iVar9;
                    uVar5 = FUN_00550070(*(undefined2 *)(pbVar14 + 4),*(undefined2 *)(pbVar14 + 6),
                                         local_34);
                    *(ushort *)(pbVar14 + 4) = uVar5;
                    if ((int)((uint)uVar5 - (uint)*(ushort *)(pbVar14 + 6)) < 0x16d) {
                      iVar9 = FUN_0054fa60();
                      if (fVar11 != 0.0) {
                        iVar9 = iVar9 / 0x49 + local_44;
                      }
                      *(short *)(pbVar14 + 6) = (short)iVar9;
                    }
                  }
                  if ((pbVar14[1] & 0x40) == 0) {
                    iVar9 = (uint)*pbVar14 * 0x20 + (int)pfVar13[0x10];
                    local_24 = (*(float *)(iVar9 + 0xc) + *pfVar13) - *(float *)(pbVar14 + 0x14);
                    local_1c = (*(float *)(iVar9 + 0x10) + pfVar13[1]) - *(float *)(pbVar14 + 0x1c);
                    uVar4 = FUN_005be2d0(local_24,local_1c);
                    *(undefined2 *)(pbVar14 + 6) = uVar4;
                    iVar9 = FUN_0054fa60();
                    local_34 = (_DAT_00805d30 / 65535.0) * (float)iVar9;
                    uVar4 = FUN_00550070(*(undefined2 *)(pbVar14 + 4),*(undefined2 *)(pbVar14 + 6),
                                         local_34);
                    *(undefined2 *)(pbVar14 + 4) = uVar4;
                    if ((pbVar14[1] & 0x40) == 0) {
                      FUN_005a9750();
                      FUN_005a97c0();
                    }
                  }
                  local_30 = *(float *)(pbVar14 + 0x14) + local_30;
                  iVar8 = iVar8 + 1;
                  local_28 = *(float *)(pbVar14 + 0x1c) + local_28;
                  pbVar14 = pbVar14 + 0x20;
                } while (iVar8 < (int)(uint)*(byte *)(pfVar13 + 7));
              }
              bVar16 = local_4a == *(char *)(pfVar13 + 7);
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
                local_24 = *(float *)(iVar9 + uVar7 * 0xc) - *pfVar13;
                local_1c = *(float *)(iVar9 + uVar7 * 0xc + 8) - pfVar13[1];
                uVar4 = FUN_005be2d0(local_24,local_1c);
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
                   && (local_3c != 0)) {
                  iVar12 = FUN_005a9b30(param_1,pfVar13,pbVar14,&local_44,local_40);
                }
                if ((pbVar14[1] & 0x40) == 0) {
                  iVar10 = FUN_005a96f0();
                  if (iVar10 != 0) {
                    local_4a = local_4a + '\x01';
                  }
                }
                else {
                  local_4a = local_4a + '\x01';
                  iVar10 = FUN_0054fa60();
                  local_34 = (_DAT_00805d30 / 65535.0) * (float)iVar10;
                  uVar5 = FUN_00550070(*(undefined2 *)(pbVar14 + 4),*(undefined2 *)(pbVar14 + 6),
                                       local_34);
                  *(ushort *)(pbVar14 + 4) = uVar5;
                  if ((int)((uint)uVar5 - (uint)*(ushort *)(pbVar14 + 6)) < 0x16d) {
                    iVar10 = FUN_0054fa60();
                    if (iVar12 != 0) {
                      iVar10 = iVar10 / 0x49 + local_44;
                    }
                    *(short *)(pbVar14 + 6) = (short)iVar10;
                  }
                }
                if ((pbVar14[1] & 0x40) == 0) {
                  iVar10 = (uint)*pbVar14 * 0x20 + (int)pfVar13[0x10];
                  local_24 = (*(float *)(iVar10 + 0xc) + *pfVar13) - *(float *)(pbVar14 + 0x14);
                  local_1c = (*(float *)(iVar10 + 0x10) + pfVar13[1]) - *(float *)(pbVar14 + 0x1c);
                  uVar4 = FUN_005be2d0(local_24,local_1c);
                  *(undefined2 *)(pbVar14 + 6) = uVar4;
                  iVar10 = FUN_0054fa60();
                  local_34 = (_DAT_00805d30 / 65535.0) * (float)iVar10;
                  uVar4 = FUN_00550070(*(undefined2 *)(pbVar14 + 4),*(undefined2 *)(pbVar14 + 6),
                                       local_34);
                  *(undefined2 *)(pbVar14 + 4) = uVar4;
                }
                bVar3 = pbVar14[1];
                if ((char)bVar3 < '\0') {
LAB_005aa552:
                  local_49 = local_49 + '\x01';
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
                  local_34 = 1.0 / (float)pbVar14[3];
                  if (local_34 < *(float *)(pbVar14 + 8) != (local_34 == *(float *)(pbVar14 + 8))) {
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
                local_30 = *(float *)(pbVar14 + 0x14) + local_30;
                iVar9 = iVar9 + 1;
                local_28 = *(float *)(pbVar14 + 0x1c) + local_28;
                pbVar14 = pbVar14 + 0x20;
              } while (iVar9 < (int)(uint)*(byte *)(pfVar13 + 7));
            }
            if (local_49 == *(char *)(pfVar13 + 7)) {
              bVar16 = local_4a == *(char *)(pfVar13 + 7);
              goto LAB_005aa717;
            }
          }
          local_34 = (float)(uint)*(byte *)(pfVar13 + 7);
          local_30 = local_30 / (float)(int)local_34;
          pfVar13[0x11] = local_30;
          local_28 = local_28 / (float)(int)local_34;
          pfVar13[0x12] = local_2c;
          pfVar13[0x13] = local_28;
          if ((0.0 < pfVar13[10]) && (DAT_0095df2c == 0)) {
            local_34 = pfVar13[10] - _DAT_00925018;
            pfVar13[10] = local_34;
            if (local_34 < 0.0 != (local_34 == 0.0)) {
              FUN_0054fa60();
              FUN_005a99e0();
            }
          }
          fVar11 = pfVar13[6];
          pfVar13[6] = (float)(((int)fVar11 << 4 ^ (uint)fVar11) & 0xf00 ^ (uint)fVar11);
        }
        local_40 = local_40 + 1;
      } while (local_40 < DAT_0095df38);
    }
  }
  return;
}

