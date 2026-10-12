/* Ghidra pseudocode, not original source.
 * ev_d6810b63b1adbb1cff68d70c4de6dcedf5c7ec9f8161f7a4b49c43fe0c68c9ee
 * Entry: 0x7413a0; label: FUN_007413a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_007413a0(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
  return;
}

