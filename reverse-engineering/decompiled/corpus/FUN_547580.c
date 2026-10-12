/* Ghidra analysis pseudocode, not original source.
 * ev_c1ca6a36f678473ebb33648a43a5c1c2c83c1c89260a3af1d5a93a85b2681cef
 * Entry: 0x547580; label: FUN_00547580
 */

int FUN_00547580(int param_1,int param_2)

{
  if (param_2 == 0) {
    if (*(int *)(param_1 + 8) != 0) {
      return *(int *)(param_1 + 8) + 0x10;
    }
  }
  else if (*(int *)(param_2 + -0xc) != 0) {
    return *(int *)(param_2 + -0xc) + 0x10;
  }
  return 0;
}

