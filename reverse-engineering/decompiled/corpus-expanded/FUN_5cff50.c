/* Ghidra pseudocode, not original source.
 * ev_f078e74f3672802c4578b8fbf1fdb2968ffe8ab04b5a400d7e6a18af3d5b4204
 * Entry: 0x5cff50; label: FUN_005cff50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005cff50(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x4c;
    return;
  }
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0xd0;
  }
  return;
}

