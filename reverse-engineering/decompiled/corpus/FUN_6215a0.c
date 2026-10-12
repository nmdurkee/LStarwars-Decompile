/* Ghidra analysis pseudocode, not original source.
 * ev_0f83c18e3dd08d4f7d4ef8091875e15de78b7d8ec17e52e6723de9bddd8785d9
 * Entry: 0x6215a0; label: FUN_006215a0
 */

void FUN_006215a0(ushort param_1)

{
  if (DAT_02912f48 != 0) {
    param_1 = CONCAT11((char)param_1,(char)(param_1 >> 8));
  }
  _param_1 = (uint)param_1;
  FUN_00621440(&param_1,2);
  return;
}

