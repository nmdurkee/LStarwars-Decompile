/* Ghidra pseudocode, not original source.
 * ev_1794ca22652287671530b7d2e638694f2898180de05a8f26cc5ace6b6aa326ae
 * Entry: 0x4d0b80; label: FUN_004d0b80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d0b80(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint *puVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined2 *puVar11;
  int iVar12;
  uint *puVar13;
  float10 fVar14;
  int local_b8c;
  float afStack_b88 [64];
  int aiStack_a88 [64];
  undefined1 local_988 [64];
  undefined4 local_948;
  undefined4 local_944;
  undefined4 local_940;
  undefined4 local_930 [3];
  undefined4 local_924 [585];
  
  uVar9 = *(uint *)(param_1 + 0x5058);
  if (uVar9 != 0) {
    puVar7 = local_930;
    iVar10 = 0x42;
    do {
      *puVar7 = 0xffffffff;
      puVar7 = puVar7 + 9;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    if (0 < *(int *)(param_1 + 0x505c)) {
      local_b8c = 0;
      do {
        iVar12 = 0;
        iVar10 = uVar9 + 0x10;
        puVar11 = (undefined2 *)(uVar9 + 0x2c);
        do {
          if (((*(char *)(uVar9 + 0x46) != '\0') ||
              ((*(char *)(uVar9 + 0x32) != '\0' && (iVar12 < 1)))) &&
             (iVar5 = ((*(char *)(iVar12 + 0x30 + uVar9) != '\0') + 0x3f) * 0x10,
             *(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe + iVar5) != '\0')) {
            FUN_005b45f0(local_988,puVar11[-2]);
            FUN_005b4f70(local_988,*puVar11);
            FUN_005b4900(local_988,iVar10);
            FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + iVar5,local_988);
          }
          iVar12 = iVar12 + 1;
          puVar11 = puVar11 + 1;
          iVar10 = iVar10 + 0xc;
        } while (iVar12 < 2);
        if ((*(char *)(uVar9 + 0x47) != '\0') && (*(char *)(uVar9 + 0x46) != '\0')) {
          iVar10 = 0;
          if (0 < DAT_0093d500) {
            puVar13 = (uint *)(DAT_0093d504 + 0x1fc);
            iVar12 = 0;
            do {
              if ((((((*puVar13 & 1) != 0) && ((*puVar13 & 0x1000) != 0)) &&
                   (*(char *)((int)puVar13 + 0x5b9) == 'D')) &&
                  ((*(short *)((int)puVar13 + 0x5ae) != 6 && (*(short *)((int)puVar13 + 0x5ae) != 5)
                   ))) && (puVar13[0x167] == uVar9)) {
                puVar6 = puVar13 + -0x18;
                if ((*(uint *)(*(int *)(puVar13[-0x6a] + 0x24) + 0x90) & 0x80000) == 0) {
                  puVar6 = puVar13 + -0x1b;
                }
                aiStack_a88[iVar10] = (int)puVar6;
                fVar14 = (float10)FUN_005becc0(puVar6,uVar9 + 0x10,0);
                afStack_b88[iVar10] = (float)fVar14;
                iVar10 = iVar10 + 1;
                if (iVar10 == 0x40) break;
              }
              iVar12 = iVar12 + 1;
              puVar13 = puVar13 + 0x436;
            } while (iVar12 < DAT_0093d500);
            if ((1 < iVar10) && (iVar12 = iVar10 + -1, iVar5 = iVar12, 0 < iVar12)) {
              do {
                iVar8 = 0;
                if (3 < iVar12) {
                  do {
                    if (afStack_b88[iVar8 + 1] < afStack_b88[iVar8]) {
                      fVar1 = afStack_b88[iVar8];
                      iVar3 = aiStack_a88[iVar8];
                      fVar2 = afStack_b88[iVar8 + 1];
                      aiStack_a88[iVar8] = aiStack_a88[iVar8 + 1];
                      afStack_b88[iVar8] = fVar2;
                      aiStack_a88[iVar8 + 1] = iVar3;
                      afStack_b88[iVar8 + 1] = fVar1;
                    }
                    if (afStack_b88[iVar8 + 2] < afStack_b88[iVar8 + 1]) {
                      fVar1 = afStack_b88[iVar8 + 1];
                      iVar3 = aiStack_a88[iVar8 + 1];
                      fVar2 = afStack_b88[iVar8 + 2];
                      aiStack_a88[iVar8 + 1] = aiStack_a88[iVar8 + 2];
                      afStack_b88[iVar8 + 1] = fVar2;
                      aiStack_a88[iVar8 + 2] = iVar3;
                      afStack_b88[iVar8 + 2] = fVar1;
                    }
                    if (afStack_b88[iVar8 + 3] < afStack_b88[iVar8 + 2]) {
                      fVar1 = afStack_b88[iVar8 + 2];
                      iVar3 = aiStack_a88[iVar8 + 2];
                      fVar2 = afStack_b88[iVar8 + 3];
                      aiStack_a88[iVar8 + 2] = aiStack_a88[iVar8 + 3];
                      afStack_b88[iVar8 + 2] = fVar2;
                      aiStack_a88[iVar8 + 3] = iVar3;
                      afStack_b88[iVar8 + 3] = fVar1;
                    }
                    if (afStack_b88[iVar8 + 4] < afStack_b88[iVar8 + 3]) {
                      fVar1 = afStack_b88[iVar8 + 3];
                      iVar3 = aiStack_a88[iVar8 + 3];
                      fVar2 = afStack_b88[iVar8 + 4];
                      aiStack_a88[iVar8 + 3] = aiStack_a88[iVar8 + 4];
                      afStack_b88[iVar8 + 3] = fVar2;
                      aiStack_a88[iVar8 + 4] = iVar3;
                      afStack_b88[iVar8 + 4] = fVar1;
                    }
                    iVar8 = iVar8 + 4;
                  } while (iVar8 < iVar10 + -4);
                }
                for (; iVar8 < iVar12; iVar8 = iVar8 + 1) {
                  if (afStack_b88[iVar8 + 1] < afStack_b88[iVar8]) {
                    fVar1 = afStack_b88[iVar8];
                    iVar3 = aiStack_a88[iVar8];
                    fVar2 = afStack_b88[iVar8 + 1];
                    aiStack_a88[iVar8] = aiStack_a88[iVar8 + 1];
                    afStack_b88[iVar8] = fVar2;
                    aiStack_a88[iVar8 + 1] = iVar3;
                    afStack_b88[iVar8 + 1] = fVar1;
                  }
                }
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
            }
          }
          local_948 = *(undefined4 *)(uVar9 + 0x10);
          local_944 = *(undefined4 *)(uVar9 + 0x14);
          iVar12 = 0;
          local_940 = *(undefined4 *)(uVar9 + 0x18);
          if (0 < iVar10) {
            puVar7 = local_924;
            do {
              puVar4 = (undefined4 *)aiStack_a88[iVar12];
              *puVar7 = *puVar4;
              puVar7[1] = puVar4[1];
              puVar7[2] = puVar4[2];
              iVar12 = iVar12 + 1;
              puVar7 = puVar7 + 9;
            } while (iVar12 < iVar10);
          }
          local_924[iVar10 * 9] = *(undefined4 *)(uVar9 + 0x1c);
          local_924[iVar10 * 9 + 1] = *(undefined4 *)(uVar9 + 0x20);
          local_924[iVar10 * 9 + 2] = *(undefined4 *)(uVar9 + 0x24);
          if (-1 < iVar10) {
            puVar7 = &local_948;
            iVar10 = iVar10 + 1;
            do {
              FUN_005dbed0(puVar7,DAT_0093b108,0);
              puVar7 = puVar7 + 9;
              iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
          }
        }
        local_b8c = local_b8c + 1;
        uVar9 = uVar9 + 0x48;
      } while (local_b8c < *(int *)(param_1 + 0x505c));
    }
  }
  return;
}

