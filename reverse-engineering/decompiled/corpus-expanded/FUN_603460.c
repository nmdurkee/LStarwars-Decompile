/* Ghidra pseudocode, not original source.
 * ev_a67b1d7875d7de5d33c5f2e23ff7bb43dcd4ff34aaa1a90d4ca40378ea72f78c
 * Entry: 0x603460; label: FUN_00603460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00603460(undefined1 *param_1,undefined4 param_2)

{
  *param_1 = 0x80;
  *(undefined4 *)(param_1 + 4) = param_2;
  param_1[1] = 3;
  return;
}

