/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56cdb0; label: FUN_0056cdb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0056cdb0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x50a4) != 0) {
    return 0;
  }
  FUN_006217e0();
  iVar1 = FUN_006217e0();
  iVar2 = 0;
  *(int *)(param_1 + 0x50a4) = iVar1;
  if (0 < iVar1) {
    iVar1 = 0;
    do {
      FUN_006216f0(*(int *)(param_1 + 0x50a0) + iVar1,8);
      FUN_00621900(iVar1 + 8 + *(int *)(param_1 + 0x50a0));
      FUN_00621900(iVar1 + 0x14 + *(int *)(param_1 + 0x50a0));
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x24;
    } while (iVar2 < *(int *)(param_1 + 0x50a4));
  }
  return 1;
}

