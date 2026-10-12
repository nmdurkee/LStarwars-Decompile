/* Ghidra analysis pseudocode, not original source.
 * ev_acb06b3e4b799a53163de8490d9831a732be2977530d73e58478bea7efdd9d98
 * Entry: 0x675840; label: FUN_00675840
 */

void FUN_00675840(undefined4 param_1,byte param_2)

{
  char *pcVar1;
  undefined2 *puVar2;
  float fVar3;
  float fVar4;
  byte bVar5;
  undefined1 uVar6;
  ushort *puVar7;
  float fVar8;
  uint uVar9;
  float *pfVar10;
  float *pfVar11;
  int iVar12;
  float *pfVar13;
  int iVar14;
  float10 fVar15;
  float local_1c;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar12 = DAT_0292186c;
  DAT_02962b2c = 0;
  DAT_02924b34 = DAT_02962b30;
  pcVar1 = (char *)(DAT_0292186c + 0x34);
  puVar2 = (undefined2 *)(DAT_0292186c + 0x148);
  DAT_0292119c = 0;
  *(undefined2 *)(DAT_0292186c + 0x8a) = 0xffff;
  if (*pcVar1 == '\x01') {
    if (*(float *)(iVar12 + 0x28) <= 0.0) {
      local_10 = ((*(float *)(iVar12 + 0x1c) + *(float *)(iVar12 + 0x28)) - 0.02) -
                 *(float *)(iVar12 + 0x50);
      fVar3 = *(float *)(iVar12 + 0x1c);
    }
    else {
      local_10 = (*(float *)(iVar12 + 0x1c) - 0.02) - *(float *)(iVar12 + 0x50);
      fVar3 = *(float *)(iVar12 + 0x1c) + *(float *)(iVar12 + 0x28);
    }
    local_1c = fVar3 + 0.02 + *(float *)(iVar12 + 0x50);
    if (*(float *)(iVar12 + 0x2c) <= 0.0) {
      local_8 = ((*(float *)(iVar12 + 0x2c) + *(float *)(iVar12 + 0x20)) - 0.02) -
                *(float *)(iVar12 + 0x50);
      fVar3 = *(float *)(iVar12 + 0x20);
    }
    else {
      local_8 = (*(float *)(iVar12 + 0x20) - 0.02) - *(float *)(iVar12 + 0x50);
      fVar3 = *(float *)(iVar12 + 0x2c) + *(float *)(iVar12 + 0x20);
    }
    if (*(float *)(iVar12 + 0x30) <= 0.0) {
      local_c = ((*(float *)(iVar12 + 0x30) + *(float *)(iVar12 + 0x24)) - 0.02) -
                *(float *)(iVar12 + 0x50);
      fVar4 = *(float *)(iVar12 + 0x24);
    }
    else {
      local_c = (*(float *)(iVar12 + 0x24) - 0.02) - *(float *)(iVar12 + 0x50);
      fVar4 = *(float *)(iVar12 + 0x30) + *(float *)(iVar12 + 0x24);
    }
    local_14 = fVar4 + 0.02 + *(float *)(iVar12 + 0x50);
    local_8 = local_8 - (fVar3 + 0.02 + *(float *)(iVar12 + 0x50));
    FUN_005c0240((local_c - local_14) * (local_c - local_14) +
                 (local_10 - local_1c) * (local_10 - local_1c) + local_8 * local_8);
  }
  else {
    fVar15 = (float10)FUN_005c0240(*(float *)(iVar12 + 0x30) * *(float *)(iVar12 + 0x30) +
                                   *(float *)(iVar12 + 0x28) * *(float *)(iVar12 + 0x28) +
                                   *(float *)(iVar12 + 0x2c) * *(float *)(iVar12 + 0x2c));
    local_c = *(float *)(DAT_0292186c + 0x50) + 0.1 + (float)fVar15;
    local_1c = local_c + *(float *)(DAT_0292186c + 0x1c) + 0.05;
    local_14 = *(float *)(DAT_0292186c + 0x24) + 0.05 + local_c;
    local_10 = (*(float *)(DAT_0292186c + 0x1c) - 0.05) - local_c;
    local_c = (*(float *)(DAT_0292186c + 0x24) - 0.05) - local_c;
  }
  *puVar2 = 0;
  *(undefined2 *)(iVar12 + 0x14a) = 0;
  local_10 = local_10 - 0.02;
  puVar7 = *(ushort **)(DAT_0292fc68 + 0x148);
  iVar12 = 0;
  fVar3 = local_c - 0.02;
  DAT_02924ab8 = 0;
  local_1c = local_1c + 0.02;
  fVar4 = local_14 + 0.02;
  for (; puVar7 != (ushort *)0x0; puVar7 = *(ushort **)(puVar7 + -2)) {
    bVar5 = *(byte *)((int)puVar7 + 3);
    if ((bVar5 == 0) || ((param_2 & bVar5) != 0)) {
      uVar9 = (uint)*puVar7;
      uVar6 = (undefined1)puVar7[1];
      local_14 = 0.0;
      if (uVar9 != 0) {
        pfVar13 = (float *)(puVar7 + 4);
        do {
          local_c = (float)uVar9;
          if (*pfVar13 != 2.1474836e+09) {
            if ((((pfVar13[3] < local_10) || (*pfVar13 < local_1c == (*pfVar13 == local_1c))) ||
                (pfVar13[9] < fVar3)) || (pfVar13[6] < fVar4 == (pfVar13[6] == fVar4))) {
              local_c = 0.0;
            }
            else {
              local_c = (float)((int)local_14 + 0x10U);
              if ((int)uVar9 < (int)((int)local_14 + 0x10U)) {
                local_c = (float)uVar9;
              }
            }
          }
          fVar8 = local_14;
          if (3 < (int)local_c - (int)local_14) {
            pfVar10 = (float *)(iVar12 * 0x10 + DAT_0292fb50);
            pfVar11 = pfVar13 + -1;
            iVar14 = (((int)local_c - (int)local_14) - 4U >> 2) + 1;
            fVar8 = (float)((int)local_14 + iVar14 * 4);
            do {
              if (((((local_10 <= *pfVar11) && (pfVar11[3] < local_1c != (pfVar11[3] == local_1c)))
                   || ((local_10 <= pfVar11[3] && (*pfVar11 < local_1c != (*pfVar11 == local_1c)))))
                  && (((fVar3 <= pfVar11[2] && (pfVar11[5] < fVar4 != (pfVar11[5] == fVar4))) ||
                      ((fVar3 <= pfVar11[5] && (pfVar11[2] < fVar4 != (pfVar11[2] == fVar4))))))) &&
                 (iVar12 < 0x40)) {
                *pfVar10 = *pfVar11;
                pfVar10[1] = pfVar11[1];
                pfVar10[2] = pfVar11[2];
                *(undefined1 *)(pfVar10 + 3) = uVar6;
                *(byte *)((int)pfVar10 + 0xd) = bVar5;
                *(undefined1 *)((int)pfVar10 + 0xe) = 0;
                *(undefined1 *)((int)pfVar10 + 0xf) = 0;
                pfVar10[4] = pfVar11[3];
                pfVar10[5] = pfVar11[4];
                pfVar10[6] = pfVar11[5];
                *(undefined1 *)(pfVar10 + 7) = uVar6;
                *(byte *)((int)pfVar10 + 0x1d) = bVar5;
                *(undefined1 *)((int)pfVar10 + 0x1e) = 0;
                *(undefined1 *)((int)pfVar10 + 0x1f) = 0;
                iVar12 = iVar12 + 2;
                pfVar10 = pfVar10 + 8;
              }
              if (((((local_10 <= pfVar11[3]) && (pfVar11[6] < local_1c != (pfVar11[6] == local_1c))
                    ) || ((local_10 <= pfVar11[6] &&
                          (pfVar11[3] < local_1c != (pfVar11[3] == local_1c))))) &&
                  (((fVar3 <= pfVar11[5] && (pfVar11[8] < fVar4 != (pfVar11[8] == fVar4))) ||
                   ((fVar3 <= pfVar11[8] && (pfVar11[5] < fVar4 != (pfVar11[5] == fVar4))))))) &&
                 (iVar12 < 0x40)) {
                *pfVar10 = pfVar11[3];
                pfVar10[1] = pfVar11[4];
                pfVar10[2] = pfVar11[5];
                *(undefined1 *)(pfVar10 + 3) = uVar6;
                *(byte *)((int)pfVar10 + 0xd) = bVar5;
                *(undefined1 *)((int)pfVar10 + 0xe) = 0;
                *(undefined1 *)((int)pfVar10 + 0xf) = 0;
                pfVar10[4] = pfVar11[6];
                pfVar10[5] = pfVar11[7];
                pfVar10[6] = pfVar11[8];
                *(undefined1 *)(pfVar10 + 7) = uVar6;
                *(byte *)((int)pfVar10 + 0x1d) = bVar5;
                *(undefined1 *)((int)pfVar10 + 0x1e) = 0;
                *(undefined1 *)((int)pfVar10 + 0x1f) = 0;
                iVar12 = iVar12 + 2;
                pfVar10 = pfVar10 + 8;
              }
              if (((((local_10 <= pfVar11[6]) && (pfVar11[9] < local_1c != (pfVar11[9] == local_1c))
                    ) || ((local_10 <= pfVar11[9] &&
                          (pfVar11[6] < local_1c != (pfVar11[6] == local_1c))))) &&
                  (((fVar3 <= pfVar11[8] && (pfVar11[0xb] < fVar4 != (pfVar11[0xb] == fVar4))) ||
                   ((fVar3 <= pfVar11[0xb] && (pfVar11[8] < fVar4 != (pfVar11[8] == fVar4))))))) &&
                 (iVar12 < 0x40)) {
                *pfVar10 = pfVar11[6];
                pfVar10[1] = pfVar11[7];
                pfVar10[2] = pfVar11[8];
                *(undefined1 *)(pfVar10 + 3) = uVar6;
                *(byte *)((int)pfVar10 + 0xd) = bVar5;
                *(undefined1 *)((int)pfVar10 + 0xe) = 0;
                *(undefined1 *)((int)pfVar10 + 0xf) = 0;
                pfVar10[4] = pfVar11[9];
                pfVar10[5] = pfVar11[10];
                pfVar10[6] = pfVar11[0xb];
                *(undefined1 *)(pfVar10 + 7) = uVar6;
                *(byte *)((int)pfVar10 + 0x1d) = bVar5;
                *(undefined1 *)((int)pfVar10 + 0x1e) = 0;
                *(undefined1 *)((int)pfVar10 + 0x1f) = 0;
                iVar12 = iVar12 + 2;
                pfVar10 = pfVar10 + 8;
              }
              if (((((local_10 <= pfVar11[9]) &&
                    (pfVar11[0xc] < local_1c != (pfVar11[0xc] == local_1c))) ||
                   ((local_10 <= pfVar11[0xc] && (pfVar11[9] < local_1c != (pfVar11[9] == local_1c))
                    ))) && (((fVar3 <= pfVar11[0xb] &&
                             (pfVar11[0xe] < fVar4 != (pfVar11[0xe] == fVar4))) ||
                            ((fVar3 <= pfVar11[0xe] &&
                             (pfVar11[0xb] < fVar4 != (pfVar11[0xb] == fVar4))))))) &&
                 (iVar12 < 0x40)) {
                *pfVar10 = pfVar11[9];
                pfVar10[1] = pfVar11[10];
                pfVar10[2] = pfVar11[0xb];
                *(undefined1 *)(pfVar10 + 3) = uVar6;
                *(byte *)((int)pfVar10 + 0xd) = bVar5;
                *(undefined1 *)((int)pfVar10 + 0xe) = 0;
                *(undefined1 *)((int)pfVar10 + 0xf) = 0;
                pfVar10[4] = pfVar11[0xc];
                pfVar10[5] = pfVar11[0xd];
                pfVar10[6] = pfVar11[0xe];
                *(undefined1 *)(pfVar10 + 7) = uVar6;
                *(byte *)((int)pfVar10 + 0x1d) = bVar5;
                *(undefined1 *)((int)pfVar10 + 0x1e) = 0;
                *(undefined1 *)((int)pfVar10 + 0x1f) = 0;
                iVar12 = iVar12 + 2;
                pfVar10 = pfVar10 + 8;
              }
              pfVar11 = pfVar11 + 0xc;
              iVar14 = iVar14 + -1;
            } while (iVar14 != 0);
          }
          if ((int)fVar8 < (int)local_c) {
            pfVar11 = (float *)(iVar12 * 0x10 + DAT_0292fb50);
            pfVar10 = (float *)(puVar7 + ((int)fVar8 * 3 + 3) * 2);
            iVar14 = (int)local_c - (int)fVar8;
            do {
              if (((((local_10 <= pfVar10[-2]) &&
                    (pfVar10[1] < local_1c != (pfVar10[1] == local_1c))) ||
                   ((local_10 <= pfVar10[1] && (pfVar10[-2] < local_1c != (pfVar10[-2] == local_1c))
                    ))) && (((fVar3 <= *pfVar10 && (pfVar10[3] < fVar4 != (pfVar10[3] == fVar4))) ||
                            ((fVar3 <= pfVar10[3] && (*pfVar10 < fVar4 != (*pfVar10 == fVar4)))))))
                 && (iVar12 < 0x40)) {
                *pfVar11 = pfVar10[-2];
                pfVar11[1] = pfVar10[-1];
                pfVar11[2] = *pfVar10;
                *(undefined1 *)(pfVar11 + 3) = uVar6;
                *(byte *)((int)pfVar11 + 0xd) = bVar5;
                *(undefined1 *)((int)pfVar11 + 0xe) = 0;
                *(undefined1 *)((int)pfVar11 + 0xf) = 0;
                pfVar11[4] = pfVar10[1];
                pfVar11[5] = pfVar10[2];
                pfVar11[6] = pfVar10[3];
                *(undefined1 *)(pfVar11 + 7) = uVar6;
                *(byte *)((int)pfVar11 + 0x1d) = bVar5;
                *(undefined1 *)((int)pfVar11 + 0x1e) = 0;
                *(undefined1 *)((int)pfVar11 + 0x1f) = 0;
                iVar12 = iVar12 + 2;
                pfVar11 = pfVar11 + 8;
              }
              pfVar10 = pfVar10 + 3;
              iVar14 = iVar14 + -1;
            } while (iVar14 != 0);
          }
          uVar9 = (uint)*puVar7;
          pfVar13 = pfVar13 + 0x30;
          local_14 = (float)((int)local_14 + 0x10);
          DAT_02924ab8 = iVar12;
        } while ((int)local_14 < (int)uVar9);
      }
    }
  }
  DAT_02948edc = 0;
  return;
}

