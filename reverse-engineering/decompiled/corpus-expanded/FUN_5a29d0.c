/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a29d0; label: FUN_005a29d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a29d0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x46f8)) {
    iVar3 = 0;
    do {
      iVar1 = *(int *)(iVar3 + 0x24 + *(int *)(param_1 + 0x46f4));
      if (iVar1 != 0) {
        FUN_005e5630((int)*(short *)(iVar1 + 0x74));
        FUN_005e50e0(*(undefined4 *)(iVar3 + 0x24 + *(int *)(param_1 + 0x46f4)));
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x28;
    } while (iVar2 < *(int *)(param_1 + 0x46f8));
  }
  return;
}

