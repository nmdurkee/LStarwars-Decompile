/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58af20; label: FUN_0058af20
 */

uint FUN_0058af20(int param_1,uint param_2)

{
  if (param_1 == -1) {
    return 0;
  }
  if (param_2 != 0) {
    return *(ushort *)(param_1 * 0x10 + 10 + DAT_009553dc) & param_2;
  }
  return (uint)*(ushort *)(param_1 * 0x10 + 10 + DAT_009553dc);
}

