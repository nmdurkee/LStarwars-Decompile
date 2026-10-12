/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x4296c0; label: FUN_004296c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004296c0(int param_1)

{
  if ((*(short *)(param_1 + 0x1064) == DAT_007f18ec) && (DAT_007f3e20 != '\0')) {
    FUN_00681f40("C3_Death",param_1 + 0x80);
  }
  return;
}

