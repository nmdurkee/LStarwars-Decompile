/* Ghidra pseudocode, not original source.
 * ev_3142b78bb26b296d5a5ace8e326a7bee627125b5aa8d8d8928c83f6a565e0b24
 * Entry: 0x547960; label: FUN_00547960
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00547960(uint param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 < 0x54) {
    FUN_00681eb0((int)*(short *)(PTR_DAT_008020bc + param_1 * 2 + 0x158),param_2,param_3);
  }
  return;
}

