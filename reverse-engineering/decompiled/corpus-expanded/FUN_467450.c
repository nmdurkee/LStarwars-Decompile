/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x467450; label: FUN_00467450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00467450(int param_1)

{
  if (param_1 != 0) {
    if ((*(byte *)(param_1 + 0xa0) & 0x40) != 0) {
      FUN_004673e0();
      return;
    }
    FUN_00467380();
  }
  return;
}

