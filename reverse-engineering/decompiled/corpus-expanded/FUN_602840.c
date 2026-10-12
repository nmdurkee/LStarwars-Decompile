/* Ghidra pseudocode, not original source.
 * ev_fc1ff40c7a3094b1e589789cc6fd4e7c7ceccf6febfdd6935cf97a0e254c7b0e
 * Entry: 0x602840; label: FUN_00602840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00602840(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  piVar5 = &DAT_02854da0;
  do {
    if (*piVar5 != 0) {
      iVar1 = *(int *)(*piVar5 + 0x1d0);
      iVar6 = 0;
      if (*(int *)(iVar1 + 0x14) != 0) {
        do {
          iVar2 = *(int *)(*(int *)(iVar1 + 0x10) + iVar6 * 4);
          uVar3 = *(uint *)(iVar2 + 0x28);
          if ((uVar3 != 0) && ((uVar3 & 0xf000) == 0)) {
            FUN_006df300();
            piVar4 = *(int **)(iVar2 + 0x30);
            (**(code **)(*piVar4 + 8))(piVar4);
            FUN_006df310();
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 != *(int *)(iVar1 + 0x14));
      }
    }
    piVar5 = piVar5 + 1;
  } while (piVar5 != &DAT_02854f30);
  return;
}

