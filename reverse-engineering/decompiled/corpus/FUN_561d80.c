/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x561d80; label: FUN_00561d80
 */

int FUN_00561d80(int param_1)

{
  int iVar1;
  
  if (((DAT_00804c04 == -1) ||
      (iVar1 = (int)DAT_00804c04,
      *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + iVar1 * 4) == 0)) &&
     ((DAT_00804bf4 == -1 ||
      (iVar1 = (int)DAT_00804bf4,
      *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + iVar1 * 4) == 0)))) {
    iVar1 = (int)DAT_00804bec;
  }
  return iVar1;
}

