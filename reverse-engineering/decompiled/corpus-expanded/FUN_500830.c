/* Ghidra pseudocode, not original source.
 * ev_e3284882596e4924dd8e2753f6ae25b39d285bc55fae2794478040fb50a7242b
 * Entry: 0x500830; label: FUN_00500830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00500830(uint *param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  uVar1 = param_1[4];
  iVar8 = *(int *)(param_2 + 0x10);
  if (4 < (*param_1 & 0xff)) {
    *(undefined4 *)(uVar1 + 0x1c) = *(undefined4 *)(iVar8 + 0x1c);
    *(undefined4 *)(uVar1 + 0x20) = *(undefined4 *)(iVar8 + 0x20);
  }
  if (*(int *)(iVar8 + 8) != 0) {
    *(int *)(uVar1 + 8) = *(int *)(iVar8 + 8);
  }
  *(undefined4 *)(uVar1 + 0xc) = *(undefined4 *)(iVar8 + 0xc);
  piVar2 = *(int **)(param_2 + 0x1c);
  if (((piVar2 != (int *)0x0) && (piVar3 = (int *)param_1[7], *piVar2 != 0)) &&
     (iVar8 = 0, (char)piVar2[2] != '\0')) {
    iVar7 = 0;
    do {
      iVar4 = *(int *)(*piVar2 + iVar7 + 0x50);
      if (iVar4 != 0) {
        *(int *)(*piVar3 + 0x50 + iVar7) = iVar4;
      }
      iVar8 = iVar8 + 1;
      iVar7 = iVar7 + 100;
    } while (iVar8 < (int)(uint)*(byte *)(piVar2 + 2));
  }
  piVar2 = *(int **)(param_2 + 0x14);
  if (((piVar2 != (int *)0x0) && (piVar3 = (int *)param_1[5], *piVar2 != 0)) &&
     (iVar8 = 0, (short)piVar2[1] != 0)) {
    iVar7 = 0;
    do {
      iVar4 = *piVar2;
      iVar5 = *piVar3;
      iVar6 = *(int *)(iVar4 + 0x4c + iVar7);
      if (iVar6 != 0) {
        *(int *)(iVar5 + iVar7 + 0x4c) = iVar6;
      }
      *(undefined4 *)(iVar5 + iVar7 + 0x50) = *(undefined4 *)(iVar4 + iVar7 + 0x50);
      iVar8 = iVar8 + 1;
      iVar7 = iVar7 + 0x5c;
    } while (iVar8 < (int)(uint)*(ushort *)(piVar2 + 1));
  }
  piVar2 = *(int **)(param_2 + 0x18);
  if (((piVar2 != (int *)0x0) && (piVar3 = (int *)param_1[6], *piVar2 != 0)) &&
     (iVar8 = 0, (short)piVar2[1] != 0)) {
    iVar7 = 0;
    do {
      iVar4 = *(int *)(*piVar2 + 0x44 + iVar7);
      iVar5 = *piVar2 + iVar7;
      iVar6 = *piVar3 + iVar7;
      if (iVar4 != 0) {
        *(int *)(iVar6 + 0x44) = iVar4;
      }
      iVar4 = *(int *)(iVar5 + 0x48);
      if (iVar4 != 0) {
        *(int *)(iVar6 + 0x48) = iVar4;
      }
      iVar4 = *(int *)(iVar5 + 0x4c);
      if (iVar4 != 0) {
        *(int *)(iVar6 + 0x4c) = iVar4;
      }
      iVar8 = iVar8 + 1;
      iVar7 = iVar7 + 100;
    } while (iVar8 < (int)(uint)*(ushort *)(piVar2 + 1));
  }
  piVar2 = *(int **)(param_2 + 0x24);
  if (((piVar2 != (int *)0x0) && (uVar1 = param_1[9], piVar2[1] != 0)) && (iVar8 = 0, 0 < *piVar2))
  {
    iVar7 = 0;
    do {
      *(undefined4 *)(iVar7 + 8 + *(int *)(uVar1 + 4)) = *(undefined4 *)(iVar7 + 8 + piVar2[1]);
      iVar8 = iVar8 + 1;
      iVar7 = iVar7 + 0xc;
    } while (iVar8 < *piVar2);
    param_1[2] = *(uint *)(param_2 + 8);
    return;
  }
  param_1[2] = *(uint *)(param_2 + 8);
  return;
}

