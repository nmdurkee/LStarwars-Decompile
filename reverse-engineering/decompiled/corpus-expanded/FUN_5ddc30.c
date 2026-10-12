/* Ghidra pseudocode, not original source.
 * ev_87b0cc36f0a526e4b097042d81b23e73008cbbd7a9cf76d2852b3ccb3adbc9c9
 * Entry: 0x5ddc30; label: FUN_005ddc30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ddc30(int param_1,float param_2)

{
  if (param_1 != 0) {
    if (1.0 <= param_2) {
      *(float *)(param_1 + 0x28) = param_2;
      return;
    }
    *(undefined4 *)(param_1 + 0x28) = 0x3f800000;
  }
  return;
}

