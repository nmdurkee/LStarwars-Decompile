/* Ghidra pseudocode, not original source.
 * ev_de7bd3aa239ec0c059aa1bbec058a25d35da9446e5dffd1cda86600a1f15d21b
 * Entry: 0x659290; label: FUN_00659290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00659290(float param_1)

{
  if (1.0 < param_1) {
    _DAT_00810908 = param_1;
    return;
  }
  _DAT_00810908 = 1.0;
  return;
}

