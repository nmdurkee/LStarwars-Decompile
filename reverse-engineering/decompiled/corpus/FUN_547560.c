/* Ghidra analysis pseudocode, not original source.
 * ev_c1ca6a36f678473ebb33648a43a5c1c2c83c1c89260a3af1d5a93a85b2681cef
 * Entry: 0x547560; label: FUN_00547560
 */

int FUN_00547560(int param_1,int param_2)

{
  param_2 = *(short *)(param_1 + 0x14) * param_2;
  if ((*(byte *)(param_2 + 0x2e + param_1) & 1) != 0) {
    return param_2 + param_1 + 0x30;
  }
  return 0;
}

