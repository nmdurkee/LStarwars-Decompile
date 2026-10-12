/* Ghidra pseudocode, not original source.
 * ev_23fe0c900a66283c3d20cf72d3e92d7068463e5c92bfb1d0cb56e731534c3cac
 * Entry: 0x554900; label: FUN_00554900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00554900(int *param_1)

{
  if (param_1 != (int *)0x0) {
    return *param_1 + 0x40;
  }
  return 0;
}

