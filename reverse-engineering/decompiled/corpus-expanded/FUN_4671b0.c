/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x4671b0; label: FUN_004671b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004671b0(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    return *param_1 + 0x1c;
  }
  return 0;
}

