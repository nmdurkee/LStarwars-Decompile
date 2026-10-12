/* Ghidra pseudocode, not original source.
 * ev_3142b78bb26b296d5a5ace8e326a7bee627125b5aa8d8d8928c83f6a565e0b24
 * Entry: 0x547820; label: FUN_00547820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00547820(int param_1)

{
  if ((param_1 != 0) && ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0)) {
    return 1 << (*(byte *)(param_1 + 0x280) & 0x1f);
  }
  return 0;
}

