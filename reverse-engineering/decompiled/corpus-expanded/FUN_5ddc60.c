/* Ghidra pseudocode, not original source.
 * ev_87b0cc36f0a526e4b097042d81b23e73008cbbd7a9cf76d2852b3ccb3adbc9c9
 * Entry: 0x5ddc60; label: FUN_005ddc60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005ddc60(int param_1)

{
  if ((param_1 != 0) && (-1 < *(int *)(param_1 + 0x20))) {
    return *(undefined4 *)(param_1 + *(int *)(param_1 + 0x20) * 4);
  }
  return 0xffffffff;
}

