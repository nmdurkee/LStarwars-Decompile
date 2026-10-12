/* Ghidra analysis pseudocode, not original source.
 * ev_c81f74825c4c1caab95b487b54d809df2f5062ed260a25fe246075816e66607e
 * Entry: 0x5df910; label: FUN_005df910
 */

void FUN_005df910(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  ushort *puVar10;
  int iVar11;
  int unaff_ESI;
  int iVar12;
  int local_24;
  int local_20;
  int local_1c;
  int local_14;
  
  iVar2 = *(int *)(unaff_ESI + 0x18);
  uVar5 = *(uint *)(unaff_ESI + 0x74) >> 0xf;
  iVar6 = *(int *)(unaff_ESI + 0x10) + 0xf;
  iVar6 = (int)(iVar6 + (iVar6 >> 0x1f & 0xfU)) >> 4;
  piVar9 = *(int **)(unaff_ESI + 0x30 + (uVar5 & 1) * 4);
  local_24 = 0;
  local_14 = 0;
  if (0 < iVar6) {
    iVar12 = *(int *)(unaff_ESI + 0x30 + (~uVar5 & 1) * 4) - (int)piVar9;
    do {
      if (*piVar9 == *(int *)(iVar12 + (int)piVar9)) {
        local_24 = local_24 + 0x10;
      }
      else {
        local_1c = 0;
        do {
          bVar1 = *(byte *)((int)piVar9 + local_1c);
          local_20 = 0;
          iVar11 = local_24 * 0xc;
          puVar10 = (ushort *)(iVar2 + local_24 * 2);
          do {
            iVar3 = *(int *)(iVar11 + 8 + *(int *)(unaff_ESI + 0x14));
            bVar4 = bVar1 >> ((byte)local_20 & 0x1f);
            uVar5 = bVar4 & 3;
            if ((bVar4 & 3) == 0) {
              if (*puVar10 != 0) {
                do {
                  iVar7 = *(int *)(iVar3 + uVar5 * 4) * 0x10 + *(int *)(unaff_ESI + 8);
                  uVar5 = uVar5 + 1;
                  *(undefined1 *)(iVar7 + 1) = 0;
                  *(undefined1 *)(iVar7 + -0xf) = 0;
                } while ((int)uVar5 < (int)(uint)*puVar10);
              }
            }
            else if (uVar5 == 1) {
              iVar7 = 0;
              if (*puVar10 != 0) {
                do {
                  iVar8 = *(int *)(iVar3 + iVar7 * 4) * 0x10 + *(int *)(unaff_ESI + 8);
                  iVar7 = iVar7 + 1;
                  *(undefined1 *)(iVar8 + 1) = 3;
                  *(undefined1 *)(iVar8 + -0xf) = 3;
                } while (iVar7 < (int)(uint)*puVar10);
              }
            }
            else {
              iVar7 = 0;
              if (*puVar10 != 0) {
                do {
                  iVar8 = *(int *)(iVar3 + iVar7 * 4) * 0x10 + *(int *)(unaff_ESI + 8);
                  iVar7 = iVar7 + 1;
                  *(undefined1 *)(iVar8 + 1) = 3;
                  *(undefined1 *)(iVar8 + -0xf) = 3;
                } while (iVar7 < (int)(uint)*puVar10);
              }
            }
            local_24 = local_24 + 1;
            iVar11 = iVar11 + 0xc;
            puVar10 = puVar10 + 1;
            if (*(int *)(unaff_ESI + 0x10) <= local_24) {
              return;
            }
            local_20 = local_20 + 2;
          } while (local_20 < 8);
          local_1c = local_1c + 1;
        } while (local_1c < 4);
      }
      local_14 = local_14 + 1;
      piVar9 = piVar9 + 1;
    } while (local_14 < iVar6);
  }
  return;
}

