/* Ghidra analysis pseudocode, not original source.
 * ev_c1ca6a36f678473ebb33648a43a5c1c2c83c1c89260a3af1d5a93a85b2681cef
 * Entry: 0x547b20; label: FUN_00547b20
 */

float10 FUN_00547b20(int param_1)

{
  float fVar1;
  
  fVar1 = ((float)*(byte *)(param_1 + 3) / 10.0) * ((float)*(byte *)(param_1 + 5) / 10.0);
  FUN_00650eb0(fVar1);
  FUN_00694db0(0x10,((float)*(byte *)(param_1 + 5) * 0.85) / 10.0);
  return (float10)fVar1;
}

