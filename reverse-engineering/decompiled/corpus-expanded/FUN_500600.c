/* Ghidra pseudocode, not original source.
 * ev_e3284882596e4924dd8e2753f6ae25b39d285bc55fae2794478040fb50a7242b
 * Entry: 0x500600; label: FUN_00500600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00500600(int param_1)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  iVar12 = *(int *)(param_1 + 0x5c);
  iVar2 = *(int *)(param_1 + 0xbc + (*(int *)(param_1 + 0x88) * 8 >> 0x1f & 1U) * 4);
  *(int *)(param_1 + 0x58) = iVar2;
  *(undefined4 *)(iVar2 + 0x2c) = *(undefined4 *)(iVar12 + 0x2c);
  *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(iVar12 + 0x30);
  *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(iVar12 + 0x34);
  *(uint *)(iVar2 + 0x38) =
       *(uint *)(iVar2 + 0x38) ^ (*(uint *)(iVar12 + 0x38) ^ *(uint *)(iVar2 + 0x38)) & 2;
  piVar3 = *(int **)(iVar12 + 0x1c);
  piVar4 = *(int **)(iVar2 + 0x1c);
  if (piVar4 != (int *)0x0) {
    iVar13 = 0;
    if ((char)piVar4[2] != '\0') {
      iVar11 = 0;
      do {
        uVar5 = ((undefined4 *)(*piVar4 + iVar11))[0x14];
        puVar10 = (undefined4 *)(*piVar3 + iVar11);
        puVar8 = (undefined4 *)(*piVar4 + iVar11);
        for (iVar9 = 0x19; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar8 = *puVar10;
          puVar10 = puVar10 + 1;
          puVar8 = puVar8 + 1;
        }
        *(undefined4 *)(*piVar4 + 0x50 + iVar11) = uVar5;
        iVar13 = iVar13 + 1;
        iVar11 = iVar11 + 100;
      } while (iVar13 < (int)(uint)*(byte *)(piVar4 + 2));
    }
    piVar4[1] = piVar3[1];
  }
  piVar3 = *(int **)(iVar12 + 0x14);
  piVar4 = *(int **)(iVar2 + 0x14);
  iVar13 = 0;
  if (((piVar4 != (int *)0x0) && (*piVar4 != 0)) && (param_1 = 0, (short)piVar4[1] != 0)) {
    do {
      uVar5 = *(undefined4 *)(iVar13 + 0x4c + *piVar4);
      puVar10 = (undefined4 *)(iVar13 + *piVar4);
      uVar6 = puVar10[0x14];
      puVar8 = (undefined4 *)(*piVar3 + iVar13);
      for (iVar11 = 0x17; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
      }
      *(undefined4 *)(iVar13 + 0x4c + *piVar4) = uVar5;
      *(undefined4 *)(iVar13 + 0x50 + *piVar4) = uVar6;
      iVar11 = iVar13 + *piVar4;
      if (((*(int *)(iVar13 + 0x54 + *piVar4) != 0) && (*(char *)(iVar11 + 0x59) != '\0')) &&
         (*(byte *)(iVar11 + 0x5a) != 0xff)) {
        *(uint *)(iVar11 + 0x54) = (uint)*(byte *)(iVar11 + 0x5a) * 100 + **(int **)(iVar2 + 0x1c);
      }
      param_1 = param_1 + 1;
      iVar13 = iVar13 + 0x5c;
    } while (param_1 < (int)(uint)*(ushort *)(piVar4 + 1));
  }
  piVar3 = *(int **)(iVar12 + 0x18);
  piVar4 = *(int **)(iVar2 + 0x18);
  iVar13 = 0;
  if ((piVar4 != (int *)0x0) && (param_1 = 0, (short)piVar4[1] != 0)) {
    do {
      uVar5 = *(undefined4 *)(*piVar4 + 0x44 + iVar13);
      puVar10 = (undefined4 *)(*piVar4 + iVar13);
      uVar6 = puVar10[0x12];
      uVar7 = puVar10[0x13];
      iVar11 = puVar10[0x15];
      puVar8 = (undefined4 *)(*piVar3 + iVar13);
      for (iVar9 = 0x19; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
      }
      *(undefined4 *)(*piVar4 + 0x44 + iVar13) = uVar5;
      *(undefined4 *)(*piVar4 + 0x48 + iVar13) = uVar6;
      *(undefined4 *)(*piVar4 + 0x4c + iVar13) = uVar7;
      if (((iVar11 != 0) && (iVar11 = *piVar4 + iVar13, *(char *)(*piVar4 + 0x5e + iVar13) != '\0'))
         && (bVar1 = *(byte *)(iVar11 + 0x60), bVar1 != 0xff)) {
        *(uint *)(iVar11 + 0x54) = (uint)bVar1 * 100 + **(int **)(iVar2 + 0x1c);
      }
      param_1 = param_1 + 1;
      iVar13 = iVar13 + 100;
    } while (param_1 < (int)(uint)*(ushort *)(piVar4 + 1));
  }
  piVar3 = *(int **)(iVar2 + 0x24);
  if (piVar3 != (int *)0x0) {
    puVar10 = *(undefined4 **)(*(int *)(iVar12 + 0x24) + 4);
    iVar12 = 0;
    if (0 < *piVar3) {
      puVar8 = (undefined4 *)(piVar3[1] + 8);
      do {
        puVar8[-2] = *puVar10;
        puVar8[-1] = puVar10[1];
        *puVar8 = *puVar8;
        iVar12 = iVar12 + 1;
        puVar10 = puVar10 + 3;
        puVar8 = puVar8 + 3;
      } while (iVar12 < *piVar3);
    }
  }
  return;
}

