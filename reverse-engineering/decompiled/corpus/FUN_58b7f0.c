/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58b7f0; label: FUN_0058b7f0
 */

undefined4 FUN_0058b7f0(int param_1)

{
  if (((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x2000000) == 0) &&
     (((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x94) & 0x800) == 0 ||
      (*(char *)(param_1 + 0x280) != -1)))) {
    return 0;
  }
  return 1;
}

