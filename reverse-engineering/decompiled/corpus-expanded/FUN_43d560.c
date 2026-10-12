/* Ghidra pseudocode, not original source.
 * ev_26d1fac8fd457d7aa06190d117e50b4f3cb6f2e0dd1b5e3302fd798cb5ca6742
 * Entry: 0x43d560; label: FUN_0043d560
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043d560(float param_1)

{
  if (param_1 < 0.0) {
    _DAT_007f6724 = 0.0;
    return;
  }
  _DAT_007f6724 = param_1;
  return;
}

