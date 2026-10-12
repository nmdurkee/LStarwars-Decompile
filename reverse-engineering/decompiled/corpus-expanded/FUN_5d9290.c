/* Ghidra pseudocode, not original source.
 * ev_bd8f422ab2bc288e381e81a075ad63116995ee03e48e3608bccd82f55c6aad54
 * Entry: 0x5d9290; label: FUN_005d9290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined2 FUN_005d9290(int param_1)

{
  if (param_1 != 0) {
    return *(undefined2 *)(param_1 + 0x74);
  }
  return 0;
}

