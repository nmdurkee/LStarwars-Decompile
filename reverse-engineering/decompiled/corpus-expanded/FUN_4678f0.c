/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x4678f0; label: FUN_004678f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004678f0(int param_1,int param_2)

{
  if ((((param_2 != 0) && (param_1 != 0)) && (*(char *)(param_1 + 0x7b5) == '\b')) &&
     (*(int *)(param_1 + 0x10cc) == param_2)) {
    return 1;
  }
  return 0;
}

