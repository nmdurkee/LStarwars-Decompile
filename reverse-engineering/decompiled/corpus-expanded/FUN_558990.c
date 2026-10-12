/* Ghidra pseudocode, not original source.
 * ev_f8ed381e2b466dd5bc773ab3f84ab60966b69e10a49b3e28fcf3f54e00ea1563
 * Entry: 0x558990; label: FUN_00558990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00558990(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x34) != 0)) {
    FUN_005a11f0();
    return;
  }
  return;
}

