/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x467820; label: FUN_00467820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00467820(float *param_1,int param_2)

{
  FUN_005be2d0(*(float *)(param_2 + 0x1c) - *param_1,*(float *)(param_2 + 0x24) - param_1[2]);
  return;
}

