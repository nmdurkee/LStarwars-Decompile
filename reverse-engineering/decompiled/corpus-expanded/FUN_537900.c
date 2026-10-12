/* Ghidra pseudocode, not original source.
 * ev_b6e394b5e6447b25b30eeb5758ac1a35d86131e46c625f62ba009b62f4fc19bf
 * Entry: 0x537900; label: FUN_00537900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00537900(void)

{
  uint *puVar1;
  char cVar2;
  ushort uVar3;
  short sVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  size_t sVar10;
  undefined4 *puVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  int iVar18;
  void *pvVar19;
  float10 fVar20;
  int local_c;
  int local_8;
  
  if (*(int *)(DAT_009238e4 + 100) != 0) {
    sVar10 = (*(undefined4 **)(DAT_009238e4 + 100))[3];
    _memset((void *)**(undefined4 **)(DAT_009238e4 + 100),0,sVar10);
    (*(undefined4 **)(DAT_009238e4 + 100))[2] = **(undefined4 **)(DAT_009238e4 + 100);
    *(size_t *)(*(int *)(DAT_009238e4 + 100) + 0xc) = sVar10;
    uVar5 = FUN_005322d0(*(int *)(DAT_009238e4 + 100) + 8,*(int *)(DAT_009238e4 + 100) + 4,
                         &DAT_00921f64,&DAT_00921f68);
    *(undefined4 *)(*(int *)(DAT_009238e4 + 100) + 0x10) = uVar5;
    _memset((void *)(*(int *)(DAT_009238e4 + 100) + 0x3c),0,0x1340);
    iVar6 = FUN_004f1440(DAT_009238e4 + 0x383c0);
    *(undefined4 *)(*(int *)(DAT_009238e4 + 100) + 0x34) = 0;
    for (; iVar6 != 0; iVar6 = FUN_004f1460(DAT_009238e4 + 0x383c0,iVar6)) {
      piVar12 = (int *)(*(int *)(DAT_009238e4 + 100) + 0x34);
      *piVar12 = *piVar12 + 1;
    }
    iVar6 = *(int *)(DAT_009238e4 + 100);
    if (*(int *)(iVar6 + 0x34) != 0) {
      uVar5 = FUN_00517160(iVar6 + 8,iVar6 + 4,*(int *)(iVar6 + 0x34) << 6);
      *(undefined4 *)(*(int *)(DAT_009238e4 + 100) + 0x38) = uVar5;
      iVar6 = FUN_004f1440(DAT_009238e4 + 0x383c0);
      if (iVar6 != 0) {
        iVar14 = 0;
        do {
          puVar11 = (undefined4 *)(*(int *)(*(int *)(DAT_009238e4 + 100) + 0x38) + iVar14);
          puVar16 = (undefined4 *)(iVar6 + 8);
          puVar17 = puVar11;
          for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar17 = *puVar16;
            puVar16 = puVar16 + 1;
            puVar17 = puVar17 + 1;
          }
          puVar11[0xe] = *(undefined4 *)(DAT_009238e4 + 100);
          iVar14 = iVar14 + 0x40;
          iVar6 = FUN_004f1460(DAT_009238e4 + 0x383c0,iVar6);
        } while (iVar6 != 0);
      }
    }
    if (*(int *)(*(int *)(DAT_009238e4 + 100) + 0x10) != 0) {
      iVar6 = FUN_004f1440(DAT_009238e4 + 0x3cbd8);
      *(undefined4 *)(*(int *)(DAT_009238e4 + 100) + 0x24) = 0;
      for (; iVar6 != 0; iVar6 = FUN_004f1460(DAT_009238e4 + 0x3cbd8,iVar6)) {
        if (*(int *)(iVar6 + 0x2c) != 0) {
          piVar12 = (int *)(*(int *)(DAT_009238e4 + 100) + 0x24);
          *piVar12 = *piVar12 + 1;
        }
      }
      iVar6 = *(int *)(DAT_009238e4 + 100);
      if (*(int *)(iVar6 + 0x24) != 0) {
        uVar5 = FUN_00517160(iVar6 + 8,iVar6 + 4,*(int *)(iVar6 + 0x24) * 0x3c);
        *(undefined4 *)(*(int *)(DAT_009238e4 + 100) + 0x28) = uVar5;
        sVar4 = 0;
        iVar6 = FUN_004f1440(DAT_009238e4 + 0x3cbd8);
        if (iVar6 != 0) {
          local_c = 0;
          do {
            *(undefined2 *)(iVar6 + 0x44) = 0xff;
            if (*(int *)(iVar6 + 0x2c) != 0) {
              *(short *)(iVar6 + 0x44) = sVar4;
              sVar4 = sVar4 + 1;
              iVar14 = *(int *)(*(int *)(DAT_009238e4 + 100) + 0x28) + local_c;
              local_c = local_c + 0x3c;
              pcVar7 = (char *)(iVar6 + 8);
              iVar9 = iVar14 - (int)pcVar7;
              do {
                cVar2 = *pcVar7;
                pcVar7[iVar9] = cVar2;
                pcVar7 = pcVar7 + 1;
              } while (cVar2 != '\0');
              *(undefined4 *)(iVar14 + 0x1c) = *(undefined4 *)(iVar6 + 0x24);
              *(undefined4 *)(iVar14 + 0x38) = *(undefined4 *)(iVar6 + 0x40);
              *(undefined4 *)(iVar14 + 0x10) = *(undefined4 *)(iVar6 + 0x18);
              *(undefined4 *)(iVar14 + 0x14) = *(undefined4 *)(iVar6 + 0x1c);
              *(undefined4 *)(iVar14 + 0x18) = *(undefined4 *)(iVar6 + 0x20);
              iVar9 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_009238e4 + 100) + 0x10) + 4) +
                              *(char *)(*(int *)(iVar6 + 0x2c) + 0x38) * 4);
              *(int *)(iVar14 + 0x20) = iVar9;
              *(undefined4 *)(iVar14 + 0x30) = *(undefined4 *)(iVar6 + 0x38);
              *(undefined4 *)(iVar14 + 0x34) = *(undefined4 *)(iVar6 + 0x3c);
              if ((iVar9 != 0) && (iVar18 = 0, *(short *)(iVar9 + 0x12) != 0)) {
                uVar3 = *(ushort *)(*(int *)(iVar6 + 0x30) + 0x90);
                iVar9 = *(int *)(iVar9 + 0x80);
                do {
                  if ((*(byte *)(iVar9 + 0x10) == uVar3) &&
                     ((ushort)*(byte *)(iVar9 + 0x11) == *(ushort *)(*(int *)(iVar6 + 0x34) + 0x90))
                     ) {
                    *(int *)(iVar14 + 0x24) = iVar9;
                    uVar8 = (int)*(uint *)(iVar6 + 0x40) >> 0x1f;
                    *(bool *)(iVar14 + 0x28) =
                         0x3fff < (int)((*(uint *)(iVar6 + 0x40) ^ uVar8) - uVar8);
                    break;
                  }
                  if (((ushort)*(byte *)(iVar9 + 0x10) == *(ushort *)(*(int *)(iVar6 + 0x34) + 0x90)
                      ) && (*(byte *)(iVar9 + 0x11) == uVar3)) {
                    *(int *)(iVar14 + 0x24) = iVar9;
                    *(float *)(iVar14 + 0x30) = 1.0 - *(float *)(iVar6 + 0x38);
                    *(float *)(iVar14 + 0x34) = -*(float *)(iVar6 + 0x3c);
                    uVar8 = (int)*(uint *)(iVar6 + 0x40) >> 0x1f;
                    *(bool *)(iVar14 + 0x28) =
                         (int)((*(uint *)(iVar6 + 0x40) ^ uVar8) - uVar8) < 0x4000;
                    break;
                  }
                  iVar18 = iVar18 + 1;
                  iVar9 = iVar9 + 0x24;
                } while (iVar18 < (int)(uint)*(ushort *)(*(int *)(iVar14 + 0x20) + 0x12));
              }
            }
            iVar6 = FUN_004f1460(DAT_009238e4 + 0x3cbd8,iVar6);
          } while (iVar6 != 0);
        }
      }
      *(undefined4 *)(*(int *)(DAT_009238e4 + 100) + 0x2c) = 0;
      for (iVar6 = FUN_004f1440(DAT_009238e4 + 0x41200); iVar6 != 0;
          iVar6 = FUN_004f1460(DAT_009238e4 + 0x41200,iVar6)) {
        piVar12 = (int *)(*(int *)(DAT_009238e4 + 100) + 0x2c);
        *piVar12 = *piVar12 + 1;
      }
      iVar6 = *(int *)(DAT_009238e4 + 100);
      if (*(int *)(iVar6 + 0x2c) != 0) {
        uVar5 = FUN_00517160(iVar6 + 8,iVar6 + 4,*(int *)(iVar6 + 0x2c) * 0x3c);
        *(undefined4 *)(*(int *)(DAT_009238e4 + 100) + 0x30) = uVar5;
        if ((*(int *)(*(int *)(DAT_009238e4 + 100) + 0x30) != 0) &&
           (iVar6 = FUN_004f1440(DAT_009238e4 + 0x41200), iVar6 != 0)) {
          local_8 = 0;
          do {
            iVar9 = *(int *)(*(int *)(DAT_009238e4 + 100) + 0x30) + local_8;
            pcVar7 = (char *)(iVar6 + 8);
            iVar14 = iVar9 - (int)pcVar7;
            do {
              cVar2 = *pcVar7;
              pcVar7[iVar14] = cVar2;
              pcVar7 = pcVar7 + 1;
            } while (cVar2 != '\0');
            *(undefined1 *)(iVar9 + 0x10) = 0;
            iVar14 = 0;
            piVar12 = (int *)(iVar6 + 0x1c);
            do {
              if (piVar12[-1] == 0) break;
              if (*(short *)(piVar12[-1] + 0x44) != 0xff) {
                *(char *)(iVar9 + 0x10) = *(char *)(iVar9 + 0x10) + '\x01';
              }
              if (*piVar12 == 0) break;
              if (*(short *)(*piVar12 + 0x44) != 0xff) {
                *(char *)(iVar9 + 0x10) = *(char *)(iVar9 + 0x10) + '\x01';
              }
              if (piVar12[1] == 0) break;
              if (*(short *)(piVar12[1] + 0x44) != 0xff) {
                *(char *)(iVar9 + 0x10) = *(char *)(iVar9 + 0x10) + '\x01';
              }
              if (piVar12[2] == 0) break;
              if (*(short *)(piVar12[2] + 0x44) != 0xff) {
                *(char *)(iVar9 + 0x10) = *(char *)(iVar9 + 0x10) + '\x01';
              }
              iVar14 = iVar14 + 4;
              piVar12 = piVar12 + 4;
            } while (iVar14 < 0x40);
            if (*(char *)(iVar9 + 0x10) != '\0') {
              sVar10 = (size_t)*(char *)(iVar9 + 0x10);
              piVar12 = (int *)(*(int *)(DAT_009238e4 + 100) + 8);
              pvVar19 = (void *)0x0;
              puVar1 = (uint *)(*(int *)(DAT_009238e4 + 100) + 4);
              if ((piVar12 == (int *)0x0) || (puVar1 == (uint *)0x0)) {
                FUN_00512850();
              }
              else if (*piVar12 + sVar10 < *puVar1) {
                uVar8 = *piVar12 + 0xf;
                pvVar19 = (void *)(uVar8 & 0xfffffff0);
                *piVar12 = (uVar8 & 0xfffffff0) + sVar10;
                _memset(pvVar19,0,sVar10);
              }
              else {
                FUN_00512850();
              }
              iVar14 = 0;
              *(void **)(iVar9 + 0x14) = pvVar19;
              if ('\0' < *(char *)(iVar9 + 0x10)) {
                piVar12 = (int *)(iVar6 + 0x18);
                do {
                  if (*(short *)(*piVar12 + 0x44) != 0xff) {
                    *(undefined1 *)(iVar14 + *(int *)(iVar9 + 0x14)) =
                         *(undefined1 *)(*piVar12 + 0x44);
                  }
                  iVar14 = iVar14 + 1;
                  piVar12 = piVar12 + 1;
                } while (iVar14 < *(char *)(iVar9 + 0x10));
              }
              sVar10 = (size_t)*(char *)(iVar9 + 0x10);
              piVar12 = (int *)(*(int *)(DAT_009238e4 + 100) + 8);
              pvVar19 = (void *)0x0;
              puVar1 = (uint *)(*(int *)(DAT_009238e4 + 100) + 4);
              if ((piVar12 == (int *)0x0) || (puVar1 == (uint *)0x0)) {
                FUN_00512850();
              }
              else if (*piVar12 + sVar10 < *puVar1) {
                uVar8 = *piVar12 + 0xf;
                pvVar19 = (void *)(uVar8 & 0xfffffff0);
                *piVar12 = (uVar8 & 0xfffffff0) + sVar10;
                _memset(pvVar19,0,sVar10);
              }
              else {
                FUN_00512850();
              }
              *(void **)(iVar9 + 0x18) = pvVar19;
              _memset(pvVar19,0,(int)*(char *)(iVar9 + 0x10));
            }
            local_8 = local_8 + 0x1c;
            iVar6 = FUN_004f1460(DAT_009238e4 + 0x41200,iVar6);
          } while (iVar6 != 0);
        }
      }
      iVar6 = FUN_004f1440(DAT_009238e4 + 0x371a4);
      *(undefined4 *)(*(int *)(DAT_009238e4 + 100) + 0x14) = 0;
      for (; iVar6 != 0; iVar6 = FUN_004f1460(DAT_009238e4 + 0x371a4,iVar6)) {
        piVar12 = (int *)(*(int *)(DAT_009238e4 + 100) + 0x14);
        *piVar12 = *piVar12 + 1;
      }
      iVar6 = *(int *)(DAT_009238e4 + 100);
      if (*(int *)(iVar6 + 0x14) != 0) {
        sVar10 = *(int *)(iVar6 + 0x14) * 0xa4;
        piVar12 = (int *)(iVar6 + 8);
        pvVar19 = (void *)0x0;
        if (((piVar12 == (int *)0x0) || ((uint *)(iVar6 + 4) == (uint *)0x0)) ||
           (*(uint *)(iVar6 + 4) <= *piVar12 + sVar10)) {
          iVar6 = FUN_00512850();
        }
        else {
          uVar8 = *piVar12 + 0xf;
          pvVar19 = (void *)(uVar8 & 0xfffffff0);
          *piVar12 = (uVar8 & 0xfffffff0) + sVar10;
          _memset(pvVar19,0,sVar10);
          iVar6 = DAT_009238e4;
        }
        *(void **)(*(int *)(iVar6 + 100) + 0x18) = pvVar19;
        iVar6 = FUN_004f1440(DAT_009238e4 + 0x371a4);
        if (iVar6 != 0) {
          iVar14 = 0;
          do {
            iVar18 = *(int *)(*(int *)(DAT_009238e4 + 100) + 0x18) + iVar14;
            iVar14 = iVar14 + 0xa4;
            pcVar7 = (char *)(iVar6 + 8);
            iVar9 = iVar18 - (int)pcVar7;
            do {
              cVar2 = *pcVar7;
              pcVar7[iVar9] = cVar2;
              pcVar7 = pcVar7 + 1;
            } while (cVar2 != '\0');
            pcVar7 = (char *)(iVar6 + 0x18);
            iVar9 = iVar18 - (int)pcVar7;
            do {
              cVar2 = *pcVar7;
              pcVar7[iVar9 + 0x10] = cVar2;
              pcVar7 = pcVar7 + 1;
            } while (cVar2 != '\0');
            *(undefined2 *)(iVar18 + 0x4e) = *(undefined2 *)(iVar6 + 0x58);
            *(undefined1 *)(iVar18 + 0x4c) = *(undefined1 *)(iVar6 + 0x5a);
            *(undefined1 *)(iVar18 + 0x50) = *(undefined1 *)(iVar6 + 0x5b);
            *(undefined1 *)(iVar18 + 0x51) = *(undefined1 *)(iVar6 + 0x5c);
            *(undefined4 *)(iVar18 + 0x58) = *(undefined4 *)(iVar6 + 0x54);
            *(undefined4 *)(iVar18 + 0x5c) = *(undefined4 *)(iVar6 + 0x60);
            *(undefined4 *)(iVar18 + 0x60) = *(undefined4 *)(iVar6 + 100);
            *(undefined4 *)(iVar18 + 0x48) = *(undefined4 *)(iVar6 + 0x68);
            *(undefined4 *)(iVar18 + 0x2c) = *(undefined4 *)(iVar6 + 0x34);
            *(undefined4 *)(iVar18 + 0x20) = *(undefined4 *)(iVar6 + 0x28);
            *(undefined4 *)(iVar18 + 0x24) = *(undefined4 *)(iVar6 + 0x2c);
            *(undefined4 *)(iVar18 + 0x28) = *(undefined4 *)(iVar6 + 0x30);
            *(undefined4 *)(iVar18 + 0x30) =
                 *(undefined4 *)
                  (*(int *)(*(int *)(*(int *)(DAT_009238e4 + 100) + 0x10) + 4) +
                  *(char *)(*(int *)(iVar6 + 0x3c) + 0x38) * 4);
            *(undefined4 *)(iVar18 + 0x40) = *(undefined4 *)(iVar6 + 0x48);
            *(undefined4 *)(iVar18 + 0x44) = *(undefined4 *)(iVar6 + 0x4c);
            *(undefined4 *)(iVar18 + 100) = *(undefined4 *)(iVar6 + 0x70);
            *(undefined4 *)(iVar18 + 0x68) = *(undefined4 *)(iVar6 + 0x74);
            *(undefined4 *)(iVar18 + 0x6c) = *(undefined4 *)(iVar6 + 0x78);
            *(undefined4 *)(iVar18 + 0x70) = *(undefined4 *)(iVar6 + 0x7c);
            iVar9 = *(int *)(iVar18 + 0x30);
            if ((iVar9 != 0) && (iVar13 = 0, *(short *)(iVar9 + 0x12) != 0)) {
              uVar3 = *(ushort *)(*(int *)(iVar6 + 0x40) + 0x90);
              iVar9 = *(int *)(iVar9 + 0x80);
              do {
                if ((*(byte *)(iVar9 + 0x10) == uVar3) &&
                   ((ushort)*(byte *)(iVar9 + 0x11) == *(ushort *)(*(int *)(iVar6 + 0x44) + 0x90)))
                {
                  *(int *)(iVar18 + 0x34) = iVar9;
                  uVar8 = (int)*(uint *)(iVar6 + 0x50) >> 0x1f;
                  *(bool *)(iVar18 + 0x38) =
                       0x3fff < (int)((*(uint *)(iVar6 + 0x50) ^ uVar8) - uVar8);
                  break;
                }
                if (((ushort)*(byte *)(iVar9 + 0x10) == *(ushort *)(*(int *)(iVar6 + 0x44) + 0x90))
                   && (*(byte *)(iVar9 + 0x11) == uVar3)) {
                  *(int *)(iVar18 + 0x34) = iVar9;
                  *(float *)(iVar18 + 0x40) = 1.0 - *(float *)(iVar6 + 0x48);
                  *(float *)(iVar18 + 0x44) = -*(float *)(iVar6 + 0x4c);
                  uVar8 = (int)*(uint *)(iVar6 + 0x50) >> 0x1f;
                  *(bool *)(iVar18 + 0x38) =
                       (int)((*(uint *)(iVar6 + 0x50) ^ uVar8) - uVar8) < 0x4000;
                  break;
                }
                iVar13 = iVar13 + 1;
                iVar9 = iVar9 + 0x24;
              } while (iVar13 < (int)(uint)*(ushort *)(*(int *)(iVar18 + 0x30) + 0x12));
            }
            iVar9 = 0;
            if (*(int *)(iVar6 + 0x80) != 0) {
              iVar13 = *(int *)(DAT_009238e4 + 100);
              local_c = 0;
              if (0 < *(int *)(iVar13 + 0x34)) {
                do {
                  iVar15 = *(int *)(iVar13 + 0x38) + iVar9;
                  iVar13 = FUN_004f8b10(*(int *)(iVar6 + 0x80) + 8,iVar15);
                  if (iVar13 == 0) {
                    *(int *)(iVar18 + 0x78) = iVar15;
                    break;
                  }
                  iVar13 = *(int *)(DAT_009238e4 + 100);
                  local_c = local_c + 1;
                  iVar9 = iVar9 + 0x40;
                } while (local_c < *(int *)(iVar13 + 0x34));
              }
            }
            if (*(int *)(iVar6 + 0x84) != 0) {
              iVar9 = *(int *)(DAT_009238e4 + 100);
              local_c = 0;
              if (0 < *(int *)(iVar9 + 0x24)) {
                iVar13 = 0;
                do {
                  iVar15 = *(int *)(iVar9 + 0x28) + iVar13;
                  iVar9 = FUN_004f8b10(*(int *)(iVar6 + 0x84) + 8,iVar15);
                  if (iVar9 == 0) {
                    *(int *)(iVar18 + 0x7c) = iVar15;
                    break;
                  }
                  iVar9 = *(int *)(DAT_009238e4 + 100);
                  local_c = local_c + 1;
                  iVar13 = iVar13 + 0x3c;
                } while (local_c < *(int *)(iVar9 + 0x24));
              }
            }
            iVar9 = 0;
            if (*(int *)(iVar6 + 0x88) != 0) {
              iVar13 = *(int *)(DAT_009238e4 + 100);
              local_c = 0;
              if (0 < *(int *)(iVar13 + 0x24)) {
                do {
                  iVar15 = *(int *)(iVar13 + 0x28) + iVar9;
                  iVar13 = FUN_004f8b10(*(int *)(iVar6 + 0x88) + 8,iVar15);
                  if (iVar13 == 0) {
                    *(int *)(iVar18 + 0x80) = iVar15;
                    break;
                  }
                  iVar13 = *(int *)(DAT_009238e4 + 100);
                  local_c = local_c + 1;
                  iVar9 = iVar9 + 0x3c;
                } while (local_c < *(int *)(iVar13 + 0x24));
              }
            }
            *(undefined1 *)(iVar18 + 0x84) = *(undefined1 *)(iVar6 + 0x8c);
            *(undefined1 *)(iVar18 + 0x85) = *(undefined1 *)(iVar6 + 0x8d);
            *(undefined1 *)(iVar18 + 0x86) = *(undefined1 *)(iVar6 + 0x8e);
            *(undefined4 *)(iVar18 + 0x88) = *(undefined4 *)(iVar6 + 0x90);
            *(undefined4 *)(iVar18 + 0x8c) = *(undefined4 *)(iVar6 + 0x94);
            *(undefined4 *)(iVar18 + 0x90) = *(undefined4 *)(iVar6 + 0x98);
            *(undefined4 *)(iVar18 + 0x94) = *(undefined4 *)(iVar6 + 0x9c);
            *(undefined4 *)(iVar18 + 0x98) = *(undefined4 *)(iVar6 + 0xa0);
            *(undefined4 *)(iVar18 + 0x9c) = *(undefined4 *)(iVar6 + 0xa4);
            *(undefined4 *)(iVar18 + 0xa0) = *(undefined4 *)(iVar6 + 0xa8);
            *(undefined1 *)(iVar18 + 0x87) = *(undefined1 *)(iVar6 + 0x8f);
            if ((*(char *)(iVar6 + 0x8f) == '\x01') &&
               (*(undefined1 *)(iVar18 + 0x87) = 0, *(int *)(iVar6 + 0x6c) != 0)) {
              iVar9 = *(int *)(DAT_009238e4 + 100);
              local_c = 0;
              if (0 < *(int *)(iVar9 + 0x34)) {
                iVar13 = 0;
                do {
                  iVar15 = *(int *)(iVar9 + 0x38) + iVar13;
                  iVar9 = FUN_004f8b10(*(int *)(iVar6 + 0x6c) + 8,iVar15);
                  if (iVar9 == 0) {
                    *(int *)(iVar18 + 0x74) = iVar15;
                    *(undefined1 *)(iVar18 + 0x87) = 1;
                    break;
                  }
                  iVar9 = *(int *)(DAT_009238e4 + 100);
                  local_c = local_c + 1;
                  iVar13 = iVar13 + 0x40;
                } while (local_c < *(int *)(iVar9 + 0x34));
              }
            }
            iVar6 = FUN_004f1460(DAT_009238e4 + 0x371a4,iVar6);
          } while (iVar6 != 0);
        }
      }
      if (DAT_009238e8 != (code *)0x0) {
        iVar6 = *(int *)(DAT_009238e4 + 100);
        (*DAT_009238e8)(iVar6,iVar6 + 8,iVar6 + 4);
      }
    }
    *(undefined4 *)(*(int *)(DAT_009238e4 + 100) + 0x137c) = 0;
    for (iVar6 = FUN_004f1440(DAT_009238e4 + 0x43814); iVar6 != 0;
        iVar6 = FUN_004f1460(DAT_009238e4 + 0x43814,iVar6)) {
      piVar12 = (int *)(*(int *)(DAT_009238e4 + 100) + 0x137c);
      *piVar12 = *piVar12 + 1;
    }
    iVar6 = *(int *)(DAT_009238e4 + 100);
    if (*(int *)(iVar6 + 0x137c) != 0) {
      piVar12 = (int *)(iVar6 + 8);
      sVar10 = *(int *)(iVar6 + 0x137c) * 0x58;
      pvVar19 = (void *)0x0;
      if (((piVar12 == (int *)0x0) || ((uint *)(iVar6 + 4) == (uint *)0x0)) ||
         (*(uint *)(iVar6 + 4) <= *piVar12 + sVar10)) {
        FUN_00512850();
      }
      else {
        uVar8 = *piVar12 + 0xf;
        pvVar19 = (void *)(uVar8 & 0xfffffff0);
        *piVar12 = (uVar8 & 0xfffffff0) + sVar10;
        _memset(pvVar19,0,sVar10);
      }
      *(void **)(*(int *)(DAT_009238e4 + 100) + 0x1380) = pvVar19;
      iVar6 = FUN_004f1440(DAT_009238e4 + 0x43814);
      if (iVar6 != 0) {
        iVar14 = 0;
        do {
          puVar16 = (undefined4 *)(*(int *)(*(int *)(DAT_009238e4 + 100) + 0x1380) + iVar14);
          *(undefined1 *)(puVar16 + 0x12) = 1;
          *puVar16 = *(undefined4 *)(iVar6 + 8);
          puVar16[1] = *(undefined4 *)(iVar6 + 0xc);
          puVar16[2] = *(undefined4 *)(iVar6 + 0x10);
          puVar16[3] = *(undefined4 *)(iVar6 + 0x14);
          *(undefined1 *)((int)puVar16 + 0x49) = *(undefined1 *)(iVar6 + 0x48);
          puVar16[8] = *(undefined4 *)(iVar6 + 0x20);
          puVar16[9] = *(undefined4 *)(iVar6 + 0x24);
          puVar16[10] = *(undefined4 *)(iVar6 + 0x28);
          iVar9 = FUN_005cfac0(puVar16 + 8);
          if (iVar9 != 0) {
            *(undefined1 *)((int)puVar16 + 0x4b) = 1;
          }
          puVar16[0xb] = *(undefined4 *)(iVar6 + 0x2c);
          puVar16[0xc] = *(undefined4 *)(iVar6 + 0x30);
          puVar16[0xd] = *(undefined4 *)(iVar6 + 0x34);
          puVar16[0xf] = *(undefined4 *)(iVar6 + 0x38);
          puVar16[4] = *(float *)(iVar6 + 0x18) + (float)puVar16[1];
          puVar16[6] = *(float *)(iVar6 + 0x1c) + (float)puVar16[1];
          puVar16[5] = (float)puVar16[4] - (float)puVar16[1];
          puVar16[7] = (float)puVar16[6] - (float)puVar16[1];
          puVar16[0xe] = *(undefined4 *)(iVar6 + 0x3c);
          puVar16[0x10] = *(undefined4 *)(iVar6 + 0x40);
          puVar16[0x11] = *(undefined4 *)(iVar6 + 0x44);
          cVar2 = *(char *)(iVar6 + 0x49);
          *(char *)((int)puVar16 + 0x4a) = cVar2;
          if (cVar2 == '\x02') {
            fVar20 = (float10)FUN_005c0240((float)puVar16[0x10] * (float)puVar16[0x10] +
                                           (float)puVar16[0x11] * (float)puVar16[0x11]);
LAB_005385ae:
            puVar16[3] = (float)fVar20;
          }
          else if (cVar2 == '\x01') {
            if ((float)puVar16[0x10] <= (float)puVar16[0x11]) {
              fVar20 = (float10)(float)puVar16[0x11];
            }
            else {
              fVar20 = (float10)(float)puVar16[0x10];
            }
            goto LAB_005385ae;
          }
          iVar6 = FUN_004f1460(DAT_009238e4 + 0x43814,iVar6);
          iVar14 = iVar14 + 0x58;
        } while (iVar6 != 0);
      }
    }
    if (((*(int *)(DAT_009238e4 + 100) != 0) &&
        (iVar6 = *(int *)(*(int *)(DAT_009238e4 + 100) + 0x10), iVar6 != 0)) &&
       ((iVar14 = **(int **)(iVar6 + 4), iVar14 != 0 && (iVar14 != *(int *)(iVar6 + 8))))) {
      *(int *)(iVar6 + 8) = iVar14;
    }
  }
  return;
}

