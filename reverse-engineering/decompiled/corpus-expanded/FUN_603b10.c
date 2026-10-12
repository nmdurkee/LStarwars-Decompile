/* Ghidra pseudocode, not original source.
 * ev_a67b1d7875d7de5d33c5f2e23ff7bb43dcd4ff34aaa1a90d4ca40378ea72f78c
 * Entry: 0x603b10; label: FUN_00603b10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00603b10(int param_1,undefined4 param_2,int param_3)

{
  *(float *)(*(int *)(param_1 + 4) + 0x38) = (float)param_3;
  return;
}

