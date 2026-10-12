/* Ghidra pseudocode, not original source.
 * ev_fc1ff40c7a3094b1e589789cc6fd4e7c7ceccf6febfdd6935cf97a0e254c7b0e
 * Entry: 0x6026a0; label: FUN_006026a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006026a0(int param_1)

{
  ushort *puVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  short *psVar5;
  short *psVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  puVar1 = *(ushort **)(param_1 + 0x1d0);
  uVar7 = 0;
  if (*puVar1 != 0) {
    do {
      FUN_006df300();
      FUN_006e5b70(*(int *)(puVar1 + 2) + uVar7 * 4);
      FUN_006df310();
      uVar7 = uVar7 + 1;
    } while (uVar7 != *puVar1);
  }
  uVar7 = 0;
  if (puVar1[4] != 0) {
    do {
      FUN_006df300();
      FUN_006e5b70(*(int *)(puVar1 + 6) + uVar7 * 4);
      FUN_006df310();
      uVar7 = uVar7 + 1;
    } while (uVar7 != puVar1[4]);
  }
  iVar8 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    do {
      FUN_006df300();
      FUN_006e5b70(*(int *)(*(int *)(param_1 + 8) + iVar8 * 4) + 0x24);
      FUN_006df310();
      iVar8 = iVar8 + 1;
    } while (iVar8 != *(int *)(param_1 + 4));
  }
  iVar8 = 0;
  bVar3 = false;
  if (*(int *)(puVar1 + 10) != 0) {
    do {
      iVar9 = *(int *)(*(int *)(puVar1 + 8) + iVar8 * 4);
      uVar7 = *(uint *)(iVar9 + 0x28);
      if ((uVar7 != 0) && ((uVar7 & 0xf000) == 0)) {
        bVar3 = true;
        FUN_006df300();
        piVar2 = *(int **)(iVar9 + 0x30);
        (**(code **)(*piVar2 + 8))(piVar2);
        FUN_006df310();
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 != *(int *)(puVar1 + 10));
    if (bVar3) {
      iVar8 = 0;
      do {
        if ((&DAT_02854da0)[iVar8] == param_1) {
          (&DAT_02854da0)[iVar8] = 0;
          break;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 != 100);
    }
  }
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    psVar5 = (short *)(**(int **)(param_1 + 0xc) + 500);
    do {
      iVar9 = 2;
      psVar6 = psVar5;
      do {
        if (0 < *psVar6) {
          iVar4 = FUN_00741620((int)*psVar6);
          *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) + -1;
        }
        psVar6 = psVar6 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      iVar8 = iVar8 + 1;
      psVar5 = psVar5 + 0x162;
    } while (iVar8 < *(int *)(param_1 + 0x10));
  }
  return;
}

