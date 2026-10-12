/* Ghidra pseudocode, not original source.
 * ev_26d1fac8fd457d7aa06190d117e50b4f3cb6f2e0dd1b5e3302fd798cb5ca6742
 * Entry: 0x43d500; label: FUN_0043d500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0043d500(int param_1)

{
  if (param_1 < 0) {
    DAT_007f6718 = 0;
    return;
  }
  if (4 < param_1) {
    param_1 = 4;
  }
  DAT_007f6718 = param_1;
  return;
}

