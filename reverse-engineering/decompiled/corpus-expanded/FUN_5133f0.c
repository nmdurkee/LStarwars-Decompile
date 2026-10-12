/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x5133f0; label: thunk_FUN_004f11e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void thunk_FUN_004f11e0(int param_1)

{
  if (-1 < *(int *)(param_1 + 0x570)) {
    *(int *)(param_1 + 0x570) = *(int *)(param_1 + 0x570) + -1;
  }
  return;
}

