/* Ghidra pseudocode, not original source.
 * ev_9398ef22b4c43c044c1b187060a2935e0b1d1dc3bbb9f543c9cb1dd758ae788c
 * Entry: 0x5528b0; label: FUN_005528b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005528b0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x110) == 0)) {
    iVar2 = *(int *)(param_1 + 0x1c);
    if (iVar2 != 0) {
      iVar3 = iVar2 * 0x50 + *(int *)(param_1 + 0x20) + 0x48;
      do {
        iVar1 = *(int *)(iVar3 + -0x50);
        iVar3 = iVar3 + -0x50;
        iVar2 = iVar2 + -1;
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(iVar1 + 0x40);
        }
      } while (iVar2 != 0);
    }
  }
  return;
}

