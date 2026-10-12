/* Ghidra analysis pseudocode, not original source.
 * ev_87e0baa87b87192bf5be0b8e2e04b5bd4a3d9fde71e449b8cd1bb1bc961d5da7
 * Entry: 0x5efff0; label: FUN_005efff0
 */

int FUN_005efff0(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  int local_10;
  int local_c;
  
  *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
  puVar5 = DAT_009736e0;
  uVar1 = *DAT_009736e0;
  *DAT_009736e0 = uVar1 + 4 + DAT_00973ec8 * 4;
  iVar7 = 0;
  local_10 = 0;
  puVar10 = DAT_00973ecc;
  if (DAT_00973ecc != (undefined4 *)0x0) {
    do {
      iVar9 = puVar10[7];
      if ((iVar9 == 0) || ((*(uint *)(iVar9 + 0x74) & 0x10) == 0)) {
        if (((*(byte *)(puVar10 + 5) & 2) == 0) &&
           ((iVar9 == 0 || ((*(byte *)(iVar9 + 0x74) & 6) != 0)))) {
          *(undefined4 **)(uVar1 + iVar7 * 4) = puVar10;
          puVar10[5] = puVar10[5] | 2;
          goto LAB_005f01d7;
        }
      }
      else if ((*(uint *)(iVar9 + 0x74) & 2) != 0) {
        uVar2 = *puVar5;
        *puVar5 = (uVar2 + 3 & 0xfffffffc) + 0x24;
        puVar11 = (undefined4 *)(uVar2 + 3 & 0xfffffffc);
        *puVar11 = *puVar10;
        puVar11[1] = *puVar5;
        puVar11[7] = puVar10[7];
        *(undefined2 *)(puVar11 + 8) = *(undefined2 *)(puVar10 + 8);
        *(undefined2 *)((int)puVar11 + 0x22) = *(undefined2 *)((int)puVar10 + 0x22);
        iVar9 = 0;
        local_c = 0;
        if (*(short *)(puVar10 + 8) != 0) {
          iVar12 = 0;
          do {
            iVar7 = *(int *)(*(int *)(puVar10[7] + 0x54) +
                            ((uint)*(ushort *)((int)puVar10 + 0x22) + local_c) * 4);
            if (*(int *)(iVar7 + 0x14) != *(int *)(iVar7 + 0x10)) {
              iVar6 = *(int *)(iVar7 + 0xc);
              iVar3 = puVar11[1];
              if (*(char *)(iVar6 + 0x10) == -0x80) {
                *(undefined4 *)(iVar3 + iVar12) = *(undefined4 *)(iVar6 + 0x10);
                *(undefined4 *)(iVar3 + iVar12 + 4) = *(undefined4 *)(iVar6 + 0x14);
                *(undefined4 *)(iVar3 + iVar12 + 8) = *(undefined4 *)(iVar6 + 0x18);
                uVar8 = *(undefined4 *)(iVar6 + 0x1c);
              }
              else {
                *(undefined4 *)(iVar3 + iVar12) = *(undefined4 *)(iVar6 + 0x30);
                *(undefined4 *)(iVar3 + iVar12 + 4) = *(undefined4 *)(iVar6 + 0x34);
                *(undefined4 *)(iVar3 + iVar12 + 8) = *(undefined4 *)(iVar6 + 0x38);
                uVar8 = *(undefined4 *)(iVar6 + 0x3c);
              }
              *(undefined4 *)(iVar3 + iVar12 + 0xc) = uVar8;
              puVar4 = *(undefined4 **)(iVar7 + 0x10);
              iVar6 = puVar11[1];
              *(undefined4 *)(iVar6 + iVar12 + 0x10) = *puVar4;
              iVar6 = iVar6 + iVar12 + 0x10;
              *(undefined4 *)(iVar6 + 4) = puVar4[1];
              *(undefined4 *)(iVar6 + 8) = puVar4[2];
              *(undefined4 *)(iVar6 + 0xc) = puVar4[3];
              iVar12 = iVar12 + 0x20;
              *(int *)(*(int *)(iVar7 + 0x14) + 4) = puVar11[1] + iVar12;
              *(undefined4 *)(iVar7 + 0x14) = *(undefined4 *)(iVar7 + 0x10);
              iVar9 = iVar9 + 2;
              FUN_005fca40(*(undefined4 *)(iVar7 + 8));
            }
            local_c = local_c + 1;
            iVar7 = local_10;
          } while (local_c < (int)(uint)*(ushort *)(puVar10 + 8));
        }
        iVar9 = iVar9 * 0x10;
        *(undefined1 *)(iVar9 + 1 + puVar11[1]) = 4;
        *(undefined4 *)(iVar9 + 4 + puVar11[1]) = 0;
        *(undefined1 *)(iVar9 + puVar11[1]) = 0x84;
        *puVar5 = *puVar5 + iVar9 + 0x10;
        *(undefined4 **)(uVar1 + iVar7 * 4) = puVar11;
        puVar11[5] = puVar11[5] | 2;
LAB_005f01d7:
        iVar7 = iVar7 + 1;
        local_10 = iVar7;
      }
      puVar11 = puVar10 + 2;
      puVar10 = (undefined4 *)*puVar11;
    } while ((undefined4 *)*puVar11 != (undefined4 *)0x0);
    if (iVar7 != 0) goto LAB_005f0202;
  }
  if (DAT_00973e84 == DAT_00973e80) {
    return -1;
  }
LAB_005f0202:
  (&DAT_00973ed4)[DAT_00973ed0] = *puVar5 + 3 & 0xfffffffc;
  *puVar5 = (*puVar5 + 3 & 0xfffffffc) + 0x18;
  *(int *)(&DAT_00973ed4)[DAT_00973ed0] = iVar7;
  *(uint *)((&DAT_00973ed4)[DAT_00973ed0] + 4) = uVar1;
  puVar10 = DAT_00973e84;
  if (DAT_00973e84 == DAT_00973e80) {
    iVar7 = (&DAT_00973ed4)[DAT_00973ed0];
    *(undefined1 *)(iVar7 + 8) = 0x84;
    *(undefined4 *)(iVar7 + 0xc) = 0;
    *(undefined1 *)(iVar7 + 9) = 4;
  }
  else {
    *(undefined1 *)DAT_00973e84 = 0x84;
    puVar10[1] = 0;
    *(undefined1 *)((int)puVar10 + 1) = 4;
    puVar10 = DAT_00973e80;
    iVar7 = (&DAT_00973ed4)[DAT_00973ed0];
    *(undefined4 *)(iVar7 + 8) = *DAT_00973e80;
    *(undefined4 *)(iVar7 + 0xc) = puVar10[1];
    *(undefined4 *)(iVar7 + 0x10) = puVar10[2];
    *(undefined4 *)(iVar7 + 0x14) = puVar10[3];
    FUN_005fca40(DAT_00973e78);
    DAT_00973e84 = DAT_00973e80;
  }
  iVar7 = DAT_00973ed0;
  DAT_00973ed0 = DAT_00973ed0 + 1;
  return iVar7;
}

