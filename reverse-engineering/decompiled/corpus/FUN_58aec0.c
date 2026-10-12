/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58aec0; label: FUN_0058aec0
 */

int FUN_0058aec0(int param_1)

{
  if (param_1 != -1) {
    return (int)*(short *)(param_1 * 0x10 + DAT_009553dc);
  }
  return -1;
}

