/* Ghidra pseudocode, not original source.
 * ev_bd8f422ab2bc288e381e81a075ad63116995ee03e48e3608bccd82f55c6aad54
 * Entry: 0x5d9130; label: FUN_005d9130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d9130(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xe4) = param_2;
  return;
}

