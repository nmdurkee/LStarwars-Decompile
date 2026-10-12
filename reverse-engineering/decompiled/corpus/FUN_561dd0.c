/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x561dd0; label: FUN_00561dd0
 */

int FUN_00561dd0(int param_1)

{
  int iVar1;
  
  if (((DAT_00804c08 == -1) ||
      (iVar1 = (int)DAT_00804c08,
      *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + iVar1 * 4) == 0)) &&
     ((DAT_00804bfc == -1 ||
      (iVar1 = (int)DAT_00804bfc,
      *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + iVar1 * 4) == 0)))) {
    iVar1 = (int)DAT_00804bf0;
  }
  return iVar1;
}

