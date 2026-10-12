/* Ghidra pseudocode, not original source.
 * ev_a67b1d7875d7de5d33c5f2e23ff7bb43dcd4ff34aaa1a90d4ca40378ea72f78c
 * Entry: 0x603aa0; label: FUN_00603aa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00603aa0(int param_1)

{
  if (param_1 == 0) {
    PTR_PTR_0080e794 = (undefined *)&PTR_FUN_0080e6d0;
    return;
  }
  if (param_1 != 1) {
    FUN_005f7490();
    return;
  }
  PTR_PTR_0080e794 = (undefined *)&PTR_FUN_0080e798;
  return;
}

