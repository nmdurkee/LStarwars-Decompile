/* Ghidra pseudocode, not original source.
 * ev_6d32088aadafc0ff590ef2b7105f938147ee95ce1444f973b36a6fd6e03e3889
 * Entry: 0x525cb0; label: FUN_00525cb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00525cb0(void)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  byte *pbVar5;
  char *pcVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  undefined4 uVar11;
  char *pcVar12;
  int iVar13;
  int iVar14;
  uint *puVar15;
  undefined4 *puVar16;
  int iVar17;
  int local_120;
  uint local_11c;
  int local_118;
  int local_110;
  int local_10c;
  int local_108;
  int local_100 [64];
  
  iVar13 = DAT_009238e4;
  *(undefined4 *)(DAT_009238e4 + 0x4874) = 0;
  local_110 = 0;
  *(undefined4 *)(iVar13 + 0x4878) = 0;
  iVar13 = 0;
  do {
    FUN_004f1310(DAT_009238e4 + 0x486c,iVar13 + 0x68 + DAT_009238e4);
    iVar14 = DAT_009238e4;
    iVar13 = iVar13 + 0x240;
  } while (iVar13 < 0x4800);
  *(undefined4 *)(DAT_009238e4 + 0x3187c) = 0;
  *(undefined4 *)(iVar14 + 0x31880) = 0;
  iVar14 = 0;
  iVar13 = 0;
  do {
    FUN_004f1310(DAT_009238e4 + 0x3187c,iVar14 + 0x487c + DAT_009238e4);
    iVar17 = DAT_009238e4;
    iVar14 = iVar14 + 0xb4;
  } while (iVar14 < 0x2d000);
  *(undefined4 *)(DAT_009238e4 + 0x31b84) = 0;
  *(undefined4 *)(iVar17 + 0x31b88) = 0;
  iVar14 = 0x31884;
  do {
    FUN_004f1310(DAT_009238e4 + 0x31b84,iVar14 + DAT_009238e4);
    iVar14 = iVar14 + 0xc;
  } while (iVar14 < 0x31b84);
  _memset(local_100,0,0x100);
  if (*(int *)(DAT_009238e4 + 100) != 0) {
    iVar13 = *(int *)(*(int *)(DAT_009238e4 + 100) + 0x10);
  }
  if (*(int *)(DAT_009238e4 + 0x31b94) == iVar13) {
LAB_005261dc:
    if (*(int *)(DAT_009238e4 + 0x31b94) != 0) goto LAB_00526247;
  }
  else {
    *(int *)(DAT_009238e4 + 0x31b94) = iVar13;
    if (*(int *)(DAT_009238e4 + 0x31b94) != 0) {
      pbVar5 = *(byte **)(DAT_009238e4 + 0x31b94);
      local_108 = 0;
      if (*pbVar5 != 0) {
        do {
          pcVar10 = *(char **)(*(int *)(pbVar5 + 4) + local_108 * 4);
          iVar13 = FUN_004f1440(DAT_009238e4 + 0x486c);
          if (iVar13 != 0) {
            FUN_004f1410(DAT_009238e4 + 0x486c,iVar13);
            FUN_004f1310(DAT_009238e4 + 0x4874,iVar13);
            pcVar6 = pcVar10;
            do {
              cVar1 = *pcVar6;
              pcVar6[(iVar13 + 8) - (int)pcVar10] = cVar1;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            iVar14 = FUN_004f8b10(iVar13 + 8,"LevelPath");
            if (iVar14 == 0) {
              *(uint *)(iVar13 + 0x2c) = *(uint *)(iVar13 + 0x2c) | 1;
            }
            iVar14 = 0;
            if (pcVar10[0x14] != '\0') {
              iVar17 = 0;
              puVar15 = (uint *)(iVar13 + 0x58);
              do {
                *puVar15 = *puVar15 | 1;
                FUN_004f1f10(puVar15 + -6,*(undefined4 *)(iVar17 + *(int *)(pcVar10 + 0x88)));
                iVar13 = *(int *)(pcVar10 + 0x88);
                puVar15[-2] = *(uint *)(iVar17 + 0x20 + iVar13);
                puVar15[-1] = *(uint *)(iVar17 + 0x24 + iVar13);
                iVar14 = iVar14 + 1;
                iVar17 = iVar17 + 0x28;
                puVar15 = puVar15 + 8;
              } while (iVar14 < (int)(uint)(byte)pcVar10[0x14]);
            }
            if (pcVar10[0x10] != '\0') {
              local_11c = 0;
              if (pcVar10[0x10] != '\0') {
                local_120 = 0;
                do {
                  puVar16 = (undefined4 *)(*(int *)(pcVar10 + 0x7c) + local_120);
                  iVar13 = FUN_00522970();
                  if (iVar13 != 0) {
                    *(undefined4 *)(iVar13 + 0x18) = puVar16[1];
                    *(undefined4 *)(iVar13 + 0x1c) = puVar16[2];
                    *(undefined4 *)(iVar13 + 0x20) = puVar16[3];
                    *(undefined4 *)(iVar13 + 0x24) = puVar16[4];
                    *(float *)(iVar13 + 0x28) = (float)puVar16[6] - (float)puVar16[2];
                    *(float *)(iVar13 + 0x2c) = (float)puVar16[8] - (float)puVar16[2];
                    *(undefined1 *)(iVar13 + 0x92) = *(undefined1 *)((int)puVar16 + 0x2b);
                    *(undefined4 *)(iVar13 + 0x98) = puVar16[0x10];
                    *(undefined4 *)(iVar13 + 0x9c) = puVar16[0x11];
                    *(undefined4 *)(iVar13 + 0xa0) = puVar16[0x12];
                    *(undefined4 *)(iVar13 + 0xa4) = puVar16[0x13];
                    *(undefined4 *)(iVar13 + 0xa8) = puVar16[0x14];
                    *(undefined4 *)(iVar13 + 0xac) = puVar16[0x15];
                    *(undefined2 *)(iVar13 + 0x90) = (undefined2)local_11c;
                    pcVar6 = (char *)*puVar16;
                    if (pcVar6 != (char *)0x0) {
                      pcVar12 = (char *)(iVar13 + 8);
                      do {
                        cVar1 = *pcVar6;
                        *pcVar12 = cVar1;
                        pcVar6 = pcVar6 + 1;
                        pcVar12 = pcVar12 + 1;
                      } while (cVar1 != '\0');
                    }
                    bVar2 = *(byte *)(puVar16 + 0xc);
                    if (bVar2 < (byte)pcVar10[0x7a]) {
                      iVar14 = *(int *)(pcVar10 + 0x8c);
                      sVar3 = *(short *)(iVar14 + 2 + (uint)bVar2 * 4);
                      piVar7 = local_100 + sVar3;
                      if (local_100[sVar3] == 0) {
                        iVar17 = FUN_004f1440(DAT_009238e4 + 0x31b84);
                        if (iVar17 != 0) {
                          FUN_004f1410(DAT_009238e4 + 0x31b84,iVar17);
                          FUN_004f1310(DAT_009238e4 + 0x31b8c,iVar17);
                        }
                        piVar7 = local_100 + *(short *)(iVar14 + (uint)bVar2 * 4 + 2);
                        *piVar7 = iVar17;
                      }
                      iVar14 = *piVar7;
                      if (iVar14 != 0) {
                        iVar17 = *(int *)(iVar13 + 0xb0);
                        if (iVar17 != 0) {
                          if (iVar17 == iVar14) goto LAB_0052602f;
                          *(char *)(iVar17 + 8) = *(char *)(iVar17 + 8) + -1;
                          if (*(char *)(*(int *)(iVar13 + 0xb0) + 8) < '\x02') {
                            FUN_00525b80();
                          }
                          *(undefined4 *)(iVar13 + 0xb0) = 0;
                        }
                        *(int *)(iVar13 + 0xb0) = iVar14;
                        *(char *)(iVar14 + 8) = *(char *)(iVar14 + 8) + '\x01';
                      }
                    }
                  }
LAB_0052602f:
                  local_120 = local_120 + 0x5c;
                  local_11c = local_11c + 1;
                } while ((int)local_11c < (int)(uint)(byte)pcVar10[0x10]);
              }
              local_11c = 0;
              if (pcVar10[0x10] != '\0') {
                local_118 = local_110 * 0xb4;
                local_10c = 0;
                do {
                  iVar14 = *(int *)(pcVar10 + 0x7c) + local_10c;
                  iVar13 = local_118 + 0x487c + DAT_009238e4;
                  local_120 = 0;
                  if (*(char *)(iVar14 + 0x28) != '\0') {
                    do {
                      iVar4 = *(int *)(*(int *)(iVar14 + 0x34) + local_120 * 4);
                      uVar8 = (uint)(*(byte *)(iVar4 + 0x10) != local_11c);
                      iVar17 = ((uint)*(byte *)((uVar8 == 0) + 0x10 + iVar4) + local_110) * 0xb4 +
                               0x487c + DAT_009238e4;
                      if ((iVar13 != 0) && (iVar17 != 0)) {
                        iVar9 = 0;
                        piVar7 = (int *)(iVar13 + 0x30);
                        do {
                          if (*piVar7 == iVar17) {
                            iVar9 = iVar13 + (iVar9 * 3 + 0xc) * 4;
                            if (iVar9 != 0) goto LAB_0052613e;
                            break;
                          }
                          iVar9 = iVar9 + 1;
                          piVar7 = piVar7 + 3;
                        } while (iVar9 < 8);
                      }
                      FUN_00522d50(iVar13);
                      if ((iVar13 != 0) && (iVar17 != 0)) {
                        iVar9 = 0;
                        piVar7 = (int *)(iVar13 + 0x30);
                        do {
                          if (*piVar7 == iVar17) {
                            iVar9 = iVar13 + (iVar9 * 3 + 0xc) * 4;
                            if (iVar9 != 0) {
LAB_0052613e:
                              uVar8 = *(uint *)(iVar4 + 8 + uVar8 * 4);
                              *(uint *)(iVar9 + 4) = uVar8;
                              if ((uVar8 & 0x10000000) != 0) {
                                *(uint *)(iVar9 + 4) = uVar8 & 0xefffffff;
                              }
                              *(ushort *)(iVar9 + 8) =
                                   *(ushort *)(iVar9 + 8) | *(ushort *)(iVar4 + 0x14);
                            }
                            break;
                          }
                          iVar9 = iVar9 + 1;
                          piVar7 = piVar7 + 3;
                        } while (iVar9 < 8);
                      }
                      local_120 = local_120 + 1;
                    } while (local_120 < (int)(uint)*(byte *)(iVar14 + 0x28));
                  }
                  local_118 = local_118 + 0xb4;
                  local_10c = local_10c + 0x5c;
                  *(undefined2 *)(iVar13 + 0x96) = *(undefined2 *)(iVar14 + 0x5a);
                  local_11c = local_11c + 1;
                } while ((int)local_11c < (int)(uint)(byte)pcVar10[0x10]);
              }
            }
          }
          local_110 = local_110 + (uint)(byte)pcVar10[0x10];
          pbVar5 = *(byte **)(DAT_009238e4 + 0x31b94);
          local_108 = local_108 + 1;
        } while (local_108 < (int)(uint)*pbVar5);
      }
      goto LAB_005261dc;
    }
  }
  iVar13 = FUN_004f1440(DAT_009238e4 + 0x486c);
  if (iVar13 != 0) {
    FUN_004f1410(DAT_009238e4 + 0x486c,iVar13);
    FUN_004f1310(DAT_009238e4 + 0x4874,iVar13);
    builtin_strncpy((char *)(iVar13 + 8),"Leve",4);
    builtin_strncpy((char *)(iVar13 + 0xc),"lPat",4);
    *(uint *)(iVar13 + 0x2c) = *(uint *)(iVar13 + 0x2c) | 1;
    *(undefined2 *)(iVar13 + 0x10) = 0x68;
  }
LAB_00526247:
  pcVar10 = &DAT_00921ef0;
  do {
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar1 != '\0');
  if (pcVar10 == &DAT_00921ef1) {
    uVar11 = FUN_004f1440(DAT_009238e4 + 0x4874);
    *(undefined4 *)(DAT_009238e4 + 0x4868) = uVar11;
  }
  else {
    uVar11 = FUN_00524b00(&DAT_00921ef0);
    *(undefined4 *)(DAT_009238e4 + 0x4868) = uVar11;
  }
  FUN_005242b0();
  iVar13 = 0x60;
  while( true ) {
    *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) =
         *(int *)(DAT_009238e4 + 0x4868) + -0x20 + iVar13;
    iVar14 = *(int *)(DAT_009238e4 + 0x4868);
    if ((*(byte *)(*(int *)(iVar14 + 0x28) + 0x18) & 1) != 0) break;
    *(int *)(iVar14 + 0x28) = iVar14 + iVar13;
    iVar14 = *(int *)(DAT_009238e4 + 0x4868);
    if ((*(byte *)(*(int *)(iVar14 + 0x28) + 0x18) & 1) != 0) break;
    *(int *)(iVar14 + 0x28) = iVar14 + 0x20 + iVar13;
    iVar14 = *(int *)(DAT_009238e4 + 0x4868);
    if ((((*(byte *)(*(int *)(iVar14 + 0x28) + 0x18) & 1) != 0) ||
        (*(int *)(iVar14 + 0x28) = iVar14 + 0x40 + iVar13,
        (*(byte *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) + 0x18) & 1) != 0)) ||
       (iVar13 = iVar13 + 0x80, 0x25f < iVar13)) break;
  }
  iVar13 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28);
  if ((iVar13 != 0) && ((*(byte *)(iVar13 + 0x18) & 1) == 0)) {
    *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) = 0;
  }
  return;
}

