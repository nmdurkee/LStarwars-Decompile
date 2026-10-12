/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a2990; label: FUN_005a2990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a2990(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0xc);
    iVar2 = 0;
    if (*(short *)(param_1 + 2) != 0) {
      do {
        if (iVar1 != 0) {
          FUN_005a2830(iVar1);
          iVar1 = *(int *)(iVar1 + 0x78);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)(uint)*(ushort *)(param_1 + 2));
    }
  }
  return;
}

