/* Ghidra pseudocode, not original source.
 * ev_bd8f422ab2bc288e381e81a075ad63116995ee03e48e3608bccd82f55c6aad54
 * Entry: 0x5da840; label: FUN_005da840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005da840(int param_1)

{
  if (*(int *)(param_1 + 0x110) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x110) + 0x6c);
  }
  return *(undefined4 *)(param_1 + 0x24);
}

