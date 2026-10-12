/* Ghidra pseudocode, not original source.
 * ev_cede8c042851d77bd106acb1edcf2aeeffc4764a47601c9bcb205898acb43edb
 * Entry: 0x5de440; label: FUN_005de440
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005de440(void)

{
  int iVar1;
  short *psVar2;
  short *psVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  short *psVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  int extraout_ECX;
  int extraout_ECX_00;
  undefined1 *puVar13;
  int iVar14;
  int extraout_EDX;
  int extraout_EDX_00;
  int *piVar15;
  int iVar16;
  undefined4 *puVar17;
  short *psVar18;
  undefined4 *puVar19;
  int local_10;
  int local_c;
  short *local_4;
  
  if ((DAT_00973e4c != 0) || (DAT_00973e54 != 0)) {
    local_10 = 0;
    iVar10 = DAT_00973e08;
    iVar9 = DAT_00973e5c;
    if (0 < DAT_00973e54) {
      do {
        local_4 = *(short **)(DAT_00973e58 + local_10 * 4);
        if ((*(int *)(local_4 + 0x1e) != 0) && (iVar5 = 0, 0 < iVar10)) {
LAB_005de4a0:
          if (*(short **)(DAT_00973e0c + iVar5 * 4) != local_4) goto code_r0x005de4ab;
          if ((iVar5 == -1) ||
             (*(char *)(iVar9 + iVar5) = *(char *)(iVar9 + iVar5) + -1, iVar16 = DAT_0080bab0,
             iVar10 = DAT_00973e08, iVar9 = DAT_00973e5c, *(char *)(DAT_00973e5c + iVar5) != '\0'))
          goto LAB_005de74e;
          iVar10 = -1;
          iVar9 = 0;
          local_c = -1;
          piVar6 = DAT_00973e20;
          if (0 < DAT_00973e1c) {
            do {
              if (*piVar6 == ((int)(short)(*local_4 << 4) >> 8) * 0x20000 + (int)local_4[0x3b]) {
                iVar10 = iVar9;
              }
              iVar9 = iVar9 + 1;
              piVar6 = piVar6 + 9;
              local_c = iVar10;
            } while (iVar9 < DAT_00973e1c);
          }
          iVar10 = *(int *)(*(int *)(local_4 + 0x1e) + 0xc);
          iVar9 = local_c * 0x24;
          if (DAT_00973e20[local_c * 9 + 1] == iVar10) {
            DAT_00973e20[local_c * 9 + 1] = *(int *)(DAT_0080bab0 * 0x10 + 4 + iVar10);
LAB_005de596:
            iVar16 = iVar16 * 0x10;
            *(undefined1 *)(iVar16 + 1 + iVar10) = 4;
            *(undefined4 *)(iVar16 + 4 + iVar10) = 0;
            *(undefined1 *)(iVar16 + iVar10) = 0x84;
          }
          else {
            iVar7 = 0;
            if (*(ushort *)(DAT_00973e20 + local_c * 9 + 8) != 0) {
              iVar14 = DAT_0080bab0 * 0x10;
              piVar6 = (int *)(DAT_00973e0c +
                              (uint)*(ushort *)((int)DAT_00973e20 + iVar9 + 0x22) * 4);
              do {
                iVar1 = *(int *)(*(int *)(*piVar6 + 0x3c) + 0xc);
                if (*(int *)(iVar14 + 4 + iVar1) == iVar10) {
                  *(undefined4 *)(iVar14 + 4 + iVar1) = *(undefined4 *)(iVar14 + 4 + iVar10);
                  goto LAB_005de596;
                }
                iVar7 = iVar7 + 1;
                piVar6 = piVar6 + 1;
              } while (iVar7 < (int)(uint)*(ushort *)(DAT_00973e20 + local_c * 9 + 8));
            }
          }
          iVar16 = 0;
          if (0 < DAT_00973e08) {
            iVar7 = 0;
            do {
              if ((*(char *)(DAT_00973e6c + iVar16) != '\0') && (iVar10 == DAT_00973e64 + iVar7)) {
                *(undefined1 *)(DAT_00973e6c + iVar16) = 0;
                break;
              }
              iVar16 = iVar16 + 1;
              iVar7 = iVar7 + 0x80;
            } while (iVar16 < DAT_00973e08);
          }
          *(short *)(DAT_00973e20 + local_c * 9 + 8) = (short)DAT_00973e20[local_c * 9 + 8] + -1;
          if ((short)DAT_00973e20[local_c * 9 + 8] == 0) {
            piVar6 = DAT_00973ecc;
            if (DAT_00973ecc == DAT_00973e20 + local_c * 9) {
LAB_005de61d:
              DAT_00973ecc = (int *)piVar6[2];
            }
            else {
              do {
                piVar12 = piVar6;
                piVar6 = (int *)piVar12[2];
              } while (piVar6 != DAT_00973e20 + local_c * 9);
              if (piVar12 == (int *)0x0) goto LAB_005de61d;
              piVar12[2] = piVar6[2];
            }
            DAT_00973ec8 = DAT_00973ec8 + -1;
            if (local_c < DAT_00973e1c + -1) {
              do {
                puVar17 = (undefined4 *)((int)DAT_00973e20 + iVar9) + 9;
                puVar19 = (undefined4 *)((int)DAT_00973e20 + iVar9);
                for (iVar10 = 9; iVar10 != 0; iVar10 = iVar10 + -1) {
                  *puVar19 = *puVar17;
                  puVar17 = puVar17 + 1;
                  puVar19 = puVar19 + 1;
                }
                local_c = local_c + 1;
                iVar9 = iVar9 + 0x24;
              } while (local_c < DAT_00973e1c + -1);
            }
            DAT_00973e1c = DAT_00973e1c + -1;
          }
          uVar4 = *(undefined4 *)(DAT_00973e10 + iVar5 * 4);
          if (iVar5 < DAT_00973e08 + -1) {
            do {
              *(undefined4 *)(DAT_00973e0c + iVar5 * 4) =
                   *(undefined4 *)(DAT_00973e0c + 4 + iVar5 * 4);
              *(undefined4 *)(DAT_00973e10 + iVar5 * 4) =
                   *(undefined4 *)(DAT_00973e10 + 4 + iVar5 * 4);
              *(undefined1 *)(DAT_00973e5c + iVar5) = *(undefined1 *)(DAT_00973e5c + 1 + iVar5);
              iVar5 = iVar5 + 1;
            } while (iVar5 < DAT_00973e08 + -1);
          }
          *(undefined4 *)(DAT_00973e10 + -4 + DAT_00973e08 * 4) = uVar4;
          iVar10 = 0;
          *(undefined1 *)(DAT_00973e5c + -1 + DAT_00973e08) = 0;
          if (0 < DAT_00973e08) {
            do {
              if (*(char *)(DAT_00973e5c + iVar10) != '\0') {
                *(int *)(*(int *)(*(int *)(DAT_00973e0c + iVar10 * 4) + 0x3c) + 4) = iVar10;
              }
              iVar10 = iVar10 + 1;
            } while (iVar10 < DAT_00973e08);
          }
          FUN_005de390(&DAT_00973dbc);
          local_4[0x1e] = 0;
          local_4[0x1f] = 0;
          iVar10 = DAT_00973e08;
          iVar9 = DAT_00973e5c;
        }
LAB_005de74e:
        local_10 = local_10 + 1;
      } while (local_10 < DAT_00973e54);
    }
    DAT_00973e54 = 0;
    local_10 = 0;
    iVar9 = DAT_00973e5c;
    if (0 < DAT_00973e4c) {
LAB_005de780:
      psVar2 = *(short **)(DAT_00973e50 + local_10 * 4);
      iVar5 = 0;
      if (0 < iVar10) {
        do {
          if (*(short **)(DAT_00973e0c + iVar5 * 4) == psVar2) {
            if (iVar5 != -1) {
              *(char *)(iVar9 + iVar5) = *(char *)(iVar9 + iVar5) + '\x01';
              iVar9 = DAT_00973e5c;
              iVar10 = DAT_00973e08;
              goto LAB_005deaf8;
            }
            break;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar10);
      }
      psVar8 = (short *)0x0;
      if (iVar10 < 1) {
LAB_005de7d6:
        FUN_005c12e0();
        iVar9 = extraout_ECX_00;
        iVar10 = extraout_EDX_00;
      }
      else {
        do {
          if (*(char *)(iVar9 + (int)psVar8) == '\0') {
            local_4 = psVar8;
            if (psVar8 == (short *)0xffffffff) goto LAB_005de7d6;
            local_c = -1;
            iVar9 = 0;
            goto LAB_005de7f0;
          }
          psVar8 = (short *)((int)psVar8 + 1);
        } while ((int)psVar8 < iVar10);
        FUN_005c12e0();
        iVar9 = extraout_ECX;
        iVar10 = extraout_EDX;
      }
      goto LAB_005deaf8;
    }
LAB_005deb0b:
    DAT_00973e4c = 0;
  }
  return;
code_r0x005de4ab:
  iVar5 = iVar5 + 1;
  if (iVar10 <= iVar5) goto LAB_005de74e;
  goto LAB_005de4a0;
  while (iVar9 = iVar9 + 1, iVar9 < iVar10) {
LAB_005de7f0:
    if (*(char *)(DAT_00973e6c + iVar9) == '\0') {
      *(undefined1 *)(DAT_00973e6c + iVar9) = 1;
      iVar10 = DAT_00973e08;
      local_c = iVar9;
      break;
    }
  }
  iVar16 = ((int)(short)(*psVar2 << 4) >> 8) * 0x20000 + (int)psVar2[0x3b];
  iVar9 = -1;
  iVar5 = 0;
  piVar6 = DAT_00973e20;
  if (0 < DAT_00973e1c) {
    do {
      if (*piVar6 == iVar16) {
        iVar9 = iVar5;
      }
      iVar5 = iVar5 + 1;
      piVar6 = piVar6 + 9;
    } while (iVar5 < DAT_00973e1c);
  }
  psVar18 = (short *)0x0;
  if (0 < iVar10) {
    do {
      if ((*(char *)(DAT_00973e5c + (int)psVar18) != '\0') &&
         (psVar3 = *(short **)(DAT_00973e0c + (int)psVar18 * 4),
         iVar16 <= ((int)(short)(*psVar3 << 4) >> 8) * 0x20000 + (int)psVar3[0x3b])) {
        if (psVar18 != (short *)0xffffffff) goto LAB_005de890;
        break;
      }
      psVar18 = (short *)((int)psVar18 + 1);
    } while ((int)psVar18 < iVar10);
  }
  psVar18 = psVar8;
LAB_005de890:
  uVar4 = *(undefined4 *)(DAT_00973e10 + -4 + iVar10 * 4);
  for (iVar10 = iVar10 + -2; (int)psVar18 <= iVar10; iVar10 = iVar10 + -1) {
    *(undefined4 *)(DAT_00973e0c + 4 + iVar10 * 4) = *(undefined4 *)(DAT_00973e0c + iVar10 * 4);
    *(undefined4 *)(DAT_00973e10 + 4 + iVar10 * 4) = *(undefined4 *)(DAT_00973e10 + iVar10 * 4);
    *(undefined1 *)(DAT_00973e5c + 1 + iVar10) = *(undefined1 *)(DAT_00973e5c + iVar10);
  }
  *(undefined4 *)(DAT_00973e10 + (int)psVar18 * 4) = uVar4;
  iVar10 = 0;
  *(undefined1 *)(DAT_00973e5c + (int)psVar18) = 0;
  if (0 < DAT_00973e08) {
    do {
      if (*(char *)(DAT_00973e5c + iVar10) != '\0') {
        *(int *)(*(int *)(*(int *)(DAT_00973e0c + iVar10 * 4) + 0x3c) + 4) = iVar10;
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < DAT_00973e08);
  }
  *(undefined1 *)(DAT_00973e5c + (int)psVar18) = 1;
  iVar10 = *(int *)(DAT_00973e10 + (int)psVar18 * 4);
  *(int *)(psVar2 + 0x1e) = iVar10;
  local_4 = (short *)(local_c * 0x80 + DAT_00973e64);
  iVar5 = FUN_005de100(*(undefined4 *)(iVar10 + 0xc),psVar2,&local_4,DAT_00973e68);
  *(short **)(DAT_00973e0c + (int)psVar18 * 4) = psVar2;
  iVar10 = DAT_0080baac;
  *(int *)(*(int *)(psVar2 + 0x1e) + 0xc) = iVar5;
  *(int *)(*(int *)(psVar2 + 0x1e) + 0x18) = iVar10 * 0x10 + iVar5;
  **(undefined4 **)(psVar2 + 0x1e) = &DAT_00973dbc;
  *(short **)(*(int *)(psVar2 + 0x1e) + 4) = psVar18;
  iVar10 = DAT_00973e1c;
  if (iVar9 == -1) {
    if (599 < DAT_00973e1c) {
      iVar5 = FUN_005c12e0();
    }
    DAT_00973e20[iVar10 * 9] = iVar16;
    DAT_00973e20[iVar10 * 9 + 1] = iVar5;
    DAT_00973e20[iVar10 * 9 + 6] = DAT_00973e60;
    *(undefined2 *)(DAT_00973e20 + iVar10 * 9 + 8) = 0;
    piVar6 = DAT_00973e20 + iVar10 * 9;
    if (DAT_00973ecc == (int *)0x0) {
      DAT_00973ecc = piVar6;
      piVar6[2] = 0;
    }
    else {
      piVar12 = DAT_00973ecc;
      piVar15 = (int *)0x0;
      do {
        piVar11 = piVar12;
        piVar12 = piVar11;
        if (*piVar6 <= *piVar11) break;
        piVar12 = (int *)piVar11[2];
        piVar15 = piVar11;
      } while (piVar12 != (int *)0x0);
      if (piVar15 == (int *)0x0) {
        piVar6[2] = (int)DAT_00973ecc;
        DAT_00973ecc = piVar6;
      }
      else {
        piVar6[2] = (int)piVar12;
        piVar15[2] = (int)piVar6;
      }
    }
    DAT_00973ec8 = DAT_00973ec8 + 1;
    DAT_00973e1c = DAT_00973e1c + 1;
  }
  else {
    iVar10 = iVar9;
    if ((psVar18 == (short *)0x0) ||
       (psVar2 = *(short **)(DAT_00973e0c + -4 + (int)psVar18 * 4),
       ((int)(short)(*psVar2 << 4) >> 8) * 0x20000 + (int)psVar2[0x3b] != iVar16)) {
      iVar16 = DAT_00973e20[iVar9 * 9 + 1];
      puVar13 = (undefined1 *)(DAT_0080bab0 * 0x10 + iVar5);
      *puVar13 = 0x8d;
      *(int *)(puVar13 + 4) = iVar16;
      puVar13[1] = 1;
      DAT_00973e20[iVar9 * 9 + 1] = iVar5;
    }
    else {
      iVar9 = *(int *)(*(int *)(*(int *)(DAT_00973e0c + -4 + (int)psVar18 * 4) + 0x3c) + 0xc);
      iVar16 = DAT_0080bab0 * 0x10;
      uVar4 = *(undefined4 *)(iVar16 + 4 + iVar9);
      *(undefined1 *)(iVar16 + iVar5) = 0x8d;
      *(undefined4 *)(iVar16 + 4 + iVar5) = uVar4;
      *(undefined1 *)(iVar16 + 1 + iVar5) = 1;
      *(int *)(iVar16 + 4 + iVar9) = iVar5;
    }
  }
  *(short *)(DAT_00973e20 + iVar10 * 9 + 8) = (short)DAT_00973e20[iVar10 * 9 + 8] + 1;
  FUN_005de390(&DAT_00973dbc);
  iVar9 = DAT_00973e5c;
  iVar10 = DAT_00973e08;
LAB_005deaf8:
  local_10 = local_10 + 1;
  if (DAT_00973e4c <= local_10) goto LAB_005deb0b;
  goto LAB_005de780;
}

