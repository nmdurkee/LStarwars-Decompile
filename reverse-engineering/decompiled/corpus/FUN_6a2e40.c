/* Ghidra analysis pseudocode, not original source.
 * ev_84e5cb8303fa38d748e4458d34c9d4265893eb5844f058a0a1436ec0ce38dbe0
 * Entry: 0x6a2e40; label: FUN_006a2e40
 */

int FUN_006a2e40(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  byte bVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int local_1c;
  
  iVar3 = *(int *)(param_1 + 4);
  piVar4 = *(int **)(iVar3 + 0x1c);
  iVar5 = piVar4[*(int *)(param_1 + 0x28)];
  bVar10 = (char)piVar4[0x392] + 1;
  uVar15 = *piVar4 >> (bVar10 & 0x1f);
  iVar14 = piVar4[1] >> (bVar10 & 0x1f);
  if (*(int *)(param_1 + 0x18) < 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x30) == iVar14) {
    local_1c = 0;
    if (0 < *(int *)(iVar3 + 4)) {
      do {
        iVar6 = *(int *)(*(int *)(param_1 + 8) + local_1c * 4);
        iVar13 = 0;
        if (3 < iVar14) {
          iVar16 = (iVar14 - 4U >> 2) + 1;
          iVar13 = iVar16 * 4;
          puVar9 = (undefined4 *)(iVar6 + iVar14 * 4);
          puVar11 = (undefined4 *)(iVar6 + 8);
          do {
            uVar2 = puVar11[-2];
            iVar16 = iVar16 + -1;
            puVar11[-2] = *puVar9;
            *puVar9 = uVar2;
            uVar2 = puVar11[-1];
            puVar11[-1] = puVar9[1];
            puVar9[1] = uVar2;
            uVar2 = *puVar11;
            *puVar11 = puVar9[2];
            puVar9[2] = uVar2;
            uVar2 = puVar11[1];
            puVar11[1] = puVar9[3];
            puVar9[3] = uVar2;
            puVar9 = puVar9 + 4;
            puVar11 = puVar11 + 4;
          } while (iVar16 != 0);
        }
        if (iVar13 < iVar14) {
          puVar9 = (undefined4 *)(iVar6 + (iVar13 + iVar14) * 4);
          do {
            uVar2 = *(undefined4 *)(iVar6 + iVar13 * 4);
            iVar13 = iVar13 + 1;
            *(undefined4 *)(iVar6 + -4 + iVar13 * 4) = *puVar9;
            *puVar9 = uVar2;
            puVar9 = puVar9 + 1;
          } while (iVar13 < iVar14);
        }
        local_1c = local_1c + 1;
      } while (local_1c < *(int *)(iVar3 + 4));
    }
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - iVar14;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) - iVar14;
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if ((*(uint *)(param_1 + 0x28) ^ *(uint *)(param_1 + 0x24)) == 1) {
    local_1c = 0;
    if (0 < *(int *)(iVar3 + 4)) {
      iVar6 = ((int)(iVar14 - uVar15) / 2) * 4;
      uVar8 = (int)(uVar15 + iVar14) / 2;
      iVar13 = uVar8 - 1;
      do {
        iVar7 = *(int *)(*(int *)(param_1 + 8) + local_1c * 4);
        iVar16 = iVar6 + iVar7;
        iVar12 = iVar13;
        if (3 < (int)uVar8) {
          uVar17 = uVar8 >> 2;
          iVar12 = iVar13 + uVar17 * -4;
          puVar9 = (undefined4 *)(iVar16 + -4 + iVar13 * 4);
          puVar11 = (undefined4 *)(iVar7 + -0xc + iVar13 * 4);
          do {
            puVar9[1] = puVar11[3];
            uVar17 = uVar17 - 1;
            *puVar9 = *(undefined4 *)((iVar7 - iVar16) + 0x10 + (int)(puVar9 + -4));
            puVar9[-1] = puVar11[1];
            puVar9[-2] = *puVar11;
            puVar9 = puVar9 + -4;
            puVar11 = puVar11 + -4;
          } while (uVar17 != 0);
        }
        if (-1 < iVar12) {
          iVar16 = iVar6 + iVar7;
          puVar9 = (undefined4 *)(iVar16 + iVar12 * 4);
          do {
            iVar12 = iVar12 + -1;
            *puVar9 = *(undefined4 *)((int)puVar9 + (iVar7 - iVar16));
            puVar9 = puVar9 + -1;
          } while (-1 < iVar12);
        }
        local_1c = local_1c + 1;
      } while (local_1c < *(int *)(iVar3 + 4));
    }
    iVar13 = (int)(iVar14 - uVar15) / 2;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + iVar13;
  }
  else {
    if (*(uint *)(param_1 + 0x24) != 0) goto LAB_006a314b;
    local_1c = 0;
    if (0 < *(int *)(iVar3 + 4)) {
      iVar13 = (iVar14 - uVar15) * 4;
      do {
        iVar12 = *(int *)(*(int *)(param_1 + 8) + local_1c * 4);
        iVar16 = uVar15 - 1;
        iVar6 = iVar13 + iVar12;
        if (3 < (int)uVar15) {
          iVar7 = iVar16 * 4;
          uVar8 = uVar15 >> 2;
          iVar1 = iVar16 * 4;
          iVar16 = iVar16 + uVar8 * -4;
          puVar9 = (undefined4 *)(iVar6 + -4 + iVar7);
          puVar11 = (undefined4 *)(iVar12 + -0xc + iVar1);
          do {
            puVar9[1] = puVar11[3];
            uVar8 = uVar8 - 1;
            *puVar9 = *(undefined4 *)((iVar12 - iVar6) + 0x10 + (int)(puVar9 + -4));
            puVar9[-1] = puVar11[1];
            puVar9[-2] = *puVar11;
            puVar9 = puVar9 + -4;
            puVar11 = puVar11 + -4;
          } while (uVar8 != 0);
        }
        if (-1 < iVar16) {
          iVar6 = iVar13 + iVar12;
          puVar9 = (undefined4 *)(iVar6 + iVar16 * 4);
          do {
            iVar16 = iVar16 + -1;
            *puVar9 = *(undefined4 *)((int)puVar9 + (iVar12 - iVar6));
            puVar9 = puVar9 + -1;
          } while (-1 < iVar16);
        }
        local_1c = local_1c + 1;
      } while (local_1c < *(int *)(iVar3 + 4));
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + (iVar14 - uVar15);
    iVar13 = iVar14 - uVar15;
  }
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + iVar13;
LAB_006a314b:
  if (param_2 != (undefined4 *)0x0) {
    iVar13 = 0;
    if (0 < *(int *)(iVar3 + 4)) {
      do {
        *(int *)(*(int *)(param_1 + 0xc) + iVar13 * 4) =
             *(int *)(*(int *)(param_1 + 8) + iVar13 * 4) + *(int *)(param_1 + 0x18) * 4;
        iVar13 = iVar13 + 1;
      } while (iVar13 < *(int *)(iVar3 + 4));
    }
    *param_2 = *(undefined4 *)(param_1 + 0xc);
  }
  return (iVar14 - *(int *)(param_1 + 0x18)) + (iVar5 >> (bVar10 & 0x1f));
}

