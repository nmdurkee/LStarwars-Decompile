/* Ghidra pseudocode, not original source.
 * ev_3142b78bb26b296d5a5ace8e326a7bee627125b5aa8d8d8928c83f6a565e0b24
 * Entry: 0x547990; label: FUN_00547990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00547990(uint param_1)

{
  if (param_1 < 0x54) {
    return (int)*(short *)(PTR_DAT_008020bc + param_1 * 2 + 0x158);
  }
  return -1;
}

