/* Ghidra pseudocode, not original source.
 * ev_fc1ff40c7a3094b1e589789cc6fd4e7c7ceccf6febfdd6935cf97a0e254c7b0e
 * Entry: 0x6028b0; label: FUN_006028b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006028b0(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = &DAT_02854da0;
  do {
    if (*piVar3 != 0) {
      iVar1 = *(int *)(*piVar3 + 0x1d0);
      iVar4 = 0;
      if (*(int *)(iVar1 + 0x14) != 0) {
        do {
          iVar2 = *(int *)(*(int *)(iVar1 + 0x10) + iVar4 * 4);
          if ((*(uint *)(iVar2 + 0x28) != 0) && ((*(uint *)(iVar2 + 0x28) & 0xf000) == 0)) {
            FUN_006df300();
            FUN_006e4810((uint)*(ushort *)(iVar2 + 8) * *(int *)(iVar2 + 0x18),0x208,0,0,
                         iVar2 + 0x30);
            FUN_006df310();
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 != *(int *)(iVar1 + 0x14));
      }
    }
    piVar3 = piVar3 + 1;
  } while (piVar3 != &DAT_02854f30);
  return;
}

