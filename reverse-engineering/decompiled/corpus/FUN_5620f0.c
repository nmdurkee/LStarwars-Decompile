/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x5620f0; label: FUN_005620f0
 */

undefined4 FUN_005620f0(int param_1)

{
  int iVar1;
  
  iVar1 = (int)*(char *)(param_1 + 0x7b5);
  if ((((*(uint *)(PTR_PTR_007fb0e4 + iVar1 * 0x10 + 8) & 0x1004) != 0) &&
      (((DAT_00802898 == -1 || (iVar1 != DAT_00802898)) || (*(char *)(param_1 + 0x7b3) != '\0'))))
     && ((DAT_00802840 == -1 || (iVar1 != DAT_00802840)))) {
    return 1;
  }
  return 0;
}

