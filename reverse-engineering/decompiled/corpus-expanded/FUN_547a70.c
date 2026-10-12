/* Ghidra pseudocode, not original source.
 * ev_3142b78bb26b296d5a5ace8e326a7bee627125b5aa8d8d8928c83f6a565e0b24
 * Entry: 0x547a70; label: FUN_00547a70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00547a70(int param_1)

{
  return (float10)(((float)*(byte *)(param_1 + 4) / 10.0) * ((float)*(byte *)(param_1 + 5) / 10.0));
}

