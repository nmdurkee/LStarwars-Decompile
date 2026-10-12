/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x562150; label: FUN_00562150
 */

undefined4 FUN_00562150(int param_1)

{
  if ((((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 8) != 0) &&
      (DAT_00804c0c != -1)) &&
     (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804c0c * 4) != 0)) {
    return 1;
  }
  return 0;
}

