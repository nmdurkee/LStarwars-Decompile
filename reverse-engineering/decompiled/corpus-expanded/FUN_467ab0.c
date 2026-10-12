/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x467ab0; label: FUN_00467ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_00467ab0(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0xfe);
  }
  return 0;
}

