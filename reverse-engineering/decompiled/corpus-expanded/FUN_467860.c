/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x467860; label: FUN_00467860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00467860(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x28), iVar1 != 0)) {
    if ((*(byte *)(param_1 + 0xa0) & 0x40) == 0) {
      if (*(int *)(iVar1 + 0xc) != 2) {
        return 0;
      }
    }
    else if (*(int *)(iVar1 + 0xc) != 0) {
      return 0;
    }
  }
  return 1;
}

