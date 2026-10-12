/* Ghidra pseudocode, not original source.
 * ev_f0f87d832dbe8e7fa4eaa2c5681d260c3f1d1a42269eaf7f506f4d6846a5d20b
 * Entry: 0x548710; label: FUN_00548710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00548710(void)

{
  if (DAT_00924de8 != 0) {
    FUN_00681e90((int)*(short *)(PTR_DAT_008020bc + 0x192),0);
    DAT_00924de8 = 0;
    return;
  }
  FUN_00681e90((int)*(short *)(PTR_DAT_008020bc + 0x194),0);
  DAT_00924de8 = 1;
  return;
}

