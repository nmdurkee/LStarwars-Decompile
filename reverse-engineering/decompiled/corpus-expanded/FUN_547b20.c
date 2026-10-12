/* Ghidra pseudocode, not original source.
 * ev_3142b78bb26b296d5a5ace8e326a7bee627125b5aa8d8d8928c83f6a565e0b24
 * Entry: 0x547b20; label: FUN_00547b20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00547b20(int param_1)

{
  float fVar1;
  
  fVar1 = ((float)*(byte *)(param_1 + 3) / 10.0) * ((float)*(byte *)(param_1 + 5) / 10.0);
  FUN_00650eb0(fVar1);
  FUN_00694db0(0x10,((float)*(byte *)(param_1 + 5) * 0.85) / 10.0);
  return (float10)fVar1;
}

