/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58b840; label: FUN_0058b840
 */

undefined4 FUN_0058b840(int param_1)

{
  if (((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x94) & 0x800000) != 0) &&
     (*(char *)(param_1 + 0x283) == '\x06')) {
    return 1;
  }
  return 0;
}

