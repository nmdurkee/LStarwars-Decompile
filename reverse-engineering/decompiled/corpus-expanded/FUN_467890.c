/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x467890; label: FUN_00467890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00467890(int param_1)

{
  int iVar1;
  
  if ((((*(uint *)(param_1 + 0x74) & 2) == 0) &&
      ((*(float *)(param_1 + 0x4c) <= 0.0 || ((*(uint *)(param_1 + 0xa0) & 0x2000) != 0)))) &&
     (((*(uint *)(param_1 + 0x74) & 0x40) == 0 || ((*(uint *)(param_1 + 0xa0) & 0x800) != 0)))) {
    iVar1 = *(int *)(param_1 + 0x28);
    if (iVar1 != 0) {
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
  return 0;
}

