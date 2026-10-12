/* Ghidra pseudocode, not original source.
 * ev_bd8f422ab2bc288e381e81a075ad63116995ee03e48e3608bccd82f55c6aad54
 * Entry: 0x5da330; label: FUN_005da330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005da330(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x6c) != 0)) {
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x74)) {
      do {
        *(undefined1 *)(iVar1 + param_2) = 0;
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0x74));
    }
    iVar1 = 0;
    *(undefined1 *)(param_2 + *(int *)(param_1 + 0xe0)) = 1;
    if (0 < *(int *)(param_1 + 0xdc)) {
      piVar2 = (int *)(param_1 + 0x9c);
      do {
        if (-1 < *(short *)(*piVar2 + 0x9e)) {
          *(undefined1 *)(*(short *)(*piVar2 + 0x9e) + param_2) = 1;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar1 < *(int *)(param_1 + 0xdc));
    }
  }
  return;
}

