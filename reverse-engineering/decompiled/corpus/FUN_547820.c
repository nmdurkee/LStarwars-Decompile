/* Ghidra analysis pseudocode, not original source.
 * ev_c1ca6a36f678473ebb33648a43a5c1c2c83c1c89260a3af1d5a93a85b2681cef
 * Entry: 0x547820; label: FUN_00547820
 */

int FUN_00547820(int param_1)

{
  if ((param_1 != 0) && ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0)) {
    return 1 << (*(byte *)(param_1 + 0x280) & 0x1f);
  }
  return 0;
}

