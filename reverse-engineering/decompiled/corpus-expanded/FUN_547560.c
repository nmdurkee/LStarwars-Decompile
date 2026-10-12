/* Ghidra pseudocode, not original source.
 * ev_3142b78bb26b296d5a5ace8e326a7bee627125b5aa8d8d8928c83f6a565e0b24
 * Entry: 0x547560; label: FUN_00547560
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00547560(int param_1,int param_2)

{
  param_2 = *(short *)(param_1 + 0x14) * param_2;
  if ((*(byte *)(param_2 + 0x2e + param_1) & 1) != 0) {
    return param_2 + param_1 + 0x30;
  }
  return 0;
}

