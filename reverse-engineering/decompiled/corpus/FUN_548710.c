/* Ghidra analysis pseudocode, not original source.
 * ev_5937183d084659f3cd2a7a2e71fd5c7a233dbdbc790437ca60456b8bfcc76022
 * Entry: 0x548710; label: FUN_00548710
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

