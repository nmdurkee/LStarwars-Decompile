/* Ghidra pseudocode, not original source.
 * ev_bd8f422ab2bc288e381e81a075ad63116995ee03e48e3608bccd82f55c6aad54
 * Entry: 0x5da2d0; label: FUN_005da2d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005da2d0(int param_1,short param_2)

{
  int iVar1;
  int *piVar2;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x6c) != 0)) {
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0xdc)) {
      piVar2 = (int *)(param_1 + 0x9c);
      do {
        if (*(short *)(*piVar2 + 0x9e) == param_2) {
          return 1;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar1 < *(int *)(param_1 + 0xdc));
    }
    return 0;
  }
  return 1;
}

